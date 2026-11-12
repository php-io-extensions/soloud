<?php

/** @generate-class-entries */

namespace SoLoud {

/** @not-serializable */
class FilterInstance
{
    public int $mNumParams;

    public int $mParamChanged;

    public int $mParam;

    public ?\SoLoud\Fader $mParamFader;

    public function __construct() {}

    public function initParams(int $aNumParams): int {}

    public function updateParams(float $aTime): void {}

    public function filter(?string &$aBuffer, int $aSamples, int $aBufferSize, int $aChannels, float $aSamplerate, float $aTime): void {}

    public function filterChannel(?string &$aBuffer, int $aSamples, float $aSamplerate, float $aTime, int $aChannel, int $aChannels): void {}

    public function getFilterParameter(int $aAttributeId): float {}

    public function setFilterParameter(int $aAttributeId, float $aValue): void {}

    public function fadeFilterParameter(int $aAttributeId, float $aTo, float $aTime, float $aStartTime): void {}

    public function oscillateFilterParameter(int $aAttributeId, float $aFrom, float $aTo, float $aTime, float $aStartTime): void {}
}

/** @not-serializable */
abstract class Filter
{
    /** @cvalue SoLoud::Filter::FLOAT_PARAM */
    public const int FLOAT_PARAM = UNKNOWN;

    /** @cvalue SoLoud::Filter::INT_PARAM */
    public const int INT_PARAM = UNKNOWN;

    /** @cvalue SoLoud::Filter::BOOL_PARAM */
    public const int BOOL_PARAM = UNKNOWN;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function createInstance(): ?\SoLoud\FilterInstance {}
}

/** @not-serializable */
class FFTFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(?\SoLoud\FFTFilter $aParent = null) {}

    public function fftFilterChannel(?string &$aFFTBuffer, int $aSamples, float $aSamplerate, float $aTime, int $aChannel, int $aChannels): void {}

    public function comp2MagPhase(?string &$aFFTBuffer, int $aSamples): void {}

    public function magPhase2MagFreq(?string &$aFFTBuffer, int $aSamples, float $aSamplerate, int $aChannel): void {}

    public function magFreq2MagPhase(?string &$aFFTBuffer, int $aSamples, float $aSamplerate, int $aChannel): void {}

    public function magPhase2Comp(?string &$aFFTBuffer, int $aSamples): void {}

    public function init(): void {}
}

/** @not-serializable */
class FFTFilter extends \SoLoud\Filter
{
    public function __construct() {}

    public function createInstance(): ?\SoLoud\FilterInstance {}
}

/** @not-serializable */
class BassboostFilterInstance extends \SoLoud\FFTFilterInstance
{
    public function __construct(\SoLoud\BassboostFilter $aParent) {}
}

/** @not-serializable */
class BassboostFilter extends \SoLoud\FFTFilter
{
    /** @cvalue SoLoud::BassboostFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::BassboostFilter::BOOST */
    public const int BOOST = UNKNOWN;

    public float $mBoost;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function setParams(float $aBoost): int {}

    public function createInstance(): ?\SoLoud\FilterInstance {}
}

/** @not-serializable */
abstract class BQRStateData
{
    public float $mY1;

    public float $mY2;

    public float $mX1;

    public float $mX2;
}

/** @not-serializable */
class BiquadResonantFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\BiquadResonantFilter $aParent) {}
}

/** @not-serializable */
class BiquadResonantFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::BiquadResonantFilter::LOWPASS */
    public const int LOWPASS = UNKNOWN;

    /** @cvalue SoLoud::BiquadResonantFilter::HIGHPASS */
    public const int HIGHPASS = UNKNOWN;

    /** @cvalue SoLoud::BiquadResonantFilter::BANDPASS */
    public const int BANDPASS = UNKNOWN;

    /** @cvalue SoLoud::BiquadResonantFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::BiquadResonantFilter::TYPE */
    public const int TYPE = UNKNOWN;

    /** @cvalue SoLoud::BiquadResonantFilter::FREQUENCY */
    public const int FREQUENCY = UNKNOWN;

    /** @cvalue SoLoud::BiquadResonantFilter::RESONANCE */
    public const int RESONANCE = UNKNOWN;

    public int $mFilterType;

    public float $mFrequency;

    public float $mResonance;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function createInstance(): ?\SoLoud\BiquadResonantFilterInstance {}

    public function setParams(int $aType, float $aFrequency, float $aResonance): int {}
}

/** @not-serializable */
class DCRemovalFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\DCRemovalFilter $aParent) {}
}

/** @not-serializable */
class DCRemovalFilter extends \SoLoud\Filter
{
    public float $mLength;

    public function __construct() {}

    public function createInstance(): ?\SoLoud\FilterInstance {}

    public function setParams(float $aLength = 0.100000001): int {}
}

/** @not-serializable */
class DuckFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\DuckFilter $aParent) {}
}

/** @not-serializable */
class DuckFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::DuckFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::DuckFilter::ONRAMP */
    public const int ONRAMP = UNKNOWN;

    /** @cvalue SoLoud::DuckFilter::OFFRAMP */
    public const int OFFRAMP = UNKNOWN;

    /** @cvalue SoLoud::DuckFilter::LEVEL */
    public const int LEVEL = UNKNOWN;

    public ?\SoLoud\Soloud $mSoloud;

    public float $mOnRamp;

    public float $mOffRamp;

    public float $mLevel;

    public int $mListenTo;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function createInstance(): ?\SoLoud\FilterInstance {}

    public function setParams(?\SoLoud\Soloud $aSoloud, int $aListenTo, float $aOnRamp = 0.100000001, float $aOffRamp = 0.5, float $aLevel = 0.100000001): int {}
}

/** @not-serializable */
class EchoFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\EchoFilter $aParent) {}
}

/** @not-serializable */
class EchoFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::EchoFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::EchoFilter::DELAY */
    public const int DELAY = UNKNOWN;

    /** @cvalue SoLoud::EchoFilter::DECAY */
    public const int DECAY = UNKNOWN;

    /** @cvalue SoLoud::EchoFilter::FILTER */
    public const int FILTER = UNKNOWN;

    public float $mDelay;

    public float $mDecay;

    public float $mFilter;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function createInstance(): ?\SoLoud\FilterInstance {}

    public function setParams(float $aDelay, float $aDecay = 0.699999988, float $aFilter = 0.0): int {}
}

/** @not-serializable */
class EqFilterInstance extends \SoLoud\FFTFilterInstance
{
    public function __construct(\SoLoud\EqFilter $aParent) {}
}

/** @not-serializable */
class EqFilter extends \SoLoud\FFTFilter
{
    /** @cvalue SoLoud::EqFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND1 */
    public const int BAND1 = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND2 */
    public const int BAND2 = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND3 */
    public const int BAND3 = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND4 */
    public const int BAND4 = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND5 */
    public const int BAND5 = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND6 */
    public const int BAND6 = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND7 */
    public const int BAND7 = UNKNOWN;

    /** @cvalue SoLoud::EqFilter::BAND8 */
    public const int BAND8 = UNKNOWN;

    public string $mVolume;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function setParam(int $aBand, float $aVolume): int {}

    public function createInstance(): ?\SoLoud\FilterInstance {}
}

/** @not-serializable */
class FlangerFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\FlangerFilter $aParent) {}
}

/** @not-serializable */
class FlangerFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::FlangerFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::FlangerFilter::DELAY */
    public const int DELAY = UNKNOWN;

    /** @cvalue SoLoud::FlangerFilter::FREQ */
    public const int FREQ = UNKNOWN;

    public float $mDelay;

    public float $mFreq;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function createInstance(): ?\SoLoud\FilterInstance {}

    public function setParams(float $aDelay, float $aFreq): int {}
}

/** @not-serializable */
class FreeverbFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\FreeverbFilter $aParent) {}
}

/** @not-serializable */
class FreeverbFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::FreeverbFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::FreeverbFilter::FREEZE */
    public const int FREEZE = UNKNOWN;

    /** @cvalue SoLoud::FreeverbFilter::ROOMSIZE */
    public const int ROOMSIZE = UNKNOWN;

    /** @cvalue SoLoud::FreeverbFilter::DAMP */
    public const int DAMP = UNKNOWN;

    /** @cvalue SoLoud::FreeverbFilter::WIDTH */
    public const int WIDTH = UNKNOWN;

    public float $mMode;

    public float $mRoomSize;

    public float $mDamp;

    public float $mWidth;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function createInstance(): ?\SoLoud\FreeverbFilterInstance {}

    public function setParams(float $aMode, float $aRoomSize, float $aDamp, float $aWidth): int {}
}

/** @not-serializable */
class LofiChannelData
{
    public float $mSample;

    public float $mSamplesToSkip;

    public function __construct(float $mSample = 0.0, float $mSamplesToSkip = 0.0) {}
}

/** @not-serializable */
class LofiFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\LofiFilter $aParent) {}
}

/** @not-serializable */
class LofiFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::LofiFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::LofiFilter::SAMPLERATE */
    public const int SAMPLERATE = UNKNOWN;

    /** @cvalue SoLoud::LofiFilter::BITDEPTH */
    public const int BITDEPTH = UNKNOWN;

    public float $mSampleRate;

    public float $mBitdepth;

    public function __construct() {}

    public function createInstance(): ?\SoLoud\LofiFilterInstance {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function setParams(float $aSampleRate, float $aBitdepth): int {}
}

/** @not-serializable */
class RobotizeFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\RobotizeFilter $aParent) {}
}

/** @not-serializable */
class RobotizeFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::RobotizeFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::RobotizeFilter::FREQ */
    public const int FREQ = UNKNOWN;

    /** @cvalue SoLoud::RobotizeFilter::WAVE */
    public const int WAVE = UNKNOWN;

    public float $mFreq;

    public int $mWave;

    public function __construct() {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}

    public function setParams(float $aFreq, int $aWaveform): void {}

    public function createInstance(): ?\SoLoud\FilterInstance {}
}

/** @not-serializable */
class WaveShaperFilterInstance extends \SoLoud\FilterInstance
{
    public function __construct(\SoLoud\WaveShaperFilter $aParent) {}
}

/** @not-serializable */
class WaveShaperFilter extends \SoLoud\Filter
{
    /** @cvalue SoLoud::WaveShaperFilter::WET */
    public const int WET = UNKNOWN;

    /** @cvalue SoLoud::WaveShaperFilter::AMOUNT */
    public const int AMOUNT = UNKNOWN;

    public float $mAmount;

    public function __construct() {}

    public function createInstance(): ?\SoLoud\WaveShaperFilterInstance {}

    public function setParams(float $aAmount): int {}

    public function getParamCount(): int {}

    public function getParamName(int $aParamIndex): ?string {}

    public function getParamType(int $aParamIndex): int {}

    public function getParamMax(int $aParamIndex): float {}

    public function getParamMin(int $aParamIndex): float {}
}

}
