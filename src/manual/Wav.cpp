/*
 * Wav and WavStream loaders that take raw memory, bound by hand. Ownership rules: mem.h.
 */

#include "mem.h"

/* The arginfo tables name these with C linkage. */
extern "C" {

ZEND_METHOD(SoLoud_Wav, loadMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::Wav *self = static_cast<SoLoud::Wav *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Wav));
	unsigned int aLength;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-wav-loadmem-length") && aLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-wav-loadmem-length */
		RETURN_THROWS();
	}
	const unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadMem(data, aLength, aCopy, aTakeOwnership));
}

ZEND_METHOD(SoLoud_WavStream, loadMem)
{
	zend_string *mem;
	zend_long length;
	bool aCopy = false, aTakeOwnership = true;
	SOLOUD_LOAD_PARAMS(mem, length, aCopy, aTakeOwnership);
	SoLoud::WavStream *self = static_cast<SoLoud::WavStream *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_WavStream));
	unsigned int aDataLen;
	if (self == NULL || !soloud_uint_arg(length, 2, &aDataLen)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-wavstream-loadmem-length") && aDataLen > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-wavstream-loadmem-length */
		RETURN_THROWS();
	}
	const unsigned char *data = soloud_mem<unsigned char>(ZEND_THIS, mem, aDataLen, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadMem(data, aDataLen, aCopy, aTakeOwnership));
}

/* loadRawWave8 / 16 convert the samples into SoLoud's own buffer; nothing is kept. */
ZEND_METHOD(SoLoud_Wav, loadRawWave8)
{
	zend_string *mem;
	zend_long length, channels = 1;
	double samplerate = 44100.0;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(mem)
		Z_PARAM_LONG(length)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_LONG(channels)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::Wav *self = static_cast<SoLoud::Wav *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Wav));
	unsigned int aLength, aChannels;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength) || !soloud_uint_arg(channels, 4, &aChannels)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-wav-loadrawwave8-length") && aLength > ZSTR_LEN(mem)) {
		zend_argument_value_error(2, "must be at most %zu, the length of $aMem", ZSTR_LEN(mem)); /* binding:soloud-wav-loadrawwave8-length */
		RETURN_THROWS();
	}
	RETURN_LONG(self->loadRawWave8(reinterpret_cast<unsigned char *>(ZSTR_VAL(mem)), aLength, (float) samplerate, aChannels));
}

ZEND_METHOD(SoLoud_Wav, loadRawWave16)
{
	zend_string *mem;
	zend_long length, channels = 1;
	double samplerate = 44100.0;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(mem)
		Z_PARAM_LONG(length)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_LONG(channels)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::Wav *self = static_cast<SoLoud::Wav *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Wav));
	unsigned int aLength, aChannels;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength) || !soloud_uint_arg(channels, 4, &aChannels)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-wav-loadrawwave16-length") && aLength > ZSTR_LEN(mem) / sizeof(short)) {
		zend_argument_value_error(2, "must be at most %zu, the samples in $aMem", ZSTR_LEN(mem) / sizeof(short)); /* binding:soloud-wav-loadrawwave16-length */
		RETURN_THROWS();
	}
	RETURN_LONG(self->loadRawWave16(reinterpret_cast<short *>(ZSTR_VAL(mem)), aLength, (float) samplerate, aChannels));
}

ZEND_METHOD(SoLoud_Wav, loadRawWave)
{
	zend_string *mem;
	zend_long length, channels = 1;
	double samplerate = 44100.0;
	bool aCopy = false, aTakeOwnership = true;
	ZEND_PARSE_PARAMETERS_START(2, 6)
		Z_PARAM_STR(mem)
		Z_PARAM_LONG(length)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_LONG(channels)
		Z_PARAM_BOOL(aCopy)
		Z_PARAM_BOOL(aTakeOwnership)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::Wav *self = static_cast<SoLoud::Wav *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_Wav));
	unsigned int aLength, aChannels;
	if (self == NULL || !soloud_uint_arg(length, 2, &aLength) || !soloud_uint_arg(channels, 4, &aChannels)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-wav-loadrawwave-length") && aLength > ZSTR_LEN(mem) / sizeof(float)) {
		zend_argument_value_error(2, "must be at most %zu, the samples in $aMem", ZSTR_LEN(mem) / sizeof(float)); /* binding:soloud-wav-loadrawwave-length */
		RETURN_THROWS();
	}
	float *data = soloud_mem<float>(ZEND_THIS, mem, aLength, aCopy, aTakeOwnership);
	RETURN_LONG(self->loadRawWave(data, aLength, (float) samplerate, aChannels, aCopy, aTakeOwnership));
}

}
