<?php

declare(strict_types=1);

use SoLoud\DiskFile;
use SoLoud\MemoryFile;

it('reads, seeks and reports position on a MemoryFile', function () {
    $f = new MemoryFile();
    expect($f->openMem('0123456789abcdef', 16, false, false))->toBe(0);

    $b = '';
    expect($f->read($b, 4))->toBe(4)
        ->and($b)->toBe('0123')
        ->and($f->pos())->toBe(4)
        ->and($f->length())->toBe(16)
        ->and($f->read8())->toBe(ord('4'))
        ->and($f->getMemPtr())->toBe('0123456789abcdef');

    $f->seek(-2);
    expect($f->pos())->toBe(14)->and($f->eof())->toBe(0);
});

it('reads a DiskFile', function () {
    $path = tempnam(sys_get_temp_dir(), 'soloud');
    file_put_contents($path, 'disk');
    $f = new DiskFile();
    expect($f->open($path))->toBe(0)
        ->and($f->length())->toBe(4)
        ->and($f->getFilePtr())->not->toBe(0);

    $b = '';
    expect($f->read($b, 16))->toBe(4)->and($b)->toBe('disk');
    unset($f);
    unlink($path);
});

it('loads a Wav and a WavStream from a MemoryFile', function () {
    $f = new MemoryFile();
    $f->openMem(supportWav(), strlen(supportWav()), true, false);
    $wav = new SoLoud\Wav();
    $stream = new SoLoud\WavStream();

    expect($wav->loadFile($f))->toBe(0)->and($wav->getLength())->toBeGreaterThan(0.0);

    // SoLoud's loaders read from the file's current position.
    $f->seek(0);
    expect($stream->loadFile($f))->toBe(0);
});

it('holds the File a WavStream streams from', function () {
    $f = new MemoryFile();
    $f->openMem(supportWav(), strlen(supportWav()), true, false);
    $stream = new SoLoud\WavStream();
    $stream->loadFile($f);
    $ref = WeakReference::create($f);
    unset($f);
    gc_collect_cycles();

    expect($ref->get())->not->toBeNull();
});

it('transforms a unit impulse to a flat spectrum', function () {
    $b = pack('g*', 1.0, ...array_fill(0, 255, 0.0));
    SoLoud\FFT\fft256($b);
    $bins = unpack('g*', $b);

    expect(strlen($b))->toBe(256 * 4);
    for ($k = 0; $k < 128; $k++) {
        $mag = hypot($bins[2 * $k + 1], $bins[2 * $k + 2]);
        expect(abs($mag - 1.0))->toBeLessThan(1e-5);
    }
});

it('sizes an FFT buffer from the call', function () {
    $b = '';
    SoLoud\FFT\fft($b, 64);
    SoLoud\FFT\ifft($b, 64);
    expect(strlen($b))->toBe(64 * 4);
});

it('draws WELL512 values from a seed', function () {
    $p = new SoLoud\Misc\Prg();
    $p->srand(1);

    // Upstream's Prg::rand() for seed 1, computed from soloud_misc.cpp.
    expect([$p->rand(), $p->rand(), $p->rand()])->toBe([812122448, 388245880, 2683841656]);
});

it('generates a waveform sample', function () {
    expect(SoLoud\Misc\generateWaveform(SoLoud\Soloud::WAVE_SQUARE, 0.25))->toBe(-0.5)
        ->and(SoLoud\Misc\generateWaveform(SoLoud\Soloud::WAVE_SQUARE, 0.75))->toBe(0.5);
});

it('fades linearly', function () {
    $f = new SoLoud\Fader();
    $f->set(0.0, 1.0, 1.0, 0.0);

    expect(abs($f->get(0.5) - 0.5))->toBeLessThan(1e-6);
});

it('cycles a mutex and reads the clock', function () {
    $m = SoLoud\Thread\createMutex();
    SoLoud\Thread\lockMutex($m);
    SoLoud\Thread\unlockMutex($m);
    SoLoud\Thread\destroyMutex($m);
    $t = SoLoud\Thread\getTimeMillis();
    SoLoud\Thread\sleep(2);

    expect($m)->not->toBe(0)->and(SoLoud\Thread\getTimeMillis())->toBeGreaterThanOrEqual($t);
});

it('allocates an aligned float buffer', function () {
    $b = new SoLoud\AlignedFloatBuffer();

    expect($b->init(16))->toBe(0)->and($b->mFloats)->toBe(16);
    $b->clear();
});

it('runs and joins a thread pool', function () {
    $p = new SoLoud\Thread\Pool();
    $p->init(2);

    expect($p->mThreadCount)->toBe(2);
    unset($p);
});
