<?php

declare(strict_types=1);

// FilterInstance::initParams() with fewer parameters than SoLoud writes (parameter 0) or the instance reads.
// Release build: refused. Probe build with the site off, under libgmalloc: SoLoud reads past mParam.

it('refuses a parameter count below the instance\'s', function () {
    $run = soloudChild(<<<'PHP'
        $i = new SoLoud\EchoFilterInstance(new SoLoud\EchoFilter());
        $i->initParams(0);
        return true;
    PHP);
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
});

it('reads past the parameters with the check off', function () {
    soloudProbe();
    // EqFilterInstance reads 9 parameters once its FFT window fills; initParams(1) leaves it one.
    $run = soloudChild(<<<'PHP'
        $i = new SoLoud\EqFilterInstance(new SoLoud\EqFilter());
        $i->initParams(1);
        $b = '';
        $i->filter($b, 1024, 1024, 1, 44100.0, 0.0);
        return true;
    PHP, 'soloud-filterinstance-initparams-count', gmalloc: true);
    expect($run['signal'])->not->toBeNull();
});

it('reinitialises at the instance\'s own count', function () {
    $i = new SoLoud\EchoFilterInstance(new SoLoud\EchoFilter());

    expect($i->initParams($i->mNumParams))->toBe(0)
        ->and($i->getFilterParameter(0))->toBe(1.0);
});
