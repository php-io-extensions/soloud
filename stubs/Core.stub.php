<?php

/** @generate-class-entries */

namespace SoLoud {

/** @var int
 * @cvalue SoLoud::SO_NO_ERROR
 */
const SO_NO_ERROR = UNKNOWN;

/** @var int
 * @cvalue SoLoud::INVALID_PARAMETER
 */
const INVALID_PARAMETER = UNKNOWN;

/** @var int
 * @cvalue SoLoud::FILE_NOT_FOUND
 */
const FILE_NOT_FOUND = UNKNOWN;

/** @var int
 * @cvalue SoLoud::FILE_LOAD_FAILED
 */
const FILE_LOAD_FAILED = UNKNOWN;

/** @var int
 * @cvalue SoLoud::DLL_NOT_FOUND
 */
const DLL_NOT_FOUND = UNKNOWN;

/** @var int
 * @cvalue SoLoud::OUT_OF_MEMORY
 */
const OUT_OF_MEMORY = UNKNOWN;

/** @var int
 * @cvalue SoLoud::NOT_IMPLEMENTED
 */
const NOT_IMPLEMENTED = UNKNOWN;

/** @var int
 * @cvalue SoLoud::UNKNOWN_ERROR
 */
const UNKNOWN_ERROR = UNKNOWN;

/** @not-serializable */
class Fader
{
    public float $mFrom;

    public float $mTo;

    public float $mDelta;

    public float $mTime;

    public float $mStartTime;

    public float $mEndTime;

    public float $mCurrent;

    public int $mActive;

    public function __construct() {}

    public function setLFO(float $aFrom, float $aTo, float $aTime, float $aStartTime): void {}

    public function set(float $aFrom, float $aTo, float $aTime, float $aStartTime): void {}

    public function get(float $aCurrentTime): float {}
}

/** @not-serializable */
class AudioSourceInstance3dData
{
    public string $m3dPosition;

    public string $m3dVelocity;

    public float $m3dMinDistance;

    public float $m3dMaxDistance;

    public float $m3dAttenuationRolloff;

    public int $m3dAttenuationModel;

    public float $m3dDopplerFactor;

    public ?\SoLoud\AudioCollider $mCollider;

    public ?\SoLoud\AudioAttenuator $mAttenuator;

    public int $mColliderData;

    public float $mDopplerValue;

    public float $m3dVolume;

    public string $mChannelVolume;

    public int $mFlags;

    public int $mHandle;

    public function __construct() {}

    public function init(\SoLoud\AudioSource $aSource): void {}
}

/** @not-serializable */
abstract class AudioCollider
{
    public function collide(?\SoLoud\Soloud $aSoloud, ?\SoLoud\AudioSourceInstance3dData $aAudioInstance3dData, int $aUserData): float {}
}

/** @not-serializable */
abstract class AudioAttenuator
{
    public function attenuate(float $aDistance, float $aMinDistance, float $aMaxDistance, float $aRolloffFactor): float {}
}

/** @not-serializable */
abstract class AudioSourceInstance
{
    /** @cvalue SoLoud::AudioSourceInstance::LOOPING */
    public const int LOOPING = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::PROTECTED */
    public const int PROTECTED = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::PAUSED */
    public const int PAUSED = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::PROCESS_3D */
    public const int PROCESS_3D = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::LISTENER_RELATIVE */
    public const int LISTENER_RELATIVE = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::INAUDIBLE */
    public const int INAUDIBLE = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::INAUDIBLE_KILL */
    public const int INAUDIBLE_KILL = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::INAUDIBLE_TICK */
    public const int INAUDIBLE_TICK = UNKNOWN;

    /** @cvalue SoLoud::AudioSourceInstance::DISABLE_AUTOSTOP */
    public const int DISABLE_AUTOSTOP = UNKNOWN;

    public int $mPlayIndex;

    public int $mLoopCount;

    public int $mFlags;

    public float $mPan;

    public string $mChannelVolume;

    public float $mSetVolume;

    public float $mOverallVolume;

    public float $mBaseSamplerate;

    public float $mSamplerate;

    public int $mChannels;

    public float $mSetRelativePlaySpeed;

    public float $mOverallRelativePlaySpeed;

    public float $mStreamTime;

    public float $mStreamPosition;

    public \SoLoud\Fader $mPanFader;

    public \SoLoud\Fader $mVolumeFader;

    public \SoLoud\Fader $mRelativePlaySpeedFader;

    public \SoLoud\Fader $mPauseScheduler;

    public \SoLoud\Fader $mStopScheduler;

    public int $mActiveFader;

    public string $mCurrentChannelVolume;

    public int $mAudioSourceID;

    public int $mBusHandle;

    public array $mFilter;

    public array $mResampleData;

    public int $mSrcOffset;

    public int $mLeftoverSamples;

    public int $mDelaySamples;

    public float $mLoopPoint;

    public function __construct() {}

    public function init(\SoLoud\AudioSource $aSource, int $aPlayIndex): void {}

    public function getAudio(?string &$aBuffer, int $aSamplesToRead, int $aBufferSize): int {}

    public function hasEnded(): bool {}

    public function seek(float $aSeconds, ?string &$mScratch, int $mScratchSize): int {}

    public function rewind(): int {}

    public function getInfo(int $aInfoKey): float {}
}

/** @not-serializable */
abstract class AudioSource
{
    /** @cvalue SoLoud::AudioSource::SHOULD_LOOP */
    public const int SHOULD_LOOP = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::SINGLE_INSTANCE */
    public const int SINGLE_INSTANCE = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::VISUALIZATION_DATA */
    public const int VISUALIZATION_DATA = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::PROCESS_3D */
    public const int PROCESS_3D = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::LISTENER_RELATIVE */
    public const int LISTENER_RELATIVE = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::DISTANCE_DELAY */
    public const int DISTANCE_DELAY = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::INAUDIBLE_KILL */
    public const int INAUDIBLE_KILL = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::INAUDIBLE_TICK */
    public const int INAUDIBLE_TICK = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::DISABLE_AUTOSTOP */
    public const int DISABLE_AUTOSTOP = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::NO_ATTENUATION */
    public const int NO_ATTENUATION = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::INVERSE_DISTANCE */
    public const int INVERSE_DISTANCE = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::LINEAR_DISTANCE */
    public const int LINEAR_DISTANCE = UNKNOWN;

    /** @cvalue SoLoud::AudioSource::EXPONENTIAL_DISTANCE */
    public const int EXPONENTIAL_DISTANCE = UNKNOWN;

    public int $mFlags;

    public float $mBaseSamplerate;

    public float $mVolume;

    public int $mChannels;

    public int $mAudioSourceID;

    public float $m3dMinDistance;

    public float $m3dMaxDistance;

    public float $m3dAttenuationRolloff;

    public int $m3dAttenuationModel;

    public float $m3dDopplerFactor;

    public array $mFilter;

    public ?\SoLoud\Soloud $mSoloud;

    public ?\SoLoud\AudioCollider $mCollider;

    public ?\SoLoud\AudioAttenuator $mAttenuator;

    public int $mColliderData;

    public float $mLoopPoint;

    public function __construct() {}

    public function setVolume(float $aVolume): void {}

    public function setLooping(bool $aLoop): void {}

    public function setSingleInstance(bool $aSingleInstance): void {}

    public function setAutoStop(bool $aAutoStop): void {}

    public function set3dMinMaxDistance(float $aMinDistance, float $aMaxDistance): void {}

    public function set3dAttenuation(int $aAttenuationModel, float $aAttenuationRolloffFactor): void {}

    public function set3dDopplerFactor(float $aDopplerFactor): void {}

    public function set3dListenerRelative(bool $aListenerRelative): void {}

    public function set3dDistanceDelay(bool $aDistanceDelay): void {}

    public function set3dCollider(?\SoLoud\AudioCollider $aCollider, int $aUserData = 0): void {}

    public function set3dAttenuator(?\SoLoud\AudioAttenuator $aAttenuator): void {}

    public function setInaudibleBehavior(bool $aMustTick, bool $aKill): void {}

    public function setLoopPoint(float $aLoopPoint): void {}

    public function getLoopPoint(): float {}

    public function setFilter(int $aFilterId, ?\SoLoud\Filter $aFilter): void {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}

    public function stop(): void {}
}

/** @not-serializable */
class Soloud
{
    /** @cvalue SoLoud::Soloud::AUTO */
    public const int AUTO = UNKNOWN;

    /** @cvalue SoLoud::Soloud::SDL1 */
    public const int SDL1 = UNKNOWN;

    /** @cvalue SoLoud::Soloud::SDL2 */
    public const int SDL2 = UNKNOWN;

    /** @cvalue SoLoud::Soloud::PORTAUDIO */
    public const int PORTAUDIO = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WINMM */
    public const int WINMM = UNKNOWN;

    /** @cvalue SoLoud::Soloud::XAUDIO2 */
    public const int XAUDIO2 = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WASAPI */
    public const int WASAPI = UNKNOWN;

    /** @cvalue SoLoud::Soloud::ALSA */
    public const int ALSA = UNKNOWN;

    /** @cvalue SoLoud::Soloud::JACK */
    public const int JACK = UNKNOWN;

    /** @cvalue SoLoud::Soloud::OSS */
    public const int OSS = UNKNOWN;

    /** @cvalue SoLoud::Soloud::OPENAL */
    public const int OPENAL = UNKNOWN;

    /** @cvalue SoLoud::Soloud::COREAUDIO */
    public const int COREAUDIO = UNKNOWN;

    /** @cvalue SoLoud::Soloud::OPENSLES */
    public const int OPENSLES = UNKNOWN;

    /** @cvalue SoLoud::Soloud::VITA_HOMEBREW */
    public const int VITA_HOMEBREW = UNKNOWN;

    /** @cvalue SoLoud::Soloud::MINIAUDIO */
    public const int MINIAUDIO = UNKNOWN;

    /** @cvalue SoLoud::Soloud::NOSOUND */
    public const int NOSOUND = UNKNOWN;

    /** @cvalue SoLoud::Soloud::NULLDRIVER */
    public const int NULLDRIVER = UNKNOWN;

    /** @cvalue SoLoud::Soloud::BACKEND_MAX */
    public const int BACKEND_MAX = UNKNOWN;

    /** @cvalue SoLoud::Soloud::CLIP_ROUNDOFF */
    public const int CLIP_ROUNDOFF = UNKNOWN;

    /** @cvalue SoLoud::Soloud::ENABLE_VISUALIZATION */
    public const int ENABLE_VISUALIZATION = UNKNOWN;

    /** @cvalue SoLoud::Soloud::LEFT_HANDED_3D */
    public const int LEFT_HANDED_3D = UNKNOWN;

    /** @cvalue SoLoud::Soloud::NO_FPU_REGISTER_CHANGE */
    public const int NO_FPU_REGISTER_CHANGE = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_SQUARE */
    public const int WAVE_SQUARE = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_SAW */
    public const int WAVE_SAW = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_SIN */
    public const int WAVE_SIN = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_TRIANGLE */
    public const int WAVE_TRIANGLE = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_BOUNCE */
    public const int WAVE_BOUNCE = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_JAWS */
    public const int WAVE_JAWS = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_HUMPS */
    public const int WAVE_HUMPS = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_FSQUARE */
    public const int WAVE_FSQUARE = UNKNOWN;

    /** @cvalue SoLoud::Soloud::WAVE_FSAW */
    public const int WAVE_FSAW = UNKNOWN;

    /** @cvalue SoLoud::Soloud::RESAMPLER_POINT */
    public const int RESAMPLER_POINT = UNKNOWN;

    /** @cvalue SoLoud::Soloud::RESAMPLER_LINEAR */
    public const int RESAMPLER_LINEAR = UNKNOWN;

    /** @cvalue SoLoud::Soloud::RESAMPLER_CATMULLROM */
    public const int RESAMPLER_CATMULLROM = UNKNOWN;

    public int $mBackendData;

    public int $mAudioThreadMutex;

    public bool $mInsideAudioThreadMutex;

    public int $mBackendCleanupFunc;

    public int $mBackendPauseFunc;

    public int $mBackendResumeFunc;

    public int $mMaxActiveVoices;

    public int $mHighestVoice;

    public \SoLoud\AlignedFloatBuffer $mScratch;

    public int $mScratchSize;

    public \SoLoud\AlignedFloatBuffer $mOutputScratch;

    public int $mResampleData;

    public \SoLoud\AlignedFloatBuffer $mResampleDataBuffer;

    public int $mResampleDataOwner;

    public array $mVoice;

    public int $mResampler;

    public int $mSamplerate;

    public int $mChannels;

    public int $mBackendID;

    public ?string $mBackendString;

    public int $mBufferSize;

    public int $mFlags;

    public float $mGlobalVolume;

    public float $mPostClipScaler;

    public int $mPlayIndex;

    public int $mAudioSourceID;

    public \SoLoud\Fader $mGlobalVolumeFader;

    public float $mStreamTime;

    public float $mLastClockedTime;

    public array $mFilter;

    public array $mFilterInstance;

    public string $mVisualizationChannelVolume;

    public string $mVisualizationWaveData;

    public string $mFFTData;

    public string $mWaveData;

    public string $m3dPosition;

    public string $m3dAt;

    public string $m3dUp;

    public string $m3dVelocity;

    public float $m3dSoundSpeed;

    public string $m3dSpeakerPosition;

    public array $m3dData;

    public int $mVoiceGroup;

    public int $mVoiceGroupCount;

    public array $mActiveVoice;

    public int $mActiveVoiceCount;

    public bool $mActiveVoiceDirty;

    public function __construct() {}

    public function init(int $aFlags = \SoLoud\Soloud::CLIP_ROUNDOFF, int $aBackend = \SoLoud\Soloud::AUTO, int $aSamplerate = \SoLoud\Soloud::AUTO, int $aBufferSize = \SoLoud\Soloud::AUTO, int $aChannels = 2): int {}

    public function pause(): int {}

    public function resume(): int {}

    public function deinit(): void {}

    public function getVersion(): int {}

    public function getErrorString(int $aErrorCode): ?string {}

    public function getBackendId(): int {}

    public function getBackendString(): ?string {}

    public function getBackendChannels(): int {}

    public function getBackendSamplerate(): int {}

    public function getBackendBufferSize(): int {}

    public function setSpeakerPosition(int $aChannel, float $aX, float $aY, float $aZ): int {}

    public function getSpeakerPosition(int $aChannel, ?float &$aX, ?float &$aY, ?float &$aZ): int {}

    public function play(\SoLoud\AudioSource $aSound, float $aVolume = -1.0, float $aPan = 0.0, bool $aPaused = false, int $aBus = 0): int {}

    public function playClocked(float $aSoundTime, \SoLoud\AudioSource $aSound, float $aVolume = -1.0, float $aPan = 0.0, int $aBus = 0): int {}

    public function play3d(\SoLoud\AudioSource $aSound, float $aPosX, float $aPosY, float $aPosZ, float $aVelX = 0.0, float $aVelY = 0.0, float $aVelZ = 0.0, float $aVolume = 1.0, bool $aPaused = false, int $aBus = 0): int {}

    public function play3dClocked(float $aSoundTime, \SoLoud\AudioSource $aSound, float $aPosX, float $aPosY, float $aPosZ, float $aVelX = 0.0, float $aVelY = 0.0, float $aVelZ = 0.0, float $aVolume = 1.0, int $aBus = 0): int {}

    public function playBackground(\SoLoud\AudioSource $aSound, float $aVolume = -1.0, bool $aPaused = false, int $aBus = 0): int {}

    public function seek(int $aVoiceHandle, float $aSeconds): int {}

    public function stop(int $aVoiceHandle): void {}

    public function stopAll(): void {}

    public function stopAudioSource(\SoLoud\AudioSource $aSound): void {}

    public function countAudioSource(\SoLoud\AudioSource $aSound): int {}

    public function setFilterParameter(int $aVoiceHandle, int $aFilterId, int $aAttributeId, float $aValue): void {}

    public function getFilterParameter(int $aVoiceHandle, int $aFilterId, int $aAttributeId): float {}

    public function fadeFilterParameter(int $aVoiceHandle, int $aFilterId, int $aAttributeId, float $aTo, float $aTime): void {}

    public function oscillateFilterParameter(int $aVoiceHandle, int $aFilterId, int $aAttributeId, float $aFrom, float $aTo, float $aTime): void {}

    public function getStreamTime(int $aVoiceHandle): float {}

    public function getStreamPosition(int $aVoiceHandle): float {}

    public function getPause(int $aVoiceHandle): bool {}

    public function getVolume(int $aVoiceHandle): float {}

    public function getOverallVolume(int $aVoiceHandle): float {}

    public function getPan(int $aVoiceHandle): float {}

    public function getSamplerate(int $aVoiceHandle): float {}

    public function getProtectVoice(int $aVoiceHandle): bool {}

    public function getActiveVoiceCount(): int {}

    public function getVoiceCount(): int {}

    public function isValidVoiceHandle(int $aVoiceHandle): bool {}

    public function getRelativePlaySpeed(int $aVoiceHandle): float {}

    public function getPostClipScaler(): float {}

    public function getMainResampler(): int {}

    public function getGlobalVolume(): float {}

    public function getMaxActiveVoiceCount(): int {}

    public function getLooping(int $aVoiceHandle): bool {}

    public function getAutoStop(int $aVoiceHandle): bool {}

    public function getLoopPoint(int $aVoiceHandle): float {}

    public function setLoopPoint(int $aVoiceHandle, float $aLoopPoint): void {}

    public function setLooping(int $aVoiceHandle, bool $aLooping): void {}

    public function setAutoStop(int $aVoiceHandle, bool $aAutoStop): void {}

    public function setMaxActiveVoiceCount(int $aVoiceCount): int {}

    public function setInaudibleBehavior(int $aVoiceHandle, bool $aMustTick, bool $aKill): void {}

    public function setGlobalVolume(float $aVolume): void {}

    public function setPostClipScaler(float $aScaler): void {}

    public function setMainResampler(int $aResampler): void {}

    public function setPause(int $aVoiceHandle, bool $aPause): void {}

    public function setPauseAll(bool $aPause): void {}

    public function setRelativePlaySpeed(int $aVoiceHandle, float $aSpeed): int {}

    public function setProtectVoice(int $aVoiceHandle, bool $aProtect): void {}

    public function setSamplerate(int $aVoiceHandle, float $aSamplerate): void {}

    public function setPan(int $aVoiceHandle, float $aPan): void {}

    public function setPanAbsolute(int $aVoiceHandle, float $aLVolume, float $aRVolume): void {}

    public function setChannelVolume(int $aVoiceHandle, int $aChannel, float $aVolume): void {}

    public function setVolume(int $aVoiceHandle, float $aVolume): void {}

    public function setDelaySamples(int $aVoiceHandle, int $aSamples): void {}

    public function fadeVolume(int $aVoiceHandle, float $aTo, float $aTime): void {}

    public function fadePan(int $aVoiceHandle, float $aTo, float $aTime): void {}

    public function fadeRelativePlaySpeed(int $aVoiceHandle, float $aTo, float $aTime): void {}

    public function fadeGlobalVolume(float $aTo, float $aTime): void {}

    public function schedulePause(int $aVoiceHandle, float $aTime): void {}

    public function scheduleStop(int $aVoiceHandle, float $aTime): void {}

    public function oscillateVolume(int $aVoiceHandle, float $aFrom, float $aTo, float $aTime): void {}

    public function oscillatePan(int $aVoiceHandle, float $aFrom, float $aTo, float $aTime): void {}

    public function oscillateRelativePlaySpeed(int $aVoiceHandle, float $aFrom, float $aTo, float $aTime): void {}

    public function oscillateGlobalVolume(float $aFrom, float $aTo, float $aTime): void {}

    public function setGlobalFilter(int $aFilterId, ?\SoLoud\Filter $aFilter): void {}

    public function setVisualizationEnable(bool $aEnable): void {}

    public function calcFFT(): string {}

    public function getWave(): string {}

    public function getApproximateVolume(int $aChannel): float {}

    public function getLoopCount(int $aVoiceHandle): int {}

    public function getInfo(int $aVoiceHandle, int $aInfoKey): float {}

    public function createVoiceGroup(): int {}

    public function destroyVoiceGroup(int $aVoiceGroupHandle): int {}

    public function addVoiceToGroup(int $aVoiceGroupHandle, int $aVoiceHandle): int {}

    public function isVoiceGroup(int $aVoiceGroupHandle): bool {}

    public function isVoiceGroupEmpty(int $aVoiceGroupHandle): bool {}

    public function update3dAudio(): void {}

    public function set3dSoundSpeed(float $aSpeed): int {}

    public function get3dSoundSpeed(): float {}

    public function set3dListenerParameters(float $aPosX, float $aPosY, float $aPosZ, float $aAtX, float $aAtY, float $aAtZ, float $aUpX, float $aUpY, float $aUpZ, float $aVelocityX = 0.0, float $aVelocityY = 0.0, float $aVelocityZ = 0.0): void {}

    public function set3dListenerPosition(float $aPosX, float $aPosY, float $aPosZ): void {}

    public function set3dListenerAt(float $aAtX, float $aAtY, float $aAtZ): void {}

    public function set3dListenerUp(float $aUpX, float $aUpY, float $aUpZ): void {}

    public function set3dListenerVelocity(float $aVelocityX, float $aVelocityY, float $aVelocityZ): void {}

    public function set3dSourceParameters(int $aVoiceHandle, float $aPosX, float $aPosY, float $aPosZ, float $aVelocityX = 0.0, float $aVelocityY = 0.0, float $aVelocityZ = 0.0): void {}

    public function set3dSourcePosition(int $aVoiceHandle, float $aPosX, float $aPosY, float $aPosZ): void {}

    public function set3dSourceVelocity(int $aVoiceHandle, float $aVelocityX, float $aVelocityY, float $aVelocityZ): void {}

    public function set3dSourceMinMaxDistance(int $aVoiceHandle, float $aMinDistance, float $aMaxDistance): void {}

    public function set3dSourceAttenuation(int $aVoiceHandle, int $aAttenuationModel, float $aAttenuationRolloffFactor): void {}

    public function set3dSourceDopplerFactor(int $aVoiceHandle, float $aDopplerFactor): void {}

    public function mix(?string &$aBuffer, int $aSamples): void {}

    public function mixSigned16(?string &$aBuffer, int $aSamples): void {}
}

}
