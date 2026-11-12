/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b10a197c169a811a5db279719dae17a3496ed6e4 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_BusInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Bus, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_BusInstance_hasEnded, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_Bus___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_Bus_createInstance, 0, 0, SoLoud\\BusInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_setFilter, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aFilterId, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aFilter, SoLoud\\Filter, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_play, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPan, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPaused, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_playClocked, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSoundTime, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPan, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_play3d, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelX, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelY, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelZ, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPaused, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_play3dClocked, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSoundTime, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelX, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelY, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelZ, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "1.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_setChannels, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aChannels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_setVisualizationEnable, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_annexSound, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_calcFFT, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Bus_getWave arginfo_class_SoLoud_Bus_calcFFT

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_getApproximateVolume, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_getActiveVoiceCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Bus_getResampler arginfo_class_SoLoud_Bus_getActiveVoiceCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_setResampler, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aResampler, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Bus_findBusHandle, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_QueueInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Queue, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_QueueInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_Queue___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_Queue_createInstance, 0, 0, SoLoud\\QueueInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Queue_play, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Queue_getQueueCount arginfo_class_SoLoud_Bus_getActiveVoiceCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Queue_isCurrentlyPlaying, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Queue_setParamsFromAudioSource arginfo_class_SoLoud_Queue_play

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Queue_setParams, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSamplerate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aChannels, IS_LONG, 0, "2")
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Queue_findQueueHandle arginfo_class_SoLoud_Bus_findBusHandle

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_SpeechInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Speech, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_SpeechInstance_rewind arginfo_class_SoLoud_Bus_getActiveVoiceCount

#define arginfo_class_SoLoud_SpeechInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_Speech___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Speech_setText, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aText, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Speech_setParams, 0, 0, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBaseFrequency, IS_LONG, 0, "1330")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBaseSpeed, IS_DOUBLE, 0, "10.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBaseDeclination, IS_DOUBLE, 0, "0.5")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBaseWaveform, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_Speech_createInstance, 0, 0, SoLoud\\AudioSourceInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_SfxrParams___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, wave_type, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_base_freq, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_freq_limit, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_freq_ramp, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_freq_dramp, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_duty, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_duty_ramp, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_vib_strength, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_vib_speed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_vib_delay, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_env_attack, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_env_sustain, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_env_decay, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_env_punch, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter_on, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_lpf_resonance, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_lpf_freq, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_lpf_ramp, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_hpf_freq, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_hpf_ramp, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_pha_offset, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_pha_ramp, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_repeat_speed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_arp_speed, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, p_arp_mod, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, master_vol, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sound_vol, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_SfxrInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Sfxr, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_SfxrInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_Sfxr___construct arginfo_class_SoLoud_Bus___construct

#define arginfo_class_SoLoud_Sfxr_resetParams arginfo_class_SoLoud_Bus_findBusHandle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Sfxr_loadParams, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFilename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Sfxr_loadParamsMem, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aMem, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, aLength, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aCopy, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aTakeOwnership, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Sfxr_loadParamsFile, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aFile, SoLoud\\File, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Sfxr_loadPreset, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aPresetNo, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aRandSeed, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Sfxr_createInstance arginfo_class_SoLoud_Speech_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_NoiseInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\\116oise, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_NoiseInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_Noise___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Noise_setOctaveScale, 0, 10, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aOct0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct4, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct5, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct6, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct7, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct8, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aOct9, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Noise_setType, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aType, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Noise_createInstance arginfo_class_SoLoud_Speech_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_MonotoneChannel___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mEnabled, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mActive, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mPortamento, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mArpCounter, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mArp, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mLastNote, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mPortamentoToNote, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mVibrato, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mVibratoIndex, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mVibratoDepth, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mVibratoSpeed, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_MonotoneHardwareChannel___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mEnabled, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mSamplePos, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mSamplePosInc, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_MonotoneSong___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mVersion, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mTotalPatterns, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mTotalTracks, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mCellSize, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_MonotoneInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Monotone, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_MonotoneInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_Monotone___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Monotone_setParams, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aHardwareChannels, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aWaveform, IS_LONG, 0, "SoLoud\\Soloud::WAVE_SQUARE")
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Monotone_load arginfo_class_SoLoud_Sfxr_loadParams

#define arginfo_class_SoLoud_Monotone_loadMem arginfo_class_SoLoud_Sfxr_loadParamsMem

#define arginfo_class_SoLoud_Monotone_loadFile arginfo_class_SoLoud_Sfxr_loadParamsFile

#define arginfo_class_SoLoud_Monotone_createInstance arginfo_class_SoLoud_Speech_createInstance

#define arginfo_class_SoLoud_Monotone_clear arginfo_class_SoLoud_Bus_findBusHandle

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_TedSidInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\TedSid, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_TedSidInstance_tick arginfo_class_SoLoud_Bus_findBusHandle

#define arginfo_class_SoLoud_TedSidInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_TedSidInstance_getInfo, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aInfoKey, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_TedSid___construct arginfo_class_SoLoud_Bus___construct

#define arginfo_class_SoLoud_TedSid_load arginfo_class_SoLoud_Sfxr_loadParams

#define arginfo_class_SoLoud_TedSid_loadMem arginfo_class_SoLoud_Sfxr_loadParamsMem

#define arginfo_class_SoLoud_TedSid_loadFile arginfo_class_SoLoud_Sfxr_loadParamsFile

#define arginfo_class_SoLoud_TedSid_createInstance arginfo_class_SoLoud_Speech_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_VicInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Vic, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_VicInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_Vic___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Vic_setModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Vic_getModel arginfo_class_SoLoud_Bus_getActiveVoiceCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Vic_setRegister, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, reg, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Vic_getRegister, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reg, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Vic_createInstance arginfo_class_SoLoud_Speech_createInstance

#define arginfo_class_SoLoud_VizsnResonator___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_VizsnResonator_resonate, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, i, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_VizsnResonator_antiresonate arginfo_class_SoLoud_VizsnResonator_resonate

#define arginfo_class_SoLoud_VizsnBank___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_VizsnInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Vizsn, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_VizsnInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_VizsnInstance_vcsrc, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPitch, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoicetype, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_VizsnInstance_noisrc, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_VizsnInstance_genwave arginfo_class_SoLoud_VizsnInstance_noisrc

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_VizsnInstance_setphone, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, aB, SoLoud\\VizsnBank, 1)
	ZEND_ARG_TYPE_INFO(0, aP, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aPitch, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_VizsnInstance_slidePrepare, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aNumtix, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_VizsnInstance_slideTick arginfo_class_SoLoud_Bus_findBusHandle

#define arginfo_class_SoLoud_Vizsn___construct arginfo_class_SoLoud_Bus___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Vizsn_setText, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aText, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Vizsn_createInstance arginfo_class_SoLoud_Speech_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_AyInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Ay, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_AyInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_AyInstance_rewind arginfo_class_SoLoud_Bus_getActiveVoiceCount

#define arginfo_class_SoLoud_AyInstance_getInfo arginfo_class_SoLoud_TedSidInstance_getInfo

#define arginfo_class_SoLoud_Ay___construct arginfo_class_SoLoud_Bus___construct

#define arginfo_class_SoLoud_Ay_load arginfo_class_SoLoud_Sfxr_loadParams

#define arginfo_class_SoLoud_Ay_loadFile arginfo_class_SoLoud_Sfxr_loadParamsFile

#define arginfo_class_SoLoud_Ay_loadMem arginfo_class_SoLoud_Sfxr_loadParamsMem

#define arginfo_class_SoLoud_Ay_createInstance arginfo_class_SoLoud_Speech_createInstance

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_OpenmptInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Openmpt, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_OpenmptInstance_hasEnded arginfo_class_SoLoud_BusInstance_hasEnded

#define arginfo_class_SoLoud_Openmpt___construct arginfo_class_SoLoud_Bus___construct

#define arginfo_class_SoLoud_Openmpt_load arginfo_class_SoLoud_Sfxr_loadParams

#define arginfo_class_SoLoud_Openmpt_loadMem arginfo_class_SoLoud_Sfxr_loadParamsMem

#define arginfo_class_SoLoud_Openmpt_loadFile arginfo_class_SoLoud_Sfxr_loadParamsFile

#define arginfo_class_SoLoud_Openmpt_createInstance arginfo_class_SoLoud_Speech_createInstance

ZEND_METHOD(SoLoud_BusInstance, __construct);
ZEND_METHOD(SoLoud_BusInstance, hasEnded);
ZEND_METHOD(SoLoud_Bus, __construct);
ZEND_METHOD(SoLoud_Bus, createInstance);
ZEND_METHOD(SoLoud_Bus, setFilter);
ZEND_METHOD(SoLoud_Bus, play);
ZEND_METHOD(SoLoud_Bus, playClocked);
ZEND_METHOD(SoLoud_Bus, play3d);
ZEND_METHOD(SoLoud_Bus, play3dClocked);
ZEND_METHOD(SoLoud_Bus, setChannels);
ZEND_METHOD(SoLoud_Bus, setVisualizationEnable);
ZEND_METHOD(SoLoud_Bus, annexSound);
ZEND_METHOD(SoLoud_Bus, calcFFT);
ZEND_METHOD(SoLoud_Bus, getWave);
ZEND_METHOD(SoLoud_Bus, getApproximateVolume);
ZEND_METHOD(SoLoud_Bus, getActiveVoiceCount);
ZEND_METHOD(SoLoud_Bus, getResampler);
ZEND_METHOD(SoLoud_Bus, setResampler);
ZEND_METHOD(SoLoud_Bus, findBusHandle);
ZEND_METHOD(SoLoud_QueueInstance, __construct);
ZEND_METHOD(SoLoud_QueueInstance, hasEnded);
ZEND_METHOD(SoLoud_Queue, __construct);
ZEND_METHOD(SoLoud_Queue, createInstance);
ZEND_METHOD(SoLoud_Queue, play);
ZEND_METHOD(SoLoud_Queue, getQueueCount);
ZEND_METHOD(SoLoud_Queue, isCurrentlyPlaying);
ZEND_METHOD(SoLoud_Queue, setParamsFromAudioSource);
ZEND_METHOD(SoLoud_Queue, setParams);
ZEND_METHOD(SoLoud_Queue, findQueueHandle);
ZEND_METHOD(SoLoud_SpeechInstance, __construct);
ZEND_METHOD(SoLoud_SpeechInstance, rewind);
ZEND_METHOD(SoLoud_SpeechInstance, hasEnded);
ZEND_METHOD(SoLoud_Speech, __construct);
ZEND_METHOD(SoLoud_Speech, setText);
ZEND_METHOD(SoLoud_Speech, setParams);
ZEND_METHOD(SoLoud_Speech, createInstance);
ZEND_METHOD(SoLoud_SfxrParams, __construct);
ZEND_METHOD(SoLoud_SfxrInstance, __construct);
ZEND_METHOD(SoLoud_SfxrInstance, hasEnded);
ZEND_METHOD(SoLoud_Sfxr, __construct);
ZEND_METHOD(SoLoud_Sfxr, resetParams);
ZEND_METHOD(SoLoud_Sfxr, loadParams);
ZEND_METHOD(SoLoud_Sfxr, loadParamsMem);
ZEND_METHOD(SoLoud_Sfxr, loadParamsFile);
ZEND_METHOD(SoLoud_Sfxr, loadPreset);
ZEND_METHOD(SoLoud_Sfxr, createInstance);
ZEND_METHOD(SoLoud_NoiseInstance, __construct);
ZEND_METHOD(SoLoud_NoiseInstance, hasEnded);
ZEND_METHOD(SoLoud_Noise, __construct);
ZEND_METHOD(SoLoud_Noise, setOctaveScale);
ZEND_METHOD(SoLoud_Noise, setType);
ZEND_METHOD(SoLoud_Noise, createInstance);
ZEND_METHOD(SoLoud_MonotoneChannel, __construct);
ZEND_METHOD(SoLoud_MonotoneHardwareChannel, __construct);
ZEND_METHOD(SoLoud_MonotoneSong, __construct);
ZEND_METHOD(SoLoud_MonotoneInstance, __construct);
ZEND_METHOD(SoLoud_MonotoneInstance, hasEnded);
ZEND_METHOD(SoLoud_Monotone, __construct);
ZEND_METHOD(SoLoud_Monotone, setParams);
ZEND_METHOD(SoLoud_Monotone, load);
ZEND_METHOD(SoLoud_Monotone, loadMem);
ZEND_METHOD(SoLoud_Monotone, loadFile);
ZEND_METHOD(SoLoud_Monotone, createInstance);
ZEND_METHOD(SoLoud_Monotone, clear);
ZEND_METHOD(SoLoud_TedSidInstance, __construct);
ZEND_METHOD(SoLoud_TedSidInstance, tick);
ZEND_METHOD(SoLoud_TedSidInstance, hasEnded);
ZEND_METHOD(SoLoud_TedSidInstance, getInfo);
ZEND_METHOD(SoLoud_TedSid, __construct);
ZEND_METHOD(SoLoud_TedSid, load);
ZEND_METHOD(SoLoud_TedSid, loadMem);
ZEND_METHOD(SoLoud_TedSid, loadFile);
ZEND_METHOD(SoLoud_TedSid, createInstance);
ZEND_METHOD(SoLoud_VicInstance, __construct);
ZEND_METHOD(SoLoud_VicInstance, hasEnded);
ZEND_METHOD(SoLoud_Vic, __construct);
ZEND_METHOD(SoLoud_Vic, setModel);
ZEND_METHOD(SoLoud_Vic, getModel);
ZEND_METHOD(SoLoud_Vic, setRegister);
ZEND_METHOD(SoLoud_Vic, getRegister);
ZEND_METHOD(SoLoud_Vic, createInstance);
ZEND_METHOD(SoLoud_VizsnResonator, __construct);
ZEND_METHOD(SoLoud_VizsnResonator, resonate);
ZEND_METHOD(SoLoud_VizsnResonator, antiresonate);
ZEND_METHOD(SoLoud_VizsnBank, __construct);
ZEND_METHOD(SoLoud_VizsnInstance, __construct);
ZEND_METHOD(SoLoud_VizsnInstance, hasEnded);
ZEND_METHOD(SoLoud_VizsnInstance, vcsrc);
ZEND_METHOD(SoLoud_VizsnInstance, noisrc);
ZEND_METHOD(SoLoud_VizsnInstance, genwave);
ZEND_METHOD(SoLoud_VizsnInstance, setphone);
ZEND_METHOD(SoLoud_VizsnInstance, slidePrepare);
ZEND_METHOD(SoLoud_VizsnInstance, slideTick);
ZEND_METHOD(SoLoud_Vizsn, __construct);
ZEND_METHOD(SoLoud_Vizsn, setText);
ZEND_METHOD(SoLoud_Vizsn, createInstance);
ZEND_METHOD(SoLoud_AyInstance, __construct);
ZEND_METHOD(SoLoud_AyInstance, hasEnded);
ZEND_METHOD(SoLoud_AyInstance, rewind);
ZEND_METHOD(SoLoud_AyInstance, getInfo);
ZEND_METHOD(SoLoud_Ay, __construct);
ZEND_METHOD(SoLoud_Ay, load);
ZEND_METHOD(SoLoud_Ay, loadFile);
ZEND_METHOD(SoLoud_Ay, loadMem);
ZEND_METHOD(SoLoud_Ay, createInstance);
ZEND_METHOD(SoLoud_OpenmptInstance, __construct);
ZEND_METHOD(SoLoud_OpenmptInstance, hasEnded);
ZEND_METHOD(SoLoud_Openmpt, __construct);
ZEND_METHOD(SoLoud_Openmpt, load);
ZEND_METHOD(SoLoud_Openmpt, loadMem);
ZEND_METHOD(SoLoud_Openmpt, loadFile);
ZEND_METHOD(SoLoud_Openmpt, createInstance);

static const zend_function_entry class_SoLoud_BusInstance_methods[] = {
	ZEND_ME(SoLoud_BusInstance, __construct, arginfo_class_SoLoud_BusInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_BusInstance, hasEnded, arginfo_class_SoLoud_BusInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Bus_methods[] = {
	ZEND_ME(SoLoud_Bus, __construct, arginfo_class_SoLoud_Bus___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, createInstance, arginfo_class_SoLoud_Bus_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, setFilter, arginfo_class_SoLoud_Bus_setFilter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, play, arginfo_class_SoLoud_Bus_play, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, playClocked, arginfo_class_SoLoud_Bus_playClocked, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, play3d, arginfo_class_SoLoud_Bus_play3d, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, play3dClocked, arginfo_class_SoLoud_Bus_play3dClocked, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, setChannels, arginfo_class_SoLoud_Bus_setChannels, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, setVisualizationEnable, arginfo_class_SoLoud_Bus_setVisualizationEnable, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, annexSound, arginfo_class_SoLoud_Bus_annexSound, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, calcFFT, arginfo_class_SoLoud_Bus_calcFFT, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, getWave, arginfo_class_SoLoud_Bus_getWave, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, getApproximateVolume, arginfo_class_SoLoud_Bus_getApproximateVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, getActiveVoiceCount, arginfo_class_SoLoud_Bus_getActiveVoiceCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, getResampler, arginfo_class_SoLoud_Bus_getResampler, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, setResampler, arginfo_class_SoLoud_Bus_setResampler, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Bus, findBusHandle, arginfo_class_SoLoud_Bus_findBusHandle, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_QueueInstance_methods[] = {
	ZEND_ME(SoLoud_QueueInstance, __construct, arginfo_class_SoLoud_QueueInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_QueueInstance, hasEnded, arginfo_class_SoLoud_QueueInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Queue_methods[] = {
	ZEND_ME(SoLoud_Queue, __construct, arginfo_class_SoLoud_Queue___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Queue, createInstance, arginfo_class_SoLoud_Queue_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Queue, play, arginfo_class_SoLoud_Queue_play, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Queue, getQueueCount, arginfo_class_SoLoud_Queue_getQueueCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Queue, isCurrentlyPlaying, arginfo_class_SoLoud_Queue_isCurrentlyPlaying, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Queue, setParamsFromAudioSource, arginfo_class_SoLoud_Queue_setParamsFromAudioSource, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Queue, setParams, arginfo_class_SoLoud_Queue_setParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Queue, findQueueHandle, arginfo_class_SoLoud_Queue_findQueueHandle, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_SpeechInstance_methods[] = {
	ZEND_ME(SoLoud_SpeechInstance, __construct, arginfo_class_SoLoud_SpeechInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_SpeechInstance, rewind, arginfo_class_SoLoud_SpeechInstance_rewind, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_SpeechInstance, hasEnded, arginfo_class_SoLoud_SpeechInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Speech_methods[] = {
	ZEND_ME(SoLoud_Speech, __construct, arginfo_class_SoLoud_Speech___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Speech, setText, arginfo_class_SoLoud_Speech_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Speech, setParams, arginfo_class_SoLoud_Speech_setParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Speech, createInstance, arginfo_class_SoLoud_Speech_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_SfxrParams_methods[] = {
	ZEND_ME(SoLoud_SfxrParams, __construct, arginfo_class_SoLoud_SfxrParams___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_SfxrInstance_methods[] = {
	ZEND_ME(SoLoud_SfxrInstance, __construct, arginfo_class_SoLoud_SfxrInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_SfxrInstance, hasEnded, arginfo_class_SoLoud_SfxrInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Sfxr_methods[] = {
	ZEND_ME(SoLoud_Sfxr, __construct, arginfo_class_SoLoud_Sfxr___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Sfxr, resetParams, arginfo_class_SoLoud_Sfxr_resetParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Sfxr, loadParams, arginfo_class_SoLoud_Sfxr_loadParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Sfxr, loadParamsMem, arginfo_class_SoLoud_Sfxr_loadParamsMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Sfxr, loadParamsFile, arginfo_class_SoLoud_Sfxr_loadParamsFile, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Sfxr, loadPreset, arginfo_class_SoLoud_Sfxr_loadPreset, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Sfxr, createInstance, arginfo_class_SoLoud_Sfxr_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_NoiseInstance_methods[] = {
	ZEND_ME(SoLoud_NoiseInstance, __construct, arginfo_class_SoLoud_NoiseInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_NoiseInstance, hasEnded, arginfo_class_SoLoud_NoiseInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Noise_methods[] = {
	ZEND_ME(SoLoud_Noise, __construct, arginfo_class_SoLoud_Noise___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Noise, setOctaveScale, arginfo_class_SoLoud_Noise_setOctaveScale, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Noise, setType, arginfo_class_SoLoud_Noise_setType, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Noise, createInstance, arginfo_class_SoLoud_Noise_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_MonotoneChannel_methods[] = {
	ZEND_ME(SoLoud_MonotoneChannel, __construct, arginfo_class_SoLoud_MonotoneChannel___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_MonotoneHardwareChannel_methods[] = {
	ZEND_ME(SoLoud_MonotoneHardwareChannel, __construct, arginfo_class_SoLoud_MonotoneHardwareChannel___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_MonotoneSong_methods[] = {
	ZEND_ME(SoLoud_MonotoneSong, __construct, arginfo_class_SoLoud_MonotoneSong___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_MonotoneInstance_methods[] = {
	ZEND_ME(SoLoud_MonotoneInstance, __construct, arginfo_class_SoLoud_MonotoneInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_MonotoneInstance, hasEnded, arginfo_class_SoLoud_MonotoneInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Monotone_methods[] = {
	ZEND_ME(SoLoud_Monotone, __construct, arginfo_class_SoLoud_Monotone___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Monotone, setParams, arginfo_class_SoLoud_Monotone_setParams, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Monotone, load, arginfo_class_SoLoud_Monotone_load, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Monotone, loadMem, arginfo_class_SoLoud_Monotone_loadMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Monotone, loadFile, arginfo_class_SoLoud_Monotone_loadFile, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Monotone, createInstance, arginfo_class_SoLoud_Monotone_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Monotone, clear, arginfo_class_SoLoud_Monotone_clear, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_TedSidInstance_methods[] = {
	ZEND_ME(SoLoud_TedSidInstance, __construct, arginfo_class_SoLoud_TedSidInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_TedSidInstance, tick, arginfo_class_SoLoud_TedSidInstance_tick, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_TedSidInstance, hasEnded, arginfo_class_SoLoud_TedSidInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_TedSidInstance, getInfo, arginfo_class_SoLoud_TedSidInstance_getInfo, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_TedSid_methods[] = {
	ZEND_ME(SoLoud_TedSid, __construct, arginfo_class_SoLoud_TedSid___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_TedSid, load, arginfo_class_SoLoud_TedSid_load, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_TedSid, loadMem, arginfo_class_SoLoud_TedSid_loadMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_TedSid, loadFile, arginfo_class_SoLoud_TedSid_loadFile, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_TedSid, createInstance, arginfo_class_SoLoud_TedSid_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_VicInstance_methods[] = {
	ZEND_ME(SoLoud_VicInstance, __construct, arginfo_class_SoLoud_VicInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VicInstance, hasEnded, arginfo_class_SoLoud_VicInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Vic_methods[] = {
	ZEND_ME(SoLoud_Vic, __construct, arginfo_class_SoLoud_Vic___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Vic, setModel, arginfo_class_SoLoud_Vic_setModel, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Vic, getModel, arginfo_class_SoLoud_Vic_getModel, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Vic, setRegister, arginfo_class_SoLoud_Vic_setRegister, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Vic, getRegister, arginfo_class_SoLoud_Vic_getRegister, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Vic, createInstance, arginfo_class_SoLoud_Vic_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_VizsnResonator_methods[] = {
	ZEND_ME(SoLoud_VizsnResonator, __construct, arginfo_class_SoLoud_VizsnResonator___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnResonator, resonate, arginfo_class_SoLoud_VizsnResonator_resonate, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnResonator, antiresonate, arginfo_class_SoLoud_VizsnResonator_antiresonate, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_VizsnBank_methods[] = {
	ZEND_ME(SoLoud_VizsnBank, __construct, arginfo_class_SoLoud_VizsnBank___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_VizsnInstance_methods[] = {
	ZEND_ME(SoLoud_VizsnInstance, __construct, arginfo_class_SoLoud_VizsnInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnInstance, hasEnded, arginfo_class_SoLoud_VizsnInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnInstance, vcsrc, arginfo_class_SoLoud_VizsnInstance_vcsrc, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnInstance, noisrc, arginfo_class_SoLoud_VizsnInstance_noisrc, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnInstance, genwave, arginfo_class_SoLoud_VizsnInstance_genwave, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnInstance, setphone, arginfo_class_SoLoud_VizsnInstance_setphone, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnInstance, slidePrepare, arginfo_class_SoLoud_VizsnInstance_slidePrepare, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_VizsnInstance, slideTick, arginfo_class_SoLoud_VizsnInstance_slideTick, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Vizsn_methods[] = {
	ZEND_ME(SoLoud_Vizsn, __construct, arginfo_class_SoLoud_Vizsn___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Vizsn, setText, arginfo_class_SoLoud_Vizsn_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Vizsn, createInstance, arginfo_class_SoLoud_Vizsn_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_AyInstance_methods[] = {
	ZEND_ME(SoLoud_AyInstance, __construct, arginfo_class_SoLoud_AyInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AyInstance, hasEnded, arginfo_class_SoLoud_AyInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AyInstance, rewind, arginfo_class_SoLoud_AyInstance_rewind, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AyInstance, getInfo, arginfo_class_SoLoud_AyInstance_getInfo, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Ay_methods[] = {
	ZEND_ME(SoLoud_Ay, __construct, arginfo_class_SoLoud_Ay___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Ay, load, arginfo_class_SoLoud_Ay_load, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Ay, loadFile, arginfo_class_SoLoud_Ay_loadFile, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Ay, loadMem, arginfo_class_SoLoud_Ay_loadMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Ay, createInstance, arginfo_class_SoLoud_Ay_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_OpenmptInstance_methods[] = {
	ZEND_ME(SoLoud_OpenmptInstance, __construct, arginfo_class_SoLoud_OpenmptInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_OpenmptInstance, hasEnded, arginfo_class_SoLoud_OpenmptInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Openmpt_methods[] = {
	ZEND_ME(SoLoud_Openmpt, __construct, arginfo_class_SoLoud_Openmpt___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Openmpt, load, arginfo_class_SoLoud_Openmpt_load, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Openmpt, loadMem, arginfo_class_SoLoud_Openmpt_loadMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Openmpt, loadFile, arginfo_class_SoLoud_Openmpt_loadFile, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Openmpt, createInstance, arginfo_class_SoLoud_Openmpt_createInstance, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_SoLoud_BusInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "BusInstance", class_SoLoud_BusInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mParent_default_value;
	ZVAL_UNDEF(&property_mParent_default_value);
	zend_string *property_mParent_name = zend_string_init("mParent", sizeof("mParent") - 1, 1);
	zend_string *property_mParent_class_SoLoud_Bus = zend_string_init("SoLoud\\Bus", sizeof("SoLoud\\Bus")-1, 1);
	zend_declare_typed_property(class_entry, property_mParent_name, &property_mParent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mParent_class_SoLoud_Bus, 0, MAY_BE_NULL));
	zend_string_release(property_mParent_name);

	zval property_mScratchSize_default_value;
	ZVAL_UNDEF(&property_mScratchSize_default_value);
	zend_string *property_mScratchSize_name = zend_string_init("mScratchSize", sizeof("mScratchSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_mScratchSize_name, &property_mScratchSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mScratchSize_name);

	zval property_mScratch_default_value;
	ZVAL_UNDEF(&property_mScratch_default_value);
	zend_string *property_mScratch_name = zend_string_init("mScratch", sizeof("mScratch") - 1, 1);
	zend_string *property_mScratch_class_SoLoud_AlignedFloatBuffer = zend_string_init("SoLoud\\AlignedFloatBuffer", sizeof("SoLoud\\AlignedFloatBuffer")-1, 1);
	zend_declare_typed_property(class_entry, property_mScratch_name, &property_mScratch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mScratch_class_SoLoud_AlignedFloatBuffer, 0, 0));
	zend_string_release(property_mScratch_name);

	zval property_mVisualizationChannelVolume_default_value;
	ZVAL_UNDEF(&property_mVisualizationChannelVolume_default_value);
	zend_string *property_mVisualizationChannelVolume_name = zend_string_init("mVisualizationChannelVolume", sizeof("mVisualizationChannelVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVisualizationChannelVolume_name, &property_mVisualizationChannelVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mVisualizationChannelVolume_name);

	zval property_mVisualizationWaveData_default_value;
	ZVAL_UNDEF(&property_mVisualizationWaveData_default_value);
	zend_string *property_mVisualizationWaveData_name = zend_string_init("mVisualizationWaveData", sizeof("mVisualizationWaveData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVisualizationWaveData_name, &property_mVisualizationWaveData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mVisualizationWaveData_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Bus(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Bus", class_SoLoud_Bus_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mInstance_default_value;
	ZVAL_UNDEF(&property_mInstance_default_value);
	zend_string *property_mInstance_name = zend_string_init("mInstance", sizeof("mInstance") - 1, 1);
	zend_string *property_mInstance_class_SoLoud_BusInstance = zend_string_init("SoLoud\\BusInstance", sizeof("SoLoud\\BusInstance")-1, 1);
	zend_declare_typed_property(class_entry, property_mInstance_name, &property_mInstance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mInstance_class_SoLoud_BusInstance, 0, MAY_BE_NULL));
	zend_string_release(property_mInstance_name);

	zval property_mChannelHandle_default_value;
	ZVAL_UNDEF(&property_mChannelHandle_default_value);
	zend_string *property_mChannelHandle_name = zend_string_init("mChannelHandle", sizeof("mChannelHandle") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannelHandle_name, &property_mChannelHandle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mChannelHandle_name);

	zval property_mResampler_default_value;
	ZVAL_UNDEF(&property_mResampler_default_value);
	zend_string *property_mResampler_name = zend_string_init("mResampler", sizeof("mResampler") - 1, 1);
	zend_declare_typed_property(class_entry, property_mResampler_name, &property_mResampler_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mResampler_name);

	zval property_mFFTData_default_value;
	ZVAL_UNDEF(&property_mFFTData_default_value);
	zend_string *property_mFFTData_name = zend_string_init("mFFTData", sizeof("mFFTData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFFTData_name, &property_mFFTData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mFFTData_name);

	zval property_mWaveData_default_value;
	ZVAL_UNDEF(&property_mWaveData_default_value);
	zend_string *property_mWaveData_name = zend_string_init("mWaveData", sizeof("mWaveData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mWaveData_name, &property_mWaveData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mWaveData_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_QueueInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "QueueInstance", class_SoLoud_QueueInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Queue(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Queue", class_SoLoud_Queue_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mReadIndex_default_value;
	ZVAL_UNDEF(&property_mReadIndex_default_value);
	zend_string *property_mReadIndex_name = zend_string_init("mReadIndex", sizeof("mReadIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mReadIndex_name, &property_mReadIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mReadIndex_name);

	zval property_mWriteIndex_default_value;
	ZVAL_UNDEF(&property_mWriteIndex_default_value);
	zend_string *property_mWriteIndex_name = zend_string_init("mWriteIndex", sizeof("mWriteIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mWriteIndex_name, &property_mWriteIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mWriteIndex_name);

	zval property_mCount_default_value;
	ZVAL_UNDEF(&property_mCount_default_value);
	zend_string *property_mCount_name = zend_string_init("mCount", sizeof("mCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mCount_name, &property_mCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mCount_name);

	zval property_mSource_default_value;
	ZVAL_UNDEF(&property_mSource_default_value);
	zend_string *property_mSource_name = zend_string_init("mSource", sizeof("mSource") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSource_name, &property_mSource_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mSource_name);

	zval property_mInstance_default_value;
	ZVAL_UNDEF(&property_mInstance_default_value);
	zend_string *property_mInstance_name = zend_string_init("mInstance", sizeof("mInstance") - 1, 1);
	zend_string *property_mInstance_class_SoLoud_QueueInstance = zend_string_init("SoLoud\\QueueInstance", sizeof("SoLoud\\QueueInstance")-1, 1);
	zend_declare_typed_property(class_entry, property_mInstance_name, &property_mInstance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mInstance_class_SoLoud_QueueInstance, 0, MAY_BE_NULL));
	zend_string_release(property_mInstance_name);

	zval property_mQueueHandle_default_value;
	ZVAL_UNDEF(&property_mQueueHandle_default_value);
	zend_string *property_mQueueHandle_name = zend_string_init("mQueueHandle", sizeof("mQueueHandle") - 1, 1);
	zend_declare_typed_property(class_entry, property_mQueueHandle_name, &property_mQueueHandle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mQueueHandle_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_SpeechInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "SpeechInstance", class_SoLoud_SpeechInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Speech(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Speech", class_SoLoud_Speech_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mBaseFrequency_default_value;
	ZVAL_UNDEF(&property_mBaseFrequency_default_value);
	zend_string *property_mBaseFrequency_name = zend_string_init("mBaseFrequency", sizeof("mBaseFrequency") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBaseFrequency_name, &property_mBaseFrequency_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBaseFrequency_name);

	zval property_mBaseSpeed_default_value;
	ZVAL_UNDEF(&property_mBaseSpeed_default_value);
	zend_string *property_mBaseSpeed_name = zend_string_init("mBaseSpeed", sizeof("mBaseSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBaseSpeed_name, &property_mBaseSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mBaseSpeed_name);

	zval property_mBaseDeclination_default_value;
	ZVAL_UNDEF(&property_mBaseDeclination_default_value);
	zend_string *property_mBaseDeclination_name = zend_string_init("mBaseDeclination", sizeof("mBaseDeclination") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBaseDeclination_name, &property_mBaseDeclination_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mBaseDeclination_name);

	zval property_mBaseWaveform_default_value;
	ZVAL_UNDEF(&property_mBaseWaveform_default_value);
	zend_string *property_mBaseWaveform_name = zend_string_init("mBaseWaveform", sizeof("mBaseWaveform") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBaseWaveform_name, &property_mBaseWaveform_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBaseWaveform_name);

	zval property_mFrames_default_value;
	ZVAL_UNDEF(&property_mFrames_default_value);
	zend_string *property_mFrames_name = zend_string_init("mFrames", sizeof("mFrames") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFrames_name, &property_mFrames_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFrames_name);

	zval property_mElement_default_value;
	ZVAL_UNDEF(&property_mElement_default_value);
	zend_string *property_mElement_name = zend_string_init("mElement", sizeof("mElement") - 1, 1);
	zend_declare_typed_property(class_entry, property_mElement_name, &property_mElement_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mElement_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_SfxrParams(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "SfxrParams", class_SoLoud_SfxrParams_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_wave_type_default_value;
	ZVAL_UNDEF(&property_wave_type_default_value);
	zend_string *property_wave_type_name = zend_string_init("wave_type", sizeof("wave_type") - 1, 1);
	zend_declare_typed_property(class_entry, property_wave_type_name, &property_wave_type_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_wave_type_name);

	zval property_p_base_freq_default_value;
	ZVAL_UNDEF(&property_p_base_freq_default_value);
	zend_string *property_p_base_freq_name = zend_string_init("p_base_freq", sizeof("p_base_freq") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_base_freq_name, &property_p_base_freq_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_base_freq_name);

	zval property_p_freq_limit_default_value;
	ZVAL_UNDEF(&property_p_freq_limit_default_value);
	zend_string *property_p_freq_limit_name = zend_string_init("p_freq_limit", sizeof("p_freq_limit") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_freq_limit_name, &property_p_freq_limit_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_freq_limit_name);

	zval property_p_freq_ramp_default_value;
	ZVAL_UNDEF(&property_p_freq_ramp_default_value);
	zend_string *property_p_freq_ramp_name = zend_string_init("p_freq_ramp", sizeof("p_freq_ramp") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_freq_ramp_name, &property_p_freq_ramp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_freq_ramp_name);

	zval property_p_freq_dramp_default_value;
	ZVAL_UNDEF(&property_p_freq_dramp_default_value);
	zend_string *property_p_freq_dramp_name = zend_string_init("p_freq_dramp", sizeof("p_freq_dramp") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_freq_dramp_name, &property_p_freq_dramp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_freq_dramp_name);

	zval property_p_duty_default_value;
	ZVAL_UNDEF(&property_p_duty_default_value);
	zend_string *property_p_duty_name = zend_string_init("p_duty", sizeof("p_duty") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_duty_name, &property_p_duty_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_duty_name);

	zval property_p_duty_ramp_default_value;
	ZVAL_UNDEF(&property_p_duty_ramp_default_value);
	zend_string *property_p_duty_ramp_name = zend_string_init("p_duty_ramp", sizeof("p_duty_ramp") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_duty_ramp_name, &property_p_duty_ramp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_duty_ramp_name);

	zval property_p_vib_strength_default_value;
	ZVAL_UNDEF(&property_p_vib_strength_default_value);
	zend_string *property_p_vib_strength_name = zend_string_init("p_vib_strength", sizeof("p_vib_strength") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_vib_strength_name, &property_p_vib_strength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_vib_strength_name);

	zval property_p_vib_speed_default_value;
	ZVAL_UNDEF(&property_p_vib_speed_default_value);
	zend_string *property_p_vib_speed_name = zend_string_init("p_vib_speed", sizeof("p_vib_speed") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_vib_speed_name, &property_p_vib_speed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_vib_speed_name);

	zval property_p_vib_delay_default_value;
	ZVAL_UNDEF(&property_p_vib_delay_default_value);
	zend_string *property_p_vib_delay_name = zend_string_init("p_vib_delay", sizeof("p_vib_delay") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_vib_delay_name, &property_p_vib_delay_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_vib_delay_name);

	zval property_p_env_attack_default_value;
	ZVAL_UNDEF(&property_p_env_attack_default_value);
	zend_string *property_p_env_attack_name = zend_string_init("p_env_attack", sizeof("p_env_attack") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_env_attack_name, &property_p_env_attack_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_env_attack_name);

	zval property_p_env_sustain_default_value;
	ZVAL_UNDEF(&property_p_env_sustain_default_value);
	zend_string *property_p_env_sustain_name = zend_string_init("p_env_sustain", sizeof("p_env_sustain") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_env_sustain_name, &property_p_env_sustain_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_env_sustain_name);

	zval property_p_env_decay_default_value;
	ZVAL_UNDEF(&property_p_env_decay_default_value);
	zend_string *property_p_env_decay_name = zend_string_init("p_env_decay", sizeof("p_env_decay") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_env_decay_name, &property_p_env_decay_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_env_decay_name);

	zval property_p_env_punch_default_value;
	ZVAL_UNDEF(&property_p_env_punch_default_value);
	zend_string *property_p_env_punch_name = zend_string_init("p_env_punch", sizeof("p_env_punch") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_env_punch_name, &property_p_env_punch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_env_punch_name);

	zval property_filter_on_default_value;
	ZVAL_UNDEF(&property_filter_on_default_value);
	zend_string *property_filter_on_name = zend_string_init("filter_on", sizeof("filter_on") - 1, 1);
	zend_declare_typed_property(class_entry, property_filter_on_name, &property_filter_on_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_filter_on_name);

	zval property_p_lpf_resonance_default_value;
	ZVAL_UNDEF(&property_p_lpf_resonance_default_value);
	zend_string *property_p_lpf_resonance_name = zend_string_init("p_lpf_resonance", sizeof("p_lpf_resonance") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_lpf_resonance_name, &property_p_lpf_resonance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_lpf_resonance_name);

	zval property_p_lpf_freq_default_value;
	ZVAL_UNDEF(&property_p_lpf_freq_default_value);
	zend_string *property_p_lpf_freq_name = zend_string_init("p_lpf_freq", sizeof("p_lpf_freq") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_lpf_freq_name, &property_p_lpf_freq_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_lpf_freq_name);

	zval property_p_lpf_ramp_default_value;
	ZVAL_UNDEF(&property_p_lpf_ramp_default_value);
	zend_string *property_p_lpf_ramp_name = zend_string_init("p_lpf_ramp", sizeof("p_lpf_ramp") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_lpf_ramp_name, &property_p_lpf_ramp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_lpf_ramp_name);

	zval property_p_hpf_freq_default_value;
	ZVAL_UNDEF(&property_p_hpf_freq_default_value);
	zend_string *property_p_hpf_freq_name = zend_string_init("p_hpf_freq", sizeof("p_hpf_freq") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_hpf_freq_name, &property_p_hpf_freq_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_hpf_freq_name);

	zval property_p_hpf_ramp_default_value;
	ZVAL_UNDEF(&property_p_hpf_ramp_default_value);
	zend_string *property_p_hpf_ramp_name = zend_string_init("p_hpf_ramp", sizeof("p_hpf_ramp") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_hpf_ramp_name, &property_p_hpf_ramp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_hpf_ramp_name);

	zval property_p_pha_offset_default_value;
	ZVAL_UNDEF(&property_p_pha_offset_default_value);
	zend_string *property_p_pha_offset_name = zend_string_init("p_pha_offset", sizeof("p_pha_offset") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_pha_offset_name, &property_p_pha_offset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_pha_offset_name);

	zval property_p_pha_ramp_default_value;
	ZVAL_UNDEF(&property_p_pha_ramp_default_value);
	zend_string *property_p_pha_ramp_name = zend_string_init("p_pha_ramp", sizeof("p_pha_ramp") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_pha_ramp_name, &property_p_pha_ramp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_pha_ramp_name);

	zval property_p_repeat_speed_default_value;
	ZVAL_UNDEF(&property_p_repeat_speed_default_value);
	zend_string *property_p_repeat_speed_name = zend_string_init("p_repeat_speed", sizeof("p_repeat_speed") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_repeat_speed_name, &property_p_repeat_speed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_repeat_speed_name);

	zval property_p_arp_speed_default_value;
	ZVAL_UNDEF(&property_p_arp_speed_default_value);
	zend_string *property_p_arp_speed_name = zend_string_init("p_arp_speed", sizeof("p_arp_speed") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_arp_speed_name, &property_p_arp_speed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_arp_speed_name);

	zval property_p_arp_mod_default_value;
	ZVAL_UNDEF(&property_p_arp_mod_default_value);
	zend_string *property_p_arp_mod_name = zend_string_init("p_arp_mod", sizeof("p_arp_mod") - 1, 1);
	zend_declare_typed_property(class_entry, property_p_arp_mod_name, &property_p_arp_mod_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p_arp_mod_name);

	zval property_master_vol_default_value;
	ZVAL_UNDEF(&property_master_vol_default_value);
	zend_string *property_master_vol_name = zend_string_init("master_vol", sizeof("master_vol") - 1, 1);
	zend_declare_typed_property(class_entry, property_master_vol_name, &property_master_vol_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_master_vol_name);

	zval property_sound_vol_default_value;
	ZVAL_UNDEF(&property_sound_vol_default_value);
	zend_string *property_sound_vol_name = zend_string_init("sound_vol", sizeof("sound_vol") - 1, 1);
	zend_declare_typed_property(class_entry, property_sound_vol_name, &property_sound_vol_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_sound_vol_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_SfxrInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "SfxrInstance", class_SoLoud_SfxrInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Sfxr(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Sfxr", class_SoLoud_Sfxr_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_COIN_value;
	ZVAL_LONG(&const_COIN_value, SoLoud::Sfxr::COIN);
	zend_string *const_COIN_name = zend_string_init_interned("COIN", sizeof("COIN") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_COIN_name, &const_COIN_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_COIN_name);

	zval const_LASER_value;
	ZVAL_LONG(&const_LASER_value, SoLoud::Sfxr::LASER);
	zend_string *const_LASER_name = zend_string_init_interned("LASER", sizeof("LASER") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LASER_name, &const_LASER_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LASER_name);

	zval const_EXPLOSION_value;
	ZVAL_LONG(&const_EXPLOSION_value, SoLoud::Sfxr::EXPLOSION);
	zend_string *const_EXPLOSION_name = zend_string_init_interned("EXPLOSION", sizeof("EXPLOSION") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_EXPLOSION_name, &const_EXPLOSION_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_EXPLOSION_name);

	zval const_POWERUP_value;
	ZVAL_LONG(&const_POWERUP_value, SoLoud::Sfxr::POWERUP);
	zend_string *const_POWERUP_name = zend_string_init_interned("POWERUP", sizeof("POWERUP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_POWERUP_name, &const_POWERUP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_POWERUP_name);

	zval const_HURT_value;
	ZVAL_LONG(&const_HURT_value, SoLoud::Sfxr::HURT);
	zend_string *const_HURT_name = zend_string_init_interned("HURT", sizeof("HURT") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_HURT_name, &const_HURT_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_HURT_name);

	zval const_JUMP_value;
	ZVAL_LONG(&const_JUMP_value, SoLoud::Sfxr::JUMP);
	zend_string *const_JUMP_name = zend_string_init_interned("JUMP", sizeof("JUMP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_JUMP_name, &const_JUMP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_JUMP_name);

	zval const_BLIP_value;
	ZVAL_LONG(&const_BLIP_value, SoLoud::Sfxr::BLIP);
	zend_string *const_BLIP_name = zend_string_init_interned("BLIP", sizeof("BLIP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BLIP_name, &const_BLIP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BLIP_name);

	zval property_mParams_default_value;
	ZVAL_UNDEF(&property_mParams_default_value);
	zend_string *property_mParams_name = zend_string_init("mParams", sizeof("mParams") - 1, 1);
	zend_string *property_mParams_class_SoLoud_SfxrParams = zend_string_init("SoLoud\\SfxrParams", sizeof("SoLoud\\SfxrParams")-1, 1);
	zend_declare_typed_property(class_entry, property_mParams_name, &property_mParams_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mParams_class_SoLoud_SfxrParams, 0, 0));
	zend_string_release(property_mParams_name);

	zval property_mRand_default_value;
	ZVAL_UNDEF(&property_mRand_default_value);
	zend_string *property_mRand_name = zend_string_init("mRand", sizeof("mRand") - 1, 1);
	zend_string *property_mRand_class_SoLoud_Misc_Prg = zend_string_init("SoLoud\\Misc\\Prg", sizeof("SoLoud\\Misc\\Prg")-1, 1);
	zend_declare_typed_property(class_entry, property_mRand_name, &property_mRand_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mRand_class_SoLoud_Misc_Prg, 0, 0));
	zend_string_release(property_mRand_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_NoiseInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "NoiseInstance", class_SoLoud_NoiseInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mOctaveScale_default_value;
	ZVAL_UNDEF(&property_mOctaveScale_default_value);
	zend_string *property_mOctaveScale_name = zend_string_init("mOctaveScale", sizeof("mOctaveScale") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOctaveScale_name, &property_mOctaveScale_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mOctaveScale_name);

	zval property_mPrg_default_value;
	ZVAL_UNDEF(&property_mPrg_default_value);
	zend_string *property_mPrg_name = zend_string_init("mPrg", sizeof("mPrg") - 1, 1);
	zend_string *property_mPrg_class_SoLoud_Misc_Prg = zend_string_init("SoLoud\\Misc\\Prg", sizeof("SoLoud\\Misc\\Prg")-1, 1);
	zend_declare_typed_property(class_entry, property_mPrg_name, &property_mPrg_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mPrg_class_SoLoud_Misc_Prg, 0, 0));
	zend_string_release(property_mPrg_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Noise(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Noise", class_SoLoud_Noise_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_WHITE_value;
	ZVAL_LONG(&const_WHITE_value, SoLoud::Noise::WHITE);
	zend_string *const_WHITE_name = zend_string_init_interned("WHITE", sizeof("WHITE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WHITE_name, &const_WHITE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WHITE_name);

	zval const_PINK_value;
	ZVAL_LONG(&const_PINK_value, SoLoud::Noise::PINK);
	zend_string *const_PINK_name = zend_string_init_interned("PINK", sizeof("PINK") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PINK_name, &const_PINK_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PINK_name);

	zval const_BROWNISH_value;
	ZVAL_LONG(&const_BROWNISH_value, SoLoud::Noise::BROWNISH);
	zend_string *const_BROWNISH_name = zend_string_init_interned("BROWNISH", sizeof("BROWNISH") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BROWNISH_name, &const_BROWNISH_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BROWNISH_name);

	zval const_BLUEISH_value;
	ZVAL_LONG(&const_BLUEISH_value, SoLoud::Noise::BLUEISH);
	zend_string *const_BLUEISH_name = zend_string_init_interned("BLUEISH", sizeof("BLUEISH") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BLUEISH_name, &const_BLUEISH_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BLUEISH_name);

	zval property_mOctaveScale_default_value;
	ZVAL_UNDEF(&property_mOctaveScale_default_value);
	zend_string *property_mOctaveScale_name = zend_string_init("mOctaveScale", sizeof("mOctaveScale") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOctaveScale_name, &property_mOctaveScale_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mOctaveScale_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_MonotoneChannel(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "MonotoneChannel", class_SoLoud_MonotoneChannel_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mEnabled_default_value;
	ZVAL_UNDEF(&property_mEnabled_default_value);
	zend_string *property_mEnabled_name = zend_string_init("mEnabled", sizeof("mEnabled") - 1, 1);
	zend_declare_typed_property(class_entry, property_mEnabled_name, &property_mEnabled_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mEnabled_name);

	zval property_mActive_default_value;
	ZVAL_UNDEF(&property_mActive_default_value);
	zend_string *property_mActive_name = zend_string_init("mActive", sizeof("mActive") - 1, 1);
	zend_declare_typed_property(class_entry, property_mActive_name, &property_mActive_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mActive_name);

	zval property_mFreq_default_value;
	ZVAL_UNDEF(&property_mFreq_default_value);
	zend_string *property_mFreq_name = zend_string_init("mFreq", sizeof("mFreq") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFreq_name, &property_mFreq_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mFreq_name);

	zval property_mPortamento_default_value;
	ZVAL_UNDEF(&property_mPortamento_default_value);
	zend_string *property_mPortamento_name = zend_string_init("mPortamento", sizeof("mPortamento") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPortamento_name, &property_mPortamento_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mPortamento_name);

	zval property_mArpCounter_default_value;
	ZVAL_UNDEF(&property_mArpCounter_default_value);
	zend_string *property_mArpCounter_name = zend_string_init("mArpCounter", sizeof("mArpCounter") - 1, 1);
	zend_declare_typed_property(class_entry, property_mArpCounter_name, &property_mArpCounter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mArpCounter_name);

	zval property_mArp_default_value;
	ZVAL_UNDEF(&property_mArp_default_value);
	zend_string *property_mArp_name = zend_string_init("mArp", sizeof("mArp") - 1, 1);
	zend_declare_typed_property(class_entry, property_mArp_name, &property_mArp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mArp_name);

	zval property_mLastNote_default_value;
	ZVAL_UNDEF(&property_mLastNote_default_value);
	zend_string *property_mLastNote_name = zend_string_init("mLastNote", sizeof("mLastNote") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLastNote_name, &property_mLastNote_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mLastNote_name);

	zval property_mPortamentoToNote_default_value;
	ZVAL_UNDEF(&property_mPortamentoToNote_default_value);
	zend_string *property_mPortamentoToNote_name = zend_string_init("mPortamentoToNote", sizeof("mPortamentoToNote") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPortamentoToNote_name, &property_mPortamentoToNote_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mPortamentoToNote_name);

	zval property_mVibrato_default_value;
	ZVAL_UNDEF(&property_mVibrato_default_value);
	zend_string *property_mVibrato_name = zend_string_init("mVibrato", sizeof("mVibrato") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVibrato_name, &property_mVibrato_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mVibrato_name);

	zval property_mVibratoIndex_default_value;
	ZVAL_UNDEF(&property_mVibratoIndex_default_value);
	zend_string *property_mVibratoIndex_name = zend_string_init("mVibratoIndex", sizeof("mVibratoIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVibratoIndex_name, &property_mVibratoIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mVibratoIndex_name);

	zval property_mVibratoDepth_default_value;
	ZVAL_UNDEF(&property_mVibratoDepth_default_value);
	zend_string *property_mVibratoDepth_name = zend_string_init("mVibratoDepth", sizeof("mVibratoDepth") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVibratoDepth_name, &property_mVibratoDepth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mVibratoDepth_name);

	zval property_mVibratoSpeed_default_value;
	ZVAL_UNDEF(&property_mVibratoSpeed_default_value);
	zend_string *property_mVibratoSpeed_name = zend_string_init("mVibratoSpeed", sizeof("mVibratoSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVibratoSpeed_name, &property_mVibratoSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mVibratoSpeed_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_MonotoneHardwareChannel(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "MonotoneHardwareChannel", class_SoLoud_MonotoneHardwareChannel_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mEnabled_default_value;
	ZVAL_UNDEF(&property_mEnabled_default_value);
	zend_string *property_mEnabled_name = zend_string_init("mEnabled", sizeof("mEnabled") - 1, 1);
	zend_declare_typed_property(class_entry, property_mEnabled_name, &property_mEnabled_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mEnabled_name);

	zval property_mSamplePos_default_value;
	ZVAL_UNDEF(&property_mSamplePos_default_value);
	zend_string *property_mSamplePos_name = zend_string_init("mSamplePos", sizeof("mSamplePos") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSamplePos_name, &property_mSamplePos_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSamplePos_name);

	zval property_mSamplePosInc_default_value;
	ZVAL_UNDEF(&property_mSamplePosInc_default_value);
	zend_string *property_mSamplePosInc_name = zend_string_init("mSamplePosInc", sizeof("mSamplePosInc") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSamplePosInc_name, &property_mSamplePosInc_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSamplePosInc_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_MonotoneSong(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "MonotoneSong", class_SoLoud_MonotoneSong_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mTitle_default_value;
	ZVAL_UNDEF(&property_mTitle_default_value);
	zend_string *property_mTitle_name = zend_string_init("mTitle", sizeof("mTitle") - 1, 1);
	zend_declare_typed_property(class_entry, property_mTitle_name, &property_mTitle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_mTitle_name);

	zval property_mComment_default_value;
	ZVAL_UNDEF(&property_mComment_default_value);
	zend_string *property_mComment_name = zend_string_init("mComment", sizeof("mComment") - 1, 1);
	zend_declare_typed_property(class_entry, property_mComment_name, &property_mComment_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_mComment_name);

	zval property_mVersion_default_value;
	ZVAL_UNDEF(&property_mVersion_default_value);
	zend_string *property_mVersion_name = zend_string_init("mVersion", sizeof("mVersion") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVersion_name, &property_mVersion_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mVersion_name);

	zval property_mTotalPatterns_default_value;
	ZVAL_UNDEF(&property_mTotalPatterns_default_value);
	zend_string *property_mTotalPatterns_name = zend_string_init("mTotalPatterns", sizeof("mTotalPatterns") - 1, 1);
	zend_declare_typed_property(class_entry, property_mTotalPatterns_name, &property_mTotalPatterns_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mTotalPatterns_name);

	zval property_mTotalTracks_default_value;
	ZVAL_UNDEF(&property_mTotalTracks_default_value);
	zend_string *property_mTotalTracks_name = zend_string_init("mTotalTracks", sizeof("mTotalTracks") - 1, 1);
	zend_declare_typed_property(class_entry, property_mTotalTracks_name, &property_mTotalTracks_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mTotalTracks_name);

	zval property_mCellSize_default_value;
	ZVAL_UNDEF(&property_mCellSize_default_value);
	zend_string *property_mCellSize_name = zend_string_init("mCellSize", sizeof("mCellSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_mCellSize_name, &property_mCellSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mCellSize_name);

	zval property_mOrder_default_value;
	ZVAL_UNDEF(&property_mOrder_default_value);
	zend_string *property_mOrder_name = zend_string_init("mOrder", sizeof("mOrder") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOrder_name, &property_mOrder_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mOrder_name);

	zval property_mPatternData_default_value;
	ZVAL_UNDEF(&property_mPatternData_default_value);
	zend_string *property_mPatternData_name = zend_string_init("mPatternData", sizeof("mPatternData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPatternData_name, &property_mPatternData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mPatternData_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_MonotoneInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "MonotoneInstance", class_SoLoud_MonotoneInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mChannel_default_value;
	ZVAL_UNDEF(&property_mChannel_default_value);
	zend_string *property_mChannel_name = zend_string_init("mChannel", sizeof("mChannel") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannel_name, &property_mChannel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mChannel_name);

	zval property_mOutput_default_value;
	ZVAL_UNDEF(&property_mOutput_default_value);
	zend_string *property_mOutput_name = zend_string_init("mOutput", sizeof("mOutput") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOutput_name, &property_mOutput_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mOutput_name);

	zval property_mNextChannel_default_value;
	ZVAL_UNDEF(&property_mNextChannel_default_value);
	zend_string *property_mNextChannel_name = zend_string_init("mNextChannel", sizeof("mNextChannel") - 1, 1);
	zend_declare_typed_property(class_entry, property_mNextChannel_name, &property_mNextChannel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mNextChannel_name);

	zval property_mTempo_default_value;
	ZVAL_UNDEF(&property_mTempo_default_value);
	zend_string *property_mTempo_name = zend_string_init("mTempo", sizeof("mTempo") - 1, 1);
	zend_declare_typed_property(class_entry, property_mTempo_name, &property_mTempo_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mTempo_name);

	zval property_mOrder_default_value;
	ZVAL_UNDEF(&property_mOrder_default_value);
	zend_string *property_mOrder_name = zend_string_init("mOrder", sizeof("mOrder") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOrder_name, &property_mOrder_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mOrder_name);

	zval property_mRow_default_value;
	ZVAL_UNDEF(&property_mRow_default_value);
	zend_string *property_mRow_name = zend_string_init("mRow", sizeof("mRow") - 1, 1);
	zend_declare_typed_property(class_entry, property_mRow_name, &property_mRow_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mRow_name);

	zval property_mSampleCount_default_value;
	ZVAL_UNDEF(&property_mSampleCount_default_value);
	zend_string *property_mSampleCount_name = zend_string_init("mSampleCount", sizeof("mSampleCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSampleCount_name, &property_mSampleCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mSampleCount_name);

	zval property_mRowTick_default_value;
	ZVAL_UNDEF(&property_mRowTick_default_value);
	zend_string *property_mRowTick_name = zend_string_init("mRowTick", sizeof("mRowTick") - 1, 1);
	zend_declare_typed_property(class_entry, property_mRowTick_name, &property_mRowTick_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mRowTick_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Monotone(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Monotone", class_SoLoud_Monotone_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mNotesHz_default_value;
	ZVAL_UNDEF(&property_mNotesHz_default_value);
	zend_string *property_mNotesHz_name = zend_string_init("mNotesHz", sizeof("mNotesHz") - 1, 1);
	zend_declare_typed_property(class_entry, property_mNotesHz_name, &property_mNotesHz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mNotesHz_name);

	zval property_mVibTable_default_value;
	ZVAL_UNDEF(&property_mVibTable_default_value);
	zend_string *property_mVibTable_name = zend_string_init("mVibTable", sizeof("mVibTable") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVibTable_name, &property_mVibTable_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mVibTable_name);

	zval property_mHardwareChannels_default_value;
	ZVAL_UNDEF(&property_mHardwareChannels_default_value);
	zend_string *property_mHardwareChannels_name = zend_string_init("mHardwareChannels", sizeof("mHardwareChannels") - 1, 1);
	zend_declare_typed_property(class_entry, property_mHardwareChannels_name, &property_mHardwareChannels_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mHardwareChannels_name);

	zval property_mWaveform_default_value;
	ZVAL_UNDEF(&property_mWaveform_default_value);
	zend_string *property_mWaveform_name = zend_string_init("mWaveform", sizeof("mWaveform") - 1, 1);
	zend_declare_typed_property(class_entry, property_mWaveform_name, &property_mWaveform_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mWaveform_name);

	zval property_mSong_default_value;
	ZVAL_UNDEF(&property_mSong_default_value);
	zend_string *property_mSong_name = zend_string_init("mSong", sizeof("mSong") - 1, 1);
	zend_string *property_mSong_class_SoLoud_MonotoneSong = zend_string_init("SoLoud\\MonotoneSong", sizeof("SoLoud\\MonotoneSong")-1, 1);
	zend_declare_typed_property(class_entry, property_mSong_name, &property_mSong_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mSong_class_SoLoud_MonotoneSong, 0, 0));
	zend_string_release(property_mSong_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_TedSidInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "TedSidInstance", class_SoLoud_TedSidInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_TedSid(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "TedSid", class_SoLoud_TedSid_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mLooppos_default_value;
	ZVAL_UNDEF(&property_mLooppos_default_value);
	zend_string *property_mLooppos_name = zend_string_init("mLooppos", sizeof("mLooppos") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLooppos_name, &property_mLooppos_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mLooppos_name);

	zval property_mLength_default_value;
	ZVAL_UNDEF(&property_mLength_default_value);
	zend_string *property_mLength_name = zend_string_init("mLength", sizeof("mLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLength_name, &property_mLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mLength_name);

	zval property_mOps_default_value;
	ZVAL_UNDEF(&property_mOps_default_value);
	zend_string *property_mOps_name = zend_string_init("mOps", sizeof("mOps") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOps_name, &property_mOps_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mOps_name);

	zval property_mModel_default_value;
	ZVAL_UNDEF(&property_mModel_default_value);
	zend_string *property_mModel_name = zend_string_init("mModel", sizeof("mModel") - 1, 1);
	zend_declare_typed_property(class_entry, property_mModel_name, &property_mModel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mModel_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_VicInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "VicInstance", class_SoLoud_VicInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_m_parent_default_value;
	ZVAL_UNDEF(&property_m_parent_default_value);
	zend_string *property_m_parent_name = zend_string_init("m_parent", sizeof("m_parent") - 1, 1);
	zend_string *property_m_parent_class_SoLoud_Vic = zend_string_init("SoLoud\\Vic", sizeof("SoLoud\\Vic")-1, 1);
	zend_declare_typed_property(class_entry, property_m_parent_name, &property_m_parent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_m_parent_class_SoLoud_Vic, 0, MAY_BE_NULL));
	zend_string_release(property_m_parent_name);

	zval property_m_phase_default_value;
	ZVAL_UNDEF(&property_m_phase_default_value);
	zend_string *property_m_phase_name = zend_string_init("m_phase", sizeof("m_phase") - 1, 1);
	zend_declare_typed_property(class_entry, property_m_phase_name, &property_m_phase_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_m_phase_name);

	zval property_m_noisePos_default_value;
	ZVAL_UNDEF(&property_m_noisePos_default_value);
	zend_string *property_m_noisePos_name = zend_string_init("m_noisePos", sizeof("m_noisePos") - 1, 1);
	zend_declare_typed_property(class_entry, property_m_noisePos_name, &property_m_noisePos_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_m_noisePos_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Vic(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Vic", class_SoLoud_Vic_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_PAL_value;
	ZVAL_LONG(&const_PAL_value, SoLoud::Vic::PAL);
	zend_string *const_PAL_name = zend_string_init_interned("PAL", sizeof("PAL") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PAL_name, &const_PAL_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PAL_name);

	zval const_NTSC_value;
	ZVAL_LONG(&const_NTSC_value, SoLoud::Vic::NTSC);
	zend_string *const_NTSC_name = zend_string_init_interned("NTSC", sizeof("NTSC") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_NTSC_name, &const_NTSC_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_NTSC_name);

	zval const_BASS_value;
	ZVAL_LONG(&const_BASS_value, SoLoud::Vic::BASS);
	zend_string *const_BASS_name = zend_string_init_interned("BASS", sizeof("BASS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BASS_name, &const_BASS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BASS_name);

	zval const_ALTO_value;
	ZVAL_LONG(&const_ALTO_value, SoLoud::Vic::ALTO);
	zend_string *const_ALTO_name = zend_string_init_interned("ALTO", sizeof("ALTO") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_ALTO_name, &const_ALTO_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_ALTO_name);

	zval const_SOPRANO_value;
	ZVAL_LONG(&const_SOPRANO_value, SoLoud::Vic::SOPRANO);
	zend_string *const_SOPRANO_name = zend_string_init_interned("SOPRANO", sizeof("SOPRANO") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_SOPRANO_name, &const_SOPRANO_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_SOPRANO_name);

	zval const_NOISE_value;
	ZVAL_LONG(&const_NOISE_value, SoLoud::Vic::NOISE);
	zend_string *const_NOISE_name = zend_string_init_interned("NOISE", sizeof("NOISE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_NOISE_name, &const_NOISE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_NOISE_name);

	zval const_MAX_REGS_value;
	ZVAL_LONG(&const_MAX_REGS_value, SoLoud::Vic::MAX_REGS);
	zend_string *const_MAX_REGS_name = zend_string_init_interned("MAX_REGS", sizeof("MAX_REGS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_MAX_REGS_name, &const_MAX_REGS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_MAX_REGS_name);

	zval property_m_model_default_value;
	ZVAL_UNDEF(&property_m_model_default_value);
	zend_string *property_m_model_name = zend_string_init("m_model", sizeof("m_model") - 1, 1);
	zend_declare_typed_property(class_entry, property_m_model_name, &property_m_model_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_m_model_name);

	zval property_m_clocks_default_value;
	ZVAL_UNDEF(&property_m_clocks_default_value);
	zend_string *property_m_clocks_name = zend_string_init("m_clocks", sizeof("m_clocks") - 1, 1);
	zend_declare_typed_property(class_entry, property_m_clocks_name, &property_m_clocks_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m_clocks_name);

	zval property_m_regs_default_value;
	ZVAL_UNDEF(&property_m_regs_default_value);
	zend_string *property_m_regs_name = zend_string_init("m_regs", sizeof("m_regs") - 1, 1);
	zend_declare_typed_property(class_entry, property_m_regs_name, &property_m_regs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m_regs_name);

	zval property_m_noise_default_value;
	ZVAL_UNDEF(&property_m_noise_default_value);
	zend_string *property_m_noise_name = zend_string_init("m_noise", sizeof("m_noise") - 1, 1);
	zend_declare_typed_property(class_entry, property_m_noise_name, &property_m_noise_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m_noise_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_VizsnResonator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "VizsnResonator", class_SoLoud_VizsnResonator_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_a_default_value;
	ZVAL_UNDEF(&property_a_default_value);
	zend_string *property_a_name = zend_string_init("a", sizeof("a") - 1, 1);
	zend_declare_typed_property(class_entry, property_a_name, &property_a_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_a_name);

	zval property_b_default_value;
	ZVAL_UNDEF(&property_b_default_value);
	zend_string *property_b_name = zend_string_init("b", sizeof("b") - 1, 1);
	zend_declare_typed_property(class_entry, property_b_name, &property_b_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_b_name);

	zval property_c_default_value;
	ZVAL_UNDEF(&property_c_default_value);
	zend_string *property_c_name = zend_string_init("c", sizeof("c") - 1, 1);
	zend_declare_typed_property(class_entry, property_c_name, &property_c_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_c_name);

	zval property_p1_default_value;
	ZVAL_UNDEF(&property_p1_default_value);
	zend_string *property_p1_name = zend_string_init("p1", sizeof("p1") - 1, 1);
	zend_declare_typed_property(class_entry, property_p1_name, &property_p1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p1_name);

	zval property_p2_default_value;
	ZVAL_UNDEF(&property_p2_default_value);
	zend_string *property_p2_name = zend_string_init("p2", sizeof("p2") - 1, 1);
	zend_declare_typed_property(class_entry, property_p2_name, &property_p2_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_p2_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_VizsnBank(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "VizsnBank", class_SoLoud_VizsnBank_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_r_default_value;
	ZVAL_UNDEF(&property_r_default_value);
	zend_string *property_r_name = zend_string_init("r", sizeof("r") - 1, 1);
	zend_declare_typed_property(class_entry, property_r_name, &property_r_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_r_name);

	zval property_pitch_default_value;
	ZVAL_UNDEF(&property_pitch_default_value);
	zend_string *property_pitch_name = zend_string_init("pitch", sizeof("pitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_pitch_name, &property_pitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_pitch_name);

	zval property_frica_default_value;
	ZVAL_UNDEF(&property_frica_default_value);
	zend_string *property_frica_name = zend_string_init("frica", sizeof("frica") - 1, 1);
	zend_declare_typed_property(class_entry, property_frica_name, &property_frica_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_frica_name);

	zval property_voice_default_value;
	ZVAL_UNDEF(&property_voice_default_value);
	zend_string *property_voice_name = zend_string_init("voice", sizeof("voice") - 1, 1);
	zend_declare_typed_property(class_entry, property_voice_name, &property_voice_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_voice_name);

	zval property_aspir_default_value;
	ZVAL_UNDEF(&property_aspir_default_value);
	zend_string *property_aspir_name = zend_string_init("aspir", sizeof("aspir") - 1, 1);
	zend_declare_typed_property(class_entry, property_aspir_name, &property_aspir_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_aspir_name);

	zval property_bypas_default_value;
	ZVAL_UNDEF(&property_bypas_default_value);
	zend_string *property_bypas_name = zend_string_init("bypas", sizeof("bypas") - 1, 1);
	zend_declare_typed_property(class_entry, property_bypas_name, &property_bypas_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_bypas_name);

	zval property_breth_default_value;
	ZVAL_UNDEF(&property_breth_default_value);
	zend_string *property_breth_name = zend_string_init("breth", sizeof("breth") - 1, 1);
	zend_declare_typed_property(class_entry, property_breth_name, &property_breth_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_breth_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_VizsnInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "VizsnInstance", class_SoLoud_VizsnInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mParent_default_value;
	ZVAL_UNDEF(&property_mParent_default_value);
	zend_string *property_mParent_name = zend_string_init("mParent", sizeof("mParent") - 1, 1);
	zend_string *property_mParent_class_SoLoud_Vizsn = zend_string_init("SoLoud\\Vizsn", sizeof("SoLoud\\Vizsn")-1, 1);
	zend_declare_typed_property(class_entry, property_mParent_name, &property_mParent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mParent_class_SoLoud_Vizsn, 0, MAY_BE_NULL));
	zend_string_release(property_mParent_name);

	zval property_mBank0_default_value;
	ZVAL_UNDEF(&property_mBank0_default_value);
	zend_string *property_mBank0_name = zend_string_init("mBank0", sizeof("mBank0") - 1, 1);
	zend_string *property_mBank0_class_SoLoud_VizsnBank = zend_string_init("SoLoud\\VizsnBank", sizeof("SoLoud\\VizsnBank")-1, 1);
	zend_declare_typed_property(class_entry, property_mBank0_name, &property_mBank0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mBank0_class_SoLoud_VizsnBank, 0, 0));
	zend_string_release(property_mBank0_name);

	zval property_mBank1_default_value;
	ZVAL_UNDEF(&property_mBank1_default_value);
	zend_string *property_mBank1_name = zend_string_init("mBank1", sizeof("mBank1") - 1, 1);
	zend_string *property_mBank1_class_SoLoud_VizsnBank = zend_string_init("SoLoud\\VizsnBank", sizeof("SoLoud\\VizsnBank")-1, 1);
	zend_declare_typed_property(class_entry, property_mBank1_name, &property_mBank1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mBank1_class_SoLoud_VizsnBank, 0, 0));
	zend_string_release(property_mBank1_name);

	zval property_mBank0to1_default_value;
	ZVAL_UNDEF(&property_mBank0to1_default_value);
	zend_string *property_mBank0to1_name = zend_string_init("mBank0to1", sizeof("mBank0to1") - 1, 1);
	zend_string *property_mBank0to1_class_SoLoud_VizsnBank = zend_string_init("SoLoud\\VizsnBank", sizeof("SoLoud\\VizsnBank")-1, 1);
	zend_declare_typed_property(class_entry, property_mBank0to1_name, &property_mBank0to1_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mBank0to1_class_SoLoud_VizsnBank, 0, 0));
	zend_string_release(property_mBank0to1_name);

	zval property_mNper_default_value;
	ZVAL_UNDEF(&property_mNper_default_value);
	zend_string *property_mNper_name = zend_string_init("mNper", sizeof("mNper") - 1, 1);
	zend_declare_typed_property(class_entry, property_mNper_name, &property_mNper_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mNper_name);

	zval property_mNmod_default_value;
	ZVAL_UNDEF(&property_mNmod_default_value);
	zend_string *property_mNmod_name = zend_string_init("mNmod", sizeof("mNmod") - 1, 1);
	zend_declare_typed_property(class_entry, property_mNmod_name, &property_mNmod_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mNmod_name);

	zval property_mNopen_default_value;
	ZVAL_UNDEF(&property_mNopen_default_value);
	zend_string *property_mNopen_name = zend_string_init("mNopen", sizeof("mNopen") - 1, 1);
	zend_declare_typed_property(class_entry, property_mNopen_name, &property_mNopen_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mNopen_name);

	zval property_mEchobuf_default_value;
	ZVAL_UNDEF(&property_mEchobuf_default_value);
	zend_string *property_mEchobuf_name = zend_string_init("mEchobuf", sizeof("mEchobuf") - 1, 1);
	zend_declare_typed_property(class_entry, property_mEchobuf_name, &property_mEchobuf_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mEchobuf_name);

	zval property_mPtr_default_value;
	ZVAL_UNDEF(&property_mPtr_default_value);
	zend_string *property_mPtr_name = zend_string_init("mPtr", sizeof("mPtr") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPtr_name, &property_mPtr_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mPtr_name);

	zval property_mCurrentVoiceType_default_value;
	ZVAL_UNDEF(&property_mCurrentVoiceType_default_value);
	zend_string *property_mCurrentVoiceType_name = zend_string_init("mCurrentVoiceType", sizeof("mCurrentVoiceType") - 1, 1);
	zend_declare_typed_property(class_entry, property_mCurrentVoiceType_name, &property_mCurrentVoiceType_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mCurrentVoiceType_name);

	zval property_mPitch_default_value;
	ZVAL_UNDEF(&property_mPitch_default_value);
	zend_string *property_mPitch_name = zend_string_init("mPitch", sizeof("mPitch") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPitch_name, &property_mPitch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mPitch_name);

	zval property_mS_default_value;
	ZVAL_UNDEF(&property_mS_default_value);
	zend_string *property_mS_name = zend_string_init("mS", sizeof("mS") - 1, 1);
	zend_declare_typed_property(class_entry, property_mS_name, &property_mS_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_mS_name);

	zval property_mBuf_default_value;
	ZVAL_UNDEF(&property_mBuf_default_value);
	zend_string *property_mBuf_name = zend_string_init("mBuf", sizeof("mBuf") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBuf_name, &property_mBuf_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mBuf_name);

	zval property_mBufwrite_default_value;
	ZVAL_UNDEF(&property_mBufwrite_default_value);
	zend_string *property_mBufwrite_name = zend_string_init("mBufwrite", sizeof("mBufwrite") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBufwrite_name, &property_mBufwrite_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBufwrite_name);

	zval property_mBufread_default_value;
	ZVAL_UNDEF(&property_mBufread_default_value);
	zend_string *property_mBufread_name = zend_string_init("mBufread", sizeof("mBufread") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBufread_name, &property_mBufread_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBufread_name);

	zval property_mA_default_value;
	ZVAL_UNDEF(&property_mA_default_value);
	zend_string *property_mA_name = zend_string_init("mA", sizeof("mA") - 1, 1);
	zend_declare_typed_property(class_entry, property_mA_name, &property_mA_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mA_name);

	zval property_mB_default_value;
	ZVAL_UNDEF(&property_mB_default_value);
	zend_string *property_mB_name = zend_string_init("mB", sizeof("mB") - 1, 1);
	zend_declare_typed_property(class_entry, property_mB_name, &property_mB_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mB_name);

	zval property_mOrgv_default_value;
	ZVAL_UNDEF(&property_mOrgv_default_value);
	zend_string *property_mOrgv_name = zend_string_init("mOrgv", sizeof("mOrgv") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOrgv_name, &property_mOrgv_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mOrgv_name);

	zval property_mGlotlast_default_value;
	ZVAL_UNDEF(&property_mGlotlast_default_value);
	zend_string *property_mGlotlast_name = zend_string_init("mGlotlast", sizeof("mGlotlast") - 1, 1);
	zend_declare_typed_property(class_entry, property_mGlotlast_name, &property_mGlotlast_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mGlotlast_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Vizsn(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Vizsn", class_SoLoud_Vizsn_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mText_default_value;
	ZVAL_UNDEF(&property_mText_default_value);
	zend_string *property_mText_name = zend_string_init("mText", sizeof("mText") - 1, 1);
	zend_declare_typed_property(class_entry, property_mText_name, &property_mText_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_mText_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_AyInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "AyInstance", class_SoLoud_AyInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mParent_default_value;
	ZVAL_UNDEF(&property_mParent_default_value);
	zend_string *property_mParent_name = zend_string_init("mParent", sizeof("mParent") - 1, 1);
	zend_string *property_mParent_class_SoLoud_Ay = zend_string_init("SoLoud\\Ay", sizeof("SoLoud\\Ay")-1, 1);
	zend_declare_typed_property(class_entry, property_mParent_name, &property_mParent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mParent_class_SoLoud_Ay, 0, MAY_BE_NULL));
	zend_string_release(property_mParent_name);

	zval property_mChip_default_value;
	ZVAL_UNDEF(&property_mChip_default_value);
	zend_string *property_mChip_name = zend_string_init("mChip", sizeof("mChip") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChip_name, &property_mChip_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mChip_name);

	zval property_mPos_default_value;
	ZVAL_UNDEF(&property_mPos_default_value);
	zend_string *property_mPos_name = zend_string_init("mPos", sizeof("mPos") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPos_name, &property_mPos_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mPos_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Ay(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Ay", class_SoLoud_Ay_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mYm_default_value;
	ZVAL_UNDEF(&property_mYm_default_value);
	zend_string *property_mYm_name = zend_string_init("mYm", sizeof("mYm") - 1, 1);
	zend_declare_typed_property(class_entry, property_mYm_name, &property_mYm_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_mYm_name);

	zval property_mChipspeed_default_value;
	ZVAL_UNDEF(&property_mChipspeed_default_value);
	zend_string *property_mChipspeed_name = zend_string_init("mChipspeed", sizeof("mChipspeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChipspeed_name, &property_mChipspeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mChipspeed_name);

	zval property_mCpuspeed_default_value;
	ZVAL_UNDEF(&property_mCpuspeed_default_value);
	zend_string *property_mCpuspeed_name = zend_string_init("mCpuspeed", sizeof("mCpuspeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_mCpuspeed_name, &property_mCpuspeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mCpuspeed_name);

	zval property_mLooppos_default_value;
	ZVAL_UNDEF(&property_mLooppos_default_value);
	zend_string *property_mLooppos_name = zend_string_init("mLooppos", sizeof("mLooppos") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLooppos_name, &property_mLooppos_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mLooppos_name);

	zval property_mLength_default_value;
	ZVAL_UNDEF(&property_mLength_default_value);
	zend_string *property_mLength_name = zend_string_init("mLength", sizeof("mLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLength_name, &property_mLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mLength_name);

	zval property_mOps_default_value;
	ZVAL_UNDEF(&property_mOps_default_value);
	zend_string *property_mOps_name = zend_string_init("mOps", sizeof("mOps") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOps_name, &property_mOps_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mOps_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_OpenmptInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "OpenmptInstance", class_SoLoud_OpenmptInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Openmpt(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Openmpt", class_SoLoud_Openmpt_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mData_default_value;
	ZVAL_UNDEF(&property_mData_default_value);
	zend_string *property_mData_name = zend_string_init("mData", sizeof("mData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mData_name, &property_mData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_mData_name);

	zval property_mDataLen_default_value;
	ZVAL_UNDEF(&property_mDataLen_default_value);
	zend_string *property_mDataLen_name = zend_string_init("mDataLen", sizeof("mDataLen") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDataLen_name, &property_mDataLen_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mDataLen_name);

	return class_entry;
}
