/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b48c94a1dd8cde5c79a2a30e73e2bc959472f710 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_FilterInstance___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_initParams, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aNumParams, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_updateParams, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_filter, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aSamples, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aBufferSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aChannels, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSamplerate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_filterChannel, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aSamples, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSamplerate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aChannels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_getFilterParameter, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_setFilterParameter, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aValue, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_fadeFilterParameter, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aStartTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FilterInstance_oscillateFilterParameter, 0, 5, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFrom, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aStartTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Filter___construct arginfo_class_SoLoud_FilterInstance___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Filter_getParamCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Filter_getParamName, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aParamIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Filter_getParamType, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aParamIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Filter_getParamMax, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aParamIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Filter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_Filter_createInstance, 0, 0, SoLoud\\FilterInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_FFTFilterInstance___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, aParent, SoLoud\\FFTFilter, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FFTFilterInstance_fftFilterChannel, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aFFTBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aSamples, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSamplerate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aChannels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FFTFilterInstance_comp2MagPhase, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aFFTBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aSamples, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FFTFilterInstance_magPhase2MagFreq, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aFFTBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aSamples, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSamplerate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_FFTFilterInstance_magFreq2MagPhase arginfo_class_SoLoud_FFTFilterInstance_magPhase2MagFreq

#define arginfo_class_SoLoud_FFTFilterInstance_magPhase2Comp arginfo_class_SoLoud_FFTFilterInstance_comp2MagPhase

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FFTFilterInstance_init, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_FFTFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_FFTFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_BassboostFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\BassboostFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_BassboostFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_BassboostFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_BassboostFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_BassboostFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_BassboostFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_BassboostFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_BassboostFilter_setParams, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aBoost, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_BassboostFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_BiquadResonantFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\BiquadResonantFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_BiquadResonantFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_BiquadResonantFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_BiquadResonantFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_BiquadResonantFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_BiquadResonantFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_BiquadResonantFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_BiquadResonantFilter_createInstance, 0, 0, SoLoud\\BiquadResonantFilterInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_BiquadResonantFilter_setParams, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aType, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFrequency, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aResonance, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_DCRemovalFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\DCRemovalFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_DCRemovalFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_DCRemovalFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_DCRemovalFilter_setParams, 0, 0, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aLength, IS_DOUBLE, 0, "0.100000001")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_DuckFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\DuckFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_DuckFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_DuckFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_DuckFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_DuckFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_DuckFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_DuckFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_DuckFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_DuckFilter_setParams, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSoloud, SoLoud\\Soloud, 1)
	ZEND_ARG_TYPE_INFO(0, aListenTo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aOnRamp, IS_DOUBLE, 0, "0.100000001")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aOffRamp, IS_DOUBLE, 0, "0.5")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aLevel, IS_DOUBLE, 0, "0.100000001")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_EchoFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\EchoFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_EchoFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_EchoFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_EchoFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_EchoFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_EchoFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_EchoFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_EchoFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_EchoFilter_setParams, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aDelay, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aDecay, IS_DOUBLE, 0, "0.699999988")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aFilter, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_EqFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\EqFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_EqFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_EqFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_EqFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_EqFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_EqFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_EqFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_EqFilter_setParam, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aBand, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVolume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_EqFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_FlangerFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\FlangerFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_FlangerFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_FlangerFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_FlangerFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_FlangerFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_FlangerFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_FlangerFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_FlangerFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FlangerFilter_setParams, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aDelay, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aFreq, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_FreeverbFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\FreeverbFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_FreeverbFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_FreeverbFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_FreeverbFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_FreeverbFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_FreeverbFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_FreeverbFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_FreeverbFilter_createInstance, 0, 0, SoLoud\\FreeverbFilterInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_FreeverbFilter_setParams, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aMode, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aRoomSize, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aDamp, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aWidth, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_LofiChannelData___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mSample, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mSamplesToSkip, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_LofiFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\LofiFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_LofiFilter___construct arginfo_class_SoLoud_FilterInstance___construct

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_LofiFilter_createInstance, 0, 0, SoLoud\\LofiFilterInstance, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_LofiFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_LofiFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_LofiFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_LofiFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_LofiFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_LofiFilter_setParams, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSampleRate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aBitdepth, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_RobotizeFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\RobotizeFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_RobotizeFilter___construct arginfo_class_SoLoud_FilterInstance___construct

#define arginfo_class_SoLoud_RobotizeFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_RobotizeFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_RobotizeFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_RobotizeFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_RobotizeFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_RobotizeFilter_setParams, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aFreq, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aWaveform, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_RobotizeFilter_createInstance arginfo_class_SoLoud_Filter_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_WaveShaperFilterInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\WaveShaperFilter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_WaveShaperFilter___construct arginfo_class_SoLoud_FilterInstance___construct

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_WaveShaperFilter_createInstance, 0, 0, SoLoud\\WaveShaperFilterInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_WaveShaperFilter_setParams, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAmount, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_WaveShaperFilter_getParamCount arginfo_class_SoLoud_Filter_getParamCount

#define arginfo_class_SoLoud_WaveShaperFilter_getParamName arginfo_class_SoLoud_Filter_getParamName

#define arginfo_class_SoLoud_WaveShaperFilter_getParamType arginfo_class_SoLoud_Filter_getParamType

#define arginfo_class_SoLoud_WaveShaperFilter_getParamMax arginfo_class_SoLoud_Filter_getParamMax

#define arginfo_class_SoLoud_WaveShaperFilter_getParamMin arginfo_class_SoLoud_Filter_getParamMax

ZEND_METHOD(SoLoud_FilterInstance, __construct);
ZEND_METHOD(SoLoud_FilterInstance, initParams);
ZEND_METHOD(SoLoud_FilterInstance, updateParams);
ZEND_METHOD(SoLoud_FilterInstance, filter);
ZEND_METHOD(SoLoud_FilterInstance, filterChannel);
ZEND_METHOD(SoLoud_FilterInstance, getFilterParameter);
ZEND_METHOD(SoLoud_FilterInstance, setFilterParameter);
ZEND_METHOD(SoLoud_FilterInstance, fadeFilterParameter);
ZEND_METHOD(SoLoud_FilterInstance, oscillateFilterParameter);
ZEND_METHOD(SoLoud_Filter, __construct);
ZEND_METHOD(SoLoud_Filter, getParamCount);
ZEND_METHOD(SoLoud_Filter, getParamName);
ZEND_METHOD(SoLoud_Filter, getParamType);
ZEND_METHOD(SoLoud_Filter, getParamMax);
ZEND_METHOD(SoLoud_Filter, getParamMin);
ZEND_METHOD(SoLoud_Filter, createInstance);
ZEND_METHOD(SoLoud_FFTFilterInstance, __construct);
ZEND_METHOD(SoLoud_FFTFilterInstance, fftFilterChannel);
ZEND_METHOD(SoLoud_FFTFilterInstance, comp2MagPhase);
ZEND_METHOD(SoLoud_FFTFilterInstance, magPhase2MagFreq);
ZEND_METHOD(SoLoud_FFTFilterInstance, magFreq2MagPhase);
ZEND_METHOD(SoLoud_FFTFilterInstance, magPhase2Comp);
ZEND_METHOD(SoLoud_FFTFilterInstance, init);
ZEND_METHOD(SoLoud_FFTFilter, __construct);
ZEND_METHOD(SoLoud_FFTFilter, createInstance);
ZEND_METHOD(SoLoud_BassboostFilterInstance, __construct);
ZEND_METHOD(SoLoud_BassboostFilter, __construct);
ZEND_METHOD(SoLoud_BassboostFilter, getParamCount);
ZEND_METHOD(SoLoud_BassboostFilter, getParamName);
ZEND_METHOD(SoLoud_BassboostFilter, getParamType);
ZEND_METHOD(SoLoud_BassboostFilter, getParamMax);
ZEND_METHOD(SoLoud_BassboostFilter, getParamMin);
ZEND_METHOD(SoLoud_BassboostFilter, setParams);
ZEND_METHOD(SoLoud_BassboostFilter, createInstance);
ZEND_METHOD(SoLoud_BiquadResonantFilterInstance, __construct);
ZEND_METHOD(SoLoud_BiquadResonantFilter, __construct);
ZEND_METHOD(SoLoud_BiquadResonantFilter, getParamCount);
ZEND_METHOD(SoLoud_BiquadResonantFilter, getParamName);
ZEND_METHOD(SoLoud_BiquadResonantFilter, getParamType);
ZEND_METHOD(SoLoud_BiquadResonantFilter, getParamMax);
ZEND_METHOD(SoLoud_BiquadResonantFilter, getParamMin);
ZEND_METHOD(SoLoud_BiquadResonantFilter, createInstance);
ZEND_METHOD(SoLoud_BiquadResonantFilter, setParams);
ZEND_METHOD(SoLoud_DCRemovalFilterInstance, __construct);
ZEND_METHOD(SoLoud_DCRemovalFilter, __construct);
ZEND_METHOD(SoLoud_DCRemovalFilter, createInstance);
ZEND_METHOD(SoLoud_DCRemovalFilter, setParams);
ZEND_METHOD(SoLoud_DuckFilterInstance, __construct);
ZEND_METHOD(SoLoud_DuckFilter, __construct);
ZEND_METHOD(SoLoud_DuckFilter, getParamCount);
ZEND_METHOD(SoLoud_DuckFilter, getParamName);
ZEND_METHOD(SoLoud_DuckFilter, getParamType);
ZEND_METHOD(SoLoud_DuckFilter, getParamMax);
ZEND_METHOD(SoLoud_DuckFilter, getParamMin);
ZEND_METHOD(SoLoud_DuckFilter, createInstance);
ZEND_METHOD(SoLoud_DuckFilter, setParams);
ZEND_METHOD(SoLoud_EchoFilterInstance, __construct);
ZEND_METHOD(SoLoud_EchoFilter, __construct);
ZEND_METHOD(SoLoud_EchoFilter, getParamCount);
ZEND_METHOD(SoLoud_EchoFilter, getParamName);
ZEND_METHOD(SoLoud_EchoFilter, getParamType);
ZEND_METHOD(SoLoud_EchoFilter, getParamMax);
ZEND_METHOD(SoLoud_EchoFilter, getParamMin);
ZEND_METHOD(SoLoud_EchoFilter, createInstance);
ZEND_METHOD(SoLoud_EchoFilter, setParams);
ZEND_METHOD(SoLoud_EqFilterInstance, __construct);
ZEND_METHOD(SoLoud_EqFilter, __construct);
ZEND_METHOD(SoLoud_EqFilter, getParamCount);
ZEND_METHOD(SoLoud_EqFilter, getParamName);
ZEND_METHOD(SoLoud_EqFilter, getParamType);
ZEND_METHOD(SoLoud_EqFilter, getParamMax);
ZEND_METHOD(SoLoud_EqFilter, getParamMin);
ZEND_METHOD(SoLoud_EqFilter, setParam);
ZEND_METHOD(SoLoud_EqFilter, createInstance);
ZEND_METHOD(SoLoud_FlangerFilterInstance, __construct);
ZEND_METHOD(SoLoud_FlangerFilter, __construct);
ZEND_METHOD(SoLoud_FlangerFilter, getParamCount);
ZEND_METHOD(SoLoud_FlangerFilter, getParamName);
ZEND_METHOD(SoLoud_FlangerFilter, getParamType);
ZEND_METHOD(SoLoud_FlangerFilter, getParamMax);
ZEND_METHOD(SoLoud_FlangerFilter, getParamMin);
ZEND_METHOD(SoLoud_FlangerFilter, createInstance);
ZEND_METHOD(SoLoud_FlangerFilter, setParams);
ZEND_METHOD(SoLoud_FreeverbFilterInstance, __construct);
ZEND_METHOD(SoLoud_FreeverbFilter, __construct);
ZEND_METHOD(SoLoud_FreeverbFilter, getParamCount);
ZEND_METHOD(SoLoud_FreeverbFilter, getParamName);
ZEND_METHOD(SoLoud_FreeverbFilter, getParamType);
ZEND_METHOD(SoLoud_FreeverbFilter, getParamMax);
ZEND_METHOD(SoLoud_FreeverbFilter, getParamMin);
ZEND_METHOD(SoLoud_FreeverbFilter, createInstance);
ZEND_METHOD(SoLoud_FreeverbFilter, setParams);
ZEND_METHOD(SoLoud_LofiChannelData, __construct);
ZEND_METHOD(SoLoud_LofiFilterInstance, __construct);
ZEND_METHOD(SoLoud_LofiFilter, __construct);
ZEND_METHOD(SoLoud_LofiFilter, createInstance);
ZEND_METHOD(SoLoud_LofiFilter, getParamCount);
ZEND_METHOD(SoLoud_LofiFilter, getParamName);
ZEND_METHOD(SoLoud_LofiFilter, getParamType);
ZEND_METHOD(SoLoud_LofiFilter, getParamMax);
ZEND_METHOD(SoLoud_LofiFilter, getParamMin);
ZEND_METHOD(SoLoud_LofiFilter, setParams);
ZEND_METHOD(SoLoud_RobotizeFilterInstance, __construct);
ZEND_METHOD(SoLoud_RobotizeFilter, __construct);
ZEND_METHOD(SoLoud_RobotizeFilter, getParamCount);
ZEND_METHOD(SoLoud_RobotizeFilter, getParamName);
ZEND_METHOD(SoLoud_RobotizeFilter, getParamType);
ZEND_METHOD(SoLoud_RobotizeFilter, getParamMax);
ZEND_METHOD(SoLoud_RobotizeFilter, getParamMin);
ZEND_METHOD(SoLoud_RobotizeFilter, setParams);
ZEND_METHOD(SoLoud_RobotizeFilter, createInstance);
ZEND_METHOD(SoLoud_WaveShaperFilterInstance, __construct);
ZEND_METHOD(SoLoud_WaveShaperFilter, __construct);
ZEND_METHOD(SoLoud_WaveShaperFilter, createInstance);
ZEND_METHOD(SoLoud_WaveShaperFilter, setParams);
ZEND_METHOD(SoLoud_WaveShaperFilter, getParamCount);
ZEND_METHOD(SoLoud_WaveShaperFilter, getParamName);
ZEND_METHOD(SoLoud_WaveShaperFilter, getParamType);
ZEND_METHOD(SoLoud_WaveShaperFilter, getParamMax);
ZEND_METHOD(SoLoud_WaveShaperFilter, getParamMin);

static const zend_function_entry class_SoLoud_FilterInstance_methods[] = {
	ZEND_ME(SoLoud_FilterInstance, __construct, arginfo_class_SoLoud_FilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, initParams, arginfo_class_SoLoud_FilterInstance_initParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, updateParams, arginfo_class_SoLoud_FilterInstance_updateParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, filter, arginfo_class_SoLoud_FilterInstance_filter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, filterChannel, arginfo_class_SoLoud_FilterInstance_filterChannel, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, getFilterParameter, arginfo_class_SoLoud_FilterInstance_getFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, setFilterParameter, arginfo_class_SoLoud_FilterInstance_setFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, fadeFilterParameter, arginfo_class_SoLoud_FilterInstance_fadeFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FilterInstance, oscillateFilterParameter, arginfo_class_SoLoud_FilterInstance_oscillateFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Filter_methods[] = {
	ZEND_ME(SoLoud_Filter, __construct, arginfo_class_SoLoud_Filter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Filter, getParamCount, arginfo_class_SoLoud_Filter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Filter, getParamName, arginfo_class_SoLoud_Filter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Filter, getParamType, arginfo_class_SoLoud_Filter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Filter, getParamMax, arginfo_class_SoLoud_Filter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Filter, getParamMin, arginfo_class_SoLoud_Filter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Filter, createInstance, arginfo_class_SoLoud_Filter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_FFTFilterInstance_methods[] = {
	ZEND_ME(SoLoud_FFTFilterInstance, __construct, arginfo_class_SoLoud_FFTFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FFTFilterInstance, fftFilterChannel, arginfo_class_SoLoud_FFTFilterInstance_fftFilterChannel, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FFTFilterInstance, comp2MagPhase, arginfo_class_SoLoud_FFTFilterInstance_comp2MagPhase, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FFTFilterInstance, magPhase2MagFreq, arginfo_class_SoLoud_FFTFilterInstance_magPhase2MagFreq, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FFTFilterInstance, magFreq2MagPhase, arginfo_class_SoLoud_FFTFilterInstance_magFreq2MagPhase, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FFTFilterInstance, magPhase2Comp, arginfo_class_SoLoud_FFTFilterInstance_magPhase2Comp, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FFTFilterInstance, init, arginfo_class_SoLoud_FFTFilterInstance_init, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_FFTFilter_methods[] = {
	ZEND_ME(SoLoud_FFTFilter, __construct, arginfo_class_SoLoud_FFTFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FFTFilter, createInstance, arginfo_class_SoLoud_FFTFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_BassboostFilterInstance_methods[] = {
	ZEND_ME(SoLoud_BassboostFilterInstance, __construct, arginfo_class_SoLoud_BassboostFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_BassboostFilter_methods[] = {
	ZEND_ME(SoLoud_BassboostFilter, __construct, arginfo_class_SoLoud_BassboostFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BassboostFilter, getParamCount, arginfo_class_SoLoud_BassboostFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BassboostFilter, getParamName, arginfo_class_SoLoud_BassboostFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BassboostFilter, getParamType, arginfo_class_SoLoud_BassboostFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BassboostFilter, getParamMax, arginfo_class_SoLoud_BassboostFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BassboostFilter, getParamMin, arginfo_class_SoLoud_BassboostFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BassboostFilter, setParams, arginfo_class_SoLoud_BassboostFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BassboostFilter, createInstance, arginfo_class_SoLoud_BassboostFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_BiquadResonantFilterInstance_methods[] = {
	ZEND_ME(SoLoud_BiquadResonantFilterInstance, __construct, arginfo_class_SoLoud_BiquadResonantFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_BiquadResonantFilter_methods[] = {
	ZEND_ME(SoLoud_BiquadResonantFilter, __construct, arginfo_class_SoLoud_BiquadResonantFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BiquadResonantFilter, getParamCount, arginfo_class_SoLoud_BiquadResonantFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BiquadResonantFilter, getParamName, arginfo_class_SoLoud_BiquadResonantFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BiquadResonantFilter, getParamType, arginfo_class_SoLoud_BiquadResonantFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BiquadResonantFilter, getParamMax, arginfo_class_SoLoud_BiquadResonantFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BiquadResonantFilter, getParamMin, arginfo_class_SoLoud_BiquadResonantFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BiquadResonantFilter, createInstance, arginfo_class_SoLoud_BiquadResonantFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BiquadResonantFilter, setParams, arginfo_class_SoLoud_BiquadResonantFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_DCRemovalFilterInstance_methods[] = {
	ZEND_ME(SoLoud_DCRemovalFilterInstance, __construct, arginfo_class_SoLoud_DCRemovalFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_DCRemovalFilter_methods[] = {
	ZEND_ME(SoLoud_DCRemovalFilter, __construct, arginfo_class_SoLoud_DCRemovalFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DCRemovalFilter, createInstance, arginfo_class_SoLoud_DCRemovalFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DCRemovalFilter, setParams, arginfo_class_SoLoud_DCRemovalFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_DuckFilterInstance_methods[] = {
	ZEND_ME(SoLoud_DuckFilterInstance, __construct, arginfo_class_SoLoud_DuckFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_DuckFilter_methods[] = {
	ZEND_ME(SoLoud_DuckFilter, __construct, arginfo_class_SoLoud_DuckFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DuckFilter, getParamCount, arginfo_class_SoLoud_DuckFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DuckFilter, getParamName, arginfo_class_SoLoud_DuckFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DuckFilter, getParamType, arginfo_class_SoLoud_DuckFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DuckFilter, getParamMax, arginfo_class_SoLoud_DuckFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DuckFilter, getParamMin, arginfo_class_SoLoud_DuckFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DuckFilter, createInstance, arginfo_class_SoLoud_DuckFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DuckFilter, setParams, arginfo_class_SoLoud_DuckFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_EchoFilterInstance_methods[] = {
	ZEND_ME(SoLoud_EchoFilterInstance, __construct, arginfo_class_SoLoud_EchoFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_EchoFilter_methods[] = {
	ZEND_ME(SoLoud_EchoFilter, __construct, arginfo_class_SoLoud_EchoFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EchoFilter, getParamCount, arginfo_class_SoLoud_EchoFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EchoFilter, getParamName, arginfo_class_SoLoud_EchoFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EchoFilter, getParamType, arginfo_class_SoLoud_EchoFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EchoFilter, getParamMax, arginfo_class_SoLoud_EchoFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EchoFilter, getParamMin, arginfo_class_SoLoud_EchoFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EchoFilter, createInstance, arginfo_class_SoLoud_EchoFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EchoFilter, setParams, arginfo_class_SoLoud_EchoFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_EqFilterInstance_methods[] = {
	ZEND_ME(SoLoud_EqFilterInstance, __construct, arginfo_class_SoLoud_EqFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_EqFilter_methods[] = {
	ZEND_ME(SoLoud_EqFilter, __construct, arginfo_class_SoLoud_EqFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EqFilter, getParamCount, arginfo_class_SoLoud_EqFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EqFilter, getParamName, arginfo_class_SoLoud_EqFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EqFilter, getParamType, arginfo_class_SoLoud_EqFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EqFilter, getParamMax, arginfo_class_SoLoud_EqFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EqFilter, getParamMin, arginfo_class_SoLoud_EqFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EqFilter, setParam, arginfo_class_SoLoud_EqFilter_setParam, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_EqFilter, createInstance, arginfo_class_SoLoud_EqFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_FlangerFilterInstance_methods[] = {
	ZEND_ME(SoLoud_FlangerFilterInstance, __construct, arginfo_class_SoLoud_FlangerFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_FlangerFilter_methods[] = {
	ZEND_ME(SoLoud_FlangerFilter, __construct, arginfo_class_SoLoud_FlangerFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FlangerFilter, getParamCount, arginfo_class_SoLoud_FlangerFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FlangerFilter, getParamName, arginfo_class_SoLoud_FlangerFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FlangerFilter, getParamType, arginfo_class_SoLoud_FlangerFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FlangerFilter, getParamMax, arginfo_class_SoLoud_FlangerFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FlangerFilter, getParamMin, arginfo_class_SoLoud_FlangerFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FlangerFilter, createInstance, arginfo_class_SoLoud_FlangerFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FlangerFilter, setParams, arginfo_class_SoLoud_FlangerFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_FreeverbFilterInstance_methods[] = {
	ZEND_ME(SoLoud_FreeverbFilterInstance, __construct, arginfo_class_SoLoud_FreeverbFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_FreeverbFilter_methods[] = {
	ZEND_ME(SoLoud_FreeverbFilter, __construct, arginfo_class_SoLoud_FreeverbFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FreeverbFilter, getParamCount, arginfo_class_SoLoud_FreeverbFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FreeverbFilter, getParamName, arginfo_class_SoLoud_FreeverbFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FreeverbFilter, getParamType, arginfo_class_SoLoud_FreeverbFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FreeverbFilter, getParamMax, arginfo_class_SoLoud_FreeverbFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FreeverbFilter, getParamMin, arginfo_class_SoLoud_FreeverbFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FreeverbFilter, createInstance, arginfo_class_SoLoud_FreeverbFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_FreeverbFilter, setParams, arginfo_class_SoLoud_FreeverbFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_LofiChannelData_methods[] = {
	ZEND_ME(SoLoud_LofiChannelData, __construct, arginfo_class_SoLoud_LofiChannelData___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_LofiFilterInstance_methods[] = {
	ZEND_ME(SoLoud_LofiFilterInstance, __construct, arginfo_class_SoLoud_LofiFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_LofiFilter_methods[] = {
	ZEND_ME(SoLoud_LofiFilter, __construct, arginfo_class_SoLoud_LofiFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_LofiFilter, createInstance, arginfo_class_SoLoud_LofiFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_LofiFilter, getParamCount, arginfo_class_SoLoud_LofiFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_LofiFilter, getParamName, arginfo_class_SoLoud_LofiFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_LofiFilter, getParamType, arginfo_class_SoLoud_LofiFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_LofiFilter, getParamMax, arginfo_class_SoLoud_LofiFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_LofiFilter, getParamMin, arginfo_class_SoLoud_LofiFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_LofiFilter, setParams, arginfo_class_SoLoud_LofiFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_RobotizeFilterInstance_methods[] = {
	ZEND_ME(SoLoud_RobotizeFilterInstance, __construct, arginfo_class_SoLoud_RobotizeFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_RobotizeFilter_methods[] = {
	ZEND_ME(SoLoud_RobotizeFilter, __construct, arginfo_class_SoLoud_RobotizeFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_RobotizeFilter, getParamCount, arginfo_class_SoLoud_RobotizeFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_RobotizeFilter, getParamName, arginfo_class_SoLoud_RobotizeFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_RobotizeFilter, getParamType, arginfo_class_SoLoud_RobotizeFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_RobotizeFilter, getParamMax, arginfo_class_SoLoud_RobotizeFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_RobotizeFilter, getParamMin, arginfo_class_SoLoud_RobotizeFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_RobotizeFilter, setParams, arginfo_class_SoLoud_RobotizeFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_RobotizeFilter, createInstance, arginfo_class_SoLoud_RobotizeFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_WaveShaperFilterInstance_methods[] = {
	ZEND_ME(SoLoud_WaveShaperFilterInstance, __construct, arginfo_class_SoLoud_WaveShaperFilterInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_WaveShaperFilter_methods[] = {
	ZEND_ME(SoLoud_WaveShaperFilter, __construct, arginfo_class_SoLoud_WaveShaperFilter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WaveShaperFilter, createInstance, arginfo_class_SoLoud_WaveShaperFilter_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WaveShaperFilter, setParams, arginfo_class_SoLoud_WaveShaperFilter_setParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WaveShaperFilter, getParamCount, arginfo_class_SoLoud_WaveShaperFilter_getParamCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WaveShaperFilter, getParamName, arginfo_class_SoLoud_WaveShaperFilter_getParamName, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WaveShaperFilter, getParamType, arginfo_class_SoLoud_WaveShaperFilter_getParamType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WaveShaperFilter, getParamMax, arginfo_class_SoLoud_WaveShaperFilter_getParamMax, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WaveShaperFilter, getParamMin, arginfo_class_SoLoud_WaveShaperFilter_getParamMin, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_SoLoud_FilterInstance(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "FilterInstance", class_SoLoud_FilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mNumParams_default_value;
	ZVAL_UNDEF(&property_mNumParams_default_value);
	zend_string *property_mNumParams_name = zend_string_init("mNumParams", sizeof("mNumParams") - 1, 1);
	zend_declare_typed_property(class_entry, property_mNumParams_name, &property_mNumParams_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mNumParams_name);

	zval property_mParamChanged_default_value;
	ZVAL_UNDEF(&property_mParamChanged_default_value);
	zend_string *property_mParamChanged_name = zend_string_init("mParamChanged", sizeof("mParamChanged") - 1, 1);
	zend_declare_typed_property(class_entry, property_mParamChanged_name, &property_mParamChanged_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mParamChanged_name);

	zval property_mParam_default_value;
	ZVAL_UNDEF(&property_mParam_default_value);
	zend_string *property_mParam_name = zend_string_init("mParam", sizeof("mParam") - 1, 1);
	zend_declare_typed_property(class_entry, property_mParam_name, &property_mParam_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mParam_name);

	zval property_mParamFader_default_value;
	ZVAL_UNDEF(&property_mParamFader_default_value);
	zend_string *property_mParamFader_name = zend_string_init("mParamFader", sizeof("mParamFader") - 1, 1);
	zend_string *property_mParamFader_class_SoLoud_Fader = zend_string_init("SoLoud\\Fader", sizeof("SoLoud\\Fader")-1, 1);
	zend_declare_typed_property(class_entry, property_mParamFader_name, &property_mParamFader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mParamFader_class_SoLoud_Fader, 0, MAY_BE_NULL));
	zend_string_release(property_mParamFader_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Filter(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Filter", class_SoLoud_Filter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	zval const_FLOAT_PARAM_value;
	ZVAL_LONG(&const_FLOAT_PARAM_value, SoLoud::Filter::FLOAT_PARAM);
	zend_string *const_FLOAT_PARAM_name = zend_string_init_interned("FLOAT_PARAM", sizeof("FLOAT_PARAM") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_FLOAT_PARAM_name, &const_FLOAT_PARAM_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_FLOAT_PARAM_name);

	zval const_INT_PARAM_value;
	ZVAL_LONG(&const_INT_PARAM_value, SoLoud::Filter::INT_PARAM);
	zend_string *const_INT_PARAM_name = zend_string_init_interned("INT_PARAM", sizeof("INT_PARAM") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_INT_PARAM_name, &const_INT_PARAM_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_INT_PARAM_name);

	zval const_BOOL_PARAM_value;
	ZVAL_LONG(&const_BOOL_PARAM_value, SoLoud::Filter::BOOL_PARAM);
	zend_string *const_BOOL_PARAM_name = zend_string_init_interned("BOOL_PARAM", sizeof("BOOL_PARAM") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BOOL_PARAM_name, &const_BOOL_PARAM_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BOOL_PARAM_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_FFTFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "FFTFilterInstance", class_SoLoud_FFTFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_FFTFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "FFTFilter", class_SoLoud_FFTFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_BassboostFilterInstance(zend_class_entry *class_entry_SoLoud_FFTFilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "BassboostFilterInstance", class_SoLoud_BassboostFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FFTFilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_BassboostFilter(zend_class_entry *class_entry_SoLoud_FFTFilter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "BassboostFilter", class_SoLoud_BassboostFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FFTFilter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::BassboostFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_BOOST_value;
	ZVAL_LONG(&const_BOOST_value, SoLoud::BassboostFilter::BOOST);
	zend_string *const_BOOST_name = zend_string_init_interned("BOOST", sizeof("BOOST") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BOOST_name, &const_BOOST_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BOOST_name);

	zval property_mBoost_default_value;
	ZVAL_UNDEF(&property_mBoost_default_value);
	zend_string *property_mBoost_name = zend_string_init("mBoost", sizeof("mBoost") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBoost_name, &property_mBoost_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mBoost_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_BQRStateData(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "BQRStateData", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mY1_default_value;
	ZVAL_UNDEF(&property_mY1_default_value);
	zend_string *property_mY1_name = zend_string_init("mY1", sizeof("mY1") - 1, 1);
	zend_declare_typed_property(class_entry, property_mY1_name, &property_mY1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mY1_name);

	zval property_mY2_default_value;
	ZVAL_UNDEF(&property_mY2_default_value);
	zend_string *property_mY2_name = zend_string_init("mY2", sizeof("mY2") - 1, 1);
	zend_declare_typed_property(class_entry, property_mY2_name, &property_mY2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mY2_name);

	zval property_mX1_default_value;
	ZVAL_UNDEF(&property_mX1_default_value);
	zend_string *property_mX1_name = zend_string_init("mX1", sizeof("mX1") - 1, 1);
	zend_declare_typed_property(class_entry, property_mX1_name, &property_mX1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mX1_name);

	zval property_mX2_default_value;
	ZVAL_UNDEF(&property_mX2_default_value);
	zend_string *property_mX2_name = zend_string_init("mX2", sizeof("mX2") - 1, 1);
	zend_declare_typed_property(class_entry, property_mX2_name, &property_mX2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mX2_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_BiquadResonantFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "BiquadResonantFilterInstance", class_SoLoud_BiquadResonantFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_BiquadResonantFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "BiquadResonantFilter", class_SoLoud_BiquadResonantFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_LOWPASS_value;
	ZVAL_LONG(&const_LOWPASS_value, SoLoud::BiquadResonantFilter::LOWPASS);
	zend_string *const_LOWPASS_name = zend_string_init_interned("LOWPASS", sizeof("LOWPASS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LOWPASS_name, &const_LOWPASS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LOWPASS_name);

	zval const_HIGHPASS_value;
	ZVAL_LONG(&const_HIGHPASS_value, SoLoud::BiquadResonantFilter::HIGHPASS);
	zend_string *const_HIGHPASS_name = zend_string_init_interned("HIGHPASS", sizeof("HIGHPASS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_HIGHPASS_name, &const_HIGHPASS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_HIGHPASS_name);

	zval const_BANDPASS_value;
	ZVAL_LONG(&const_BANDPASS_value, SoLoud::BiquadResonantFilter::BANDPASS);
	zend_string *const_BANDPASS_name = zend_string_init_interned("BANDPASS", sizeof("BANDPASS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BANDPASS_name, &const_BANDPASS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BANDPASS_name);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::BiquadResonantFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_TYPE_value;
	ZVAL_LONG(&const_TYPE_value, SoLoud::BiquadResonantFilter::TYPE);
	zend_string *const_TYPE_name = zend_string_init_interned("TYPE", sizeof("TYPE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_TYPE_name, &const_TYPE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_TYPE_name);

	zval const_FREQUENCY_value;
	ZVAL_LONG(&const_FREQUENCY_value, SoLoud::BiquadResonantFilter::FREQUENCY);
	zend_string *const_FREQUENCY_name = zend_string_init_interned("FREQUENCY", sizeof("FREQUENCY") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_FREQUENCY_name, &const_FREQUENCY_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_FREQUENCY_name);

	zval const_RESONANCE_value;
	ZVAL_LONG(&const_RESONANCE_value, SoLoud::BiquadResonantFilter::RESONANCE);
	zend_string *const_RESONANCE_name = zend_string_init_interned("RESONANCE", sizeof("RESONANCE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_RESONANCE_name, &const_RESONANCE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_RESONANCE_name);

	zval property_mFilterType_default_value;
	ZVAL_UNDEF(&property_mFilterType_default_value);
	zend_string *property_mFilterType_name = zend_string_init("mFilterType", sizeof("mFilterType") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFilterType_name, &property_mFilterType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFilterType_name);

	zval property_mFrequency_default_value;
	ZVAL_UNDEF(&property_mFrequency_default_value);
	zend_string *property_mFrequency_name = zend_string_init("mFrequency", sizeof("mFrequency") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFrequency_name, &property_mFrequency_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mFrequency_name);

	zval property_mResonance_default_value;
	ZVAL_UNDEF(&property_mResonance_default_value);
	zend_string *property_mResonance_name = zend_string_init("mResonance", sizeof("mResonance") - 1, 1);
	zend_declare_typed_property(class_entry, property_mResonance_name, &property_mResonance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mResonance_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_DCRemovalFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "DCRemovalFilterInstance", class_SoLoud_DCRemovalFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_DCRemovalFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "DCRemovalFilter", class_SoLoud_DCRemovalFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mLength_default_value;
	ZVAL_UNDEF(&property_mLength_default_value);
	zend_string *property_mLength_name = zend_string_init("mLength", sizeof("mLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLength_name, &property_mLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mLength_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_DuckFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "DuckFilterInstance", class_SoLoud_DuckFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_DuckFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "DuckFilter", class_SoLoud_DuckFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::DuckFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_ONRAMP_value;
	ZVAL_LONG(&const_ONRAMP_value, SoLoud::DuckFilter::ONRAMP);
	zend_string *const_ONRAMP_name = zend_string_init_interned("ONRAMP", sizeof("ONRAMP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_ONRAMP_name, &const_ONRAMP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_ONRAMP_name);

	zval const_OFFRAMP_value;
	ZVAL_LONG(&const_OFFRAMP_value, SoLoud::DuckFilter::OFFRAMP);
	zend_string *const_OFFRAMP_name = zend_string_init_interned("OFFRAMP", sizeof("OFFRAMP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_OFFRAMP_name, &const_OFFRAMP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_OFFRAMP_name);

	zval const_LEVEL_value;
	ZVAL_LONG(&const_LEVEL_value, SoLoud::DuckFilter::LEVEL);
	zend_string *const_LEVEL_name = zend_string_init_interned("LEVEL", sizeof("LEVEL") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LEVEL_name, &const_LEVEL_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LEVEL_name);

	zval property_mSoloud_default_value;
	ZVAL_UNDEF(&property_mSoloud_default_value);
	zend_string *property_mSoloud_name = zend_string_init("mSoloud", sizeof("mSoloud") - 1, 1);
	zend_string *property_mSoloud_class_SoLoud_Soloud = zend_string_init("SoLoud\\Soloud", sizeof("SoLoud\\Soloud")-1, 1);
	zend_declare_typed_property(class_entry, property_mSoloud_name, &property_mSoloud_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mSoloud_class_SoLoud_Soloud, 0, MAY_BE_NULL));
	zend_string_release(property_mSoloud_name);

	zval property_mOnRamp_default_value;
	ZVAL_UNDEF(&property_mOnRamp_default_value);
	zend_string *property_mOnRamp_name = zend_string_init("mOnRamp", sizeof("mOnRamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOnRamp_name, &property_mOnRamp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mOnRamp_name);

	zval property_mOffRamp_default_value;
	ZVAL_UNDEF(&property_mOffRamp_default_value);
	zend_string *property_mOffRamp_name = zend_string_init("mOffRamp", sizeof("mOffRamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOffRamp_name, &property_mOffRamp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mOffRamp_name);

	zval property_mLevel_default_value;
	ZVAL_UNDEF(&property_mLevel_default_value);
	zend_string *property_mLevel_name = zend_string_init("mLevel", sizeof("mLevel") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLevel_name, &property_mLevel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mLevel_name);

	zval property_mListenTo_default_value;
	ZVAL_UNDEF(&property_mListenTo_default_value);
	zend_string *property_mListenTo_name = zend_string_init("mListenTo", sizeof("mListenTo") - 1, 1);
	zend_declare_typed_property(class_entry, property_mListenTo_name, &property_mListenTo_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mListenTo_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_EchoFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "EchoFilterInstance", class_SoLoud_EchoFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_EchoFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "EchoFilter", class_SoLoud_EchoFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::EchoFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_DELAY_value;
	ZVAL_LONG(&const_DELAY_value, SoLoud::EchoFilter::DELAY);
	zend_string *const_DELAY_name = zend_string_init_interned("DELAY", sizeof("DELAY") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_DELAY_name, &const_DELAY_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_DELAY_name);

	zval const_DECAY_value;
	ZVAL_LONG(&const_DECAY_value, SoLoud::EchoFilter::DECAY);
	zend_string *const_DECAY_name = zend_string_init_interned("DECAY", sizeof("DECAY") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_DECAY_name, &const_DECAY_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_DECAY_name);

	zval const_FILTER_value;
	ZVAL_LONG(&const_FILTER_value, SoLoud::EchoFilter::FILTER);
	zend_string *const_FILTER_name = zend_string_init_interned("FILTER", sizeof("FILTER") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_FILTER_name, &const_FILTER_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_FILTER_name);

	zval property_mDelay_default_value;
	ZVAL_UNDEF(&property_mDelay_default_value);
	zend_string *property_mDelay_name = zend_string_init("mDelay", sizeof("mDelay") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDelay_name, &property_mDelay_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mDelay_name);

	zval property_mDecay_default_value;
	ZVAL_UNDEF(&property_mDecay_default_value);
	zend_string *property_mDecay_name = zend_string_init("mDecay", sizeof("mDecay") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDecay_name, &property_mDecay_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mDecay_name);

	zval property_mFilter_default_value;
	ZVAL_UNDEF(&property_mFilter_default_value);
	zend_string *property_mFilter_name = zend_string_init("mFilter", sizeof("mFilter") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFilter_name, &property_mFilter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mFilter_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_EqFilterInstance(zend_class_entry *class_entry_SoLoud_FFTFilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "EqFilterInstance", class_SoLoud_EqFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FFTFilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_EqFilter(zend_class_entry *class_entry_SoLoud_FFTFilter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "EqFilter", class_SoLoud_EqFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FFTFilter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::EqFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_BAND1_value;
	ZVAL_LONG(&const_BAND1_value, SoLoud::EqFilter::BAND1);
	zend_string *const_BAND1_name = zend_string_init_interned("BAND1", sizeof("BAND1") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND1_name, &const_BAND1_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND1_name);

	zval const_BAND2_value;
	ZVAL_LONG(&const_BAND2_value, SoLoud::EqFilter::BAND2);
	zend_string *const_BAND2_name = zend_string_init_interned("BAND2", sizeof("BAND2") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND2_name, &const_BAND2_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND2_name);

	zval const_BAND3_value;
	ZVAL_LONG(&const_BAND3_value, SoLoud::EqFilter::BAND3);
	zend_string *const_BAND3_name = zend_string_init_interned("BAND3", sizeof("BAND3") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND3_name, &const_BAND3_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND3_name);

	zval const_BAND4_value;
	ZVAL_LONG(&const_BAND4_value, SoLoud::EqFilter::BAND4);
	zend_string *const_BAND4_name = zend_string_init_interned("BAND4", sizeof("BAND4") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND4_name, &const_BAND4_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND4_name);

	zval const_BAND5_value;
	ZVAL_LONG(&const_BAND5_value, SoLoud::EqFilter::BAND5);
	zend_string *const_BAND5_name = zend_string_init_interned("BAND5", sizeof("BAND5") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND5_name, &const_BAND5_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND5_name);

	zval const_BAND6_value;
	ZVAL_LONG(&const_BAND6_value, SoLoud::EqFilter::BAND6);
	zend_string *const_BAND6_name = zend_string_init_interned("BAND6", sizeof("BAND6") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND6_name, &const_BAND6_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND6_name);

	zval const_BAND7_value;
	ZVAL_LONG(&const_BAND7_value, SoLoud::EqFilter::BAND7);
	zend_string *const_BAND7_name = zend_string_init_interned("BAND7", sizeof("BAND7") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND7_name, &const_BAND7_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND7_name);

	zval const_BAND8_value;
	ZVAL_LONG(&const_BAND8_value, SoLoud::EqFilter::BAND8);
	zend_string *const_BAND8_name = zend_string_init_interned("BAND8", sizeof("BAND8") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BAND8_name, &const_BAND8_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BAND8_name);

	zval property_mVolume_default_value;
	ZVAL_UNDEF(&property_mVolume_default_value);
	zend_string *property_mVolume_name = zend_string_init("mVolume", sizeof("mVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVolume_name, &property_mVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mVolume_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_FlangerFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "FlangerFilterInstance", class_SoLoud_FlangerFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_FlangerFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "FlangerFilter", class_SoLoud_FlangerFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::FlangerFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_DELAY_value;
	ZVAL_LONG(&const_DELAY_value, SoLoud::FlangerFilter::DELAY);
	zend_string *const_DELAY_name = zend_string_init_interned("DELAY", sizeof("DELAY") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_DELAY_name, &const_DELAY_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_DELAY_name);

	zval const_FREQ_value;
	ZVAL_LONG(&const_FREQ_value, SoLoud::FlangerFilter::FREQ);
	zend_string *const_FREQ_name = zend_string_init_interned("FREQ", sizeof("FREQ") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_FREQ_name, &const_FREQ_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_FREQ_name);

	zval property_mDelay_default_value;
	ZVAL_UNDEF(&property_mDelay_default_value);
	zend_string *property_mDelay_name = zend_string_init("mDelay", sizeof("mDelay") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDelay_name, &property_mDelay_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mDelay_name);

	zval property_mFreq_default_value;
	ZVAL_UNDEF(&property_mFreq_default_value);
	zend_string *property_mFreq_name = zend_string_init("mFreq", sizeof("mFreq") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFreq_name, &property_mFreq_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mFreq_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_FreeverbFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "FreeverbFilterInstance", class_SoLoud_FreeverbFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_FreeverbFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "FreeverbFilter", class_SoLoud_FreeverbFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::FreeverbFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_FREEZE_value;
	ZVAL_LONG(&const_FREEZE_value, SoLoud::FreeverbFilter::FREEZE);
	zend_string *const_FREEZE_name = zend_string_init_interned("FREEZE", sizeof("FREEZE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_FREEZE_name, &const_FREEZE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_FREEZE_name);

	zval const_ROOMSIZE_value;
	ZVAL_LONG(&const_ROOMSIZE_value, SoLoud::FreeverbFilter::ROOMSIZE);
	zend_string *const_ROOMSIZE_name = zend_string_init_interned("ROOMSIZE", sizeof("ROOMSIZE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_ROOMSIZE_name, &const_ROOMSIZE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_ROOMSIZE_name);

	zval const_DAMP_value;
	ZVAL_LONG(&const_DAMP_value, SoLoud::FreeverbFilter::DAMP);
	zend_string *const_DAMP_name = zend_string_init_interned("DAMP", sizeof("DAMP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_DAMP_name, &const_DAMP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_DAMP_name);

	zval const_WIDTH_value;
	ZVAL_LONG(&const_WIDTH_value, SoLoud::FreeverbFilter::WIDTH);
	zend_string *const_WIDTH_name = zend_string_init_interned("WIDTH", sizeof("WIDTH") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WIDTH_name, &const_WIDTH_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WIDTH_name);

	zval property_mMode_default_value;
	ZVAL_UNDEF(&property_mMode_default_value);
	zend_string *property_mMode_name = zend_string_init("mMode", sizeof("mMode") - 1, 1);
	zend_declare_typed_property(class_entry, property_mMode_name, &property_mMode_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mMode_name);

	zval property_mRoomSize_default_value;
	ZVAL_UNDEF(&property_mRoomSize_default_value);
	zend_string *property_mRoomSize_name = zend_string_init("mRoomSize", sizeof("mRoomSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_mRoomSize_name, &property_mRoomSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mRoomSize_name);

	zval property_mDamp_default_value;
	ZVAL_UNDEF(&property_mDamp_default_value);
	zend_string *property_mDamp_name = zend_string_init("mDamp", sizeof("mDamp") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDamp_name, &property_mDamp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mDamp_name);

	zval property_mWidth_default_value;
	ZVAL_UNDEF(&property_mWidth_default_value);
	zend_string *property_mWidth_name = zend_string_init("mWidth", sizeof("mWidth") - 1, 1);
	zend_declare_typed_property(class_entry, property_mWidth_name, &property_mWidth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mWidth_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_LofiChannelData(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "LofiChannelData", class_SoLoud_LofiChannelData_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mSample_default_value;
	ZVAL_UNDEF(&property_mSample_default_value);
	zend_string *property_mSample_name = zend_string_init("mSample", sizeof("mSample") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSample_name, &property_mSample_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSample_name);

	zval property_mSamplesToSkip_default_value;
	ZVAL_UNDEF(&property_mSamplesToSkip_default_value);
	zend_string *property_mSamplesToSkip_name = zend_string_init("mSamplesToSkip", sizeof("mSamplesToSkip") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSamplesToSkip_name, &property_mSamplesToSkip_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSamplesToSkip_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_LofiFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "LofiFilterInstance", class_SoLoud_LofiFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_LofiFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "LofiFilter", class_SoLoud_LofiFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::LofiFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_SAMPLERATE_value;
	ZVAL_LONG(&const_SAMPLERATE_value, SoLoud::LofiFilter::SAMPLERATE);
	zend_string *const_SAMPLERATE_name = zend_string_init_interned("SAMPLERATE", sizeof("SAMPLERATE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_SAMPLERATE_name, &const_SAMPLERATE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_SAMPLERATE_name);

	zval const_BITDEPTH_value;
	ZVAL_LONG(&const_BITDEPTH_value, SoLoud::LofiFilter::BITDEPTH);
	zend_string *const_BITDEPTH_name = zend_string_init_interned("BITDEPTH", sizeof("BITDEPTH") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BITDEPTH_name, &const_BITDEPTH_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BITDEPTH_name);

	zval property_mSampleRate_default_value;
	ZVAL_UNDEF(&property_mSampleRate_default_value);
	zend_string *property_mSampleRate_name = zend_string_init("mSampleRate", sizeof("mSampleRate") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSampleRate_name, &property_mSampleRate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSampleRate_name);

	zval property_mBitdepth_default_value;
	ZVAL_UNDEF(&property_mBitdepth_default_value);
	zend_string *property_mBitdepth_name = zend_string_init("mBitdepth", sizeof("mBitdepth") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBitdepth_name, &property_mBitdepth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mBitdepth_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_RobotizeFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "RobotizeFilterInstance", class_SoLoud_RobotizeFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_RobotizeFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "RobotizeFilter", class_SoLoud_RobotizeFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::RobotizeFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_FREQ_value;
	ZVAL_LONG(&const_FREQ_value, SoLoud::RobotizeFilter::FREQ);
	zend_string *const_FREQ_name = zend_string_init_interned("FREQ", sizeof("FREQ") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_FREQ_name, &const_FREQ_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_FREQ_name);

	zval const_WAVE_value;
	ZVAL_LONG(&const_WAVE_value, SoLoud::RobotizeFilter::WAVE);
	zend_string *const_WAVE_name = zend_string_init_interned("WAVE", sizeof("WAVE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_name, &const_WAVE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_name);

	zval property_mFreq_default_value;
	ZVAL_UNDEF(&property_mFreq_default_value);
	zend_string *property_mFreq_name = zend_string_init("mFreq", sizeof("mFreq") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFreq_name, &property_mFreq_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mFreq_name);

	zval property_mWave_default_value;
	ZVAL_UNDEF(&property_mWave_default_value);
	zend_string *property_mWave_name = zend_string_init("mWave", sizeof("mWave") - 1, 1);
	zend_declare_typed_property(class_entry, property_mWave_name, &property_mWave_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mWave_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_WaveShaperFilterInstance(zend_class_entry *class_entry_SoLoud_FilterInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "WaveShaperFilterInstance", class_SoLoud_WaveShaperFilterInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_FilterInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_WaveShaperFilter(zend_class_entry *class_entry_SoLoud_Filter)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "WaveShaperFilter", class_SoLoud_WaveShaperFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_Filter, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WET_value;
	ZVAL_LONG(&const_WET_value, SoLoud::WaveShaperFilter::WET);
	zend_string *const_WET_name = zend_string_init_interned("WET", sizeof("WET") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WET_name, &const_WET_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WET_name);

	zval const_AMOUNT_value;
	ZVAL_LONG(&const_AMOUNT_value, SoLoud::WaveShaperFilter::AMOUNT);
	zend_string *const_AMOUNT_name = zend_string_init_interned("AMOUNT", sizeof("AMOUNT") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_AMOUNT_name, &const_AMOUNT_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_AMOUNT_name);

	zval property_mAmount_default_value;
	ZVAL_UNDEF(&property_mAmount_default_value);
	zend_string *property_mAmount_name = zend_string_init("mAmount", sizeof("mAmount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mAmount_name, &property_mAmount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mAmount_name);

	return class_entry;
}
