/*
 * PHP subclasses of SoLoud's abstract classes, and the owner queue that runs their PHP from SoLoud's threads.
 *
 * A PHP class extending AudioSource, AudioSourceInstance, Filter, FilterInstance, FFTFilterInstance,
 * AudioCollider, AudioAttenuator, File or Thread::PoolTask gets a C++ trampoline as its native: a subclass of
 * the SoLoud class whose virtuals call the PHP methods. SoLoud's own threads (the mixer, pool workers, threads
 * from Thread::createThread) never enter PHP: the trampoline posts the call to the queue of the PHP thread that
 * made the object (its owner), raises the owner's EG(vm_interrupt) and waits. The owner runs it from
 * zend_interrupt_function, or from the next binding call. Calls on the owner thread run inline.
 *
 * A mixer call waits at most one buffer's duration for the PHP call to finish, then returns the SoLoud no-op
 * (silence, an unchanged buffer, 0): the mixer holds the engine's audio mutex, which a PHP callback may need.
 * PHP works on a copy of the buffer, so a late result is dropped. Thread functions and pool tasks hold no
 * SoLoud lock and wait until PHP has run them, or the owner's request ends.
 */

#ifndef SOLOUD_CALLBACKS_H
#define SOLOUD_CALLBACKS_H

#include "runtime.h"
#include "soloud_fftfilter.h"
#include "soloud_thread.h"

#include <functional>

/* Whether a PHP subclass of cls gets a trampoline. */
bool soloud_trampolined(const soloud_class *cls);

/* A PHP-subclass object's native: its trampoline, built (default-constructed) on first use. NULL when the
 * object is not a PHP subclass of a trampolined class, or is gone. */
void *soloud_trampoline(soloud_object *obj);

/* FilterInstance / FFTFilterInstance constructors called through parent::__construct() from a PHP subclass. */
void *soloud_trampoline_filterinstance(soloud_object *obj);
void *soloud_trampoline_fftfilterinstance(soloud_object *obj, SoLoud::FFTFilter *aParent);

/* The generated constructors: a trampoline for a PHP subclass, the SoLoud class otherwise. */
inline void *soloud_new_FilterInstance(soloud_object *obj)
{
	return obj->php ? soloud_trampoline_filterinstance(obj) : static_cast<void *>(new SoLoud::FilterInstance());
}

inline void *soloud_new_FFTFilterInstance(soloud_object *obj, SoLoud::FFTFilter *aParent)
{
	if (obj->php) {
		return soloud_trampoline_fftfilterinstance(obj, aParent);
	}
	return aParent != NULL ? new SoLoud::FFTFilterInstance(aParent) : new SoLoud::FFTFilterInstance();
}

/* Free handler for a trampolined object: the PHP side is gone, queued calls on it become no-ops. */
void soloud_trampoline_free(soloud_object *obj);
/* Deletes a trampoline PHP owns, as its own type. */
void soloud_trampoline_delete(soloud_object *obj, void *native);

/* A PHP override's return value, checked against what the virtual returns: TypeError otherwise. For
 * SOLOUD_RET_INSTANCE, *native is the instance's trampoline, which must be one nothing else owns. */
enum { SOLOUD_RET_INT, SOLOUD_RET_FLOAT, SOLOUD_RET_BOOL, SOLOUD_RET_STRING, SOLOUD_RET_INSTANCE };
bool soloud_callback_result(zval *ret, int expected, const char *method, const soloud_class *base, void **native);

/* Runs blocking on a helper thread while this thread serves its owner queue; returns when blocking has. */
void soloud_serve_until(const std::function<void()> &blocking);

/* Runs what the owner queue holds for this thread (calls posted from SoLoud's threads, releases). */
void soloud_serve(void);

/* Thread::createThread: runs aCallable(aParameter) on this thread when the new thread asks for it. */
SoLoud::Thread::ThreadHandle soloud_create_thread(zval *aCallable, zval *aParameter);

void soloud_callbacks_minit(void);
void soloud_callbacks_rinit(void);
void soloud_callbacks_rshutdown(void);

#endif
