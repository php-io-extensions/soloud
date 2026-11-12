/*
 * Soloud members that take or return raw buffers, bound by hand: the header does not state their sizes.
 */

#include "../gen/classes.h"

/* The arginfo tables name these with C linkage. */
extern "C" {

static SoLoud::Soloud *soloud_engine_this(zval *self)
{
	return static_cast<SoLoud::Soloud *>(soloud_this(self, &soloud_class_SoLoud_Soloud));
}

/* mix_internal writes mChannels rows of the sample count rounded up to 16 into mOutputScratch and mScratch,
 * each mScratchSize * MAX_CHANNELS floats (soloud.cpp:597-601). Before init, mScratchSize is 0. */
static bool soloud_mix_fits(SoLoud::Soloud *engine, unsigned int aSamples)
{
	uint64_t stride = ((uint64_t) aSamples + 15) & ~(uint64_t) 0xf;
	return stride * engine->mChannels <= (uint64_t) engine->mScratchSize * MAX_CHANNELS;
}

static unsigned int soloud_mix_most(SoLoud::Soloud *engine)
{
	return engine->mChannels == 0 ? 0 : engine->mScratchSize * MAX_CHANNELS / engine->mChannels;
}

/* float * out: aSamples frames of mChannels floats, as a packed-float string. */
ZEND_METHOD(SoLoud_Soloud, mix)
{
	zval *buffer;
	zend_long samples;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(samples)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::Soloud *self = soloud_engine_this(ZEND_THIS);
	if (self == NULL) {
		RETURN_THROWS();
	}
	unsigned int aSamples;
	if (!soloud_uint_arg(samples, 2, &aSamples)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-mix-samples") && !soloud_mix_fits(self, aSamples)) {
		zend_argument_value_error(2, "must be at most %u, the engine's mix buffer (0 before init())", soloud_mix_most(self)); /* binding:soloud-mix-samples */
		RETURN_THROWS();
	}
	zend_string *out = zend_string_alloc((size_t) aSamples * self->mChannels * sizeof(float), 0);
	self->mix(reinterpret_cast<float *>(ZSTR_VAL(out)), aSamples);
	ZSTR_VAL(out)[ZSTR_LEN(out)] = '\0';
	ZEND_TRY_ASSIGN_REF_STR(buffer, out);
}

/* As mix, in signed 16-bit samples. */
ZEND_METHOD(SoLoud_Soloud, mixSigned16)
{
	zval *buffer;
	zend_long samples;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(samples)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::Soloud *self = soloud_engine_this(ZEND_THIS);
	if (self == NULL) {
		RETURN_THROWS();
	}
	unsigned int aSamples;
	if (!soloud_uint_arg(samples, 2, &aSamples)) {
		RETURN_THROWS();
	}
	if (!SOLOUD_PROBE_OFF("soloud-mixsigned16-samples") && !soloud_mix_fits(self, aSamples)) {
		zend_argument_value_error(2, "must be at most %u, the engine's mix buffer (0 before init())", soloud_mix_most(self)); /* binding:soloud-mixsigned16-samples */
		RETURN_THROWS();
	}
	zend_string *out = zend_string_alloc((size_t) aSamples * self->mChannels * sizeof(short), 0);
	self->mixSigned16(reinterpret_cast<short *>(ZSTR_VAL(out)), aSamples);
	ZSTR_VAL(out)[ZSTR_LEN(out)] = '\0';
	ZEND_TRY_ASSIGN_REF_STR(buffer, out);
}

/* SoLoud returns its 256-float visualisation buffers; PHP gets a copy. */
ZEND_METHOD(SoLoud_Soloud, getWave)
{
	ZEND_PARSE_PARAMETERS_NONE();
	SoLoud::Soloud *self = soloud_engine_this(ZEND_THIS);
	if (self == NULL) {
		RETURN_THROWS();
	}
	RETURN_STRINGL(reinterpret_cast<const char *>(self->getWave()), 256 * sizeof(float));
}

ZEND_METHOD(SoLoud_Soloud, calcFFT)
{
	ZEND_PARSE_PARAMETERS_NONE();
	SoLoud::Soloud *self = soloud_engine_this(ZEND_THIS);
	if (self == NULL) {
		RETURN_THROWS();
	}
	RETURN_STRINGL(reinterpret_cast<const char *>(self->calcFFT()), 256 * sizeof(float));
}

/* float & out-parameters: by-reference floats. */
ZEND_METHOD(SoLoud_Soloud, getSpeakerPosition)
{
	zend_long channel;
	zval *x, *y, *z;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(channel)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::Soloud *self = soloud_engine_this(ZEND_THIS);
	if (self == NULL) {
		RETURN_THROWS();
	}
	unsigned int aChannel;
	if (!soloud_uint_arg(channel, 1, &aChannel)) {
		RETURN_THROWS();
	}
	float aX = 0, aY = 0, aZ = 0;
	SoLoud::result r = self->getSpeakerPosition(aChannel, aX, aY, aZ);
	ZEND_TRY_ASSIGN_REF_DOUBLE(x, aX);
	ZEND_TRY_ASSIGN_REF_DOUBLE(y, aY);
	ZEND_TRY_ASSIGN_REF_DOUBLE(z, aZ);
	RETURN_LONG(r);
}

}
