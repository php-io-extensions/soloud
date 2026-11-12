<?php

/** @generate-class-entries */

namespace SoLoud {

/** @var int
 * @cvalue SoLoud::WAVSTREAM_WAV
 */
const WAVSTREAM_WAV = UNKNOWN;

/** @var int
 * @cvalue SoLoud::WAVSTREAM_OGG
 */
const WAVSTREAM_OGG = UNKNOWN;

/** @var int
 * @cvalue SoLoud::WAVSTREAM_FLAC
 */
const WAVSTREAM_FLAC = UNKNOWN;

/** @var int
 * @cvalue SoLoud::WAVSTREAM_MP3
 */
const WAVSTREAM_MP3 = UNKNOWN;

/** @not-serializable */
class Wav extends \SoLoud\AudioSource
{
    public int $mData;

    public int $mSampleCount;

    public function __construct() {}

    public function load(string $aFilename): int {}

    public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function loadFile(?\SoLoud\File $aFile): int {}

    public function loadRawWave8(string $aMem, int $aLength, float $aSamplerate = 44100.0, int $aChannels = 1): int {}

    public function loadRawWave16(string $aMem, int $aLength, float $aSamplerate = 44100.0, int $aChannels = 1): int {}

    public function loadRawWave(string $aMem, int $aLength, float $aSamplerate = 44100.0, int $aChannels = 1, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}

    public function getLength(): float {}
}

/** @not-serializable */
class WavInstance extends \SoLoud\AudioSourceInstance
{
    public function __construct(\SoLoud\Wav $aParent) {}

    public function rewind(): int {}

    public function hasEnded(): bool {}
}

/** @not-serializable */
class WavStream extends \SoLoud\AudioSource
{
    public int $mFiletype;

    public ?string $mFilename;

    public ?\SoLoud\File $mMemFile;

    public ?\SoLoud\File $mStreamFile;

    public int $mSampleCount;

    public function __construct() {}

    public function load(string $aFilename): int {}

    public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function loadToMem(string $aFilename): int {}

    public function loadFile(?\SoLoud\File $aFile): int {}

    public function loadFileToMem(?\SoLoud\File $aFile): int {}

    public function createInstance(): ?\SoLoud\AudioSourceInstance {}

    public function getLength(): float {}

    public function parse(?\SoLoud\File $aFile): int {}
}

/** @not-serializable */
class WavStreamInstance extends \SoLoud\AudioSourceInstance
{
    public function __construct(\SoLoud\WavStream $aParent) {}

    public function rewind(): int {}

    public function hasEnded(): bool {}
}

}
