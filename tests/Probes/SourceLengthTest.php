<?php

declare(strict_types=1);

// A length past the PHP string, for the audio sources that load from memory.
// Release build: refused with ValueError. Probe build with that site off: SoLoud reads past the string.

dataset('source lengths', [
    'soloud-ay-loadmem-length' => ['soloud-ay-loadmem-length', '$s = new SoLoud\Ay(); return $s->loadMem("ZXAY", 1 << 28, true, false);'],
    'soloud-monotone-loadmem-length' => ['soloud-monotone-loadmem-length', '$s = new SoLoud\Monotone(); return $s->loadMem("\x08MONOTONE", 1 << 28, true, false);'],
    'soloud-openmpt-loadmem-length' => ['soloud-openmpt-loadmem-length', '$s = new SoLoud\Openmpt(); return $s->loadMem("xm", 1 << 28, true, false);'],
    'soloud-tedsid-loadmem-length' => ['soloud-tedsid-loadmem-length', '$s = new SoLoud\TedSid(); return $s->loadMem("DUMP", 1 << 28, true, false);'],
    'soloud-sfxr-loadparamsmem-length' => ['soloud-sfxr-loadparamsmem-length', '$s = new SoLoud\Sfxr(); return $s->loadParamsMem("\x66\0\0\0", 1 << 28, true, false);'],
]);

it('refuses a length past the string', function (string $site, string $code) {
    $run = soloudChild($code);
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('source lengths');

it('reads past the string with the check off', function (string $site, string $code) {
    soloudProbe();
    $run = soloudChild($code, $site);
    expect($run['signal'])->not->toBeNull();
})->with('source lengths');
