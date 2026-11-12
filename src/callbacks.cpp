/*
 * Trampolines and the owner queue: see callbacks.h.
 */

#include "callbacks.h"
#include "gen/classes.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <deque>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

namespace {

enum { SOLOUD_POSTED, SOLOUD_STARTED, SOLOUD_DONE };

struct soloud_owner;

/* One PHP object behind a trampoline. object and held are touched on the owner thread only. */
struct soloud_link {
	std::shared_ptr<soloud_owner> owner;
	zend_object *object = NULL;      /* NULL once the PHP object is freed */
	std::atomic<bool> gone{false};   /* calls on it are no-ops */
	bool held = false;               /* SoLoud owns the native; the trampoline holds a reference to object */
	uint32_t overrides = 0;          /* bit i: the PHP class overrides virtual i of its trampoline */
};

struct soloud_request {
	std::function<bool()> run;
	bool php = true;                 /* runs PHP: skipped (no-op) while an exception is pending */
	int state = SOLOUD_POSTED;
	bool ok = false;
};

/* The queue of one PHP request's thread. */
struct soloud_owner {
	std::mutex lock;
	std::condition_variable cond;
	std::deque<std::shared_ptr<soloud_request>> queue;
	std::atomic<bool> pending{false};
	zend_atomic_bool *interrupt = NULL;
	std::thread::id thread;
	bool alive = true;
	bool serving = false;            /* owner thread only */
};

thread_local std::shared_ptr<soloud_owner> soloud_current;

void (*soloud_prev_interrupt)(zend_execute_data *execute_data);

/* Posts run to owner and waits up to seconds (< 0: until it ran or the owner's request ended).
 * false: not run in time, an exception was pending, or run failed. Inline on the owner thread. */
bool soloud_run(const std::shared_ptr<soloud_owner> &owner, double seconds, bool php, std::function<bool()> run)
{
	if (owner == NULL) {
		return false;
	}
	if (owner->thread == std::this_thread::get_id()) {
		if (!owner->alive || (php && EG(exception))) {
			return false;
		}
		return run();
	}
	auto request = std::make_shared<soloud_request>();
	request->run = std::move(run);
	request->php = php;
	std::unique_lock<std::mutex> lock(owner->lock);
	if (!owner->alive) {
		return false;
	}
	owner->queue.push_back(request);
	owner->pending = true;
	zend_atomic_bool_store(owner->interrupt, true);
	owner->cond.notify_all();
	auto done = [&] { return request->state == SOLOUD_DONE || !owner->alive; };
	if (seconds < 0) {
		owner->cond.wait(lock, done);
	} else {
		owner->cond.wait_for(lock, std::chrono::duration<double>(seconds), done);
	}
	if (request->state != SOLOUD_DONE) {
		/* Withdrawn: a posted request is skipped, a started one finishes on its copies and is dropped. */
		request->state = SOLOUD_DONE;
		return false;
	}
	return request->ok;
}

/* Posts run to owner without waiting (releases). */
void soloud_post(const std::shared_ptr<soloud_owner> &owner, std::function<bool()> run)
{
	auto request = std::make_shared<soloud_request>();
	request->run = std::move(run);
	request->php = false;
	std::lock_guard<std::mutex> lock(owner->lock);
	if (!owner->alive) {
		return;
	}
	owner->queue.push_back(request);
	owner->pending = true;
	zend_atomic_bool_store(owner->interrupt, true);
	owner->cond.notify_all();
}

void soloud_serve_owner(soloud_owner *owner)
{
	if (owner->serving) {
		return;
	}
	owner->serving = true;
	std::unique_lock<std::mutex> lock(owner->lock);
	while (!owner->queue.empty()) {
		auto request = owner->queue.front();
		owner->queue.pop_front();
		if (request->state != SOLOUD_POSTED) {
			continue;
		}
		request->state = SOLOUD_STARTED;
		lock.unlock();
		bool ok = !(request->php && EG(exception)) && request->run();
		lock.lock();
		if (request->state == SOLOUD_STARTED) {
			request->state = SOLOUD_DONE;
			request->ok = ok;
		}
		owner->cond.notify_all();
	}
	owner->pending = false;
	owner->serving = false;
}

void soloud_interrupt(zend_execute_data *execute_data)
{
	if (soloud_prev_interrupt != NULL) {
		soloud_prev_interrupt(execute_data);
	}
	soloud_serve();
}

/* ---- calling PHP (owner thread) ---- */

/* $object->name(...args); false when it threw. ret is set on success, and the caller releases it. */
bool soloud_call(zend_object *object, const char *name, zval *ret, uint32_t argc, zval *argv)
{
	zend_string *method = zend_string_init(name, strlen(name), 0);
	ZVAL_UNDEF(ret);
	zend_result called = zend_call_method_if_exists(object, method, ret, argc, argv);
	zend_string_release(method);
	if (called == FAILURE || EG(exception)) {
		zval_ptr_dtor(ret);
		ZVAL_UNDEF(ret);
		return false;
	}
	return true;
}

/* A by-reference string argument holding count floats from data. */
void soloud_ref_floats(zval *arg, const float *data, size_t count)
{
	zval str;
	ZVAL_STR(&str, zend_string_init(reinterpret_cast<const char *>(data), count * sizeof(float), 0));
	ZVAL_NEW_REF(arg, &str);
}

/* Copies the by-reference string back: at most count floats; the rest of data is kept. */
void soloud_unref_floats(zval *arg, float *data, size_t count)
{
	zval *out = Z_REFVAL_P(arg);
	if (Z_TYPE_P(out) == IS_STRING) {
		memcpy(data, Z_STRVAL_P(out), std::min(count * sizeof(float), Z_STRLEN_P(out) & ~(sizeof(float) - 1)));
	}
}

/* Channel i of a SoLoud buffer starts at i * aBufferSize and spans aSamples. */
size_t soloud_strides(unsigned int aChannels, unsigned int aSamples, unsigned int aBufferSize)
{
	return (size_t) (std::max(aChannels, 1u) - 1) * aBufferSize + std::max(aSamples, aBufferSize);
}

/* Bits: which virtuals a PHP class overrides (a user function in its function table). */
uint32_t soloud_overrides(zend_class_entry *ce, std::initializer_list<const char *> names)
{
	uint32_t bits = 0, bit = 1;
	for (const char *name : names) {
		zend_function *fn = (zend_function *) zend_hash_str_find_ptr_lc(&ce->function_table, name, strlen(name));
		if (fn != NULL && fn->type == ZEND_USER_FUNCTION) {
			bits |= bit;
		}
		bit <<= 1;
	}
	return bits;
}

/* What every trampoline carries. */
struct soloud_tramp {
	std::shared_ptr<soloud_link> link;

	bool has(uint32_t bit) const
	{
		return link != NULL && (link->overrides & bit) != 0 && !link->gone;
	}

	/* Runs php(object) on the owner: within seconds (< 0: no deadline). */
	bool call(double seconds, std::function<bool(zend_object *)> php) const
	{
		std::shared_ptr<soloud_link> l = link;
		return soloud_run(l->owner, seconds, true, [l, php] {
			return !l->gone && l->object != NULL && php(l->object);
		});
	}

	/* SoLoud deleted this native (any thread): the owner clears the PHP object's native, drops the held ref. */
	void release(void *native)
	{
		if (link == NULL) {
			return;
		}
		link->gone = true;
		std::shared_ptr<soloud_link> l = link;
		soloud_post(l->owner, [l, native] {
			zend_object *object = l->object;
			if (object == NULL) {
				return true;
			}
			soloud_object *obj = soloud_from(object);
			if (obj->native == native) {
				zend_ulong key = (zend_ulong) (uintptr_t) native;
				if (zend_hash_index_find_ptr(&SOLOUD_G(boxes), key) == object) {
					zend_hash_index_del(&SOLOUD_G(boxes), key);
				}
				obj->native = NULL;
			}
			if (l->held) {
				l->held = false;
				OBJ_RELEASE(object);
			}
			return true;
		});
	}
};

const double soloud_short_wait = 0.1;   /* calls with no buffer to time them by */

double soloud_buffer_seconds(unsigned int aSamples, float aSamplerate)
{
	return aSamples / (aSamplerate > 0 ? (double) aSamplerate : 44100.0);
}

/* ---- AudioSourceInstance ---- */

enum { ASI_GETAUDIO = 1, ASI_HASENDED = 2, ASI_SEEK = 4, ASI_REWIND = 8, ASI_GETINFO = 16 };

struct PhpAudioSourceInstance : SoLoud::AudioSourceInstance {
	soloud_tramp t;

	~PhpAudioSourceInstance() override
	{
		t.release(this);
	}

	unsigned int getAudio(float *aBuffer, unsigned int aSamplesToRead, unsigned int aBufferSize) override
	{
		size_t count = soloud_strides(mChannels, aSamplesToRead, aBufferSize);
		auto buffer = std::make_shared<std::vector<float>>(count, 0.0f);
		auto produced = std::make_shared<zend_long>(0);
		bool ok = t.has(ASI_GETAUDIO) && t.call(soloud_buffer_seconds(aSamplesToRead, mSamplerate), [=](zend_object *object) {
			zval args[3], ret;
			soloud_ref_floats(&args[0], buffer->data(), count);
			ZVAL_LONG(&args[1], aSamplesToRead);
			ZVAL_LONG(&args[2], aBufferSize);
			bool called = soloud_call(object, "getAudio", &ret, 3, args);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_INT, "getAudio", NULL, NULL)) {
				soloud_unref_floats(&args[0], buffer->data(), count);
				*produced = zval_get_long(&ret);
			}
			zval_ptr_dtor(&ret);
			zval_ptr_dtor(&args[0]);
			return called && !EG(exception);
		});
		memcpy(aBuffer, buffer->data(), count * sizeof(float));
		return ok ? (unsigned int) std::clamp<zend_long>(*produced, 0, aSamplesToRead) : 0;
	}

	bool hasEnded() override
	{
		/* Ended when the PHP side is gone or has no hasEnded(). A call that is skipped (an exception is
		 * pending) or late keeps the voice, which plays silence meanwhile. */
		if (!t.has(ASI_HASENDED)) {
			return true;
		}
		auto ended = std::make_shared<bool>(false);
		t.call(soloud_short_wait, [=](zend_object *object) {
			zval ret;
			bool called = soloud_call(object, "hasEnded", &ret, 0, NULL);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_BOOL, "hasEnded", NULL, NULL)) {
				*ended = zend_is_true(&ret);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		return *ended;
	}

	SoLoud::result seek(SoLoud::time aSeconds, float *mScratch, unsigned int mScratchSize) override
	{
		if (!t.has(ASI_SEEK)) {
			return SoLoud::AudioSourceInstance::seek(aSeconds, mScratch, mScratchSize);
		}
		auto scratch = std::make_shared<std::vector<float>>(mScratch, mScratch + mScratchSize);
		auto res = std::make_shared<zend_long>(SoLoud::NOT_IMPLEMENTED);
		bool ok = t.call(soloud_short_wait, [=](zend_object *object) {
			zval args[3], ret;
			ZVAL_DOUBLE(&args[0], aSeconds);
			soloud_ref_floats(&args[1], scratch->data(), scratch->size());
			ZVAL_LONG(&args[2], mScratchSize);
			bool called = soloud_call(object, "seek", &ret, 3, args);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_INT, "seek", NULL, NULL)) {
				soloud_unref_floats(&args[1], scratch->data(), scratch->size());
				*res = zval_get_long(&ret);
			}
			zval_ptr_dtor(&ret);
			zval_ptr_dtor(&args[1]);
			return called;
		});
		if (ok) {
			std::copy(scratch->begin(), scratch->end(), mScratch);
		}
		return ok ? (SoLoud::result) *res : SoLoud::NOT_IMPLEMENTED;
	}

	SoLoud::result rewind() override
	{
		if (!t.has(ASI_REWIND)) {
			return SoLoud::AudioSourceInstance::rewind();
		}
		auto res = std::make_shared<zend_long>(SoLoud::NOT_IMPLEMENTED);
		t.call(soloud_short_wait, [=](zend_object *object) {
			zval ret;
			bool called = soloud_call(object, "rewind", &ret, 0, NULL);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_INT, "rewind", NULL, NULL)) {
				*res = zval_get_long(&ret);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		return (SoLoud::result) *res;
	}

	float getInfo(unsigned int aInfoKey) override
	{
		if (!t.has(ASI_GETINFO)) {
			return SoLoud::AudioSourceInstance::getInfo(aInfoKey);
		}
		auto info = std::make_shared<double>(0);
		t.call(soloud_short_wait, [=](zend_object *object) {
			zval arg, ret;
			ZVAL_LONG(&arg, aInfoKey);
			bool called = soloud_call(object, "getInfo", &ret, 1, &arg);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_FLOAT, "getInfo", NULL, NULL)) {
				*info = zval_get_double(&ret);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		return (float) *info;
	}
};

/* createInstance()'s result: a PHP-subclass object of base that nothing owns yet. SoLoud takes it: the PHP
 * object no longer deletes the native, and the trampoline holds the object until SoLoud deletes it. */
void *soloud_take_instance(zval *ret, const char *method, const soloud_class *base)
{
	void *native = NULL;
	if (!soloud_callback_result(ret, SOLOUD_RET_INSTANCE, method, base, &native)) {
		return NULL;
	}
	soloud_object *obj = soloud_from(Z_OBJ_P(ret));
	obj->owned = false;
	(*static_cast<std::shared_ptr<soloud_link> *>(obj->link))->held = true;
	GC_ADDREF(Z_OBJ_P(ret));
	return native;
}

/* ---- AudioSource ---- */

struct PhpAudioSource : SoLoud::AudioSource {
	soloud_tramp t;

	SoLoud::AudioSourceInstance *createInstance() override
	{
		auto taken = std::make_shared<void *>(nullptr);
		t.call(soloud_short_wait, [=](zend_object *object) {
			zval ret;
			bool called = soloud_call(object, "createInstance", &ret, 0, NULL);
			if (called) {
				*taken = soloud_take_instance(&ret, "createInstance", &soloud_class_SoLoud_AudioSourceInstance);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		/* play() does not check for NULL: an inert instance plays silence and ends. */
		return *taken != NULL ? static_cast<SoLoud::AudioSourceInstance *>(*taken) : new PhpAudioSourceInstance();
	}
};

/* ---- FilterInstance, FFTFilterInstance ---- */

enum { FI_FILTER = 1, FI_FILTERCHANNEL = 2, FI_FFTFILTERCHANNEL = 4 };

/* filter() / filterChannel() / fftFilterChannel() through PHP, on a copy of count floats. */
bool soloud_filter_call(const soloud_tramp &t, const char *method, float *aBuffer, size_t count, double seconds,
	std::function<void(zval *)> fill, uint32_t argc)
{
	auto buffer = std::make_shared<std::vector<float>>(aBuffer, aBuffer + count);
	std::string name = method;
	bool ok = t.call(seconds, [=](zend_object *object) {
		zval args[6], ret;
		soloud_ref_floats(&args[0], buffer->data(), count);
		fill(args);
		bool called = soloud_call(object, name.c_str(), &ret, argc, args);
		if (called) {
			soloud_unref_floats(&args[0], buffer->data(), count);
		}
		zval_ptr_dtor(&ret);
		zval_ptr_dtor(&args[0]);
		return called;
	});
	if (ok) {
		std::copy(buffer->begin(), buffer->end(), aBuffer);
	}
	return ok;
}

template <class Base>
struct PhpFilterInstanceOf : Base {
	soloud_tramp t;

	using Base::Base;

	~PhpFilterInstanceOf() override
	{
		t.release(this);
	}

	void filter(float *aBuffer, unsigned int aSamples, unsigned int aBufferSize, unsigned int aChannels, float aSamplerate, SoLoud::time aTime) override
	{
		if (!t.has(FI_FILTER)) {
			Base::filter(aBuffer, aSamples, aBufferSize, aChannels, aSamplerate, aTime);
			return;
		}
		soloud_filter_call(t, "filter", aBuffer, soloud_strides(aChannels, aSamples, aBufferSize), soloud_buffer_seconds(aSamples, aSamplerate),
			[=](zval *args) {
				ZVAL_LONG(&args[1], aSamples);
				ZVAL_LONG(&args[2], aBufferSize);
				ZVAL_LONG(&args[3], aChannels);
				ZVAL_DOUBLE(&args[4], aSamplerate);
				ZVAL_DOUBLE(&args[5], aTime);
			}, 6);
	}

	void filterChannel(float *aBuffer, unsigned int aSamples, float aSamplerate, SoLoud::time aTime, unsigned int aChannel, unsigned int aChannels) override
	{
		if (!t.has(FI_FILTERCHANNEL)) {
			Base::filterChannel(aBuffer, aSamples, aSamplerate, aTime, aChannel, aChannels);
			return;
		}
		soloud_filter_call(t, "filterChannel", aBuffer, aSamples, soloud_buffer_seconds(aSamples, aSamplerate),
			[=](zval *args) {
				ZVAL_LONG(&args[1], aSamples);
				ZVAL_DOUBLE(&args[2], aSamplerate);
				ZVAL_DOUBLE(&args[3], aTime);
				ZVAL_LONG(&args[4], aChannel);
				ZVAL_LONG(&args[5], aChannels);
			}, 6);
	}
};

typedef PhpFilterInstanceOf<SoLoud::FilterInstance> PhpFilterInstance;

struct PhpFFTFilterInstance : PhpFilterInstanceOf<SoLoud::FFTFilterInstance> {
	using PhpFilterInstanceOf<SoLoud::FFTFilterInstance>::PhpFilterInstanceOf;

	void fftFilterChannel(float *aFFTBuffer, unsigned int aSamples, float aSamplerate, SoLoud::time aTime, unsigned int aChannel, unsigned int aChannels) override
	{
		if (!t.has(FI_FFTFILTERCHANNEL)) {
			SoLoud::FFTFilterInstance::fftFilterChannel(aFFTBuffer, aSamples, aSamplerate, aTime, aChannel, aChannels);
			return;
		}
		soloud_filter_call(t, "fftFilterChannel", aFFTBuffer, (size_t) aSamples * 2, soloud_buffer_seconds(aSamples, aSamplerate),
			[=](zval *args) {
				ZVAL_LONG(&args[1], aSamples);
				ZVAL_DOUBLE(&args[2], aSamplerate);
				ZVAL_DOUBLE(&args[3], aTime);
				ZVAL_LONG(&args[4], aChannel);
				ZVAL_LONG(&args[5], aChannels);
			}, 6);
	}
};

/* ---- Filter ---- */

enum { F_CREATEINSTANCE = 1, F_GETPARAMCOUNT = 2, F_GETPARAMNAME = 4, F_GETPARAMTYPE = 8, F_GETPARAMMAX = 16, F_GETPARAMMIN = 32 };

struct PhpFilter : SoLoud::Filter {
	soloud_tramp t;
	std::string name;   /* getParamName()'s storage */

	SoLoud::FilterInstance *createInstance() override
	{
		auto taken = std::make_shared<void *>(nullptr);
		t.call(soloud_short_wait, [=](zend_object *object) {
			zval ret;
			bool called = soloud_call(object, "createInstance", &ret, 0, NULL);
			if (called) {
				*taken = soloud_take_instance(&ret, "createInstance", &soloud_class_SoLoud_FilterInstance);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		/* A plain FilterInstance leaves the buffer as it is. */
		return *taken != NULL ? static_cast<SoLoud::FilterInstance *>(*taken) : new SoLoud::FilterInstance();
	}

	/* A numeric getParam*() through PHP: def when not overridden or not answered. */
	double number(uint32_t bit, const char *method, int expected, zval *arg, double def)
	{
		auto value = std::make_shared<double>(def);
		zval a;
		bool hasArg = arg != NULL;
		if (hasArg) {
			ZVAL_COPY_VALUE(&a, arg);
		}
		std::string m = method;
		t.has(bit) && t.call(soloud_short_wait, [=](zend_object *object) {
			zval ret, in = a;
			bool called = soloud_call(object, m.c_str(), &ret, hasArg ? 1 : 0, hasArg ? &in : NULL);
			if (called && soloud_callback_result(&ret, expected, m.c_str(), NULL, NULL)) {
				*value = zval_get_double(&ret);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		return *value;
	}

	int getParamCount() override
	{
		return (int) number(F_GETPARAMCOUNT, "getParamCount", SOLOUD_RET_INT, NULL, SoLoud::Filter::getParamCount());
	}

	const char *getParamName(unsigned int aParamIndex) override
	{
		if (!t.has(F_GETPARAMNAME)) {
			return SoLoud::Filter::getParamName(aParamIndex);
		}
		auto out = std::make_shared<std::string>();
		auto got = std::make_shared<bool>(false);
		t.call(soloud_short_wait, [=](zend_object *object) {
			zval arg, ret;
			ZVAL_LONG(&arg, aParamIndex);
			bool called = soloud_call(object, "getParamName", &ret, 1, &arg);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_STRING, "getParamName", NULL, NULL)) {
				out->assign(Z_STRVAL(ret), Z_STRLEN(ret));
				*got = true;
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		if (!*got) {
			return SoLoud::Filter::getParamName(aParamIndex);
		}
		name = *out;
		return name.c_str();
	}

	unsigned int getParamType(unsigned int aParamIndex) override
	{
		zval arg;
		ZVAL_LONG(&arg, aParamIndex);
		return (unsigned int) number(F_GETPARAMTYPE, "getParamType", SOLOUD_RET_INT, &arg, SoLoud::Filter::getParamType(aParamIndex));
	}

	float getParamMax(unsigned int aParamIndex) override
	{
		zval arg;
		ZVAL_LONG(&arg, aParamIndex);
		return (float) number(F_GETPARAMMAX, "getParamMax", SOLOUD_RET_FLOAT, &arg, SoLoud::Filter::getParamMax(aParamIndex));
	}

	float getParamMin(unsigned int aParamIndex) override
	{
		zval arg;
		ZVAL_LONG(&arg, aParamIndex);
		return (float) number(F_GETPARAMMIN, "getParamMin", SOLOUD_RET_FLOAT, &arg, SoLoud::Filter::getParamMin(aParamIndex));
	}
};

/* ---- AudioCollider, AudioAttenuator ---- */

struct PhpAudioCollider : SoLoud::AudioCollider {
	soloud_tramp t;

	float collide(SoLoud::Soloud *aSoloud, SoLoud::AudioSourceInstance3dData *aAudioInstance3dData, int aUserData) override
	{
		/* The 3d data lives in the engine: PHP gets its own copy. */
		auto data = std::make_shared<SoLoud::AudioSourceInstance3dData>(*aAudioInstance3dData);
		auto value = std::make_shared<double>(0);
		t.has(1) && t.call(soloud_short_wait, [=](zend_object *object) {
			zval args[3], ret;
			zend_object *engine = (zend_object *) zend_hash_index_find_ptr(&SOLOUD_G(boxes), (zend_ulong) (uintptr_t) aSoloud);
			if (engine != NULL) {
				ZVAL_OBJ_COPY(&args[0], engine);
			} else {
				ZVAL_NULL(&args[0]);
			}
			soloud_wrap_owned(new SoLoud::AudioSourceInstance3dData(*data), &soloud_class_SoLoud_AudioSourceInstance3dData, &args[1]);
			ZVAL_LONG(&args[2], aUserData);
			bool called = soloud_call(object, "collide", &ret, 3, args);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_FLOAT, "collide", NULL, NULL)) {
				*value = zval_get_double(&ret);
			}
			zval_ptr_dtor(&ret);
			zval_ptr_dtor(&args[0]);
			zval_ptr_dtor(&args[1]);
			return called;
		});
		return (float) *value;
	}
};

struct PhpAudioAttenuator : SoLoud::AudioAttenuator {
	soloud_tramp t;

	float attenuate(float aDistance, float aMinDistance, float aMaxDistance, float aRolloffFactor) override
	{
		auto value = std::make_shared<double>(1);
		t.has(1) && t.call(soloud_short_wait, [=](zend_object *object) {
			zval args[4], ret;
			ZVAL_DOUBLE(&args[0], aDistance);
			ZVAL_DOUBLE(&args[1], aMinDistance);
			ZVAL_DOUBLE(&args[2], aMaxDistance);
			ZVAL_DOUBLE(&args[3], aRolloffFactor);
			bool called = soloud_call(object, "attenuate", &ret, 4, args);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_FLOAT, "attenuate", NULL, NULL)) {
				*value = zval_get_double(&ret);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		return (float) *value;
	}
};

/* ---- File ---- */

enum { FILE_EOF = 1, FILE_READ = 2, FILE_LENGTH = 4, FILE_SEEK = 8, FILE_POS = 16 };

struct PhpFile : SoLoud::File {
	soloud_tramp t;

	zend_long integer(uint32_t bit, const char *method, zval *arg, zend_long def)
	{
		auto value = std::make_shared<zend_long>(def);
		zval a;
		bool hasArg = arg != NULL;
		if (hasArg) {
			ZVAL_COPY_VALUE(&a, arg);
		}
		std::string m = method;
		t.has(bit) && t.call(soloud_short_wait, [=](zend_object *object) {
			zval ret, in = a;
			bool called = soloud_call(object, m.c_str(), &ret, hasArg ? 1 : 0, hasArg ? &in : NULL);
			if (called && Z_TYPE(ret) != IS_NULL && soloud_callback_result(&ret, SOLOUD_RET_INT, m.c_str(), NULL, NULL)) {
				*value = zval_get_long(&ret);
			}
			zval_ptr_dtor(&ret);
			return called;
		});
		return *value;
	}

	int eof() override
	{
		return (int) integer(FILE_EOF, "eof", NULL, 1);
	}

	unsigned int read(unsigned char *aDst, unsigned int aBytes) override
	{
		auto bytes = std::make_shared<std::string>();
		auto got = std::make_shared<zend_long>(0);
		bool ok = t.has(FILE_READ) && t.call(soloud_short_wait, [=](zend_object *object) {
			zval args[2], str, ret;
			ZVAL_EMPTY_STRING(&str);
			ZVAL_NEW_REF(&args[0], &str);
			ZVAL_LONG(&args[1], aBytes);
			bool called = soloud_call(object, "read", &ret, 2, args);
			zval *out = Z_REFVAL(args[0]);
			if (called && soloud_callback_result(&ret, SOLOUD_RET_INT, "read", NULL, NULL) && Z_TYPE_P(out) == IS_STRING) {
				bytes->assign(Z_STRVAL_P(out), std::min<size_t>(Z_STRLEN_P(out), aBytes));
				*got = zval_get_long(&ret);
			}
			zval_ptr_dtor(&ret);
			zval_ptr_dtor(&args[0]);
			return called;
		});
		if (!ok) {
			return 0;
		}
		size_t n = std::min<size_t>(bytes->size(), (size_t) std::clamp<zend_long>(*got, 0, aBytes));
		memcpy(aDst, bytes->data(), n);
		return (unsigned int) n;
	}

	unsigned int length() override
	{
		return (unsigned int) integer(FILE_LENGTH, "length", NULL, 0);
	}

	void seek(int aOffset) override
	{
		zval arg;
		ZVAL_LONG(&arg, aOffset);
		integer(FILE_SEEK, "seek", &arg, 0);
	}

	unsigned int pos() override
	{
		return (unsigned int) integer(FILE_POS, "pos", NULL, 0);
	}
};

/* ---- Thread::PoolTask ---- */

struct PhpPoolTask : SoLoud::Thread::PoolTask {
	soloud_tramp t;

	void work() override
	{
		/* A pool worker holds no SoLoud lock: it waits until the owner has run the task. */
		t.has(1) && t.call(-1, [](zend_object *object) {
			zval ret;
			bool called = soloud_call(object, "work", &ret, 0, NULL);
			zval_ptr_dtor(&ret);
			return called;
		});
	}
};

/* ---- the factory table ---- */

struct soloud_factory {
	const soloud_class *cls;
	void *(*make)(zend_class_entry *ce, std::shared_ptr<soloud_link> link);
	void (*destroy)(void *native);   /* as the trampoline type: AudioCollider, AudioAttenuator and PoolTask
	                                    have no virtual destructor */
};

template <class T, class Base>
void soloud_unmake(void *native)
{
	delete static_cast<T *>(static_cast<Base *>(native));
}

template <class T>
void *soloud_make(std::shared_ptr<soloud_link> link, uint32_t overrides)
{
	T *native = new T();
	link->overrides = overrides;
	native->t.link = link;
	return native;
}

const soloud_factory soloud_factories[] = {
	{&soloud_class_SoLoud_AudioSource, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpAudioSource>(l, soloud_overrides(ce, {"createInstance"}));
	}, soloud_unmake<PhpAudioSource, SoLoud::AudioSource>},
	{&soloud_class_SoLoud_AudioSourceInstance, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpAudioSourceInstance>(l, soloud_overrides(ce, {"getAudio", "hasEnded", "seek", "rewind", "getInfo"}));
	}, soloud_unmake<PhpAudioSourceInstance, SoLoud::AudioSourceInstance>},
	{&soloud_class_SoLoud_Filter, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpFilter>(l, soloud_overrides(ce, {"createInstance", "getParamCount", "getParamName", "getParamType", "getParamMax", "getParamMin"}));
	}, soloud_unmake<PhpFilter, SoLoud::Filter>},
	{&soloud_class_SoLoud_FilterInstance, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpFilterInstance>(l, soloud_overrides(ce, {"filter", "filterChannel"}));
	}, soloud_unmake<PhpFilterInstance, SoLoud::FilterInstance>},
	{&soloud_class_SoLoud_FFTFilterInstance, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpFFTFilterInstance>(l, soloud_overrides(ce, {"filter", "filterChannel", "fftFilterChannel"}));
	}, soloud_unmake<PhpFFTFilterInstance, SoLoud::FFTFilterInstance>},
	{&soloud_class_SoLoud_AudioCollider, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpAudioCollider>(l, soloud_overrides(ce, {"collide"}));
	}, soloud_unmake<PhpAudioCollider, SoLoud::AudioCollider>},
	{&soloud_class_SoLoud_AudioAttenuator, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpAudioAttenuator>(l, soloud_overrides(ce, {"attenuate"}));
	}, soloud_unmake<PhpAudioAttenuator, SoLoud::AudioAttenuator>},
	{&soloud_class_SoLoud_File, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpFile>(l, soloud_overrides(ce, {"eof", "read", "length", "seek", "pos"}));
	}, soloud_unmake<PhpFile, SoLoud::File>},
	{&soloud_class_SoLoud_Thread_PoolTask, [](zend_class_entry *ce, std::shared_ptr<soloud_link> l) {
		return soloud_make<PhpPoolTask>(l, soloud_overrides(ce, {"work"}));
	}, soloud_unmake<PhpPoolTask, SoLoud::Thread::PoolTask>},
};

const soloud_factory *soloud_factory_of(const soloud_class *cls)
{
	for (const soloud_factory &f : soloud_factories) {
		if (f.cls == cls) {
			return &f;
		}
	}
	return NULL;
}

std::shared_ptr<soloud_link> soloud_new_link(soloud_object *obj)
{
	auto link = std::make_shared<soloud_link>();
	link->owner = soloud_current;
	link->object = &obj->std;
	obj->link = new std::shared_ptr<soloud_link>(link);
	return link;
}

/* A trampoline built through a constructor: its link and overrides. */
template <class T, class... A>
void *soloud_construct(soloud_object *obj, std::initializer_list<const char *> names, A... args)
{
	T *native = new T(args...);
	auto link = soloud_new_link(obj);
	link->overrides = soloud_overrides(obj->std.ce, names);
	native->t.link = link;
	return native;
}

/* ---- Thread::createThread ---- */

/* One thread function: its PHP callable and parameter (owner thread refcounts), and its owner. */
struct soloud_thread_job {
	std::shared_ptr<soloud_owner> owner;
	zval callable;
	zval parameter;
};

void soloud_thread_main(void *param)
{
	soloud_thread_job *job = static_cast<soloud_thread_job *>(param);
	std::shared_ptr<soloud_owner> owner = job->owner;
	soloud_run(owner, -1, true, [job] {
		zval ret;
		ZVAL_UNDEF(&ret);
		call_user_function(NULL, NULL, &job->callable, &ret, 1, &job->parameter);
		zval_ptr_dtor(&ret);
		return !EG(exception);
	});
	/* The zvals are the owner's to release; with the owner's request over, the store has freed them. */
	soloud_post(owner, [job] {
		zval_ptr_dtor(&job->callable);
		zval_ptr_dtor(&job->parameter);
		delete job;
		return true;
	});
}

} // namespace

/* ---- callbacks.h ---- */

bool soloud_trampolined(const soloud_class *cls)
{
	return soloud_factory_of(cls) != NULL;
}

void *soloud_trampoline(soloud_object *obj)
{
	if (obj->native != NULL) {
		return obj->native;
	}
	if (!obj->php || obj->link != NULL || soloud_current == NULL) {
		return NULL;
	}
	const soloud_factory *f = soloud_factory_of(obj->cls);
	if (f == NULL) {
		return NULL;
	}
	void *native = f->make(obj->std.ce, soloud_new_link(obj));
	soloud_adopt(obj, native, true);
	return native;
}

void *soloud_trampoline_filterinstance(soloud_object *obj)
{
	return soloud_construct<PhpFilterInstance>(obj, {"filter", "filterChannel"});
}

void *soloud_trampoline_fftfilterinstance(soloud_object *obj, SoLoud::FFTFilter *aParent)
{
	if (aParent == NULL) {
		return soloud_construct<PhpFFTFilterInstance>(obj, {"filter", "filterChannel", "fftFilterChannel"});
	}
	return soloud_construct<PhpFFTFilterInstance>(obj, {"filter", "filterChannel", "fftFilterChannel"}, aParent);
}

void soloud_trampoline_free(soloud_object *obj)
{
	if (obj->link == NULL) {
		return;
	}
	auto *link = static_cast<std::shared_ptr<soloud_link> *>(obj->link);
	(*link)->gone = true;
	(*link)->object = NULL;
	delete link;
	obj->link = NULL;
}

void soloud_trampoline_delete(soloud_object *obj, void *native)
{
	const soloud_factory *f = soloud_factory_of(obj->cls);
	if (f != NULL) {
		f->destroy(native);
	}
}

bool soloud_callback_result(zval *ret, int expected, const char *method, const soloud_class *base, void **native)
{
	switch (expected) {
		case SOLOUD_RET_INT:
			if (Z_TYPE_P(ret) == IS_LONG) {
				return true;
			}
			zend_type_error("%s() must return int, %s returned", method, zend_zval_value_name(ret));
			return false;
		case SOLOUD_RET_FLOAT:
			if (Z_TYPE_P(ret) == IS_DOUBLE || Z_TYPE_P(ret) == IS_LONG) {
				return true;
			}
			zend_type_error("%s() must return float, %s returned", method, zend_zval_value_name(ret));
			return false;
		case SOLOUD_RET_BOOL:
			if (Z_TYPE_P(ret) == IS_TRUE || Z_TYPE_P(ret) == IS_FALSE) {
				return true;
			}
			zend_type_error("%s() must return bool, %s returned", method, zend_zval_value_name(ret));
			return false;
		case SOLOUD_RET_STRING:
			if (Z_TYPE_P(ret) == IS_STRING) {
				return true;
			}
			zend_type_error("%s() must return string, %s returned", method, zend_zval_value_name(ret));
			return false;
		case SOLOUD_RET_INSTANCE: {
			/* SoLoud deletes what createInstance() gives it: only a trampoline nothing else owns can go. */
			soloud_object *obj = Z_TYPE_P(ret) == IS_OBJECT && soloud_handles(Z_OBJ_P(ret)) ? soloud_from(Z_OBJ_P(ret)) : NULL;
			void *taken = obj != NULL && obj->php && soloud_is_a(obj->cls, base) ? soloud_trampoline(obj) : NULL;
			if (taken == NULL || !obj->owned) {
				zend_type_error("%s() must return a new instance of a PHP class extending %s, which SoLoud then owns", method, base->name);
				return false;
			}
			*native = taken;
			return true;
		}
	}
	return false;
}

void soloud_serve(void)
{
	if (soloud_current != NULL && soloud_current->pending) {
		soloud_serve_owner(soloud_current.get());
	}
}

void soloud_serve_until(const std::function<void()> &blocking)
{
	std::shared_ptr<soloud_owner> owner = soloud_current;
	if (owner == NULL) {
		blocking();
		return;
	}
	bool done = false;
	std::thread helper([&] {
		blocking();
		std::lock_guard<std::mutex> lock(owner->lock);
		done = true;
		owner->cond.notify_all();
	});
	for (;;) {
		soloud_serve_owner(owner.get());
		std::unique_lock<std::mutex> lock(owner->lock);
		if (done) {
			break;
		}
		owner->cond.wait(lock, [&] { return done || !owner->queue.empty(); });
	}
	helper.join();
	soloud_serve_owner(owner.get());
}

SoLoud::Thread::ThreadHandle soloud_create_thread(zval *aCallable, zval *aParameter)
{
	soloud_thread_job *job = new soloud_thread_job();
	job->owner = soloud_current;
	ZVAL_COPY(&job->callable, aCallable);
	ZVAL_COPY(&job->parameter, aParameter);
	return SoLoud::Thread::createThread(soloud_thread_main, job);
}

void soloud_callbacks_minit(void)
{
	soloud_prev_interrupt = zend_interrupt_function;
	zend_interrupt_function = soloud_interrupt;
}

void soloud_callbacks_rinit(void)
{
	auto owner = std::make_shared<soloud_owner>();
	owner->thread = std::this_thread::get_id();
	owner->interrupt = &EG(vm_interrupt);
	soloud_current = owner;
}

/* Request end: queued calls run as no-ops, releases still run (the objects are alive until the store is
 * freed), and every waiting thread wakes. Later calls on this owner are no-ops. */
void soloud_callbacks_rshutdown(void)
{
	std::shared_ptr<soloud_owner> owner = soloud_current;
	if (owner == NULL) {
		return;
	}
	std::deque<std::shared_ptr<soloud_request>> left;
	{
		std::lock_guard<std::mutex> lock(owner->lock);
		owner->alive = false;
		left.swap(owner->queue);
		owner->cond.notify_all();
	}
	for (auto &request : left) {
		if (!request->php && request->state == SOLOUD_POSTED) {
			request->run();
		}
	}
	soloud_current.reset();
}
