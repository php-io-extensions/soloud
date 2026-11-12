/*
 * Filter-instance processing bound by hand. Buffers are sized from the call's own counts. A filter instance
 * sizes its channel state from the channel count of its first call (SoLoud: "we don't know channel count
 * before this"); soloud_object::channels records that count, and the kept refusals stop calls that would run
 * past it. Every PHP-reachable instance is PHP-made, so the first call is always one of these bindings.
 */

#include "mem.h"

#include <algorithm>
#include <cstdio>

namespace {

/* SoLoud's FFT filter window (soloud_fftfilter.cpp STFT_WINDOW_SIZE); the helpers index state by it. */
const unsigned int soloud_fft_window = 256;

/* The most channels a call may name: the instance's first count, within what its fixed state holds. */
unsigned int soloud_filter_most(soloud_object *obj, SoLoud::FilterInstance *self)
{
	unsigned int most = obj->channels != 0 ? obj->channels : MAX_CHANNELS;
	if (dynamic_cast<SoLoud::LofiFilterInstance *>(self) != NULL) {
		most = std::min(most, 2u); /* LofiFilterInstance::mChannelData[2] */
	}
	return most;
}

/* false, with why, when SoLoud would run past the instance's state. whole: filter(); else filterChannel(aChannel). */
bool soloud_filter_fits(soloud_object *obj, SoLoud::FilterInstance *self, unsigned int aChannels, unsigned int aChannel, bool whole, char *why, size_t size)
{
	if (self->mParam == NULL && dynamic_cast<SoLoud::FFTFilterInstance *>(self) != NULL) {
		snprintf(why, size, "FFTFilterInstance built without a parent FFTFilter has no parameters, and SoLoud reads parameter 0");
		return false;
	}
	if (whole && aChannels != 2 && dynamic_cast<SoLoud::FreeverbFilterInstance *>(self) != NULL) {
		snprintf(why, size, "$aChannels must be 2: SoLoud's Freeverb is stereo only");
		return false;
	}
	unsigned int most = soloud_filter_most(obj, self);
	if (aChannels == 0 || aChannels > most) {
		snprintf(why, size, "$aChannels must be between 1 and %u, the channels the instance's state holds", most);
		return false;
	}
	if (!whole && aChannel >= aChannels) {
		snprintf(why, size, "$aChannel must be less than $aChannels (%u)", aChannels);
		return false;
	}
	return true;
}

/* false, with why, when an FFT helper would read state SoLoud has not allocated or index past it. */
bool soloud_fft_fits(soloud_object *obj, unsigned int aSamples, unsigned int aChannel, char *why, size_t size)
{
	if (obj->channels == 0) {
		snprintf(why, size, "The instance has no FFT state yet: SoLoud allocates it on the first filter() or filterChannel() call");
		return false;
	}
	if (aChannel >= obj->channels) {
		snprintf(why, size, "$aChannel must be less than %u, the channels the instance's state holds", obj->channels);
		return false;
	}
	if (aSamples > soloud_fft_window) {
		snprintf(why, size, "$aSamples must be at most %u, SoLoud's FFT window", soloud_fft_window);
		return false;
	}
	return true;
}

} // namespace

/* The arginfo tables name these with C linkage. */
extern "C" {

ZEND_METHOD(SoLoud_FilterInstance, initParams)
{
	zend_long count;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	SoLoud::FilterInstance *self = static_cast<SoLoud::FilterInstance *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_FilterInstance));
	if (self == NULL) {
		RETURN_THROWS();
	}
	/* SoLoud writes parameter 0, the instance reads the count it was built with, and a failed allocation aborts. */
	zend_long least = std::max<zend_long>(1, self->mNumParams);
	if (!SOLOUD_PROBE_OFF("soloud-filterinstance-initparams-count") && (count < least || count > 256)) {
		zend_argument_value_error(1, "must be between " ZEND_LONG_FMT " and 256, the parameters the instance reads", least); /* binding:soloud-filterinstance-initparams-count */
		RETURN_THROWS();
	}
	RETURN_LONG(self->initParams((int) count));
}

ZEND_METHOD(SoLoud_FilterInstance, filter)
{
	zval *buffer;
	zend_long samples, bufferSize, channels;
	double samplerate, time;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(samples)
		Z_PARAM_LONG(bufferSize)
		Z_PARAM_LONG(channels)
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_DOUBLE(time)
	ZEND_PARSE_PARAMETERS_END();
	soloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));
	SoLoud::FilterInstance *self = static_cast<SoLoud::FilterInstance *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_FilterInstance));
	unsigned int aSamples, aBufferSize, aChannels;
	if (self == NULL || !soloud_uint_arg(samples, 2, &aSamples) || !soloud_uint_arg(bufferSize, 3, &aBufferSize) || !soloud_uint_arg(channels, 4, &aChannels)) {
		RETURN_THROWS();
	}
	char why[160];
	if (!SOLOUD_PROBE_OFF("soloud-filterinstance-filter-channels") && !soloud_filter_fits(obj, self, aChannels, 0, true, why, sizeof why)) {
		zend_value_error("%s", why); /* binding:soloud-filterinstance-filter-channels */
		RETURN_THROWS();
	}
	if (obj->channels == 0) {
		obj->channels = aChannels;
	}
	/* Channel i starts at i * aBufferSize and spans aSamples; the buffer holds every channel's full stride. */
	size_t count = aChannels != 0 ? (size_t) (aChannels - 1) * aBufferSize + std::max(aSamples, aBufferSize) : 0;
	zend_string *b = soloud_float_buffer(buffer, count);
	float *data = reinterpret_cast<float *>(ZSTR_VAL(b));
	if (obj->php) {
		/* parent::filter() from a PHP subclass: SoLoud's implementation, not the PHP override again. */
		self->SoLoud::FilterInstance::filter(data, aSamples, aBufferSize, aChannels, (float) samplerate, time);
	} else {
		self->filter(data, aSamples, aBufferSize, aChannels, (float) samplerate, time);
	}
	ZEND_TRY_ASSIGN_REF_STR(buffer, b);
}

ZEND_METHOD(SoLoud_FilterInstance, filterChannel)
{
	zval *buffer;
	zend_long samples, channel, channels;
	double samplerate, time;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(samples)
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_DOUBLE(time)
		Z_PARAM_LONG(channel)
		Z_PARAM_LONG(channels)
	ZEND_PARSE_PARAMETERS_END();
	soloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));
	SoLoud::FilterInstance *self = static_cast<SoLoud::FilterInstance *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_FilterInstance));
	unsigned int aSamples, aChannel, aChannels;
	if (self == NULL || !soloud_uint_arg(samples, 2, &aSamples) || !soloud_uint_arg(channel, 5, &aChannel) || !soloud_uint_arg(channels, 6, &aChannels)) {
		RETURN_THROWS();
	}
	char why[160];
	if (!SOLOUD_PROBE_OFF("soloud-filterinstance-filterchannel-channels") && !soloud_filter_fits(obj, self, aChannels, aChannel, false, why, sizeof why)) {
		zend_value_error("%s", why); /* binding:soloud-filterinstance-filterchannel-channels */
		RETURN_THROWS();
	}
	if (obj->channels == 0) {
		obj->channels = aChannels;
	}
	zend_string *b = soloud_float_buffer(buffer, aSamples);
	float *data = reinterpret_cast<float *>(ZSTR_VAL(b));
	SoLoud::FFTFilterInstance *fft = obj->php ? dynamic_cast<SoLoud::FFTFilterInstance *>(self) : NULL;
	if (fft != NULL) {
		fft->SoLoud::FFTFilterInstance::filterChannel(data, aSamples, (float) samplerate, time, aChannel, aChannels);
	} else if (obj->php) {
		self->SoLoud::FilterInstance::filterChannel(data, aSamples, (float) samplerate, time, aChannel, aChannels);
	} else {
		self->filterChannel(data, aSamples, (float) samplerate, time, aChannel, aChannels);
	}
	ZEND_TRY_ASSIGN_REF_STR(buffer, b);
}

/* init() drops the FFT state pointers without freeing them (upstream); the next call sizes the state again. */
ZEND_METHOD(SoLoud_FFTFilterInstance, init)
{
	ZEND_PARSE_PARAMETERS_NONE();
	SoLoud::FFTFilterInstance *self = static_cast<SoLoud::FFTFilterInstance *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_FFTFilterInstance));
	if (self == NULL) {
		RETURN_THROWS();
	}
	self->init();
	soloud_from(Z_OBJ_P(ZEND_THIS))->channels = 0;
}

ZEND_METHOD(SoLoud_FFTFilterInstance, fftFilterChannel)
{
	zval *buffer;
	zend_long samples, channel, channels;
	double samplerate, time;
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(samples)
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_DOUBLE(time)
		Z_PARAM_LONG(channel)
		Z_PARAM_LONG(channels)
	ZEND_PARSE_PARAMETERS_END();
	soloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));
	SoLoud::FFTFilterInstance *self = static_cast<SoLoud::FFTFilterInstance *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_FFTFilterInstance));
	unsigned int aSamples, aChannel, aChannels;
	if (self == NULL || !soloud_uint_arg(samples, 2, &aSamples) || !soloud_uint_arg(channel, 5, &aChannel) || !soloud_uint_arg(channels, 6, &aChannels)) {
		RETURN_THROWS();
	}
	char why[160];
	if (!SOLOUD_PROBE_OFF("soloud-fftfilterinstance-fftfilterchannel-state") && !soloud_fft_fits(obj, aSamples, aChannel, why, sizeof why)) {
		zend_throw_exception_ex(soloud_ce_exception, 0, "%s", why); /* binding:soloud-fftfilterinstance-fftfilterchannel-state */
		RETURN_THROWS();
	}
	zend_string *b = soloud_float_buffer(buffer, (size_t) aSamples * 2);
	float *data = reinterpret_cast<float *>(ZSTR_VAL(b));
	if (obj->php) {
		self->SoLoud::FFTFilterInstance::fftFilterChannel(data, aSamples, (float) samplerate, time, aChannel, aChannels);
	} else {
		self->fftFilterChannel(data, aSamples, (float) samplerate, time, aChannel, aChannels);
	}
	ZEND_TRY_ASSIGN_REF_STR(buffer, b);
}

ZEND_METHOD(SoLoud_FFTFilterInstance, magPhase2MagFreq)
{
	zval *buffer;
	zend_long samples, channel;
	double samplerate;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(samples)
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();
	soloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));
	SoLoud::FFTFilterInstance *self = static_cast<SoLoud::FFTFilterInstance *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_FFTFilterInstance));
	unsigned int aSamples, aChannel;
	if (self == NULL || !soloud_uint_arg(samples, 2, &aSamples) || !soloud_uint_arg(channel, 4, &aChannel)) {
		RETURN_THROWS();
	}
	char why[160];
	if (!SOLOUD_PROBE_OFF("soloud-fftfilterinstance-magphase2magfreq-state") && !soloud_fft_fits(obj, aSamples, aChannel, why, sizeof why)) {
		zend_throw_exception_ex(soloud_ce_exception, 0, "%s", why); /* binding:soloud-fftfilterinstance-magphase2magfreq-state */
		RETURN_THROWS();
	}
	zend_string *b = soloud_float_buffer(buffer, (size_t) aSamples * 2);
	self->magPhase2MagFreq(reinterpret_cast<float *>(ZSTR_VAL(b)), aSamples, (float) samplerate, aChannel);
	ZEND_TRY_ASSIGN_REF_STR(buffer, b);
}

ZEND_METHOD(SoLoud_FFTFilterInstance, magFreq2MagPhase)
{
	zval *buffer;
	zend_long samples, channel;
	double samplerate;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(buffer)
		Z_PARAM_LONG(samples)
		Z_PARAM_DOUBLE(samplerate)
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();
	soloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));
	SoLoud::FFTFilterInstance *self = static_cast<SoLoud::FFTFilterInstance *>(soloud_this(ZEND_THIS, &soloud_class_SoLoud_FFTFilterInstance));
	unsigned int aSamples, aChannel;
	if (self == NULL || !soloud_uint_arg(samples, 2, &aSamples) || !soloud_uint_arg(channel, 4, &aChannel)) {
		RETURN_THROWS();
	}
	char why[160];
	if (!SOLOUD_PROBE_OFF("soloud-fftfilterinstance-magfreq2magphase-state") && !soloud_fft_fits(obj, aSamples, aChannel, why, sizeof why)) {
		zend_throw_exception_ex(soloud_ce_exception, 0, "%s", why); /* binding:soloud-fftfilterinstance-magfreq2magphase-state */
		RETURN_THROWS();
	}
	zend_string *b = soloud_float_buffer(buffer, (size_t) aSamples * 2);
	self->magFreq2MagPhase(reinterpret_cast<float *>(ZSTR_VAL(b)), aSamples, (float) samplerate, aChannel);
	ZEND_TRY_ASSIGN_REF_STR(buffer, b);
}

}
