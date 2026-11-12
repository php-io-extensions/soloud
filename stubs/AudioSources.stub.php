<?php

/** @generate-class-entries */

namespace SoLoud {

/** @not-serializable */
class BusInstance extends \SoLoud\AudioSourceInstance
{
    public ?\SoLoud\Bus $mParent;

    public int $mScratchSize;

    public \SoLoud\AlignedFloatBuffer $mScratch;

    public string $mVisualizationChannelVolume;

    public string $mVisualizationWaveData;

    public function __construct(\SoLoud\Bus $aParent) {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Bus extends \SoLoud\AudioSource
{
    public ?\SoLoud\BusInstance $mInstance;

    public int $mChannelHandle;

    public int $mResampler;

    public string $mFFTData;

    public string $mWaveData;

    public function __construct() {}

    public function createInstance(): ?\SoLoud\BusInstance {}

    public function setFilter(int $aFilterId, ?\SoLoud\Filter $aFilter): void {}

    public function play(\SoLoud\AudioSource $aSound, float $aVolume = 1.0, float $aPan = 0.0, bool $aPaused = false): int {}

    public function playClocked(float $aSoundTime, \SoLoud\AudioSource $aSound, float $aVolume = 1.0, float $aPan = 0.0): int {}

    public function play3d(\SoLoud\AudioSource $aSound, float $aPosX, float $aPosY, float $aPosZ, float $aVelX = 0.0, float $aVelY = 0.0, float $aVelZ = 0.0, float $aVolume = 1.0, bool $aPaused = false): int {}

    public function play3dClocked(float $aSoundTime, \SoLoud\AudioSource $aSound, float $aPosX, float $aPosY, float $aPosZ, float $aVelX = 0.0, float $aVelY = 0.0, float $aVelZ = 0.0, float $aVolume = 1.0): int {}

    public function setChannels(int $aChannels): int {}

    public function setVisualizationEnable(bool $aEnable): void {}

    public function annexSound(int $aVoiceHandle): void {}

    public function calcFFT(): string {}

    public function getWave(): string {}

    public function getApproximateVolume(int $aChannel): float {}

    public function getActiveVoiceCount(): int {}

    public function getResampler(): int {}

    public function setResampler(int $aResampler): void {}

    public function findBusHandle(): void {}
}

/** @not-serializable */
class QueueInstance extends \SoLoud\AudioSourceInstance
{
    public function __construct(\SoLoud\Queue $aParent) {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Queue extends \SoLoud\AudioSource
{
    public int $mReadIndex;

    public int $mWriteIndex;

    public int $mCount;

    public array $mSource;

    public ?\SoLoud\QueueInstance $mInstance;

    public int $mQueueHandle;

    public function __construct() {}

    public function createInstance(): ?\SoLoud\QueueInstance {}

    public function play(\SoLoud\AudioSource $aSound): int {}

    public function getQueueCount(): int {}

    public function isCurrentlyPlaying(\SoLoud\AudioSource $aSound): bool {}

    public function setParamsFromAudioSource(\SoLoud\AudioSource $aSound): int {}

    public function setParams(float $aSamplerate, int $aChannels = 2): int {}

    public function findQueueHandle(): void {}
}

/** @not-serializable */
class SpeechInstance extends \SoLoud\AudioSourceInstance
{
    public function __construct(\SoLoud\Speech $aParent) {}

    public function rewind(): int {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Speech extends \SoLoud\AudioSource
{
    public int $mBaseFrequency;

    public float $mBaseSpeed;

    public float $mBaseDeclination;

    public int $mBaseWaveform;

    public int $mFrames;

    public int $mElement;

    public function __construct() {}

    public function setText(string $aText): int {}

    public function setParams(int $aBaseFrequency = 1330, float $aBaseSpeed = 10.0, float $aBaseDeclination = 0.5, int $aBaseWaveform = 1): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

/** @not-serializable */
class SfxrParams
{
    public int $wave_type;

    public float $p_base_freq;

    public float $p_freq_limit;

    public float $p_freq_ramp;

    public float $p_freq_dramp;

    public float $p_duty;

    public float $p_duty_ramp;

    public float $p_vib_strength;

    public float $p_vib_speed;

    public float $p_vib_delay;

    public float $p_env_attack;

    public float $p_env_sustain;

    public float $p_env_decay;

    public float $p_env_punch;

    public bool $filter_on;

    public float $p_lpf_resonance;

    public float $p_lpf_freq;

    public float $p_lpf_ramp;

    public float $p_hpf_freq;

    public float $p_hpf_ramp;

    public float $p_pha_offset;

    public float $p_pha_ramp;

    public float $p_repeat_speed;

    public float $p_arp_speed;

    public float $p_arp_mod;

    public float $master_vol;

    public float $sound_vol;

    public function __construct(int $wave_type = 0, float $p_base_freq = 0.0, float $p_freq_limit = 0.0, float $p_freq_ramp = 0.0, float $p_freq_dramp = 0.0, float $p_duty = 0.0, float $p_duty_ramp = 0.0, float $p_vib_strength = 0.0, float $p_vib_speed = 0.0, float $p_vib_delay = 0.0, float $p_env_attack = 0.0, float $p_env_sustain = 0.0, float $p_env_decay = 0.0, float $p_env_punch = 0.0, bool $filter_on = false, float $p_lpf_resonance = 0.0, float $p_lpf_freq = 0.0, float $p_lpf_ramp = 0.0, float $p_hpf_freq = 0.0, float $p_hpf_ramp = 0.0, float $p_pha_offset = 0.0, float $p_pha_ramp = 0.0, float $p_repeat_speed = 0.0, float $p_arp_speed = 0.0, float $p_arp_mod = 0.0, float $master_vol = 0.0, float $sound_vol = 0.0) {}
}

/** @not-serializable */
class SfxrInstance extends \SoLoud\AudioSourceInstance
{
    public function __construct(\SoLoud\Sfxr $aParent) {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Sfxr extends \SoLoud\AudioSource
{
    /** @cvalue SoLoud::Sfxr::COIN */
    public const int COIN = UNKNOWN;

    /** @cvalue SoLoud::Sfxr::LASER */
    public const int LASER = UNKNOWN;

    /** @cvalue SoLoud::Sfxr::EXPLOSION */
    public const int EXPLOSION = UNKNOWN;

    /** @cvalue SoLoud::Sfxr::POWERUP */
    public const int POWERUP = UNKNOWN;

    /** @cvalue SoLoud::Sfxr::HURT */
    public const int HURT = UNKNOWN;

    /** @cvalue SoLoud::Sfxr::JUMP */
    public const int JUMP = UNKNOWN;

    /** @cvalue SoLoud::Sfxr::BLIP */
    public const int BLIP = UNKNOWN;

    public \SoLoud\SfxrParams $mParams;

    public \SoLoud\Misc\Prg $mRand;

    public function __construct() {}

    public function resetParams(): void {}

    public function loadParams(string $aFilename): int {}

    public function loadParamsMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function loadParamsFile(?\SoLoud\File $aFile): int {}

    public function loadPreset(int $aPresetNo, int $aRandSeed): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

/** @not-serializable */
class NoiseInstance extends \SoLoud\AudioSourceInstance
{
    public string $mOctaveScale;

    public \SoLoud\Misc\Prg $mPrg;

    public function __construct(\SoLoud\Noise $aParent) {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Noise extends \SoLoud\AudioSource
{
    /** @cvalue SoLoud::Noise::WHITE */
    public const int WHITE = UNKNOWN;

    /** @cvalue SoLoud::Noise::PINK */
    public const int PINK = UNKNOWN;

    /** @cvalue SoLoud::Noise::BROWNISH */
    public const int BROWNISH = UNKNOWN;

    /** @cvalue SoLoud::Noise::BLUEISH */
    public const int BLUEISH = UNKNOWN;

    public string $mOctaveScale;

    public function __construct() {}

    public function setOctaveScale(float $aOct0, float $aOct1, float $aOct2, float $aOct3, float $aOct4, float $aOct5, float $aOct6, float $aOct7, float $aOct8, float $aOct9): void {}

    public function setType(int $aType): void {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

/** @not-serializable */
class MonotoneChannel
{
    public int $mEnabled;

    public int $mActive;

    public array $mFreq;

    public int $mPortamento;

    public int $mArpCounter;

    public int $mArp;

    public int $mLastNote;

    public int $mPortamentoToNote;

    public int $mVibrato;

    public int $mVibratoIndex;

    public int $mVibratoDepth;

    public int $mVibratoSpeed;

    public function __construct(int $mEnabled = 0, int $mActive = 0, int $mPortamento = 0, int $mArpCounter = 0, int $mArp = 0, int $mLastNote = 0, int $mPortamentoToNote = 0, int $mVibrato = 0, int $mVibratoIndex = 0, int $mVibratoDepth = 0, int $mVibratoSpeed = 0) {}
}

/** @not-serializable */
class MonotoneHardwareChannel
{
    public int $mEnabled;

    public float $mSamplePos;

    public float $mSamplePosInc;

    public function __construct(int $mEnabled = 0, float $mSamplePos = 0.0, float $mSamplePosInc = 0.0) {}
}

/** @not-serializable */
class MonotoneSong
{
    public ?string $mTitle;

    public ?string $mComment;

    public int $mVersion;

    public int $mTotalPatterns;

    public int $mTotalTracks;

    public int $mCellSize;

    public string $mOrder;

    public int $mPatternData;

    public function __construct(int $mVersion = 0, int $mTotalPatterns = 0, int $mTotalTracks = 0, int $mCellSize = 0) {}
}

/** @not-serializable */
class MonotoneInstance extends \SoLoud\AudioSourceInstance
{
    public array $mChannel;

    public array $mOutput;

    public int $mNextChannel;

    public int $mTempo;

    public int $mOrder;

    public int $mRow;

    public int $mSampleCount;

    public int $mRowTick;

    public function __construct(\SoLoud\Monotone $aParent) {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Monotone extends \SoLoud\AudioSource
{
    public array $mNotesHz;

    public array $mVibTable;

    public int $mHardwareChannels;

    public int $mWaveform;

    public \SoLoud\MonotoneSong $mSong;

    public function __construct() {}

    public function setParams(int $aHardwareChannels, int $aWaveform = \SoLoud\Soloud::WAVE_SQUARE): int {}

    public function load(string $aFilename): int {}

    public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function loadFile(?\SoLoud\File $aFile): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}

    public function clear(): void {}
}

/** @not-serializable */
class TedSidInstance extends \SoLoud\AudioSourceInstance
{
    public function __construct(\SoLoud\TedSid $aParent) {}

    public function tick(): void {}

    public function hasEnded(): bool {}

    public function getInfo(int $aInfoKey): float {}
}

/** @not-serializable */
class TedSid extends \SoLoud\AudioSource
{
    public int $mLooppos;

    public int $mLength;

    public int $mOps;

    public int $mModel;

    public function __construct() {}

    public function load(string $aFilename): int {}

    public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function loadFile(?\SoLoud\File $aFile): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

/** @not-serializable */
class VicInstance extends \SoLoud\AudioSourceInstance
{
    public ?\SoLoud\Vic $m_parent;

    public array $m_phase;

    public int $m_noisePos;

    public function __construct(\SoLoud\Vic $aParent) {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Vic extends \SoLoud\AudioSource
{
    /** @cvalue SoLoud::Vic::PAL */
    public const int PAL = UNKNOWN;

    /** @cvalue SoLoud::Vic::NTSC */
    public const int NTSC = UNKNOWN;

    /** @cvalue SoLoud::Vic::BASS */
    public const int BASS = UNKNOWN;

    /** @cvalue SoLoud::Vic::ALTO */
    public const int ALTO = UNKNOWN;

    /** @cvalue SoLoud::Vic::SOPRANO */
    public const int SOPRANO = UNKNOWN;

    /** @cvalue SoLoud::Vic::NOISE */
    public const int NOISE = UNKNOWN;

    /** @cvalue SoLoud::Vic::MAX_REGS */
    public const int MAX_REGS = UNKNOWN;

    public int $m_model;

    public string $m_clocks;

    public string $m_regs;

    public string $m_noise;

    public function __construct() {}

    public function setModel(int $model): void {}

    public function getModel(): int {}

    public function setRegister(int $reg, int $value): void {}

    public function getRegister(int $reg): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

/** @not-serializable */
class VizsnResonator
{
    public float $a;

    public float $b;

    public float $c;

    public float $p1;

    public float $p2;

    public function __construct() {}

    public function resonate(float $i): float {}

    public function antiresonate(float $i): float {}
}

/** @not-serializable */
class VizsnBank
{
    public array $r;

    public float $pitch;

    public float $frica;

    public float $voice;

    public float $aspir;

    public float $bypas;

    public float $breth;

    public function __construct() {}
}

/** @not-serializable */
class VizsnInstance extends \SoLoud\AudioSourceInstance
{
    public ?\SoLoud\Vizsn $mParent;

    public \SoLoud\VizsnBank $mBank0;

    public \SoLoud\VizsnBank $mBank1;

    public \SoLoud\VizsnBank $mBank0to1;

    public int $mNper;

    public int $mNmod;

    public int $mNopen;

    public array $mEchobuf;

    public int $mPtr;

    public int $mCurrentVoiceType;

    public float $mPitch;

    public ?string $mS;

    public string $mBuf;

    public int $mBufwrite;

    public int $mBufread;

    public int $mA;

    public int $mB;

    public int $mOrgv;

    public float $mGlotlast;

    public function __construct(\SoLoud\Vizsn $aParent) {}

    public function hasEnded(): bool {}

    public function vcsrc(int $aPitch, int $aVoicetype): float {}

    public function noisrc(): float {}

    public function genwave(): float {}

    public function setphone(?\SoLoud\VizsnBank $aB, int $aP, float $aPitch): void {}

    public function slidePrepare(int $aNumtix): void {}

    public function slideTick(): void {}
}

/** @not-serializable */
class Vizsn extends \SoLoud\AudioSource
{
    public ?string $mText;

    public function __construct() {}

    public function setText(string $aText): void {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

/** @not-serializable */
class AyInstance extends \SoLoud\AudioSourceInstance
{
    public ?\SoLoud\Ay $mParent;

    public int $mChip;

    public int $mPos;

    public function __construct(\SoLoud\Ay $aParent) {}

    public function hasEnded(): bool {}

    public function rewind(): int {}

    public function getInfo(int $aInfoKey): float {}
}

/** @not-serializable */
class Ay extends \SoLoud\AudioSource
{
    public bool $mYm;

    public int $mChipspeed;

    public int $mCpuspeed;

    public int $mLooppos;

    public int $mLength;

    public int $mOps;

    public function __construct() {}

    public function load(string $aFilename): int {}

    public function loadFile(?\SoLoud\File $aFile): int {}

    public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

/** @not-serializable */
class OpenmptInstance extends \SoLoud\AudioSourceInstance
{
    public function __construct(\SoLoud\Openmpt $aParent) {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class Openmpt extends \SoLoud\AudioSource
{
    public ?string $mData;

    public int $mDataLen;

    public function __construct() {}

    public function load(string $aFilename): int {}

    public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function loadFile(?\SoLoud\File $aFile): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}
}

}
