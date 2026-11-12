/*
 * Audio-source members that take or return raw memory, bound by hand. Ownership rules: mem.h.
 */

#include "mem.h"

/* The arginfo tables name these with C linkage. */
extern "C" {

/* Bus returns its 256-float visualisation buffers; PHP gets a copy. */
ZEND_METHOD(SoLoud_Bus, calcFFT)
{
	ZEND_PARSE_PARAMETERS_NONE();
	SoLoud::Bus *self = static_cast<SoLoud::Bus *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Bus));
	if (self == NULL) {
		RETURN_THROWS();
	}
	RETURN_STRINGL(reinterpret_cast<const char *>(self->calcFFT()), 256 * sizeof(float));
}

ZEND_METHOD(SoLoud_Bus, getWave)
{
	ZEND_PARSE_PARAMETERS_NONE();
	SoLoud::Bus *self = static_cast<SoLoud::Bus *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Bus));
	if (self == NULL) {
		RETURN_THROWS();
	}
	RETURN_STRINGL(reinterpret_cast<const char *>(self->getWave()), 256 * sizeof(float));
}

ZEND_METHOD(SoLoud_Ay, loadMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::Ay *self = static_cast<SoLoud::Ay *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Ay));
	unsigned int aLength;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-ay-loadmem-length") && aLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-ay-loadmem-length */
		RETURN_THROWS();
	}
	const unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadMem(data, aLength, aCopy, aTakeOwnership));
}

ZEND_METHOD(SoLoud_Monotone, loadMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::Monotone *self = static_cast<SoLoud::Monotone *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Monotone));
	unsigned int aLength;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-monotone-loadmem-length") && aLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-monotone-loadmem-length */
		RETURN_THROWS();
	}
	const unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadMem(data, aLength, aCopy, aTakeOwnership));
}

ZEND_METHOD(SoLoud_Openmpt, loadMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::Openmpt *self = static_cast<SoLoud::Openmpt *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Openmpt));
	unsigned int aLength;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-openmpt-loadmem-length") && aLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-openmpt-loadmem-length */
		RETURN_THROWS();
	}
	const unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadMem(data, aLength, aCopy, aTakeOwnership));
}

ZEND_METHOD(SoLoud_TedSid, loadMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::TedSid *self = static_cast<SoLoud::TedSid *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_TedSid));
	unsigned int aLength;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-tedsid-loadmem-length") && aLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-tedsid-loadmem-length */
		RETURN_THROWS();
	}
	const unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadMem(data, aLength, aCopy, aTakeOwnership));
}

ZEND_METHOD(SoLoud_Sfxr, loadParamsMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::Sfxr *self = static_cast<SoLoud::Sfxr *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Sfxr));
	unsigned int aLength;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-sfxr-loadparamsmem-length") && aLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-sfxr-loadparamsmem-length */
		RETURN_THROWS();
	}
	unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadParamsMem(data, aLength, aCopy, aTakeOwnership));
}

}
