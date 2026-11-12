/*
 * File I/O on raw bytes, FILE * as an address, and the Thread mutex primitives, bound by hand. A mutex handle
 * is the address createMutex() returned; the binding tracks the live ones (SOLOUD_G(mutexes)), because a
 * stale or made-up address is freed or locked through garbage.
 */

#include "mem.h"

#include <cstdint>

namespace {

bool soloud_mutex_live(zend_long handle)
{
	return zend_hash_index_exists(&SOLOUD_G(mutexes), (zend_ulong) handle);
}

} // namespace

/* The arginfo tables name these with C linkage. */
extern "C" {

/* The bytes read, at most aBytes: SoLoud fills an aBytes buffer and says how many it wrote. */
ZEND_METHOD(SoLoud_File, read)
{
	zval *buffer;
	zend_long bytes;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(bytes)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::File *self = static_cast<SoLoud::File *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_File));
	unsigned int aBytes;
	if (self == NULL || !soloud_uint_arg(bytes, 2, &aBytes)) {
		RETURN_THROWS();
	}
	char why[192];
	if (!SOLOUD_PROBE_OFF("soloud-file-read-closed") && !soloud_file_open(self, why, sizeof why)) {
		zend_value_error("%s", why); /* binding:soloud-file-read-closed */
		RETURN_THROWS();
	}
	zend_string *out = zend_string_alloc(aBytes, 0);
	unsigned int got = std::min(self->read(reinterpret_cast<unsigned char *>(ZSTR_VAL(out)), aBytes), aBytes);
	out = zend_string_truncate(out, got, 0);
	ZSTR_VAL(out)[got] = '\0';
	ZEND_TRY_ASSIGN_REF_STR(buffer, out);
	RETURN_LONG(got);
}

/* The file's bytes, length() of them; null when the file is not in memory. */
ZEND_METHOD(SoLoud_File, getMemPtr)
{
	ZEND_PARSE_PARAMETERS_NONE();
	SoLoud::File *self = static_cast<SoLoud::File *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_File));
	if (self == NULL) {
		RETURN_THROWS();
	}
	const unsigned char *data = self->getMemPtr();
	if (data == NULL) {
		RETURN_NULL();
	}
	RETURN_STRINGL(reinterpret_cast<const char *>(data), self->length());
}

/* The FILE * address; 0 when there is none. */
ZEND_METHOD(SoLoud_File, getFilePtr)
{
	ZEND_PARSE_PARAMETERS_NONE();
	SoLoud::File *self = static_cast<SoLoud::File *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_File));
	if (self == NULL) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) (uintptr_t) self->getFilePtr());
}

ZEND_METHOD(SoLoud_MemoryFile, openMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::MemoryFile *self = static_cast<SoLoud::MemoryFile *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_MemoryFile));
	unsigned int aDataLength;
	if (self == NULL || !soloud_uint_arg(length, 2, &aDataLength)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-memoryfile-openmem-length") && aDataLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aData", ZSTR_LEN(mem)); /* binding:soloud-memoryfile-openmem-length */
		RETURN_THROWS();
	}
	const unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aDataLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->openMem(data, aDataLength, aCopy, aTakeOwnership));
}

ZEND_FUNCTION(SoLoud_Thread_createMutex)
{
	ZEND_PARSE_PARAMETERS_NONE();
	void *mutex = SoLoud::Thread::createMutex();
	if (mutex != NULL) {
		zend_hash_index_add_empty_element(&SOLOUD_G(mutexes), (zend_ulong) (uintptr_t) mutex);
	}
	RETURN_LONG((zend_long) (uintptr_t) mutex);
}

ZEND_FUNCTION(SoLoud_Thread_destroyMutex)
{
	zend_long handle;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	if (!SOLOUD_PROBE_OFF("soloud-thread-destroymutex-handle") && !soloud_mutex_live(handle)) {
		zend_argument_value_error(1, "must be a mutex createMutex() returned and destroyMutex() has not freed"); /* binding:soloud-thread-destroymutex-handle */
		RETURN_THROWS();
	}
	zend_hash_index_del(&SOLOUD_G(mutexes), (zend_ulong) handle);
	SoLoud::Thread::destroyMutex((void *) (uintptr_t) handle);
}

ZEND_FUNCTION(SoLoud_Thread_lockMutex)
{
	zend_long handle;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	if (!SOLOUD_PROBE_OFF("soloud-thread-lockmutex-handle") && !soloud_mutex_live(handle)) {
		zend_argument_value_error(1, "must be a mutex createMutex() returned and destroyMutex() has not freed"); /* binding:soloud-thread-lockmutex-handle */
		RETURN_THROWS();
	}
	SoLoud::Thread::lockMutex((void *) (uintptr_t) handle);
}

ZEND_FUNCTION(SoLoud_Thread_unlockMutex)
{
	zend_long handle;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	if (!SOLOUD_PROBE_OFF("soloud-thread-unlockmutex-handle") && !soloud_mutex_live(handle)) {
		zend_argument_value_error(1, "must be a mutex createMutex() returned and destroyMutex() has not freed"); /* binding:soloud-thread-unlockmutex-handle */
		RETURN_THROWS();
	}
	SoLoud::Thread::unlockMutex((void *) (uintptr_t) handle);
}

}
