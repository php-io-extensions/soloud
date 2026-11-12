/*
 * The object model: one PHP object per SoLoud object, PHP-constructed objects deleted with their PHP
 * object, and the references that keep the objects SoLoud points at alive.
 */

#include "runtime.h"
#include "callbacks.h"
#include "soloud_queue.h"
#include "soloud_lofifilter.h"
#include "soloud_file.h"

#include <cstdio>

ZEND_DECLARE_MODULE_GLOBALS(soloud)

zend_object_handlers soloud_handlers;

/* Internal class entry => its soloud_class, so a PHP subclass finds the SoLoud class it extends. */
static HashTable soloud_classes;

static const soloud_class *soloud_class_of(zend_class_entry *ce)
{
	for (; ce != NULL; ce = ce->parent) {
		const soloud_class *cls = (const soloud_class *) zend_hash_index_find_ptr(&soloud_classes, (zend_ulong) (uintptr_t) ce);
		if (cls != NULL) {
			return cls;
		}
	}
	return NULL;
}

bool soloud_is_a(const soloud_class *cls, const soloud_class *base)
{
	for (; cls != NULL; cls = cls->base) {
		if (cls == base) {
			return true;
		}
	}
	return false;
}

static zend_object *soloud_create_object(zend_class_entry *ce)
{
	soloud_object *obj = (soloud_object *) zend_object_alloc(sizeof(soloud_object), ce);
	obj->native = NULL;
	obj->cls = soloud_class_of(ce);
	obj->owned = false;
	obj->php = ce->type == ZEND_USER_CLASS && obj->cls != NULL && soloud_trampolined(obj->cls);
	obj->link = NULL;
	obj->channels = 0;
	memset(obj->slots, 0, sizeof obj->slots);
	obj->held = NULL;
	zend_object_std_init(&obj->std, ce);
	object_properties_init(&obj->std, ce);
	obj->std.handlers = &soloud_handlers;
	return &obj->std;
}

extern const soloud_class soloud_class_SoLoud_Soloud;
extern const soloud_class soloud_class_SoLoud_AudioSource;

/* An engine going away: SoLoud's sources keep a raw Soloud* (AudioSource::mSoloud) and their destructors
 * call through it. Clear it on every live source that points at this engine. */
static void soloud_engine_gone(SoLoud::Soloud *engine)
{
	void *other;
	ZEND_HASH_FOREACH_PTR(&SOLOUD_G(boxes), other) {
		soloud_object *o = soloud_from(static_cast<zend_object *>(other));
		if (o->native != NULL && soloud_is_a(o->cls, &soloud_class_SoLoud_AudioSource)) {
			SoLoud::AudioSource *source = static_cast<SoLoud::AudioSource *>(o->native);
			if (source->mSoloud == engine) {
				source->mSoloud = NULL;
			}
		}
	} ZEND_HASH_FOREACH_END();
}

extern const soloud_class soloud_class_SoLoud_Queue;

/* A source going away while queued: Queue keeps instances of it in its ring (mSource[]) and the mixer reads
 * their parent. Delete this source's instances and compact the ring, under the engine's audio mutex. */
static void soloud_queue_forget(SoLoud::Queue *queue, unsigned int sourceId)
{
	SoLoud::Soloud *engine = queue->mSoloud;
	if (engine != NULL) {
		engine->lockAudioMutex_internal();
	}
	SoLoud::AudioSourceInstance *keep[SOLOUD_QUEUE_MAX];
	unsigned int kept = 0;
	for (unsigned int i = 0; i < queue->mCount; i++) {
		SoLoud::AudioSourceInstance *instance = queue->mSource[(queue->mReadIndex + i) % SOLOUD_QUEUE_MAX];
		if (instance != NULL && instance->mAudioSourceID == sourceId) {
			delete instance;
		} else {
			keep[kept++] = instance;
		}
	}
	for (unsigned int i = 0; i < SOLOUD_QUEUE_MAX; i++) {
		queue->mSource[i] = i < kept ? keep[i] : NULL;
	}
	queue->mReadIndex = 0;
	queue->mWriteIndex = kept % SOLOUD_QUEUE_MAX;
	queue->mCount = kept;
	if (engine != NULL) {
		engine->unlockAudioMutex_internal();
	}
}

static void soloud_source_gone(SoLoud::AudioSource *source)
{
	void *other;
	ZEND_HASH_FOREACH_PTR(&SOLOUD_G(boxes), other) {
		soloud_object *o = soloud_from(static_cast<zend_object *>(other));
		if (o->native != NULL && o->native != source && soloud_is_a(o->cls, &soloud_class_SoLoud_Queue)) {
			soloud_queue_forget(static_cast<SoLoud::Queue *>(o->native), source->mAudioSourceID);
		}
	} ZEND_HASH_FOREACH_END();
}

extern const soloud_class soloud_class_SoLoud_Filter;

/* A filter going away while a source or an engine holds it (only in shutdown order: the holder keeps it
 * alive otherwise). Sources instance their filters per voice and some instances read their parent
 * (DCRemovalFilterInstance::mParent), so stop the holder's voices, then clear its slots. */
static void soloud_filter_gone(zend_object *object, SoLoud::Filter *filter)
{
	char role[32];
	snprintf(role, sizeof role, "filter:%u", object->handle);
	void *other;
	ZEND_HASH_FOREACH_PTR(&SOLOUD_G(boxes), other) {
		soloud_object *o = soloud_from(static_cast<zend_object *>(other));
		if (o->native == NULL || o->held == NULL || !zend_hash_str_exists(o->held, role, strlen(role))) {
			continue;
		}
		if (soloud_is_a(o->cls, &soloud_class_SoLoud_AudioSource)) {
			SoLoud::AudioSource *source = static_cast<SoLoud::AudioSource *>(o->native);
			source->stop();
			for (unsigned int i = 0; i < FILTERS_PER_STREAM; i++) {
				if (source->mFilter[i] == filter) {
					source->setFilter(i, NULL);
				}
			}
		} else if (soloud_is_a(o->cls, &soloud_class_SoLoud_Soloud)) {
			SoLoud::Soloud *engine = static_cast<SoLoud::Soloud *>(o->native);
			for (unsigned int i = 0; i < FILTERS_PER_STREAM; i++) {
				if (engine->mFilter[i] == filter) {
					engine->setGlobalFilter(i, NULL);
				}
			}
		}
	} ZEND_HASH_FOREACH_END();
}

extern const soloud_class soloud_class_SoLoud_Thread_Pool;

static void soloud_free_object(zend_object *object)
{
	soloud_object *obj = soloud_from(object);
	if (obj->php) {
		soloud_trampoline_free(obj);
	}
	if (obj->native != NULL) {
		zend_ulong key = (zend_ulong) (uintptr_t) obj->native;
		if (zend_hash_index_find_ptr(&SOLOUD_G(boxes), key) == object) {
			zend_hash_index_del(&SOLOUD_G(boxes), key);
		}
		if (obj->owned && obj->cls != NULL && (obj->php || obj->cls->destroy != NULL)) {
			void *native = obj->native;
			obj->native = NULL;
			if (soloud_is_a(obj->cls, &soloud_class_SoLoud_AudioSource)) {
				soloud_source_gone(static_cast<SoLoud::AudioSource *>(native));
			} else if (soloud_is_a(obj->cls, &soloud_class_SoLoud_Filter)) {
				soloud_filter_gone(object, static_cast<SoLoud::Filter *>(native));
			}
			if (obj->php) {
				soloud_trampoline_delete(obj, native);
			} else if (soloud_is_a(obj->cls, &soloud_class_SoLoud_Thread_Pool)) {
				/* ~Pool joins workers that may be waiting on this thread for a PHP task. */
				void (*destroy)(void *) = obj->cls->destroy;
				soloud_serve_until([&] { destroy(native); });
			} else {
				obj->cls->destroy(native);
			}
			if (soloud_is_a(obj->cls, &soloud_class_SoLoud_Soloud)) {
				soloud_engine_gone(static_cast<SoLoud::Soloud *>(native));
			}
		}
		obj->native = NULL;
	}
	if (obj->held != NULL) {
		zend_hash_destroy(obj->held);
		FREE_HASHTABLE(obj->held);
		obj->held = NULL;
	}
	zend_object_std_dtor(object);
}

static zval *soloud_read_property(zend_object *object, zend_string *name, int type, void **cache_slot, zval *rv)
{
	soloud_object *obj = soloud_from(object);
	if (soloud_trampoline(obj) != NULL) {
		for (const soloud_class *cls = obj->cls; cls != NULL; cls = cls->base) {
			if (cls->read != NULL && cls->read(obj, name, rv)) {
				return rv;
			}
		}
	}
	return zend_std_read_property(object, name, type, cache_slot, rv);
}

static zval *soloud_write_property(zend_object *object, zend_string *name, zval *value, void **cache_slot)
{
	soloud_object *obj = soloud_from(object);
	if (soloud_trampoline(obj) != NULL) {
		for (const soloud_class *cls = obj->cls; cls != NULL; cls = cls->base) {
			if (cls->write != NULL && cls->write(obj, name, value)) {
				return value;
			}
		}
	}
	return zend_std_write_property(object, name, value, cache_slot);
}

/* A field is read live: no reference into it may be taken. */
static zval *soloud_get_property_ptr_ptr(zend_object *object, zend_string *name, int type, void **cache_slot)
{
	(void) object; (void) name; (void) type; (void) cache_slot;
	return NULL;
}

void soloud_register_class(const soloud_class *info)
{
	if (soloud_classes.nTableSize == 0) {
		zend_hash_init(&soloud_classes, 64, NULL, NULL, 1);
		memcpy(&soloud_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
		soloud_handlers.offset = XtOffsetOf(soloud_object, std);
		soloud_handlers.free_obj = soloud_free_object;
		soloud_handlers.clone_obj = NULL;
		soloud_handlers.read_property = soloud_read_property;
		soloud_handlers.write_property = soloud_write_property;
		soloud_handlers.get_property_ptr_ptr = soloud_get_property_ptr_ptr;
	}
	zend_class_entry *ce = *info->ce;
	ce->create_object = soloud_create_object;
	ce->ce_flags |= ZEND_ACC_NOT_SERIALIZABLE;
	zend_hash_index_add_ptr(&soloud_classes, (zend_ulong) (uintptr_t) ce, (void *) info);
}

void soloud_runtime_mshutdown(void)
{
	if (soloud_classes.nTableSize != 0) {
		zend_hash_destroy(&soloud_classes);
	}
}

void *soloud_this(zval *self, const soloud_class *want)
{
	/* Releases first: SoLoud may have deleted a PHP instance's native on another thread. */
	soloud_serve();
	soloud_object *obj = soloud_from(Z_OBJ_P(self));
	if (soloud_trampoline(obj) == NULL || !soloud_is_a(obj->cls, want)) {
		zend_throw_error(NULL, "%s object is not constructed", want->name);
		return NULL;
	}
	return obj->native;
}

void *soloud_arg(zend_object *object, uint32_t argnum, const soloud_class *want)
{
	if (object == NULL) {
		return NULL;
	}
	soloud_object *obj = soloud_from(object);
	if (soloud_trampoline(obj) == NULL || !soloud_is_a(obj->cls, want)) {
		zend_argument_error(zend_ce_error, argnum, "must be a constructed %s", want->name);
		return NULL;
	}
	return obj->native;
}

bool soloud_fresh(soloud_object *obj)
{
	if (obj->native != NULL) {
		zend_throw_error(NULL, "%s object is already constructed", obj->cls->name);
		return false;
	}
	return true;
}

void soloud_adopt(soloud_object *obj, void *native, bool owned)
{
	obj->native = native;
	obj->owned = owned;
	zend_hash_index_update_ptr(&SOLOUD_G(boxes), (zend_ulong) (uintptr_t) native, &obj->std);
}

void soloud_wrap(void *native, const soloud_class *cls, zend_object *owner, zval *rv)
{
	if (native == NULL) {
		ZVAL_NULL(rv);
		return;
	}
	zend_object *found = (zend_object *) zend_hash_index_find_ptr(&SOLOUD_G(boxes), (zend_ulong) (uintptr_t) native);
	if (found != NULL && soloud_is_a(soloud_from(found)->cls, cls)) {
		GC_ADDREF(found);
		ZVAL_OBJ(rv, found);
		return;
	}
	zend_object *created = soloud_create_object(*cls->ce);
	soloud_object *obj = soloud_from(created);
	if (found == NULL) {
		soloud_adopt(obj, native, false);
	} else {
		obj->native = native;   /* a member at its owner's address: not in the identity map */
	}
	if (owner != NULL) {
		zval held;
		ZVAL_OBJ(&held, owner);
		soloud_hold(obj, "owner", &held);
	}
	ZVAL_OBJ(rv, created);
}

void soloud_wrap_owned(void *native, const soloud_class *cls, zval *rv)
{
	zend_object *created = soloud_create_object(*cls->ce);
	soloud_adopt(soloud_from(created), native, true);
	ZVAL_OBJ(rv, created);
}

bool soloud_handles(zend_object *object)
{
	return object->handlers == &soloud_handlers;
}

bool soloud_range_arg(zend_long value, zend_long min, zend_long max, uint32_t argnum)
{
	if (value < min || value > max) {
		zend_argument_value_error(argnum, "must be between " ZEND_LONG_FMT " and " ZEND_LONG_FMT, min, max);
		return false;
	}
	return true;
}

bool soloud_field_arg(zend_string *name, zval *value, soloud_field_kind kind, zend_long min, zend_long max, zval *out)
{
	switch (kind) {
		case SOLOUD_FIELD_READONLY:
			zend_throw_error(NULL, "Cannot modify SoLoud field $%s: it is not a scalar", ZSTR_VAL(name));
			return false;
		case SOLOUD_FIELD_BOOL:
			if (Z_TYPE_P(value) != IS_TRUE && Z_TYPE_P(value) != IS_FALSE) {
				zend_type_error("SoLoud field $%s must be of type bool, %s given", ZSTR_VAL(name), zend_zval_value_name(value));
				return false;
			}
			ZVAL_BOOL(out, Z_TYPE_P(value) == IS_TRUE);
			return true;
		case SOLOUD_FIELD_FLOAT:
			if (Z_TYPE_P(value) == IS_LONG) {
				ZVAL_DOUBLE(out, (double) Z_LVAL_P(value));
				return true;
			}
			if (Z_TYPE_P(value) != IS_DOUBLE) {
				zend_type_error("SoLoud field $%s must be of type float, %s given", ZSTR_VAL(name), zend_zval_value_name(value));
				return false;
			}
			ZVAL_DOUBLE(out, Z_DVAL_P(value));
			return true;
		case SOLOUD_FIELD_INT:
			if (Z_TYPE_P(value) != IS_LONG) {
				zend_type_error("SoLoud field $%s must be of type int, %s given", ZSTR_VAL(name), zend_zval_value_name(value));
				return false;
			}
			if (Z_LVAL_P(value) < min || Z_LVAL_P(value) > max) {
				zend_value_error("SoLoud field $%s must be between " ZEND_LONG_FMT " and " ZEND_LONG_FMT, ZSTR_VAL(name), min, max);
				return false;
			}
			ZVAL_LONG(out, Z_LVAL_P(value));
			return true;
	}
	return false;
}

bool soloud_uint_arg(zend_long value, uint32_t argnum, unsigned int *out)
{
	if (value < 0 || (zend_ulong) value > UINT32_MAX) {
		zend_argument_value_error(argnum, "must be between 0 and %u", UINT32_MAX);
		return false;
	}
	*out = (unsigned int) value;
	return true;
}

zend_string *soloud_float_buffer(zval *ref, size_t count)
{
	size_t bytes = count * sizeof(float);
	zend_string *out = zend_string_alloc(bytes, 0);
	zval *v = Z_ISREF_P(ref) ? Z_REFVAL_P(ref) : ref;
	size_t have = Z_TYPE_P(v) == IS_STRING ? Z_STRLEN_P(v) : 0;
	if (have > bytes) {
		have = bytes;
	}
	if (have > 0) {
		memcpy(ZSTR_VAL(out), Z_STRVAL_P(v), have);
	}
	memset(ZSTR_VAL(out) + have, 0, bytes - have);
	ZSTR_VAL(out)[bytes] = '\0';
	return out;
}

void soloud_hold(soloud_object *obj, const char *role, zval *value)
{
	if (obj->held == NULL) {
		ALLOC_HASHTABLE(obj->held);
		zend_hash_init(obj->held, 4, NULL, ZVAL_PTR_DTOR, 0);
	}
	Z_TRY_ADDREF_P(value);
	zend_hash_str_update(obj->held, role, strlen(role), value);
}

void soloud_unhold(soloud_object *obj, const char *role)
{
	if (obj->held != NULL) {
		zend_hash_str_del(obj->held, role, strlen(role));
	}
}

/* LofiFilterInstance::mChannelData[2]. */
static bool soloud_lofi(SoLoud::Filter *filter)
{
	return filter != NULL && dynamic_cast<SoLoud::LofiFilter *>(filter) != NULL;
}

/* init() creates the audio mutex and deinit() clears it: the engine mixes only between the two. */
static bool soloud_engine_live(SoLoud::Soloud *self)
{
	return self->mAudioThreadMutex != NULL;
}

bool soloud_engine_initialised(SoLoud::Soloud *self, char *why, size_t size)
{
	if (self->mResampleDataOwner == NULL) {
		snprintf(why, size, "The engine has not been initialised: init() has not succeeded, and a voice played now cannot be stopped");
		return false;
	}
	return true;
}

bool soloud_voice_filters_fit(SoLoud::AudioSource *aSound, char *why, size_t size)
{
	if (aSound == NULL || aSound->mChannels <= 2) {
		return true;
	}
	for (unsigned int i = 0; i < FILTERS_PER_STREAM; i++) {
		if (soloud_lofi(aSound->mFilter[i])) {
			snprintf(why, size, "$aSound has %u channels and a LofiFilter in slot %u, which holds state for 2", aSound->mChannels, i);
			return false;
		}
	}
	return true;
}

bool soloud_global_filter_fits(SoLoud::Soloud *self, unsigned int aFilterId, SoLoud::Filter *aFilter, char *why, size_t size)
{
	if (aFilterId < FILTERS_PER_STREAM && soloud_lofi(aFilter) && soloud_engine_live(self) && self->mChannels > 2) {
		snprintf(why, size, "The engine mixes %u channels and a LofiFilter holds state for 2", self->mChannels);
		return false;
	}
	return true;
}

bool soloud_init_filters_fit(soloud_object *obj, SoLoud::Soloud *self, unsigned int aChannels, char *why, size_t size)
{
	for (unsigned int i = 0; i < FILTERS_PER_STREAM; i++) {
		if (self->mFilter[i] == NULL) {
			continue;
		}
		if (soloud_lofi(self->mFilter[i]) && aChannels > 2) {
			snprintf(why, size, "Global filter %u is a LofiFilter, which holds state for 2 channels; $aChannels is %u", i, aChannels);
			return false;
		}
		if (obj->slots[i] != 0 && aChannels > obj->slots[i]) {
			snprintf(why, size, "Global filter %u's state is sized for %u channels; $aChannels is %u (deinit(), set the filter again, then init())", i, obj->slots[i], aChannels);
			return false;
		}
	}
	return true;
}

void soloud_global_filter_set(soloud_object *obj, SoLoud::Soloud *self, unsigned int aFilterId)
{
	if (aFilterId < FILTERS_PER_STREAM) {
		obj->slots[aFilterId] = self->mFilter[aFilterId] != NULL && soloud_engine_live(self) ? self->mChannels : 0;
	}
}

bool soloud_task_given(void *aTask, char *why, size_t size)
{
	if (aTask == NULL) {
		snprintf(why, size, "$aTask is null, and a pool runs its tasks without a check");
		return false;
	}
	return true;
}

bool soloud_file_open(SoLoud::File *aFile, char *why, size_t size)
{
	if (aFile == NULL) {
		snprintf(why, size, "$aFile is null, and SoLoud reads it without a check");
		return false;
	}
	SoLoud::DiskFile *disk = dynamic_cast<SoLoud::DiskFile *>(aFile);
	if (disk != NULL && disk->mFileHandle == NULL) {
		snprintf(why, size, "The DiskFile is not open: SoLoud reads through its NULL FILE *");
		return false;
	}
	SoLoud::MemoryFile *mem = dynamic_cast<SoLoud::MemoryFile *>(aFile);
	if (mem != NULL && mem->mDataLength == 0) {
		snprintf(why, size, "The MemoryFile holds no data: SoLoud seeks it to any offset, then reads past it");
		return false;
	}
	return true;
}

void soloud_init_filters_ran(soloud_object *obj, SoLoud::Soloud *self)
{
	for (unsigned int i = 0; i < FILTERS_PER_STREAM; i++) {
		if (self->mFilter[i] == NULL) {
			obj->slots[i] = 0;
		} else if (obj->slots[i] == 0) {
			obj->slots[i] = self->mChannels;
		}
	}
}
