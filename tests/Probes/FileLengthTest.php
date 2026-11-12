<?php

declare(strict_types=1);

// Site soloud-memoryfile-openmem-length: a length past the PHP string. MemoryFile copies aDataLength bytes from it.

$code = '$f = new SoLoud\MemoryFile(); return $f->openMem("data", 1 << 28, true, false);';

it('refuses a length past the string', function () use ($code) {
    $run = soloudChild($code);
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
});

it('reads past the string with the check off', function () use ($code) {
    soloudProbe();
    $run = soloudChild($code, 'soloud-memoryfile-openmem-length');
    expect($run['signal'])->not->toBeNull();
});
