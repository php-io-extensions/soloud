<?php

/** @generate-class-entries */

namespace SoLoud {

/** @not-serializable */
abstract class File
{
    public function read8(): int {}

    public function read16(): int {}

    public function read32(): int {}

    public function eof(): int {}

    public function read(?string &$aDst, int $aBytes): int {}

    public function length(): int {}

    public function seek(int $aOffset): void {}

    public function pos(): int {}

    public function getFilePtr(): int {}

    public function getMemPtr(): ?string {}
}

/** @not-serializable */
class DiskFile extends \SoLoud\File
{
    public int $mFileHandle;

    public function __construct() {}

    public function open(string $aFilename): int {}
}

/** @not-serializable */
class MemoryFile extends \SoLoud\File
{
    public int $mDataPtr;

    public int $mDataLength;

    public int $mOffset;

    public bool $mDataOwned;

    public function __construct() {}

    public function openMem(string $aData, int $aDataLength, bool $aCopy = false, bool $aTakeOwnership = true): int {}

    public function openToMem(string $aFilename): int {}

    public function openFileToMem(?\SoLoud\File $aFile): int {}
}

/** @not-serializable */
class AlignedFloatBuffer
{
    public int $mData;

    public int $mBasePtr;

    public int $mFloats;

    public function __construct() {}

    public function init(int $aFloats): int {}

    public function clear(): void {}
}

/** @not-serializable */
class TinyAlignedFloatBuffer
{
    public int $mData;

    public string $mActualData;

    public function __construct() {}
}

}

namespace SoLoud\Misc {

/** @not-serializable */
class Prg
{
    public array $mState;

    public int $mIndex;

    public function __construct() {}

    public function rand(): int {}

    public function rand_float(): float {}

    public function srand(int $aSeed): void {}
}

function generateWaveform(int $aWaveform, float $p): float {}

}

namespace SoLoud\Thread {

/** @not-serializable */
abstract class PoolTask
{
    public function work(): void {}
}

/** @not-serializable */
class Pool
{
    public int $mThreadCount;

    public int $mThread;

    public int $mWorkMutex;

    public array $mTaskArray;

    public int $mMaxTask;

    public int $mRobin;

    public int $mRunning;

    public function __construct() {}

    public function init(int $aThreadCount): void {}

    public function addWork(?\SoLoud\Thread\PoolTask $aTask): void {}

    public function getWork(): ?\SoLoud\Thread\PoolTask {}
}

function createMutex(): int {}

function destroyMutex(int $aHandle): void {}

function lockMutex(int $aHandle): void {}

function unlockMutex(int $aHandle): void {}

function sleep(int $aMSec): void {}

function getTimeMillis(): int {}

function createThread(callable $aThreadFunction, int $aParameter): int {}

function wait(int $aThreadHandle): void {}

function release(int $aThreadHandle): void {}

}

namespace SoLoud\FFT {

function fft1024(?string &$aBuffer): void {}

function fft256(?string &$aBuffer): void {}

function ifft256(?string &$aBuffer): void {}

function fft(?string &$aBuffer, int $aBufferLength): void {}

function ifft(?string &$aBuffer, int $aBufferLength): void {}

}
