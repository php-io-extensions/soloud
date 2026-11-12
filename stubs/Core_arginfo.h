/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 25c7352e09f6b9ae14366dd6fe8a58b0d9eb4bd6 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_Fader___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Fader_setLFO, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aFrom, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aStartTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Fader_set arginfo_class_SoLoud_Fader_setLFO

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Fader_get, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aCurrentTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_AudioSourceInstance3dData___construct arginfo_class_SoLoud_Fader___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSourceInstance3dData_init, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, aSource, SoLoud\\AudioSource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioCollider_collide, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, aSoloud, SoLoud\\Soloud, 1)
	ZEND_ARG_OBJ_INFO(0, aAudioInstance3dData, SoLoud\\AudioSourceInstance3dData, 1)
	ZEND_ARG_TYPE_INFO(0, aUserData, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioAttenuator_attenuate, 0, 4, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aDistance, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aMinDistance, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aMaxDistance, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aRolloffFactor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_AudioSourceInstance___construct arginfo_class_SoLoud_Fader___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSourceInstance_init, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, aSource, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO(0, aPlayIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSourceInstance_getAudio, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, aBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aSamplesToRead, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aBufferSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSourceInstance_hasEnded, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSourceInstance_seek, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSeconds, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, mScratch, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, mScratchSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSourceInstance_rewind, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSourceInstance_getInfo, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aInfoKey, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_AudioSource___construct arginfo_class_SoLoud_Fader___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_setVolume, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVolume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_setLooping, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aLoop, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_setSingleInstance, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aSingleInstance, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_setAutoStop, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aAutoStop, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_set3dMinMaxDistance, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aMinDistance, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aMaxDistance, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_set3dAttenuation, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aAttenuationModel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAttenuationRolloffFactor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_set3dDopplerFactor, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aDopplerFactor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_set3dListenerRelative, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aListenerRelative, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_set3dDistanceDelay, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aDistanceDelay, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_set3dCollider, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, aCollider, SoLoud\\AudioCollider, 1)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aUserData, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_set3dAttenuator, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, aAttenuator, SoLoud\\AudioAttenuator, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_setInaudibleBehavior, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aMustTick, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, aKill, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_setLoopPoint, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aLoopPoint, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_getLoopPoint, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_setFilter, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aFilterId, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aFilter, SoLoud\\Filter, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_AudioSource_createInstance, 0, 0, SoLoud\\AudioSourceInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AudioSource_stop, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud___construct arginfo_class_SoLoud_Fader___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_init, 0, 0, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aFlags, IS_LONG, 0, "SoLoud\\Soloud::CLIP_ROUNDOFF")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBackend, IS_LONG, 0, "SoLoud\\Soloud::AUTO")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aSamplerate, IS_LONG, 0, "SoLoud\\Soloud::AUTO")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBufferSize, IS_LONG, 0, "SoLoud\\Soloud::AUTO")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aChannels, IS_LONG, 0, "2")
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_pause arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_resume arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_deinit arginfo_class_SoLoud_AudioSource_stop

#define arginfo_class_SoLoud_Soloud_getVersion arginfo_class_SoLoud_AudioSourceInstance_rewind

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getErrorString, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aErrorCode, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_getBackendId arginfo_class_SoLoud_AudioSourceInstance_rewind

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getBackendString, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_getBackendChannels arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_getBackendSamplerate arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_getBackendBufferSize arginfo_class_SoLoud_AudioSourceInstance_rewind

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setSpeakerPosition, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getSpeakerPosition, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, aX, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, aY, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, aZ, IS_DOUBLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_play, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "-1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPan, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPaused, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBus, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_playClocked, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSoundTime, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "-1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPan, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBus, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_play3d, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelX, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelY, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelZ, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPaused, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBus, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_play3dClocked, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSoundTime, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelX, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelY, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelZ, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBus, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_playBackground, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVolume, IS_DOUBLE, 0, "-1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aPaused, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aBus, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_seek, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSeconds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_stop, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_stopAll arginfo_class_SoLoud_AudioSource_stop

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_stopAudioSource, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_countAudioSource, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aSound, SoLoud\\AudioSource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setFilterParameter, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFilterId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aValue, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getFilterParameter, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFilterId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_fadeFilterParameter, 0, 5, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFilterId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_oscillateFilterParameter, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFilterId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAttributeId, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFrom, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getStreamTime, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_getStreamPosition arginfo_class_SoLoud_Soloud_getStreamTime

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getPause, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_getVolume arginfo_class_SoLoud_Soloud_getStreamTime

#define arginfo_class_SoLoud_Soloud_getOverallVolume arginfo_class_SoLoud_Soloud_getStreamTime

#define arginfo_class_SoLoud_Soloud_getPan arginfo_class_SoLoud_Soloud_getStreamTime

#define arginfo_class_SoLoud_Soloud_getSamplerate arginfo_class_SoLoud_Soloud_getStreamTime

#define arginfo_class_SoLoud_Soloud_getProtectVoice arginfo_class_SoLoud_Soloud_getPause

#define arginfo_class_SoLoud_Soloud_getActiveVoiceCount arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_getVoiceCount arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_isValidVoiceHandle arginfo_class_SoLoud_Soloud_getPause

#define arginfo_class_SoLoud_Soloud_getRelativePlaySpeed arginfo_class_SoLoud_Soloud_getStreamTime

#define arginfo_class_SoLoud_Soloud_getPostClipScaler arginfo_class_SoLoud_AudioSource_getLoopPoint

#define arginfo_class_SoLoud_Soloud_getMainResampler arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_getGlobalVolume arginfo_class_SoLoud_AudioSource_getLoopPoint

#define arginfo_class_SoLoud_Soloud_getMaxActiveVoiceCount arginfo_class_SoLoud_AudioSourceInstance_rewind

#define arginfo_class_SoLoud_Soloud_getLooping arginfo_class_SoLoud_Soloud_getPause

#define arginfo_class_SoLoud_Soloud_getAutoStop arginfo_class_SoLoud_Soloud_getPause

#define arginfo_class_SoLoud_Soloud_getLoopPoint arginfo_class_SoLoud_Soloud_getStreamTime

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setLoopPoint, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aLoopPoint, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setLooping, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aLooping, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setAutoStop, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAutoStop, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setMaxActiveVoiceCount, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceCount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setInaudibleBehavior, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aMustTick, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, aKill, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_setGlobalVolume arginfo_class_SoLoud_AudioSource_setVolume

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setPostClipScaler, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aScaler, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setMainResampler, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aResampler, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setPause, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aPause, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setPauseAll, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aPause, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setRelativePlaySpeed, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSpeed, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setProtectVoice, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aProtect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setSamplerate, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSamplerate, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setPan, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aPan, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setPanAbsolute, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aLVolume, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aRVolume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setChannelVolume, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVolume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setVolume, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVolume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setDelaySamples, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSamples, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_fadeVolume, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_fadePan arginfo_class_SoLoud_Soloud_fadeVolume

#define arginfo_class_SoLoud_Soloud_fadeRelativePlaySpeed arginfo_class_SoLoud_Soloud_fadeVolume

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_fadeGlobalVolume, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_schedulePause, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_scheduleStop arginfo_class_SoLoud_Soloud_schedulePause

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_oscillateVolume, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFrom, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_oscillatePan arginfo_class_SoLoud_Soloud_oscillateVolume

#define arginfo_class_SoLoud_Soloud_oscillateRelativePlaySpeed arginfo_class_SoLoud_Soloud_oscillateVolume

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_oscillateGlobalVolume, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aFrom, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTo, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_setGlobalFilter arginfo_class_SoLoud_AudioSource_setFilter

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_setVisualizationEnable, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aEnable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_calcFFT, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_getWave arginfo_class_SoLoud_Soloud_calcFFT

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getApproximateVolume, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aChannel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getLoopCount, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_getInfo, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aInfoKey, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_createVoiceGroup arginfo_class_SoLoud_AudioSourceInstance_rewind

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_destroyVoiceGroup, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceGroupHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_addVoiceToGroup, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceGroupHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_isVoiceGroup, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceGroupHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_isVoiceGroupEmpty arginfo_class_SoLoud_Soloud_isVoiceGroup

#define arginfo_class_SoLoud_Soloud_update3dAudio arginfo_class_SoLoud_AudioSource_stop

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dSoundSpeed, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aSpeed, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_get3dSoundSpeed arginfo_class_SoLoud_AudioSource_getLoopPoint

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dListenerParameters, 0, 9, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aAtX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aAtY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aAtZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aUpX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aUpY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aUpZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelocityX, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelocityY, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelocityZ, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dListenerPosition, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dListenerAt, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aAtX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aAtY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aAtZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dListenerUp, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aUpX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aUpY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aUpZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dListenerVelocity, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVelocityX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aVelocityY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aVelocityZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dSourceParameters, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelocityX, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelocityY, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aVelocityZ, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dSourcePosition, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aPosX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aPosZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dSourceVelocity, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aVelocityX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aVelocityY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aVelocityZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dSourceMinMaxDistance, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aMinDistance, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aMaxDistance, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dSourceAttenuation, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAttenuationModel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aAttenuationRolloffFactor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_set3dSourceDopplerFactor, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aVoiceHandle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aDopplerFactor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Soloud_mix, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aSamples, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Soloud_mixSigned16 arginfo_class_SoLoud_Soloud_mix

ZEND_METHOD(SoLoud_Fader, __construct);
ZEND_METHOD(SoLoud_Fader, setLFO);
ZEND_METHOD(SoLoud_Fader, set);
ZEND_METHOD(SoLoud_Fader, get);
ZEND_METHOD(SoLoud_AudioSourceInstance3dData, __construct);
ZEND_METHOD(SoLoud_AudioSourceInstance3dData, init);
ZEND_METHOD(SoLoud_AudioCollider, collide);
ZEND_METHOD(SoLoud_AudioAttenuator, attenuate);
ZEND_METHOD(SoLoud_AudioSourceInstance, __construct);
ZEND_METHOD(SoLoud_AudioSourceInstance, init);
ZEND_METHOD(SoLoud_AudioSourceInstance, getAudio);
ZEND_METHOD(SoLoud_AudioSourceInstance, hasEnded);
ZEND_METHOD(SoLoud_AudioSourceInstance, seek);
ZEND_METHOD(SoLoud_AudioSourceInstance, rewind);
ZEND_METHOD(SoLoud_AudioSourceInstance, getInfo);
ZEND_METHOD(SoLoud_AudioSource, __construct);
ZEND_METHOD(SoLoud_AudioSource, setVolume);
ZEND_METHOD(SoLoud_AudioSource, setLooping);
ZEND_METHOD(SoLoud_AudioSource, setSingleInstance);
ZEND_METHOD(SoLoud_AudioSource, setAutoStop);
ZEND_METHOD(SoLoud_AudioSource, set3dMinMaxDistance);
ZEND_METHOD(SoLoud_AudioSource, set3dAttenuation);
ZEND_METHOD(SoLoud_AudioSource, set3dDopplerFactor);
ZEND_METHOD(SoLoud_AudioSource, set3dListenerRelative);
ZEND_METHOD(SoLoud_AudioSource, set3dDistanceDelay);
ZEND_METHOD(SoLoud_AudioSource, set3dCollider);
ZEND_METHOD(SoLoud_AudioSource, set3dAttenuator);
ZEND_METHOD(SoLoud_AudioSource, setInaudibleBehavior);
ZEND_METHOD(SoLoud_AudioSource, setLoopPoint);
ZEND_METHOD(SoLoud_AudioSource, getLoopPoint);
ZEND_METHOD(SoLoud_AudioSource, setFilter);
ZEND_METHOD(SoLoud_AudioSource, createInstance);
ZEND_METHOD(SoLoud_AudioSource, stop);
ZEND_METHOD(SoLoud_Soloud, __construct);
ZEND_METHOD(SoLoud_Soloud, init);
ZEND_METHOD(SoLoud_Soloud, pause);
ZEND_METHOD(SoLoud_Soloud, resume);
ZEND_METHOD(SoLoud_Soloud, deinit);
ZEND_METHOD(SoLoud_Soloud, getVersion);
ZEND_METHOD(SoLoud_Soloud, getErrorString);
ZEND_METHOD(SoLoud_Soloud, getBackendId);
ZEND_METHOD(SoLoud_Soloud, getBackendString);
ZEND_METHOD(SoLoud_Soloud, getBackendChannels);
ZEND_METHOD(SoLoud_Soloud, getBackendSamplerate);
ZEND_METHOD(SoLoud_Soloud, getBackendBufferSize);
ZEND_METHOD(SoLoud_Soloud, setSpeakerPosition);
ZEND_METHOD(SoLoud_Soloud, getSpeakerPosition);
ZEND_METHOD(SoLoud_Soloud, play);
ZEND_METHOD(SoLoud_Soloud, playClocked);
ZEND_METHOD(SoLoud_Soloud, play3d);
ZEND_METHOD(SoLoud_Soloud, play3dClocked);
ZEND_METHOD(SoLoud_Soloud, playBackground);
ZEND_METHOD(SoLoud_Soloud, seek);
ZEND_METHOD(SoLoud_Soloud, stop);
ZEND_METHOD(SoLoud_Soloud, stopAll);
ZEND_METHOD(SoLoud_Soloud, stopAudioSource);
ZEND_METHOD(SoLoud_Soloud, countAudioSource);
ZEND_METHOD(SoLoud_Soloud, setFilterParameter);
ZEND_METHOD(SoLoud_Soloud, getFilterParameter);
ZEND_METHOD(SoLoud_Soloud, fadeFilterParameter);
ZEND_METHOD(SoLoud_Soloud, oscillateFilterParameter);
ZEND_METHOD(SoLoud_Soloud, getStreamTime);
ZEND_METHOD(SoLoud_Soloud, getStreamPosition);
ZEND_METHOD(SoLoud_Soloud, getPause);
ZEND_METHOD(SoLoud_Soloud, getVolume);
ZEND_METHOD(SoLoud_Soloud, getOverallVolume);
ZEND_METHOD(SoLoud_Soloud, getPan);
ZEND_METHOD(SoLoud_Soloud, getSamplerate);
ZEND_METHOD(SoLoud_Soloud, getProtectVoice);
ZEND_METHOD(SoLoud_Soloud, getActiveVoiceCount);
ZEND_METHOD(SoLoud_Soloud, getVoiceCount);
ZEND_METHOD(SoLoud_Soloud, isValidVoiceHandle);
ZEND_METHOD(SoLoud_Soloud, getRelativePlaySpeed);
ZEND_METHOD(SoLoud_Soloud, getPostClipScaler);
ZEND_METHOD(SoLoud_Soloud, getMainResampler);
ZEND_METHOD(SoLoud_Soloud, getGlobalVolume);
ZEND_METHOD(SoLoud_Soloud, getMaxActiveVoiceCount);
ZEND_METHOD(SoLoud_Soloud, getLooping);
ZEND_METHOD(SoLoud_Soloud, getAutoStop);
ZEND_METHOD(SoLoud_Soloud, getLoopPoint);
ZEND_METHOD(SoLoud_Soloud, setLoopPoint);
ZEND_METHOD(SoLoud_Soloud, setLooping);
ZEND_METHOD(SoLoud_Soloud, setAutoStop);
ZEND_METHOD(SoLoud_Soloud, setMaxActiveVoiceCount);
ZEND_METHOD(SoLoud_Soloud, setInaudibleBehavior);
ZEND_METHOD(SoLoud_Soloud, setGlobalVolume);
ZEND_METHOD(SoLoud_Soloud, setPostClipScaler);
ZEND_METHOD(SoLoud_Soloud, setMainResampler);
ZEND_METHOD(SoLoud_Soloud, setPause);
ZEND_METHOD(SoLoud_Soloud, setPauseAll);
ZEND_METHOD(SoLoud_Soloud, setRelativePlaySpeed);
ZEND_METHOD(SoLoud_Soloud, setProtectVoice);
ZEND_METHOD(SoLoud_Soloud, setSamplerate);
ZEND_METHOD(SoLoud_Soloud, setPan);
ZEND_METHOD(SoLoud_Soloud, setPanAbsolute);
ZEND_METHOD(SoLoud_Soloud, setChannelVolume);
ZEND_METHOD(SoLoud_Soloud, setVolume);
ZEND_METHOD(SoLoud_Soloud, setDelaySamples);
ZEND_METHOD(SoLoud_Soloud, fadeVolume);
ZEND_METHOD(SoLoud_Soloud, fadePan);
ZEND_METHOD(SoLoud_Soloud, fadeRelativePlaySpeed);
ZEND_METHOD(SoLoud_Soloud, fadeGlobalVolume);
ZEND_METHOD(SoLoud_Soloud, schedulePause);
ZEND_METHOD(SoLoud_Soloud, scheduleStop);
ZEND_METHOD(SoLoud_Soloud, oscillateVolume);
ZEND_METHOD(SoLoud_Soloud, oscillatePan);
ZEND_METHOD(SoLoud_Soloud, oscillateRelativePlaySpeed);
ZEND_METHOD(SoLoud_Soloud, oscillateGlobalVolume);
ZEND_METHOD(SoLoud_Soloud, setGlobalFilter);
ZEND_METHOD(SoLoud_Soloud, setVisualizationEnable);
ZEND_METHOD(SoLoud_Soloud, calcFFT);
ZEND_METHOD(SoLoud_Soloud, getWave);
ZEND_METHOD(SoLoud_Soloud, getApproximateVolume);
ZEND_METHOD(SoLoud_Soloud, getLoopCount);
ZEND_METHOD(SoLoud_Soloud, getInfo);
ZEND_METHOD(SoLoud_Soloud, createVoiceGroup);
ZEND_METHOD(SoLoud_Soloud, destroyVoiceGroup);
ZEND_METHOD(SoLoud_Soloud, addVoiceToGroup);
ZEND_METHOD(SoLoud_Soloud, isVoiceGroup);
ZEND_METHOD(SoLoud_Soloud, isVoiceGroupEmpty);
ZEND_METHOD(SoLoud_Soloud, update3dAudio);
ZEND_METHOD(SoLoud_Soloud, set3dSoundSpeed);
ZEND_METHOD(SoLoud_Soloud, get3dSoundSpeed);
ZEND_METHOD(SoLoud_Soloud, set3dListenerParameters);
ZEND_METHOD(SoLoud_Soloud, set3dListenerPosition);
ZEND_METHOD(SoLoud_Soloud, set3dListenerAt);
ZEND_METHOD(SoLoud_Soloud, set3dListenerUp);
ZEND_METHOD(SoLoud_Soloud, set3dListenerVelocity);
ZEND_METHOD(SoLoud_Soloud, set3dSourceParameters);
ZEND_METHOD(SoLoud_Soloud, set3dSourcePosition);
ZEND_METHOD(SoLoud_Soloud, set3dSourceVelocity);
ZEND_METHOD(SoLoud_Soloud, set3dSourceMinMaxDistance);
ZEND_METHOD(SoLoud_Soloud, set3dSourceAttenuation);
ZEND_METHOD(SoLoud_Soloud, set3dSourceDopplerFactor);
ZEND_METHOD(SoLoud_Soloud, mix);
ZEND_METHOD(SoLoud_Soloud, mixSigned16);

static const zend_function_entry class_SoLoud_Fader_methods[] = {
	ZEND_ME(SoLoud_Fader, __construct, arginfo_class_SoLoud_Fader___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Fader, setLFO, arginfo_class_SoLoud_Fader_setLFO, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Fader, set, arginfo_class_SoLoud_Fader_set, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Fader, get, arginfo_class_SoLoud_Fader_get, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_AudioSourceInstance3dData_methods[] = {
	ZEND_ME(SoLoud_AudioSourceInstance3dData, __construct, arginfo_class_SoLoud_AudioSourceInstance3dData___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSourceInstance3dData, init, arginfo_class_SoLoud_AudioSourceInstance3dData_init, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_AudioCollider_methods[] = {
	ZEND_ME(SoLoud_AudioCollider, collide, arginfo_class_SoLoud_AudioCollider_collide, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_AudioAttenuator_methods[] = {
	ZEND_ME(SoLoud_AudioAttenuator, attenuate, arginfo_class_SoLoud_AudioAttenuator_attenuate, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_AudioSourceInstance_methods[] = {
	ZEND_ME(SoLoud_AudioSourceInstance, __construct, arginfo_class_SoLoud_AudioSourceInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSourceInstance, init, arginfo_class_SoLoud_AudioSourceInstance_init, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSourceInstance, getAudio, arginfo_class_SoLoud_AudioSourceInstance_getAudio, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSourceInstance, hasEnded, arginfo_class_SoLoud_AudioSourceInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSourceInstance, seek, arginfo_class_SoLoud_AudioSourceInstance_seek, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSourceInstance, rewind, arginfo_class_SoLoud_AudioSourceInstance_rewind, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSourceInstance, getInfo, arginfo_class_SoLoud_AudioSourceInstance_getInfo, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_AudioSource_methods[] = {
	ZEND_ME(SoLoud_AudioSource, __construct, arginfo_class_SoLoud_AudioSource___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, setVolume, arginfo_class_SoLoud_AudioSource_setVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, setLooping, arginfo_class_SoLoud_AudioSource_setLooping, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, setSingleInstance, arginfo_class_SoLoud_AudioSource_setSingleInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, setAutoStop, arginfo_class_SoLoud_AudioSource_setAutoStop, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, set3dMinMaxDistance, arginfo_class_SoLoud_AudioSource_set3dMinMaxDistance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, set3dAttenuation, arginfo_class_SoLoud_AudioSource_set3dAttenuation, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, set3dDopplerFactor, arginfo_class_SoLoud_AudioSource_set3dDopplerFactor, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, set3dListenerRelative, arginfo_class_SoLoud_AudioSource_set3dListenerRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, set3dDistanceDelay, arginfo_class_SoLoud_AudioSource_set3dDistanceDelay, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, set3dCollider, arginfo_class_SoLoud_AudioSource_set3dCollider, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, set3dAttenuator, arginfo_class_SoLoud_AudioSource_set3dAttenuator, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, setInaudibleBehavior, arginfo_class_SoLoud_AudioSource_setInaudibleBehavior, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, setLoopPoint, arginfo_class_SoLoud_AudioSource_setLoopPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, getLoopPoint, arginfo_class_SoLoud_AudioSource_getLoopPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, setFilter, arginfo_class_SoLoud_AudioSource_setFilter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, createInstance, arginfo_class_SoLoud_AudioSource_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AudioSource, stop, arginfo_class_SoLoud_AudioSource_stop, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Soloud_methods[] = {
	ZEND_ME(SoLoud_Soloud, __construct, arginfo_class_SoLoud_Soloud___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, init, arginfo_class_SoLoud_Soloud_init, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, pause, arginfo_class_SoLoud_Soloud_pause, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, resume, arginfo_class_SoLoud_Soloud_resume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, deinit, arginfo_class_SoLoud_Soloud_deinit, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getVersion, arginfo_class_SoLoud_Soloud_getVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getErrorString, arginfo_class_SoLoud_Soloud_getErrorString, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getBackendId, arginfo_class_SoLoud_Soloud_getBackendId, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getBackendString, arginfo_class_SoLoud_Soloud_getBackendString, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getBackendChannels, arginfo_class_SoLoud_Soloud_getBackendChannels, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getBackendSamplerate, arginfo_class_SoLoud_Soloud_getBackendSamplerate, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getBackendBufferSize, arginfo_class_SoLoud_Soloud_getBackendBufferSize, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setSpeakerPosition, arginfo_class_SoLoud_Soloud_setSpeakerPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getSpeakerPosition, arginfo_class_SoLoud_Soloud_getSpeakerPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, play, arginfo_class_SoLoud_Soloud_play, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, playClocked, arginfo_class_SoLoud_Soloud_playClocked, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, play3d, arginfo_class_SoLoud_Soloud_play3d, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, play3dClocked, arginfo_class_SoLoud_Soloud_play3dClocked, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, playBackground, arginfo_class_SoLoud_Soloud_playBackground, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, seek, arginfo_class_SoLoud_Soloud_seek, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, stop, arginfo_class_SoLoud_Soloud_stop, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, stopAll, arginfo_class_SoLoud_Soloud_stopAll, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, stopAudioSource, arginfo_class_SoLoud_Soloud_stopAudioSource, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, countAudioSource, arginfo_class_SoLoud_Soloud_countAudioSource, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setFilterParameter, arginfo_class_SoLoud_Soloud_setFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getFilterParameter, arginfo_class_SoLoud_Soloud_getFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, fadeFilterParameter, arginfo_class_SoLoud_Soloud_fadeFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, oscillateFilterParameter, arginfo_class_SoLoud_Soloud_oscillateFilterParameter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getStreamTime, arginfo_class_SoLoud_Soloud_getStreamTime, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getStreamPosition, arginfo_class_SoLoud_Soloud_getStreamPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getPause, arginfo_class_SoLoud_Soloud_getPause, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getVolume, arginfo_class_SoLoud_Soloud_getVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getOverallVolume, arginfo_class_SoLoud_Soloud_getOverallVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getPan, arginfo_class_SoLoud_Soloud_getPan, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getSamplerate, arginfo_class_SoLoud_Soloud_getSamplerate, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getProtectVoice, arginfo_class_SoLoud_Soloud_getProtectVoice, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getActiveVoiceCount, arginfo_class_SoLoud_Soloud_getActiveVoiceCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getVoiceCount, arginfo_class_SoLoud_Soloud_getVoiceCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, isValidVoiceHandle, arginfo_class_SoLoud_Soloud_isValidVoiceHandle, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getRelativePlaySpeed, arginfo_class_SoLoud_Soloud_getRelativePlaySpeed, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getPostClipScaler, arginfo_class_SoLoud_Soloud_getPostClipScaler, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getMainResampler, arginfo_class_SoLoud_Soloud_getMainResampler, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getGlobalVolume, arginfo_class_SoLoud_Soloud_getGlobalVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getMaxActiveVoiceCount, arginfo_class_SoLoud_Soloud_getMaxActiveVoiceCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getLooping, arginfo_class_SoLoud_Soloud_getLooping, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getAutoStop, arginfo_class_SoLoud_Soloud_getAutoStop, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getLoopPoint, arginfo_class_SoLoud_Soloud_getLoopPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setLoopPoint, arginfo_class_SoLoud_Soloud_setLoopPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setLooping, arginfo_class_SoLoud_Soloud_setLooping, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setAutoStop, arginfo_class_SoLoud_Soloud_setAutoStop, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setMaxActiveVoiceCount, arginfo_class_SoLoud_Soloud_setMaxActiveVoiceCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setInaudibleBehavior, arginfo_class_SoLoud_Soloud_setInaudibleBehavior, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setGlobalVolume, arginfo_class_SoLoud_Soloud_setGlobalVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setPostClipScaler, arginfo_class_SoLoud_Soloud_setPostClipScaler, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setMainResampler, arginfo_class_SoLoud_Soloud_setMainResampler, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setPause, arginfo_class_SoLoud_Soloud_setPause, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setPauseAll, arginfo_class_SoLoud_Soloud_setPauseAll, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setRelativePlaySpeed, arginfo_class_SoLoud_Soloud_setRelativePlaySpeed, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setProtectVoice, arginfo_class_SoLoud_Soloud_setProtectVoice, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setSamplerate, arginfo_class_SoLoud_Soloud_setSamplerate, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setPan, arginfo_class_SoLoud_Soloud_setPan, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setPanAbsolute, arginfo_class_SoLoud_Soloud_setPanAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setChannelVolume, arginfo_class_SoLoud_Soloud_setChannelVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setVolume, arginfo_class_SoLoud_Soloud_setVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setDelaySamples, arginfo_class_SoLoud_Soloud_setDelaySamples, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, fadeVolume, arginfo_class_SoLoud_Soloud_fadeVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, fadePan, arginfo_class_SoLoud_Soloud_fadePan, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, fadeRelativePlaySpeed, arginfo_class_SoLoud_Soloud_fadeRelativePlaySpeed, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, fadeGlobalVolume, arginfo_class_SoLoud_Soloud_fadeGlobalVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, schedulePause, arginfo_class_SoLoud_Soloud_schedulePause, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, scheduleStop, arginfo_class_SoLoud_Soloud_scheduleStop, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, oscillateVolume, arginfo_class_SoLoud_Soloud_oscillateVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, oscillatePan, arginfo_class_SoLoud_Soloud_oscillatePan, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, oscillateRelativePlaySpeed, arginfo_class_SoLoud_Soloud_oscillateRelativePlaySpeed, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, oscillateGlobalVolume, arginfo_class_SoLoud_Soloud_oscillateGlobalVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setGlobalFilter, arginfo_class_SoLoud_Soloud_setGlobalFilter, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, setVisualizationEnable, arginfo_class_SoLoud_Soloud_setVisualizationEnable, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, calcFFT, arginfo_class_SoLoud_Soloud_calcFFT, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getWave, arginfo_class_SoLoud_Soloud_getWave, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getApproximateVolume, arginfo_class_SoLoud_Soloud_getApproximateVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getLoopCount, arginfo_class_SoLoud_Soloud_getLoopCount, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, getInfo, arginfo_class_SoLoud_Soloud_getInfo, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, createVoiceGroup, arginfo_class_SoLoud_Soloud_createVoiceGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, destroyVoiceGroup, arginfo_class_SoLoud_Soloud_destroyVoiceGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, addVoiceToGroup, arginfo_class_SoLoud_Soloud_addVoiceToGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, isVoiceGroup, arginfo_class_SoLoud_Soloud_isVoiceGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, isVoiceGroupEmpty, arginfo_class_SoLoud_Soloud_isVoiceGroupEmpty, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, update3dAudio, arginfo_class_SoLoud_Soloud_update3dAudio, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dSoundSpeed, arginfo_class_SoLoud_Soloud_set3dSoundSpeed, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, get3dSoundSpeed, arginfo_class_SoLoud_Soloud_get3dSoundSpeed, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dListenerParameters, arginfo_class_SoLoud_Soloud_set3dListenerParameters, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dListenerPosition, arginfo_class_SoLoud_Soloud_set3dListenerPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dListenerAt, arginfo_class_SoLoud_Soloud_set3dListenerAt, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dListenerUp, arginfo_class_SoLoud_Soloud_set3dListenerUp, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dListenerVelocity, arginfo_class_SoLoud_Soloud_set3dListenerVelocity, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dSourceParameters, arginfo_class_SoLoud_Soloud_set3dSourceParameters, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dSourcePosition, arginfo_class_SoLoud_Soloud_set3dSourcePosition, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dSourceVelocity, arginfo_class_SoLoud_Soloud_set3dSourceVelocity, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dSourceMinMaxDistance, arginfo_class_SoLoud_Soloud_set3dSourceMinMaxDistance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dSourceAttenuation, arginfo_class_SoLoud_Soloud_set3dSourceAttenuation, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, set3dSourceDopplerFactor, arginfo_class_SoLoud_Soloud_set3dSourceDopplerFactor, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, mix, arginfo_class_SoLoud_Soloud_mix, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Soloud, mixSigned16, arginfo_class_SoLoud_Soloud_mixSigned16, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_Core_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("SoLoud\\SO_NO_ERROR", SoLoud::SO_NO_ERROR, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\INVALID_PARAMETER", SoLoud::INVALID_PARAMETER, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\FILE_NOT_FOUND", SoLoud::FILE_NOT_FOUND, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\FILE_LOAD_FAILED", SoLoud::FILE_LOAD_FAILED, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\DLL_NOT_FOUND", SoLoud::DLL_NOT_FOUND, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\OUT_OF_MEMORY", SoLoud::OUT_OF_MEMORY, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\NOT_IMPLEMENTED", SoLoud::NOT_IMPLEMENTED, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\UNKNOWN_ERROR", SoLoud::UNKNOWN_ERROR, CONST_PERSISTENT);
}

static zend_class_entry *register_class_SoLoud_Fader(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Fader", class_SoLoud_Fader_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mFrom_default_value;
	ZVAL_UNDEF(&property_mFrom_default_value);
	zend_string *property_mFrom_name = zend_string_init("mFrom", sizeof("mFrom") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFrom_name, &property_mFrom_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mFrom_name);

	zval property_mTo_default_value;
	ZVAL_UNDEF(&property_mTo_default_value);
	zend_string *property_mTo_name = zend_string_init("mTo", sizeof("mTo") - 1, 1);
	zend_declare_typed_property(class_entry, property_mTo_name, &property_mTo_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mTo_name);

	zval property_mDelta_default_value;
	ZVAL_UNDEF(&property_mDelta_default_value);
	zend_string *property_mDelta_name = zend_string_init("mDelta", sizeof("mDelta") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDelta_name, &property_mDelta_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mDelta_name);

	zval property_mTime_default_value;
	ZVAL_UNDEF(&property_mTime_default_value);
	zend_string *property_mTime_name = zend_string_init("mTime", sizeof("mTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_mTime_name, &property_mTime_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mTime_name);

	zval property_mStartTime_default_value;
	ZVAL_UNDEF(&property_mStartTime_default_value);
	zend_string *property_mStartTime_name = zend_string_init("mStartTime", sizeof("mStartTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_mStartTime_name, &property_mStartTime_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mStartTime_name);

	zval property_mEndTime_default_value;
	ZVAL_UNDEF(&property_mEndTime_default_value);
	zend_string *property_mEndTime_name = zend_string_init("mEndTime", sizeof("mEndTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_mEndTime_name, &property_mEndTime_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mEndTime_name);

	zval property_mCurrent_default_value;
	ZVAL_UNDEF(&property_mCurrent_default_value);
	zend_string *property_mCurrent_name = zend_string_init("mCurrent", sizeof("mCurrent") - 1, 1);
	zend_declare_typed_property(class_entry, property_mCurrent_name, &property_mCurrent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mCurrent_name);

	zval property_mActive_default_value;
	ZVAL_UNDEF(&property_mActive_default_value);
	zend_string *property_mActive_name = zend_string_init("mActive", sizeof("mActive") - 1, 1);
	zend_declare_typed_property(class_entry, property_mActive_name, &property_mActive_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mActive_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_AudioSourceInstance3dData(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "AudioSourceInstance3dData", class_SoLoud_AudioSourceInstance3dData_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_m3dPosition_default_value;
	ZVAL_UNDEF(&property_m3dPosition_default_value);
	zend_string *property_m3dPosition_name = zend_string_init("m3dPosition", sizeof("m3dPosition") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dPosition_name, &property_m3dPosition_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m3dPosition_name);

	zval property_m3dVelocity_default_value;
	ZVAL_UNDEF(&property_m3dVelocity_default_value);
	zend_string *property_m3dVelocity_name = zend_string_init("m3dVelocity", sizeof("m3dVelocity") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dVelocity_name, &property_m3dVelocity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m3dVelocity_name);

	zval property_m3dMinDistance_default_value;
	ZVAL_UNDEF(&property_m3dMinDistance_default_value);
	zend_string *property_m3dMinDistance_name = zend_string_init("m3dMinDistance", sizeof("m3dMinDistance") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dMinDistance_name, &property_m3dMinDistance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dMinDistance_name);

	zval property_m3dMaxDistance_default_value;
	ZVAL_UNDEF(&property_m3dMaxDistance_default_value);
	zend_string *property_m3dMaxDistance_name = zend_string_init("m3dMaxDistance", sizeof("m3dMaxDistance") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dMaxDistance_name, &property_m3dMaxDistance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dMaxDistance_name);

	zval property_m3dAttenuationRolloff_default_value;
	ZVAL_UNDEF(&property_m3dAttenuationRolloff_default_value);
	zend_string *property_m3dAttenuationRolloff_name = zend_string_init("m3dAttenuationRolloff", sizeof("m3dAttenuationRolloff") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dAttenuationRolloff_name, &property_m3dAttenuationRolloff_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dAttenuationRolloff_name);

	zval property_m3dAttenuationModel_default_value;
	ZVAL_UNDEF(&property_m3dAttenuationModel_default_value);
	zend_string *property_m3dAttenuationModel_name = zend_string_init("m3dAttenuationModel", sizeof("m3dAttenuationModel") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dAttenuationModel_name, &property_m3dAttenuationModel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_m3dAttenuationModel_name);

	zval property_m3dDopplerFactor_default_value;
	ZVAL_UNDEF(&property_m3dDopplerFactor_default_value);
	zend_string *property_m3dDopplerFactor_name = zend_string_init("m3dDopplerFactor", sizeof("m3dDopplerFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dDopplerFactor_name, &property_m3dDopplerFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dDopplerFactor_name);

	zval property_mCollider_default_value;
	ZVAL_UNDEF(&property_mCollider_default_value);
	zend_string *property_mCollider_name = zend_string_init("mCollider", sizeof("mCollider") - 1, 1);
	zend_string *property_mCollider_class_SoLoud_AudioCollider = zend_string_init("SoLoud\\AudioCollider", sizeof("SoLoud\\AudioCollider")-1, 1);
	zend_declare_typed_property(class_entry, property_mCollider_name, &property_mCollider_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mCollider_class_SoLoud_AudioCollider, 0, MAY_BE_NULL));
	zend_string_release(property_mCollider_name);

	zval property_mAttenuator_default_value;
	ZVAL_UNDEF(&property_mAttenuator_default_value);
	zend_string *property_mAttenuator_name = zend_string_init("mAttenuator", sizeof("mAttenuator") - 1, 1);
	zend_string *property_mAttenuator_class_SoLoud_AudioAttenuator = zend_string_init("SoLoud\\AudioAttenuator", sizeof("SoLoud\\AudioAttenuator")-1, 1);
	zend_declare_typed_property(class_entry, property_mAttenuator_name, &property_mAttenuator_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mAttenuator_class_SoLoud_AudioAttenuator, 0, MAY_BE_NULL));
	zend_string_release(property_mAttenuator_name);

	zval property_mColliderData_default_value;
	ZVAL_UNDEF(&property_mColliderData_default_value);
	zend_string *property_mColliderData_name = zend_string_init("mColliderData", sizeof("mColliderData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mColliderData_name, &property_mColliderData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mColliderData_name);

	zval property_mDopplerValue_default_value;
	ZVAL_UNDEF(&property_mDopplerValue_default_value);
	zend_string *property_mDopplerValue_name = zend_string_init("mDopplerValue", sizeof("mDopplerValue") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDopplerValue_name, &property_mDopplerValue_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mDopplerValue_name);

	zval property_m3dVolume_default_value;
	ZVAL_UNDEF(&property_m3dVolume_default_value);
	zend_string *property_m3dVolume_name = zend_string_init("m3dVolume", sizeof("m3dVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dVolume_name, &property_m3dVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dVolume_name);

	zval property_mChannelVolume_default_value;
	ZVAL_UNDEF(&property_mChannelVolume_default_value);
	zend_string *property_mChannelVolume_name = zend_string_init("mChannelVolume", sizeof("mChannelVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannelVolume_name, &property_mChannelVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mChannelVolume_name);

	zval property_mFlags_default_value;
	ZVAL_UNDEF(&property_mFlags_default_value);
	zend_string *property_mFlags_name = zend_string_init("mFlags", sizeof("mFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFlags_name, &property_mFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFlags_name);

	zval property_mHandle_default_value;
	ZVAL_UNDEF(&property_mHandle_default_value);
	zend_string *property_mHandle_name = zend_string_init("mHandle", sizeof("mHandle") - 1, 1);
	zend_declare_typed_property(class_entry, property_mHandle_name, &property_mHandle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mHandle_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_AudioCollider(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "AudioCollider", class_SoLoud_AudioCollider_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_AudioAttenuator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "AudioAttenuator", class_SoLoud_AudioAttenuator_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_AudioSourceInstance(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "AudioSourceInstance", class_SoLoud_AudioSourceInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	zval const_LOOPING_value;
	ZVAL_LONG(&const_LOOPING_value, SoLoud::AudioSourceInstance::LOOPING);
	zend_string *const_LOOPING_name = zend_string_init_interned("LOOPING", sizeof("LOOPING") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LOOPING_name, &const_LOOPING_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LOOPING_name);

	zval const_PROTECTED_value;
	ZVAL_LONG(&const_PROTECTED_value, SoLoud::AudioSourceInstance::PROTECTED);
	zend_string *const_PROTECTED_name = zend_string_init_interned("PROTECTED", sizeof("PROTECTED") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PROTECTED_name, &const_PROTECTED_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PROTECTED_name);

	zval const_PAUSED_value;
	ZVAL_LONG(&const_PAUSED_value, SoLoud::AudioSourceInstance::PAUSED);
	zend_string *const_PAUSED_name = zend_string_init_interned("PAUSED", sizeof("PAUSED") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PAUSED_name, &const_PAUSED_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PAUSED_name);

	zval const_PROCESS_3D_value;
	ZVAL_LONG(&const_PROCESS_3D_value, SoLoud::AudioSourceInstance::PROCESS_3D);
	zend_string *const_PROCESS_3D_name = zend_string_init_interned("PROCESS_3D", sizeof("PROCESS_3D") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PROCESS_3D_name, &const_PROCESS_3D_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PROCESS_3D_name);

	zval const_LISTENER_RELATIVE_value;
	ZVAL_LONG(&const_LISTENER_RELATIVE_value, SoLoud::AudioSourceInstance::LISTENER_RELATIVE);
	zend_string *const_LISTENER_RELATIVE_name = zend_string_init_interned("LISTENER_RELATIVE", sizeof("LISTENER_RELATIVE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LISTENER_RELATIVE_name, &const_LISTENER_RELATIVE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LISTENER_RELATIVE_name);

	zval const_INAUDIBLE_value;
	ZVAL_LONG(&const_INAUDIBLE_value, SoLoud::AudioSourceInstance::INAUDIBLE);
	zend_string *const_INAUDIBLE_name = zend_string_init_interned("INAUDIBLE", sizeof("INAUDIBLE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_INAUDIBLE_name, &const_INAUDIBLE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_INAUDIBLE_name);

	zval const_INAUDIBLE_KILL_value;
	ZVAL_LONG(&const_INAUDIBLE_KILL_value, SoLoud::AudioSourceInstance::INAUDIBLE_KILL);
	zend_string *const_INAUDIBLE_KILL_name = zend_string_init_interned("INAUDIBLE_KILL", sizeof("INAUDIBLE_KILL") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_INAUDIBLE_KILL_name, &const_INAUDIBLE_KILL_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_INAUDIBLE_KILL_name);

	zval const_INAUDIBLE_TICK_value;
	ZVAL_LONG(&const_INAUDIBLE_TICK_value, SoLoud::AudioSourceInstance::INAUDIBLE_TICK);
	zend_string *const_INAUDIBLE_TICK_name = zend_string_init_interned("INAUDIBLE_TICK", sizeof("INAUDIBLE_TICK") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_INAUDIBLE_TICK_name, &const_INAUDIBLE_TICK_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_INAUDIBLE_TICK_name);

	zval const_DISABLE_AUTOSTOP_value;
	ZVAL_LONG(&const_DISABLE_AUTOSTOP_value, SoLoud::AudioSourceInstance::DISABLE_AUTOSTOP);
	zend_string *const_DISABLE_AUTOSTOP_name = zend_string_init_interned("DISABLE_AUTOSTOP", sizeof("DISABLE_AUTOSTOP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_DISABLE_AUTOSTOP_name, &const_DISABLE_AUTOSTOP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_DISABLE_AUTOSTOP_name);

	zval property_mPlayIndex_default_value;
	ZVAL_UNDEF(&property_mPlayIndex_default_value);
	zend_string *property_mPlayIndex_name = zend_string_init("mPlayIndex", sizeof("mPlayIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPlayIndex_name, &property_mPlayIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mPlayIndex_name);

	zval property_mLoopCount_default_value;
	ZVAL_UNDEF(&property_mLoopCount_default_value);
	zend_string *property_mLoopCount_name = zend_string_init("mLoopCount", sizeof("mLoopCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLoopCount_name, &property_mLoopCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mLoopCount_name);

	zval property_mFlags_default_value;
	ZVAL_UNDEF(&property_mFlags_default_value);
	zend_string *property_mFlags_name = zend_string_init("mFlags", sizeof("mFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFlags_name, &property_mFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFlags_name);

	zval property_mPan_default_value;
	ZVAL_UNDEF(&property_mPan_default_value);
	zend_string *property_mPan_name = zend_string_init("mPan", sizeof("mPan") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPan_name, &property_mPan_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mPan_name);

	zval property_mChannelVolume_default_value;
	ZVAL_UNDEF(&property_mChannelVolume_default_value);
	zend_string *property_mChannelVolume_name = zend_string_init("mChannelVolume", sizeof("mChannelVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannelVolume_name, &property_mChannelVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mChannelVolume_name);

	zval property_mSetVolume_default_value;
	ZVAL_UNDEF(&property_mSetVolume_default_value);
	zend_string *property_mSetVolume_name = zend_string_init("mSetVolume", sizeof("mSetVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSetVolume_name, &property_mSetVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSetVolume_name);

	zval property_mOverallVolume_default_value;
	ZVAL_UNDEF(&property_mOverallVolume_default_value);
	zend_string *property_mOverallVolume_name = zend_string_init("mOverallVolume", sizeof("mOverallVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOverallVolume_name, &property_mOverallVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mOverallVolume_name);

	zval property_mBaseSamplerate_default_value;
	ZVAL_UNDEF(&property_mBaseSamplerate_default_value);
	zend_string *property_mBaseSamplerate_name = zend_string_init("mBaseSamplerate", sizeof("mBaseSamplerate") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBaseSamplerate_name, &property_mBaseSamplerate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mBaseSamplerate_name);

	zval property_mSamplerate_default_value;
	ZVAL_UNDEF(&property_mSamplerate_default_value);
	zend_string *property_mSamplerate_name = zend_string_init("mSamplerate", sizeof("mSamplerate") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSamplerate_name, &property_mSamplerate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSamplerate_name);

	zval property_mChannels_default_value;
	ZVAL_UNDEF(&property_mChannels_default_value);
	zend_string *property_mChannels_name = zend_string_init("mChannels", sizeof("mChannels") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannels_name, &property_mChannels_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mChannels_name);

	zval property_mSetRelativePlaySpeed_default_value;
	ZVAL_UNDEF(&property_mSetRelativePlaySpeed_default_value);
	zend_string *property_mSetRelativePlaySpeed_name = zend_string_init("mSetRelativePlaySpeed", sizeof("mSetRelativePlaySpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSetRelativePlaySpeed_name, &property_mSetRelativePlaySpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSetRelativePlaySpeed_name);

	zval property_mOverallRelativePlaySpeed_default_value;
	ZVAL_UNDEF(&property_mOverallRelativePlaySpeed_default_value);
	zend_string *property_mOverallRelativePlaySpeed_name = zend_string_init("mOverallRelativePlaySpeed", sizeof("mOverallRelativePlaySpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOverallRelativePlaySpeed_name, &property_mOverallRelativePlaySpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mOverallRelativePlaySpeed_name);

	zval property_mStreamTime_default_value;
	ZVAL_UNDEF(&property_mStreamTime_default_value);
	zend_string *property_mStreamTime_name = zend_string_init("mStreamTime", sizeof("mStreamTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_mStreamTime_name, &property_mStreamTime_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mStreamTime_name);

	zval property_mStreamPosition_default_value;
	ZVAL_UNDEF(&property_mStreamPosition_default_value);
	zend_string *property_mStreamPosition_name = zend_string_init("mStreamPosition", sizeof("mStreamPosition") - 1, 1);
	zend_declare_typed_property(class_entry, property_mStreamPosition_name, &property_mStreamPosition_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mStreamPosition_name);

	zval property_mPanFader_default_value;
	ZVAL_UNDEF(&property_mPanFader_default_value);
	zend_string *property_mPanFader_name = zend_string_init("mPanFader", sizeof("mPanFader") - 1, 1);
	zend_string *property_mPanFader_class_SoLoud_Fader = zend_string_init("SoLoud\\Fader", sizeof("SoLoud\\Fader")-1, 1);
	zend_declare_typed_property(class_entry, property_mPanFader_name, &property_mPanFader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mPanFader_class_SoLoud_Fader, 0, 0));
	zend_string_release(property_mPanFader_name);

	zval property_mVolumeFader_default_value;
	ZVAL_UNDEF(&property_mVolumeFader_default_value);
	zend_string *property_mVolumeFader_name = zend_string_init("mVolumeFader", sizeof("mVolumeFader") - 1, 1);
	zend_string *property_mVolumeFader_class_SoLoud_Fader = zend_string_init("SoLoud\\Fader", sizeof("SoLoud\\Fader")-1, 1);
	zend_declare_typed_property(class_entry, property_mVolumeFader_name, &property_mVolumeFader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mVolumeFader_class_SoLoud_Fader, 0, 0));
	zend_string_release(property_mVolumeFader_name);

	zval property_mRelativePlaySpeedFader_default_value;
	ZVAL_UNDEF(&property_mRelativePlaySpeedFader_default_value);
	zend_string *property_mRelativePlaySpeedFader_name = zend_string_init("mRelativePlaySpeedFader", sizeof("mRelativePlaySpeedFader") - 1, 1);
	zend_string *property_mRelativePlaySpeedFader_class_SoLoud_Fader = zend_string_init("SoLoud\\Fader", sizeof("SoLoud\\Fader")-1, 1);
	zend_declare_typed_property(class_entry, property_mRelativePlaySpeedFader_name, &property_mRelativePlaySpeedFader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mRelativePlaySpeedFader_class_SoLoud_Fader, 0, 0));
	zend_string_release(property_mRelativePlaySpeedFader_name);

	zval property_mPauseScheduler_default_value;
	ZVAL_UNDEF(&property_mPauseScheduler_default_value);
	zend_string *property_mPauseScheduler_name = zend_string_init("mPauseScheduler", sizeof("mPauseScheduler") - 1, 1);
	zend_string *property_mPauseScheduler_class_SoLoud_Fader = zend_string_init("SoLoud\\Fader", sizeof("SoLoud\\Fader")-1, 1);
	zend_declare_typed_property(class_entry, property_mPauseScheduler_name, &property_mPauseScheduler_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mPauseScheduler_class_SoLoud_Fader, 0, 0));
	zend_string_release(property_mPauseScheduler_name);

	zval property_mStopScheduler_default_value;
	ZVAL_UNDEF(&property_mStopScheduler_default_value);
	zend_string *property_mStopScheduler_name = zend_string_init("mStopScheduler", sizeof("mStopScheduler") - 1, 1);
	zend_string *property_mStopScheduler_class_SoLoud_Fader = zend_string_init("SoLoud\\Fader", sizeof("SoLoud\\Fader")-1, 1);
	zend_declare_typed_property(class_entry, property_mStopScheduler_name, &property_mStopScheduler_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mStopScheduler_class_SoLoud_Fader, 0, 0));
	zend_string_release(property_mStopScheduler_name);

	zval property_mActiveFader_default_value;
	ZVAL_UNDEF(&property_mActiveFader_default_value);
	zend_string *property_mActiveFader_name = zend_string_init("mActiveFader", sizeof("mActiveFader") - 1, 1);
	zend_declare_typed_property(class_entry, property_mActiveFader_name, &property_mActiveFader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mActiveFader_name);

	zval property_mCurrentChannelVolume_default_value;
	ZVAL_UNDEF(&property_mCurrentChannelVolume_default_value);
	zend_string *property_mCurrentChannelVolume_name = zend_string_init("mCurrentChannelVolume", sizeof("mCurrentChannelVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mCurrentChannelVolume_name, &property_mCurrentChannelVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mCurrentChannelVolume_name);

	zval property_mAudioSourceID_default_value;
	ZVAL_UNDEF(&property_mAudioSourceID_default_value);
	zend_string *property_mAudioSourceID_name = zend_string_init("mAudioSourceID", sizeof("mAudioSourceID") - 1, 1);
	zend_declare_typed_property(class_entry, property_mAudioSourceID_name, &property_mAudioSourceID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mAudioSourceID_name);

	zval property_mBusHandle_default_value;
	ZVAL_UNDEF(&property_mBusHandle_default_value);
	zend_string *property_mBusHandle_name = zend_string_init("mBusHandle", sizeof("mBusHandle") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBusHandle_name, &property_mBusHandle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBusHandle_name);

	zval property_mFilter_default_value;
	ZVAL_UNDEF(&property_mFilter_default_value);
	zend_string *property_mFilter_name = zend_string_init("mFilter", sizeof("mFilter") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFilter_name, &property_mFilter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mFilter_name);

	zval property_mResampleData_default_value;
	ZVAL_UNDEF(&property_mResampleData_default_value);
	zend_string *property_mResampleData_name = zend_string_init("mResampleData", sizeof("mResampleData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mResampleData_name, &property_mResampleData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mResampleData_name);

	zval property_mSrcOffset_default_value;
	ZVAL_UNDEF(&property_mSrcOffset_default_value);
	zend_string *property_mSrcOffset_name = zend_string_init("mSrcOffset", sizeof("mSrcOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSrcOffset_name, &property_mSrcOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mSrcOffset_name);

	zval property_mLeftoverSamples_default_value;
	ZVAL_UNDEF(&property_mLeftoverSamples_default_value);
	zend_string *property_mLeftoverSamples_name = zend_string_init("mLeftoverSamples", sizeof("mLeftoverSamples") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLeftoverSamples_name, &property_mLeftoverSamples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mLeftoverSamples_name);

	zval property_mDelaySamples_default_value;
	ZVAL_UNDEF(&property_mDelaySamples_default_value);
	zend_string *property_mDelaySamples_name = zend_string_init("mDelaySamples", sizeof("mDelaySamples") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDelaySamples_name, &property_mDelaySamples_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mDelaySamples_name);

	zval property_mLoopPoint_default_value;
	ZVAL_UNDEF(&property_mLoopPoint_default_value);
	zend_string *property_mLoopPoint_name = zend_string_init("mLoopPoint", sizeof("mLoopPoint") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLoopPoint_name, &property_mLoopPoint_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mLoopPoint_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_AudioSource(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "AudioSource", class_SoLoud_AudioSource_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	zval const_SHOULD_LOOP_value;
	ZVAL_LONG(&const_SHOULD_LOOP_value, SoLoud::AudioSource::SHOULD_LOOP);
	zend_string *const_SHOULD_LOOP_name = zend_string_init_interned("SHOULD_LOOP", sizeof("SHOULD_LOOP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_SHOULD_LOOP_name, &const_SHOULD_LOOP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_SHOULD_LOOP_name);

	zval const_SINGLE_INSTANCE_value;
	ZVAL_LONG(&const_SINGLE_INSTANCE_value, SoLoud::AudioSource::SINGLE_INSTANCE);
	zend_string *const_SINGLE_INSTANCE_name = zend_string_init_interned("SINGLE_INSTANCE", sizeof("SINGLE_INSTANCE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_SINGLE_INSTANCE_name, &const_SINGLE_INSTANCE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_SINGLE_INSTANCE_name);

	zval const_VISUALIZATION_DATA_value;
	ZVAL_LONG(&const_VISUALIZATION_DATA_value, SoLoud::AudioSource::VISUALIZATION_DATA);
	zend_string *const_VISUALIZATION_DATA_name = zend_string_init_interned("VISUALIZATION_DATA", sizeof("VISUALIZATION_DATA") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_VISUALIZATION_DATA_name, &const_VISUALIZATION_DATA_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_VISUALIZATION_DATA_name);

	zval const_PROCESS_3D_value;
	ZVAL_LONG(&const_PROCESS_3D_value, SoLoud::AudioSource::PROCESS_3D);
	zend_string *const_PROCESS_3D_name = zend_string_init_interned("PROCESS_3D", sizeof("PROCESS_3D") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PROCESS_3D_name, &const_PROCESS_3D_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PROCESS_3D_name);

	zval const_LISTENER_RELATIVE_value;
	ZVAL_LONG(&const_LISTENER_RELATIVE_value, SoLoud::AudioSource::LISTENER_RELATIVE);
	zend_string *const_LISTENER_RELATIVE_name = zend_string_init_interned("LISTENER_RELATIVE", sizeof("LISTENER_RELATIVE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LISTENER_RELATIVE_name, &const_LISTENER_RELATIVE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LISTENER_RELATIVE_name);

	zval const_DISTANCE_DELAY_value;
	ZVAL_LONG(&const_DISTANCE_DELAY_value, SoLoud::AudioSource::DISTANCE_DELAY);
	zend_string *const_DISTANCE_DELAY_name = zend_string_init_interned("DISTANCE_DELAY", sizeof("DISTANCE_DELAY") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_DISTANCE_DELAY_name, &const_DISTANCE_DELAY_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_DISTANCE_DELAY_name);

	zval const_INAUDIBLE_KILL_value;
	ZVAL_LONG(&const_INAUDIBLE_KILL_value, SoLoud::AudioSource::INAUDIBLE_KILL);
	zend_string *const_INAUDIBLE_KILL_name = zend_string_init_interned("INAUDIBLE_KILL", sizeof("INAUDIBLE_KILL") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_INAUDIBLE_KILL_name, &const_INAUDIBLE_KILL_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_INAUDIBLE_KILL_name);

	zval const_INAUDIBLE_TICK_value;
	ZVAL_LONG(&const_INAUDIBLE_TICK_value, SoLoud::AudioSource::INAUDIBLE_TICK);
	zend_string *const_INAUDIBLE_TICK_name = zend_string_init_interned("INAUDIBLE_TICK", sizeof("INAUDIBLE_TICK") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_INAUDIBLE_TICK_name, &const_INAUDIBLE_TICK_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_INAUDIBLE_TICK_name);

	zval const_DISABLE_AUTOSTOP_value;
	ZVAL_LONG(&const_DISABLE_AUTOSTOP_value, SoLoud::AudioSource::DISABLE_AUTOSTOP);
	zend_string *const_DISABLE_AUTOSTOP_name = zend_string_init_interned("DISABLE_AUTOSTOP", sizeof("DISABLE_AUTOSTOP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_DISABLE_AUTOSTOP_name, &const_DISABLE_AUTOSTOP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_DISABLE_AUTOSTOP_name);

	zval const_NO_ATTENUATION_value;
	ZVAL_LONG(&const_NO_ATTENUATION_value, SoLoud::AudioSource::NO_ATTENUATION);
	zend_string *const_NO_ATTENUATION_name = zend_string_init_interned("NO_ATTENUATION", sizeof("NO_ATTENUATION") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_NO_ATTENUATION_name, &const_NO_ATTENUATION_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_NO_ATTENUATION_name);

	zval const_INVERSE_DISTANCE_value;
	ZVAL_LONG(&const_INVERSE_DISTANCE_value, SoLoud::AudioSource::INVERSE_DISTANCE);
	zend_string *const_INVERSE_DISTANCE_name = zend_string_init_interned("INVERSE_DISTANCE", sizeof("INVERSE_DISTANCE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_INVERSE_DISTANCE_name, &const_INVERSE_DISTANCE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_INVERSE_DISTANCE_name);

	zval const_LINEAR_DISTANCE_value;
	ZVAL_LONG(&const_LINEAR_DISTANCE_value, SoLoud::AudioSource::LINEAR_DISTANCE);
	zend_string *const_LINEAR_DISTANCE_name = zend_string_init_interned("LINEAR_DISTANCE", sizeof("LINEAR_DISTANCE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LINEAR_DISTANCE_name, &const_LINEAR_DISTANCE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LINEAR_DISTANCE_name);

	zval const_EXPONENTIAL_DISTANCE_value;
	ZVAL_LONG(&const_EXPONENTIAL_DISTANCE_value, SoLoud::AudioSource::EXPONENTIAL_DISTANCE);
	zend_string *const_EXPONENTIAL_DISTANCE_name = zend_string_init_interned("EXPONENTIAL_DISTANCE", sizeof("EXPONENTIAL_DISTANCE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_EXPONENTIAL_DISTANCE_name, &const_EXPONENTIAL_DISTANCE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_EXPONENTIAL_DISTANCE_name);

	zval property_mFlags_default_value;
	ZVAL_UNDEF(&property_mFlags_default_value);
	zend_string *property_mFlags_name = zend_string_init("mFlags", sizeof("mFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFlags_name, &property_mFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFlags_name);

	zval property_mBaseSamplerate_default_value;
	ZVAL_UNDEF(&property_mBaseSamplerate_default_value);
	zend_string *property_mBaseSamplerate_name = zend_string_init("mBaseSamplerate", sizeof("mBaseSamplerate") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBaseSamplerate_name, &property_mBaseSamplerate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mBaseSamplerate_name);

	zval property_mVolume_default_value;
	ZVAL_UNDEF(&property_mVolume_default_value);
	zend_string *property_mVolume_name = zend_string_init("mVolume", sizeof("mVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVolume_name, &property_mVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mVolume_name);

	zval property_mChannels_default_value;
	ZVAL_UNDEF(&property_mChannels_default_value);
	zend_string *property_mChannels_name = zend_string_init("mChannels", sizeof("mChannels") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannels_name, &property_mChannels_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mChannels_name);

	zval property_mAudioSourceID_default_value;
	ZVAL_UNDEF(&property_mAudioSourceID_default_value);
	zend_string *property_mAudioSourceID_name = zend_string_init("mAudioSourceID", sizeof("mAudioSourceID") - 1, 1);
	zend_declare_typed_property(class_entry, property_mAudioSourceID_name, &property_mAudioSourceID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mAudioSourceID_name);

	zval property_m3dMinDistance_default_value;
	ZVAL_UNDEF(&property_m3dMinDistance_default_value);
	zend_string *property_m3dMinDistance_name = zend_string_init("m3dMinDistance", sizeof("m3dMinDistance") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dMinDistance_name, &property_m3dMinDistance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dMinDistance_name);

	zval property_m3dMaxDistance_default_value;
	ZVAL_UNDEF(&property_m3dMaxDistance_default_value);
	zend_string *property_m3dMaxDistance_name = zend_string_init("m3dMaxDistance", sizeof("m3dMaxDistance") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dMaxDistance_name, &property_m3dMaxDistance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dMaxDistance_name);

	zval property_m3dAttenuationRolloff_default_value;
	ZVAL_UNDEF(&property_m3dAttenuationRolloff_default_value);
	zend_string *property_m3dAttenuationRolloff_name = zend_string_init("m3dAttenuationRolloff", sizeof("m3dAttenuationRolloff") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dAttenuationRolloff_name, &property_m3dAttenuationRolloff_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dAttenuationRolloff_name);

	zval property_m3dAttenuationModel_default_value;
	ZVAL_UNDEF(&property_m3dAttenuationModel_default_value);
	zend_string *property_m3dAttenuationModel_name = zend_string_init("m3dAttenuationModel", sizeof("m3dAttenuationModel") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dAttenuationModel_name, &property_m3dAttenuationModel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_m3dAttenuationModel_name);

	zval property_m3dDopplerFactor_default_value;
	ZVAL_UNDEF(&property_m3dDopplerFactor_default_value);
	zend_string *property_m3dDopplerFactor_name = zend_string_init("m3dDopplerFactor", sizeof("m3dDopplerFactor") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dDopplerFactor_name, &property_m3dDopplerFactor_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dDopplerFactor_name);

	zval property_mFilter_default_value;
	ZVAL_UNDEF(&property_mFilter_default_value);
	zend_string *property_mFilter_name = zend_string_init("mFilter", sizeof("mFilter") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFilter_name, &property_mFilter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mFilter_name);

	zval property_mSoloud_default_value;
	ZVAL_UNDEF(&property_mSoloud_default_value);
	zend_string *property_mSoloud_name = zend_string_init("mSoloud", sizeof("mSoloud") - 1, 1);
	zend_string *property_mSoloud_class_SoLoud_Soloud = zend_string_init("SoLoud\\Soloud", sizeof("SoLoud\\Soloud")-1, 1);
	zend_declare_typed_property(class_entry, property_mSoloud_name, &property_mSoloud_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mSoloud_class_SoLoud_Soloud, 0, MAY_BE_NULL));
	zend_string_release(property_mSoloud_name);

	zval property_mCollider_default_value;
	ZVAL_UNDEF(&property_mCollider_default_value);
	zend_string *property_mCollider_name = zend_string_init("mCollider", sizeof("mCollider") - 1, 1);
	zend_string *property_mCollider_class_SoLoud_AudioCollider = zend_string_init("SoLoud\\AudioCollider", sizeof("SoLoud\\AudioCollider")-1, 1);
	zend_declare_typed_property(class_entry, property_mCollider_name, &property_mCollider_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mCollider_class_SoLoud_AudioCollider, 0, MAY_BE_NULL));
	zend_string_release(property_mCollider_name);

	zval property_mAttenuator_default_value;
	ZVAL_UNDEF(&property_mAttenuator_default_value);
	zend_string *property_mAttenuator_name = zend_string_init("mAttenuator", sizeof("mAttenuator") - 1, 1);
	zend_string *property_mAttenuator_class_SoLoud_AudioAttenuator = zend_string_init("SoLoud\\AudioAttenuator", sizeof("SoLoud\\AudioAttenuator")-1, 1);
	zend_declare_typed_property(class_entry, property_mAttenuator_name, &property_mAttenuator_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mAttenuator_class_SoLoud_AudioAttenuator, 0, MAY_BE_NULL));
	zend_string_release(property_mAttenuator_name);

	zval property_mColliderData_default_value;
	ZVAL_UNDEF(&property_mColliderData_default_value);
	zend_string *property_mColliderData_name = zend_string_init("mColliderData", sizeof("mColliderData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mColliderData_name, &property_mColliderData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mColliderData_name);

	zval property_mLoopPoint_default_value;
	ZVAL_UNDEF(&property_mLoopPoint_default_value);
	zend_string *property_mLoopPoint_name = zend_string_init("mLoopPoint", sizeof("mLoopPoint") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLoopPoint_name, &property_mLoopPoint_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mLoopPoint_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Soloud(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Soloud", class_SoLoud_Soloud_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval const_AUTO_value;
	ZVAL_LONG(&const_AUTO_value, SoLoud::Soloud::AUTO);
	zend_string *const_AUTO_name = zend_string_init_interned("AUTO", sizeof("AUTO") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_AUTO_name, &const_AUTO_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_AUTO_name);

	zval const_SDL1_value;
	ZVAL_LONG(&const_SDL1_value, SoLoud::Soloud::SDL1);
	zend_string *const_SDL1_name = zend_string_init_interned("SDL1", sizeof("SDL1") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_SDL1_name, &const_SDL1_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_SDL1_name);

	zval const_SDL2_value;
	ZVAL_LONG(&const_SDL2_value, SoLoud::Soloud::SDL2);
	zend_string *const_SDL2_name = zend_string_init_interned("SDL2", sizeof("SDL2") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_SDL2_name, &const_SDL2_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_SDL2_name);

	zval const_PORTAUDIO_value;
	ZVAL_LONG(&const_PORTAUDIO_value, SoLoud::Soloud::PORTAUDIO);
	zend_string *const_PORTAUDIO_name = zend_string_init_interned("PORTAUDIO", sizeof("PORTAUDIO") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PORTAUDIO_name, &const_PORTAUDIO_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PORTAUDIO_name);

	zval const_WINMM_value;
	ZVAL_LONG(&const_WINMM_value, SoLoud::Soloud::WINMM);
	zend_string *const_WINMM_name = zend_string_init_interned("WINMM", sizeof("WINMM") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WINMM_name, &const_WINMM_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WINMM_name);

	zval const_XAUDIO2_value;
	ZVAL_LONG(&const_XAUDIO2_value, SoLoud::Soloud::XAUDIO2);
	zend_string *const_XAUDIO2_name = zend_string_init_interned("XAUDIO2", sizeof("XAUDIO2") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_XAUDIO2_name, &const_XAUDIO2_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_XAUDIO2_name);

	zval const_WASAPI_value;
	ZVAL_LONG(&const_WASAPI_value, SoLoud::Soloud::WASAPI);
	zend_string *const_WASAPI_name = zend_string_init_interned("WASAPI", sizeof("WASAPI") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WASAPI_name, &const_WASAPI_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WASAPI_name);

	zval const_ALSA_value;
	ZVAL_LONG(&const_ALSA_value, SoLoud::Soloud::ALSA);
	zend_string *const_ALSA_name = zend_string_init_interned("ALSA", sizeof("ALSA") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_ALSA_name, &const_ALSA_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_ALSA_name);

	zval const_JACK_value;
	ZVAL_LONG(&const_JACK_value, SoLoud::Soloud::JACK);
	zend_string *const_JACK_name = zend_string_init_interned("JACK", sizeof("JACK") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_JACK_name, &const_JACK_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_JACK_name);

	zval const_OSS_value;
	ZVAL_LONG(&const_OSS_value, SoLoud::Soloud::OSS);
	zend_string *const_OSS_name = zend_string_init_interned("OSS", sizeof("OSS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_OSS_name, &const_OSS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_OSS_name);

	zval const_OPENAL_value;
	ZVAL_LONG(&const_OPENAL_value, SoLoud::Soloud::OPENAL);
	zend_string *const_OPENAL_name = zend_string_init_interned("OPENAL", sizeof("OPENAL") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_OPENAL_name, &const_OPENAL_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_OPENAL_name);

	zval const_COREAUDIO_value;
	ZVAL_LONG(&const_COREAUDIO_value, SoLoud::Soloud::COREAUDIO);
	zend_string *const_COREAUDIO_name = zend_string_init_interned("COREAUDIO", sizeof("COREAUDIO") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_COREAUDIO_name, &const_COREAUDIO_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_COREAUDIO_name);

	zval const_OPENSLES_value;
	ZVAL_LONG(&const_OPENSLES_value, SoLoud::Soloud::OPENSLES);
	zend_string *const_OPENSLES_name = zend_string_init_interned("OPENSLES", sizeof("OPENSLES") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_OPENSLES_name, &const_OPENSLES_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_OPENSLES_name);

	zval const_VITA_HOMEBREW_value;
	ZVAL_LONG(&const_VITA_HOMEBREW_value, SoLoud::Soloud::VITA_HOMEBREW);
	zend_string *const_VITA_HOMEBREW_name = zend_string_init_interned("VITA_HOMEBREW", sizeof("VITA_HOMEBREW") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_VITA_HOMEBREW_name, &const_VITA_HOMEBREW_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_VITA_HOMEBREW_name);

	zval const_MINIAUDIO_value;
	ZVAL_LONG(&const_MINIAUDIO_value, SoLoud::Soloud::MINIAUDIO);
	zend_string *const_MINIAUDIO_name = zend_string_init_interned("MINIAUDIO", sizeof("MINIAUDIO") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_MINIAUDIO_name, &const_MINIAUDIO_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_MINIAUDIO_name);

	zval const_NOSOUND_value;
	ZVAL_LONG(&const_NOSOUND_value, SoLoud::Soloud::NOSOUND);
	zend_string *const_NOSOUND_name = zend_string_init_interned("NOSOUND", sizeof("NOSOUND") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_NOSOUND_name, &const_NOSOUND_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_NOSOUND_name);

	zval const_NULLDRIVER_value;
	ZVAL_LONG(&const_NULLDRIVER_value, SoLoud::Soloud::NULLDRIVER);
	zend_string *const_NULLDRIVER_name = zend_string_init_interned("NULLDRIVER", sizeof("NULLDRIVER") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_NULLDRIVER_name, &const_NULLDRIVER_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_NULLDRIVER_name);

	zval const_BACKEND_MAX_value;
	ZVAL_LONG(&const_BACKEND_MAX_value, SoLoud::Soloud::BACKEND_MAX);
	zend_string *const_BACKEND_MAX_name = zend_string_init_interned("BACKEND_MAX", sizeof("BACKEND_MAX") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_BACKEND_MAX_name, &const_BACKEND_MAX_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_BACKEND_MAX_name);

	zval const_CLIP_ROUNDOFF_value;
	ZVAL_LONG(&const_CLIP_ROUNDOFF_value, SoLoud::Soloud::CLIP_ROUNDOFF);
	zend_string *const_CLIP_ROUNDOFF_name = zend_string_init_interned("CLIP_ROUNDOFF", sizeof("CLIP_ROUNDOFF") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_CLIP_ROUNDOFF_name, &const_CLIP_ROUNDOFF_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_CLIP_ROUNDOFF_name);

	zval const_ENABLE_VISUALIZATION_value;
	ZVAL_LONG(&const_ENABLE_VISUALIZATION_value, SoLoud::Soloud::ENABLE_VISUALIZATION);
	zend_string *const_ENABLE_VISUALIZATION_name = zend_string_init_interned("ENABLE_VISUALIZATION", sizeof("ENABLE_VISUALIZATION") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_ENABLE_VISUALIZATION_name, &const_ENABLE_VISUALIZATION_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_ENABLE_VISUALIZATION_name);

	zval const_LEFT_HANDED_3D_value;
	ZVAL_LONG(&const_LEFT_HANDED_3D_value, SoLoud::Soloud::LEFT_HANDED_3D);
	zend_string *const_LEFT_HANDED_3D_name = zend_string_init_interned("LEFT_HANDED_3D", sizeof("LEFT_HANDED_3D") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_LEFT_HANDED_3D_name, &const_LEFT_HANDED_3D_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_LEFT_HANDED_3D_name);

	zval const_NO_FPU_REGISTER_CHANGE_value;
	ZVAL_LONG(&const_NO_FPU_REGISTER_CHANGE_value, SoLoud::Soloud::NO_FPU_REGISTER_CHANGE);
	zend_string *const_NO_FPU_REGISTER_CHANGE_name = zend_string_init_interned("NO_FPU_REGISTER_CHANGE", sizeof("NO_FPU_REGISTER_CHANGE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_NO_FPU_REGISTER_CHANGE_name, &const_NO_FPU_REGISTER_CHANGE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_NO_FPU_REGISTER_CHANGE_name);

	zval const_WAVE_SQUARE_value;
	ZVAL_LONG(&const_WAVE_SQUARE_value, SoLoud::Soloud::WAVE_SQUARE);
	zend_string *const_WAVE_SQUARE_name = zend_string_init_interned("WAVE_SQUARE", sizeof("WAVE_SQUARE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_SQUARE_name, &const_WAVE_SQUARE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_SQUARE_name);

	zval const_WAVE_SAW_value;
	ZVAL_LONG(&const_WAVE_SAW_value, SoLoud::Soloud::WAVE_SAW);
	zend_string *const_WAVE_SAW_name = zend_string_init_interned("WAVE_SAW", sizeof("WAVE_SAW") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_SAW_name, &const_WAVE_SAW_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_SAW_name);

	zval const_WAVE_SIN_value;
	ZVAL_LONG(&const_WAVE_SIN_value, SoLoud::Soloud::WAVE_SIN);
	zend_string *const_WAVE_SIN_name = zend_string_init_interned("WAVE_SIN", sizeof("WAVE_SIN") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_SIN_name, &const_WAVE_SIN_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_SIN_name);

	zval const_WAVE_TRIANGLE_value;
	ZVAL_LONG(&const_WAVE_TRIANGLE_value, SoLoud::Soloud::WAVE_TRIANGLE);
	zend_string *const_WAVE_TRIANGLE_name = zend_string_init_interned("WAVE_TRIANGLE", sizeof("WAVE_TRIANGLE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_TRIANGLE_name, &const_WAVE_TRIANGLE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_TRIANGLE_name);

	zval const_WAVE_BOUNCE_value;
	ZVAL_LONG(&const_WAVE_BOUNCE_value, SoLoud::Soloud::WAVE_BOUNCE);
	zend_string *const_WAVE_BOUNCE_name = zend_string_init_interned("WAVE_BOUNCE", sizeof("WAVE_BOUNCE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_BOUNCE_name, &const_WAVE_BOUNCE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_BOUNCE_name);

	zval const_WAVE_JAWS_value;
	ZVAL_LONG(&const_WAVE_JAWS_value, SoLoud::Soloud::WAVE_JAWS);
	zend_string *const_WAVE_JAWS_name = zend_string_init_interned("WAVE_JAWS", sizeof("WAVE_JAWS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_JAWS_name, &const_WAVE_JAWS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_JAWS_name);

	zval const_WAVE_HUMPS_value;
	ZVAL_LONG(&const_WAVE_HUMPS_value, SoLoud::Soloud::WAVE_HUMPS);
	zend_string *const_WAVE_HUMPS_name = zend_string_init_interned("WAVE_HUMPS", sizeof("WAVE_HUMPS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_HUMPS_name, &const_WAVE_HUMPS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_HUMPS_name);

	zval const_WAVE_FSQUARE_value;
	ZVAL_LONG(&const_WAVE_FSQUARE_value, SoLoud::Soloud::WAVE_FSQUARE);
	zend_string *const_WAVE_FSQUARE_name = zend_string_init_interned("WAVE_FSQUARE", sizeof("WAVE_FSQUARE") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_FSQUARE_name, &const_WAVE_FSQUARE_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_FSQUARE_name);

	zval const_WAVE_FSAW_value;
	ZVAL_LONG(&const_WAVE_FSAW_value, SoLoud::Soloud::WAVE_FSAW);
	zend_string *const_WAVE_FSAW_name = zend_string_init_interned("WAVE_FSAW", sizeof("WAVE_FSAW") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_WAVE_FSAW_name, &const_WAVE_FSAW_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_WAVE_FSAW_name);

	zval const_RESAMPLER_POINT_value;
	ZVAL_LONG(&const_RESAMPLER_POINT_value, SoLoud::Soloud::RESAMPLER_POINT);
	zend_string *const_RESAMPLER_POINT_name = zend_string_init_interned("RESAMPLER_POINT", sizeof("RESAMPLER_POINT") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_RESAMPLER_POINT_name, &const_RESAMPLER_POINT_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_RESAMPLER_POINT_name);

	zval const_RESAMPLER_LINEAR_value;
	ZVAL_LONG(&const_RESAMPLER_LINEAR_value, SoLoud::Soloud::RESAMPLER_LINEAR);
	zend_string *const_RESAMPLER_LINEAR_name = zend_string_init_interned("RESAMPLER_LINEAR", sizeof("RESAMPLER_LINEAR") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_RESAMPLER_LINEAR_name, &const_RESAMPLER_LINEAR_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_RESAMPLER_LINEAR_name);

	zval const_RESAMPLER_CATMULLROM_value;
	ZVAL_LONG(&const_RESAMPLER_CATMULLROM_value, SoLoud::Soloud::RESAMPLER_CATMULLROM);
	zend_string *const_RESAMPLER_CATMULLROM_name = zend_string_init_interned("RESAMPLER_CATMULLROM", sizeof("RESAMPLER_CATMULLROM") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_RESAMPLER_CATMULLROM_name, &const_RESAMPLER_CATMULLROM_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_RESAMPLER_CATMULLROM_name);

	zval property_mBackendData_default_value;
	ZVAL_UNDEF(&property_mBackendData_default_value);
	zend_string *property_mBackendData_name = zend_string_init("mBackendData", sizeof("mBackendData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBackendData_name, &property_mBackendData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBackendData_name);

	zval property_mAudioThreadMutex_default_value;
	ZVAL_UNDEF(&property_mAudioThreadMutex_default_value);
	zend_string *property_mAudioThreadMutex_name = zend_string_init("mAudioThreadMutex", sizeof("mAudioThreadMutex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mAudioThreadMutex_name, &property_mAudioThreadMutex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mAudioThreadMutex_name);

	zval property_mInsideAudioThreadMutex_default_value;
	ZVAL_UNDEF(&property_mInsideAudioThreadMutex_default_value);
	zend_string *property_mInsideAudioThreadMutex_name = zend_string_init("mInsideAudioThreadMutex", sizeof("mInsideAudioThreadMutex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mInsideAudioThreadMutex_name, &property_mInsideAudioThreadMutex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_mInsideAudioThreadMutex_name);

	zval property_mBackendCleanupFunc_default_value;
	ZVAL_UNDEF(&property_mBackendCleanupFunc_default_value);
	zend_string *property_mBackendCleanupFunc_name = zend_string_init("mBackendCleanupFunc", sizeof("mBackendCleanupFunc") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBackendCleanupFunc_name, &property_mBackendCleanupFunc_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBackendCleanupFunc_name);

	zval property_mBackendPauseFunc_default_value;
	ZVAL_UNDEF(&property_mBackendPauseFunc_default_value);
	zend_string *property_mBackendPauseFunc_name = zend_string_init("mBackendPauseFunc", sizeof("mBackendPauseFunc") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBackendPauseFunc_name, &property_mBackendPauseFunc_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBackendPauseFunc_name);

	zval property_mBackendResumeFunc_default_value;
	ZVAL_UNDEF(&property_mBackendResumeFunc_default_value);
	zend_string *property_mBackendResumeFunc_name = zend_string_init("mBackendResumeFunc", sizeof("mBackendResumeFunc") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBackendResumeFunc_name, &property_mBackendResumeFunc_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBackendResumeFunc_name);

	zval property_mMaxActiveVoices_default_value;
	ZVAL_UNDEF(&property_mMaxActiveVoices_default_value);
	zend_string *property_mMaxActiveVoices_name = zend_string_init("mMaxActiveVoices", sizeof("mMaxActiveVoices") - 1, 1);
	zend_declare_typed_property(class_entry, property_mMaxActiveVoices_name, &property_mMaxActiveVoices_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mMaxActiveVoices_name);

	zval property_mHighestVoice_default_value;
	ZVAL_UNDEF(&property_mHighestVoice_default_value);
	zend_string *property_mHighestVoice_name = zend_string_init("mHighestVoice", sizeof("mHighestVoice") - 1, 1);
	zend_declare_typed_property(class_entry, property_mHighestVoice_name, &property_mHighestVoice_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mHighestVoice_name);

	zval property_mScratch_default_value;
	ZVAL_UNDEF(&property_mScratch_default_value);
	zend_string *property_mScratch_name = zend_string_init("mScratch", sizeof("mScratch") - 1, 1);
	zend_string *property_mScratch_class_SoLoud_AlignedFloatBuffer = zend_string_init("SoLoud\\AlignedFloatBuffer", sizeof("SoLoud\\AlignedFloatBuffer")-1, 1);
	zend_declare_typed_property(class_entry, property_mScratch_name, &property_mScratch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mScratch_class_SoLoud_AlignedFloatBuffer, 0, 0));
	zend_string_release(property_mScratch_name);

	zval property_mScratchSize_default_value;
	ZVAL_UNDEF(&property_mScratchSize_default_value);
	zend_string *property_mScratchSize_name = zend_string_init("mScratchSize", sizeof("mScratchSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_mScratchSize_name, &property_mScratchSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mScratchSize_name);

	zval property_mOutputScratch_default_value;
	ZVAL_UNDEF(&property_mOutputScratch_default_value);
	zend_string *property_mOutputScratch_name = zend_string_init("mOutputScratch", sizeof("mOutputScratch") - 1, 1);
	zend_string *property_mOutputScratch_class_SoLoud_AlignedFloatBuffer = zend_string_init("SoLoud\\AlignedFloatBuffer", sizeof("SoLoud\\AlignedFloatBuffer")-1, 1);
	zend_declare_typed_property(class_entry, property_mOutputScratch_name, &property_mOutputScratch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mOutputScratch_class_SoLoud_AlignedFloatBuffer, 0, 0));
	zend_string_release(property_mOutputScratch_name);

	zval property_mResampleData_default_value;
	ZVAL_UNDEF(&property_mResampleData_default_value);
	zend_string *property_mResampleData_name = zend_string_init("mResampleData", sizeof("mResampleData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mResampleData_name, &property_mResampleData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mResampleData_name);

	zval property_mResampleDataBuffer_default_value;
	ZVAL_UNDEF(&property_mResampleDataBuffer_default_value);
	zend_string *property_mResampleDataBuffer_name = zend_string_init("mResampleDataBuffer", sizeof("mResampleDataBuffer") - 1, 1);
	zend_string *property_mResampleDataBuffer_class_SoLoud_AlignedFloatBuffer = zend_string_init("SoLoud\\AlignedFloatBuffer", sizeof("SoLoud\\AlignedFloatBuffer")-1, 1);
	zend_declare_typed_property(class_entry, property_mResampleDataBuffer_name, &property_mResampleDataBuffer_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mResampleDataBuffer_class_SoLoud_AlignedFloatBuffer, 0, 0));
	zend_string_release(property_mResampleDataBuffer_name);

	zval property_mResampleDataOwner_default_value;
	ZVAL_UNDEF(&property_mResampleDataOwner_default_value);
	zend_string *property_mResampleDataOwner_name = zend_string_init("mResampleDataOwner", sizeof("mResampleDataOwner") - 1, 1);
	zend_declare_typed_property(class_entry, property_mResampleDataOwner_name, &property_mResampleDataOwner_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mResampleDataOwner_name);

	zval property_mVoice_default_value;
	ZVAL_UNDEF(&property_mVoice_default_value);
	zend_string *property_mVoice_name = zend_string_init("mVoice", sizeof("mVoice") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVoice_name, &property_mVoice_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mVoice_name);

	zval property_mResampler_default_value;
	ZVAL_UNDEF(&property_mResampler_default_value);
	zend_string *property_mResampler_name = zend_string_init("mResampler", sizeof("mResampler") - 1, 1);
	zend_declare_typed_property(class_entry, property_mResampler_name, &property_mResampler_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mResampler_name);

	zval property_mSamplerate_default_value;
	ZVAL_UNDEF(&property_mSamplerate_default_value);
	zend_string *property_mSamplerate_name = zend_string_init("mSamplerate", sizeof("mSamplerate") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSamplerate_name, &property_mSamplerate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mSamplerate_name);

	zval property_mChannels_default_value;
	ZVAL_UNDEF(&property_mChannels_default_value);
	zend_string *property_mChannels_name = zend_string_init("mChannels", sizeof("mChannels") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannels_name, &property_mChannels_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mChannels_name);

	zval property_mBackendID_default_value;
	ZVAL_UNDEF(&property_mBackendID_default_value);
	zend_string *property_mBackendID_name = zend_string_init("mBackendID", sizeof("mBackendID") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBackendID_name, &property_mBackendID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBackendID_name);

	zval property_mBackendString_default_value;
	ZVAL_UNDEF(&property_mBackendString_default_value);
	zend_string *property_mBackendString_name = zend_string_init("mBackendString", sizeof("mBackendString") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBackendString_name, &property_mBackendString_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_mBackendString_name);

	zval property_mBufferSize_default_value;
	ZVAL_UNDEF(&property_mBufferSize_default_value);
	zend_string *property_mBufferSize_name = zend_string_init("mBufferSize", sizeof("mBufferSize") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBufferSize_name, &property_mBufferSize_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBufferSize_name);

	zval property_mFlags_default_value;
	ZVAL_UNDEF(&property_mFlags_default_value);
	zend_string *property_mFlags_name = zend_string_init("mFlags", sizeof("mFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFlags_name, &property_mFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFlags_name);

	zval property_mGlobalVolume_default_value;
	ZVAL_UNDEF(&property_mGlobalVolume_default_value);
	zend_string *property_mGlobalVolume_name = zend_string_init("mGlobalVolume", sizeof("mGlobalVolume") - 1, 1);
	zend_declare_typed_property(class_entry, property_mGlobalVolume_name, &property_mGlobalVolume_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mGlobalVolume_name);

	zval property_mPostClipScaler_default_value;
	ZVAL_UNDEF(&property_mPostClipScaler_default_value);
	zend_string *property_mPostClipScaler_name = zend_string_init("mPostClipScaler", sizeof("mPostClipScaler") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPostClipScaler_name, &property_mPostClipScaler_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mPostClipScaler_name);

	zval property_mPlayIndex_default_value;
	ZVAL_UNDEF(&property_mPlayIndex_default_value);
	zend_string *property_mPlayIndex_name = zend_string_init("mPlayIndex", sizeof("mPlayIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mPlayIndex_name, &property_mPlayIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mPlayIndex_name);

	zval property_mAudioSourceID_default_value;
	ZVAL_UNDEF(&property_mAudioSourceID_default_value);
	zend_string *property_mAudioSourceID_name = zend_string_init("mAudioSourceID", sizeof("mAudioSourceID") - 1, 1);
	zend_declare_typed_property(class_entry, property_mAudioSourceID_name, &property_mAudioSourceID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mAudioSourceID_name);

	zval property_mGlobalVolumeFader_default_value;
	ZVAL_UNDEF(&property_mGlobalVolumeFader_default_value);
	zend_string *property_mGlobalVolumeFader_name = zend_string_init("mGlobalVolumeFader", sizeof("mGlobalVolumeFader") - 1, 1);
	zend_string *property_mGlobalVolumeFader_class_SoLoud_Fader = zend_string_init("SoLoud\\Fader", sizeof("SoLoud\\Fader")-1, 1);
	zend_declare_typed_property(class_entry, property_mGlobalVolumeFader_name, &property_mGlobalVolumeFader_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mGlobalVolumeFader_class_SoLoud_Fader, 0, 0));
	zend_string_release(property_mGlobalVolumeFader_name);

	zval property_mStreamTime_default_value;
	ZVAL_UNDEF(&property_mStreamTime_default_value);
	zend_string *property_mStreamTime_name = zend_string_init("mStreamTime", sizeof("mStreamTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_mStreamTime_name, &property_mStreamTime_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mStreamTime_name);

	zval property_mLastClockedTime_default_value;
	ZVAL_UNDEF(&property_mLastClockedTime_default_value);
	zend_string *property_mLastClockedTime_name = zend_string_init("mLastClockedTime", sizeof("mLastClockedTime") - 1, 1);
	zend_declare_typed_property(class_entry, property_mLastClockedTime_name, &property_mLastClockedTime_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mLastClockedTime_name);

	zval property_mFilter_default_value;
	ZVAL_UNDEF(&property_mFilter_default_value);
	zend_string *property_mFilter_name = zend_string_init("mFilter", sizeof("mFilter") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFilter_name, &property_mFilter_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mFilter_name);

	zval property_mFilterInstance_default_value;
	ZVAL_UNDEF(&property_mFilterInstance_default_value);
	zend_string *property_mFilterInstance_name = zend_string_init("mFilterInstance", sizeof("mFilterInstance") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFilterInstance_name, &property_mFilterInstance_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mFilterInstance_name);

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

	zval property_m3dPosition_default_value;
	ZVAL_UNDEF(&property_m3dPosition_default_value);
	zend_string *property_m3dPosition_name = zend_string_init("m3dPosition", sizeof("m3dPosition") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dPosition_name, &property_m3dPosition_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m3dPosition_name);

	zval property_m3dAt_default_value;
	ZVAL_UNDEF(&property_m3dAt_default_value);
	zend_string *property_m3dAt_name = zend_string_init("m3dAt", sizeof("m3dAt") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dAt_name, &property_m3dAt_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m3dAt_name);

	zval property_m3dUp_default_value;
	ZVAL_UNDEF(&property_m3dUp_default_value);
	zend_string *property_m3dUp_name = zend_string_init("m3dUp", sizeof("m3dUp") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dUp_name, &property_m3dUp_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m3dUp_name);

	zval property_m3dVelocity_default_value;
	ZVAL_UNDEF(&property_m3dVelocity_default_value);
	zend_string *property_m3dVelocity_name = zend_string_init("m3dVelocity", sizeof("m3dVelocity") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dVelocity_name, &property_m3dVelocity_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m3dVelocity_name);

	zval property_m3dSoundSpeed_default_value;
	ZVAL_UNDEF(&property_m3dSoundSpeed_default_value);
	zend_string *property_m3dSoundSpeed_name = zend_string_init("m3dSoundSpeed", sizeof("m3dSoundSpeed") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dSoundSpeed_name, &property_m3dSoundSpeed_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_m3dSoundSpeed_name);

	zval property_m3dSpeakerPosition_default_value;
	ZVAL_UNDEF(&property_m3dSpeakerPosition_default_value);
	zend_string *property_m3dSpeakerPosition_name = zend_string_init("m3dSpeakerPosition", sizeof("m3dSpeakerPosition") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dSpeakerPosition_name, &property_m3dSpeakerPosition_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_m3dSpeakerPosition_name);

	zval property_m3dData_default_value;
	ZVAL_UNDEF(&property_m3dData_default_value);
	zend_string *property_m3dData_name = zend_string_init("m3dData", sizeof("m3dData") - 1, 1);
	zend_declare_typed_property(class_entry, property_m3dData_name, &property_m3dData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_m3dData_name);

	zval property_mVoiceGroup_default_value;
	ZVAL_UNDEF(&property_mVoiceGroup_default_value);
	zend_string *property_mVoiceGroup_name = zend_string_init("mVoiceGroup", sizeof("mVoiceGroup") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVoiceGroup_name, &property_mVoiceGroup_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mVoiceGroup_name);

	zval property_mVoiceGroupCount_default_value;
	ZVAL_UNDEF(&property_mVoiceGroupCount_default_value);
	zend_string *property_mVoiceGroupCount_name = zend_string_init("mVoiceGroupCount", sizeof("mVoiceGroupCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mVoiceGroupCount_name, &property_mVoiceGroupCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mVoiceGroupCount_name);

	zval property_mActiveVoice_default_value;
	ZVAL_UNDEF(&property_mActiveVoice_default_value);
	zend_string *property_mActiveVoice_name = zend_string_init("mActiveVoice", sizeof("mActiveVoice") - 1, 1);
	zend_declare_typed_property(class_entry, property_mActiveVoice_name, &property_mActiveVoice_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mActiveVoice_name);

	zval property_mActiveVoiceCount_default_value;
	ZVAL_UNDEF(&property_mActiveVoiceCount_default_value);
	zend_string *property_mActiveVoiceCount_name = zend_string_init("mActiveVoiceCount", sizeof("mActiveVoiceCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mActiveVoiceCount_name, &property_mActiveVoiceCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mActiveVoiceCount_name);

	zval property_mActiveVoiceDirty_default_value;
	ZVAL_UNDEF(&property_mActiveVoiceDirty_default_value);
	zend_string *property_mActiveVoiceDirty_name = zend_string_init("mActiveVoiceDirty", sizeof("mActiveVoiceDirty") - 1, 1);
	zend_declare_typed_property(class_entry, property_mActiveVoiceDirty_name, &property_mActiveVoiceDirty_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_mActiveVoiceDirty_name);

	return class_entry;
}
