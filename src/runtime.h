/*
 * What every binding file shares: the PHP object that holds a SoLoud object, the identity map, the
 * references that keep SoLoud's raw pointers valid, argument marshalling and the kept-refusal switch.
 */

#ifndef SOLOUD_RUNTIME_H
#define SOLOUD_RUNTIME_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>

#include "php.h"
#include "ext/standard/info.h"
#include "zend_exceptions.h"
#include "php_soloud.h"

#include "soloud.h"
#include "soloud_file.h"

extern zend_class_entry *soloud_ce_exception;

/* A kept refusal reads if (!SOLOUD_PROBE_OFF("<id>") && (<check>)). Only a probe build can turn one off. */
#ifdef SOLOUD_PROBES
# define SOLOUD_PROBE_OFF(id) (getenv("SOLOUD_PROBE_OFF") != NULL && strcmp(getenv("SOLOUD_PROBE_OFF"), (id)) == 0)
#else
# define SOLOUD_PROBE_OFF(id) false
#endif

struct soloud_object;

/* One bound SoLoud class. Every class SoLoud derives from has a single public base at offset 0. */
struct soloud_class {
	const char *name;                         /* "SoLoud::Wav" */
	zend_class_entry **ce;
	const soloud_class *base;
	void (*destroy)(void *native);            /* delete as the exact type; NULL when PHP cannot construct it */
	/* Public fields: read into rv / write from value. false when the class has no field of that name. */
	bool (*read)(soloud_object *obj, zend_string *name, zval *rv);
	bool (*write)(soloud_object *obj, zend_string *name, zval *value);
};

struct soloud_object {
	void *native;                             /* NULL until __construct, and after a borrowed object is gone */
	const soloud_class *cls;
	bool owned;                               /* PHP constructed it: deleted with the PHP object */
	bool php;                                 /* a PHP subclass of a trampolined class: native is its trampoline */
	void *link;                               /* php: the trampoline's link (callbacks.cpp), NULL before it is built */
	unsigned int channels;                    /* filter instances: aChannels of the first PHP-made filter call, 0 before */
	unsigned int slots[FILTERS_PER_STREAM];   /* engines: channels each global filter instance's state is sized for, 0 until known */
	HashTable *held;                          /* role => the PHP value this object's native pointers need alive */
	zend_object std;
};

static inline soloud_object *soloud_from(zend_object *obj)
{
	return (soloud_object *) ((char *) obj - XtOffsetOf(soloud_object, std));
}

ZEND_BEGIN_MODULE_GLOBALS(soloud)
	HashTable boxes;                          /* native address => zend_object*, not refcounted */
	HashTable mutexes;                        /* Thread::createMutex() addresses not yet destroyed */
	HashTable threads;                        /* Thread::createThread() handles not yet released => joined (bool) */
ZEND_END_MODULE_GLOBALS(soloud)

ZEND_EXTERN_MODULE_GLOBALS(soloud)
#define SOLOUD_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(soloud, v)

extern zend_object_handlers soloud_handlers;

/* MINIT: give *info->ce SoLoud's object handlers. */
void soloud_register_class(const soloud_class *info);
bool soloud_is_a(const soloud_class *cls, const soloud_class *base);

/* The SoLoud object behind $this or an argument (a class *want is or derives from). Error when it was
 * never constructed; NULL then, and for a null argument. */
void *soloud_this(zval *self, const soloud_class *want);
void *soloud_arg(zend_object *obj, uint32_t argnum, const soloud_class *want);

/* __construct: false (Error thrown) when the object is already constructed. */
bool soloud_fresh(soloud_object *obj);
/* Give a PHP object its native object and register it in the identity map. */
void soloud_adopt(soloud_object *obj, void *native, bool owned);
/* The PHP object for a native pointer: the existing one, or a borrowed wrapper that keeps owner (the object
 * the pointer lives in, or NULL) alive. A member at offset 0 shares its owner's address; it gets its own
 * wrapper, outside the identity map. NULL → null. */
void soloud_wrap(void *native, const soloud_class *cls, zend_object *owner, zval *rv);
/* A new PHP object that owns native (a copy made for PHP). */
void soloud_wrap_owned(void *native, const soloud_class *cls, zval *rv);
/* Whether object is one of this extension's. */
bool soloud_handles(zend_object *object);

/* ValueError unless value fits unsigned int. */
bool soloud_uint_arg(zend_long value, uint32_t argnum, unsigned int *out);
/* ValueError unless min <= value <= max. */
bool soloud_range_arg(zend_long value, zend_long min, zend_long max, uint32_t argnum);

/* A value written to a public field, converted into *out. TypeError for a wrong type, ValueError out of
 * [min, max] (SOLOUD_FIELD_INT), Error for a field that is read-only. */
enum soloud_field_kind { SOLOUD_FIELD_BOOL, SOLOUD_FIELD_FLOAT, SOLOUD_FIELD_INT, SOLOUD_FIELD_READONLY };
bool soloud_field_arg(zend_string *name, zval *value, soloud_field_kind kind, zend_long min, zend_long max, zval *out);

/* An in-out float buffer of exactly count floats: the by-reference string's bytes, then zeros. The caller
 * writes it back with ZEND_TRY_ASSIGN_REF_STR. */
zend_string *soloud_float_buffer(zval *ref, size_t count);

/* Keep value alive as long as obj, under role (replacing what that role held). */
void soloud_hold(soloud_object *obj, const char *role, zval *value);
void soloud_unhold(soloud_object *obj, const char *role);

/*
 * Filter state the mixer sizes by channel count. A LofiFilterInstance holds state for 2 channels; every other
 * instance sizes its state on its first mix, and a global filter's instance keeps that size across a re-init.
 * The fit checks: false, with why, when the mixer would run past that state.
 */
bool soloud_voice_filters_fit(SoLoud::AudioSource *aSound, char *why, size_t size);
bool soloud_global_filter_fits(SoLoud::Soloud *self, unsigned int aFilterId, SoLoud::Filter *aFilter, char *why, size_t size);
bool soloud_init_filters_fit(soloud_object *obj, SoLoud::Soloud *self, unsigned int aChannels, char *why, size_t size);
/* Thread::Pool::addWork: a task to run (a pool without threads runs it at once, without a check). */
bool soloud_task_given(void *aTask, char *why, size_t size);
/* A File SoLoud can read: not NULL, a DiskFile after open(), a MemoryFile holding data. */
bool soloud_file_open(SoLoud::File *aFile, char *why, size_t size);
/* After setGlobalFilter / a successful init: record the channels each global filter instance is sized for. */
void soloud_global_filter_set(soloud_object *obj, SoLoud::Soloud *self, unsigned int aFilterId);
void soloud_init_filters_ran(soloud_object *obj, SoLoud::Soloud *self);

#endif
