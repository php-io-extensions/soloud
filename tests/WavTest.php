<?php

declare(strict_types=1);

use SoLoud\Wav;
use SoLoud\WavStream;

/** A 16-bit PCM mono RIFF/WAVE file of $samples. */
function wavFile(array $samples, int $rate = 44100): string
{
    $data = pack('s*', ...$samples);

    return 'RIFF'.pack('V', 36 + strlen($data)).'WAVE'
        .'fmt '.pack('VvvVVvv', 16, 1, 1, $rate, $rate * 2, 2, 16)
        .'data'.pack('V', strlen($data)).$data;
}

dataset('ownership', [
    'copy' => [true, false],
    'take ownership' => [false, true],
    'borrow' => [false, false],
]);

it('loads a WAV file from memory', function (bool $copy, bool $own) {
    $file = wavFile(array_fill(0, 4410, 1000));
    $wav = new Wav();

    expect($wav->loadMem($file, strlen($file), $copy, $own))->toBe(\SoLoud\SO_NO_ERROR)
        ->and($wav->getLength())->toEqualWithDelta(0.1, 1e-6)
        ->and($wav->mSampleCount)->toBe(4410);
})->with('ownership');

it('loads raw 8-bit samples', function () {
    $wav = new Wav();
    expect($wav->loadRawWave8(str_repeat("\xC0", 100), 100, 22050.0, 1))->toBe(\SoLoud\SO_NO_ERROR)
        ->and($wav->mSampleCount)->toBe(100)
        ->and($wav->getLength())->toEqualWithDelta(100 / 22050, 1e-6);
});

it('loads raw 16-bit samples', function () {
    $wav = new Wav();
    expect($wav->loadRawWave16(pack('s*', ...array_fill(0, 50, 16384)), 50, 44100.0, 2))->toBe(\SoLoud\SO_NO_ERROR)
        ->and($wav->mSampleCount)->toBe(25);
});

it('loads raw float samples under each ownership', function (bool $copy, bool $own) {
    $wav = new Wav();
    expect($wav->loadRawWave(pack('g*', 0.1, 0.2, 0.3, 0.4), 4, 8000.0, 1, $copy, $own))->toBe(\SoLoud\SO_NO_ERROR)
        ->and($wav->mSampleCount)->toBe(4);
})->with('ownership');

it('reports a missing file', function () {
    expect((new Wav())->load('/nonexistent/soloud.wav'))->toBe(\SoLoud\FILE_NOT_FOUND)
        ->and((new WavStream())->load('/nonexistent/soloud.wav'))->toBe(\SoLoud\FILE_NOT_FOUND);
});

it('streams a WAV file from memory', function (bool $copy, bool $own) {
    $file = wavFile(array_fill(0, 8820, 1000));
    $stream = new WavStream();

    expect($stream->loadMem($file, strlen($file), $copy, $own))->toBe(\SoLoud\SO_NO_ERROR)
        ->and($stream->getLength())->toEqualWithDelta(0.2, 1e-6)
        ->and($stream->mSampleCount)->toBe(8820);
})->with('ownership');
