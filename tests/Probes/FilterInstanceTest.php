<?php

declare(strict_types=1);

// Filter-instance processing called from PHP with arguments SoLoud's mixer would never pass.
// Release build: refused. Probe build with that site off, under libgmalloc: SoLoud runs past its state.

dataset('filter sites', [
    'soloud-filterinstance-filter-channels' => ['soloud-filterinstance-filter-channels', <<<'PHP'
        $i = new SoLoud\EchoFilterInstance(new SoLoud\EchoFilter());
        $b = '';
        $i->filter($b, 256, 256, 1, 44100.0, 0.0);
        $i->filter($b, 256, 256, 8, 44100.0, 0.0);
        return true;
    PHP, 'ValueError'],
    'soloud-filterinstance-filterchannel-channels' => ['soloud-filterinstance-filterchannel-channels', <<<'PHP'
        $i = new SoLoud\BiquadResonantFilterInstance(new SoLoud\BiquadResonantFilter());
        $b = '';
        $i->filterChannel($b, 256, 44100.0, 0.0, 12, 1);
        return true;
    PHP, 'ValueError'],
    'soloud-fftfilterinstance-fftfilterchannel-state' => ['soloud-fftfilterinstance-fftfilterchannel-state', <<<'PHP'
        $i = new SoLoud\FFTFilterInstance(new SoLoud\FFTFilter());
        $b = '';
        $i->fftFilterChannel($b, 4, 44100.0, 0.0, 0, 1);
        return true;
    PHP, 'SoLoudException'],
    'soloud-fftfilterinstance-magphase2magfreq-state' => ['soloud-fftfilterinstance-magphase2magfreq-state', <<<'PHP'
        $i = new SoLoud\FFTFilterInstance(new SoLoud\FFTFilter());
        $b = '';
        $i->magPhase2MagFreq($b, 4, 44100.0, 0);
        return true;
    PHP, 'SoLoudException'],
    'soloud-fftfilterinstance-magfreq2magphase-state' => ['soloud-fftfilterinstance-magfreq2magphase-state', <<<'PHP'
        $i = new SoLoud\FFTFilterInstance(new SoLoud\FFTFilter());
        $b = '';
        $i->magFreq2MagPhase($b, 4, 44100.0, 0);
        return true;
    PHP, 'SoLoudException'],
]);

it('refuses the call', function (string $site, string $code, string $class) {
    $run = soloudChild($code);
    expect($run['threw'])->toStartWith($class)->and($run['survived'])->toBeTrue();
})->with('filter sites');

it('runs past the instance state with the check off', function (string $site, string $code) {
    soloudProbe();
    $run = soloudChild($code, $site, gmalloc: true);
    expect($run['signal'])->not->toBeNull();
})->with('filter sites');

it('filters within the instance\'s first channel count', function () {
    $i = new SoLoud\EchoFilterInstance(new SoLoud\EchoFilter());
    $b = '';
    $i->filter($b, 256, 256, 2, 44100.0, 0.0);
    $i->filter($b, 256, 256, 1, 44100.0, 0.0);

    expect(strlen($b))->toBe(256 * 4);
});
