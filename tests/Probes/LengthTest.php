<?php

declare(strict_types=1);

// A length past the PHP string. SoLoud reads aLength elements from it.
// Release build: refused with ValueError. Probe build with that site off: SoLoud reads past the string.

dataset('wav lengths', [
    'soloud-wav-loadmem-length' => ['soloud-wav-loadmem-length', '$s = new SoLoud\Wav(); return $s->loadMem("RIFF", 1 << 28, true, false);'],
    'soloud-wavstream-loadmem-length' => ['soloud-wavstream-loadmem-length', '$s = new SoLoud\WavStream(); return $s->loadMem("RIFF", 1 << 28, true, false);'],
    'soloud-wav-loadrawwave8-length' => ['soloud-wav-loadrawwave8-length', '$s = new SoLoud\Wav(); return $s->loadRawWave8("\x80", 1 << 28, 44100.0, 1);'],
    'soloud-wav-loadrawwave16-length' => ['soloud-wav-loadrawwave16-length', '$s = new SoLoud\Wav(); return $s->loadRawWave16("\0\0", 1 << 28, 44100.0, 1);'],
    'soloud-wav-loadrawwave-length' => ['soloud-wav-loadrawwave-length', '$s = new SoLoud\Wav(); return $s->loadRawWave(pack("g", 1.0), 1 << 28, 44100.0, 1, true, false);'],
]);

it('refuses a length past the string', function (string $site, string $code) {
    $run = soloudChild($code);
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('wav lengths');

it('reads past the string with the check off', function (string $site, string $code) {
    soloudProbe();
    $run = soloudChild($code, $site);
    expect($run['signal'])->not->toBeNull();
})->with('wav lengths');
