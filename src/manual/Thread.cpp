/*
 * Thread::createThread / wait / release, bound by hand. The thread function is a PHP callable: the new thread
 * asks this thread to run it (callbacks.cpp). A handle is the address createThread() returned; the binding
 * tracks the live ones (SOLOUD_G(threads)), because SoLoud joins and deletes through any address it is given.
 */

#include "mem.h"
#include "../callbacks.h"

#include <cstdint>

namespace {

/* The handle's entry: false until joined. NULL when the handle is not live. */
zval *soloud_thread_entry(zend_long handle)
{
	return zend_hash_index_find(&SOLOUD_G(threads), (zend_ulong) handle);
}

} // namespace

/* The arginfo tables name these with C linkage. */
extern "C" {

ZEND_FUNCTION(SoLoud_Thread_createThread)
{
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;
	zend_long parameter;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_FUNC(fci, fcc)
		Z_PARAM_LONG(parameter)
	ZEND_PARSE_PARAMETERS_END();
	zval arg;
	ZVAL_LONG(&arg, parameter);
	SoLoud::Thread::ThreadHandle handle = soloud_create_thread(&fci.function_name, &arg);
	if (handle != NULL) {
		zval joined;
		ZVAL_FALSE(&joined);
		zend_hash_index_update(&SOLOUD_G(threads), (zend_ulong) (uintptr_t) handle, &joined);
	}
	RETURN_LONG((zend_long) (uintptr_t) handle);
}

/* Serves this thread's queue while it joins: the thread function runs here. */
ZEND_FUNCTION(SoLoud_Thread_wait)
{
	zend_long handle;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zval *entry = soloud_thread_entry(handle);
	if (!SOLOUD_PROBE_OFF("soloud-thread-wait-handle") && (entry == NULL || Z_TYPE_P(entry) == IS_TRUE)) {
		zend_argument_value_error(1, "must be a thread createThread() returned that is not yet joined or released"); /* binding:soloud-thread-wait-handle */
		RETURN_THROWS();
	}
	if (entry != NULL) {
		ZVAL_TRUE(entry);
	}
	SoLoud::Thread::ThreadHandle h = (SoLoud::Thread::ThreadHandle) (uintptr_t) handle;
	soloud_serve_until([h] { SoLoud::Thread::wait(h); });
}

ZEND_FUNCTION(SoLoud_Thread_release)
{
	zend_long handle;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	if (!SOLOUD_PROBE_OFF("soloud-thread-release-handle") && soloud_thread_entry(handle) == NULL) {
		zend_argument_value_error(1, "must be a thread createThread() returned that is not yet released"); /* binding:soloud-thread-release-handle */
		RETURN_THROWS();
	}
	zend_hash_index_del(&SOLOUD_G(threads), (zend_ulong) handle);
	SoLoud::Thread::release((SoLoud::Thread::ThreadHandle) (uintptr_t) handle);
}

}
