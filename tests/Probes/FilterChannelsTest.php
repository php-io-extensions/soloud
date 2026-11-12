<?php

declare(strict_types=1);

// The mixer runs past filter state sized for fewer channels than it mixes: a LofiFilterInstance holds state
// for 2 channels, and a global filter's instance keeps the size of its first mix across a re-init.
// Release build: refused. Probe build with that site off, under libgmalloc: the mixer faults. Each case keeps
// its sources in variables: a source PHP frees stops its voices, and a stopped voice mixes nothing.

const FILTER_CHANNELS_PRELUDE = <<<'PHP'
    $wav = function (int $channels): SoLoud\Wav {
        $w = new SoLoud\Wav();
        $w->loadRawWave(pack('g*', ...array_fill(0, $channels * 2048, 0.5)), $channels * 2048, 44100.0, $channels, true);
        return $w;
    };
    $e = new SoLoud\Soloud();
    $b = '';
    $mix = function () use ($e, &$b) {
        for ($k = 0; $k < 8; $k++) {
            $e->mix($b, 512);
        }
    };
    $e->init(0, SoLoud\Soloud::NULLDRIVER, 44100, 512, 8);

PHP;

// A 6-channel source with a LofiFilter, and an 8-channel bus playing on the engine. Inline, not closures: the
// probe children allocate only what their case needs, so libgmalloc places the filter state the same way.
const LOFI6 = '$w = $wav(6); $w->setFilter(0, $lf = new SoLoud\LofiFilter()); ';
const BUS8 = '$bb = new SoLoud\Bus(); $bb->setChannels(8); $e->play($bb); ';

dataset('filter channel sites', [
    'soloud-soloud-play-filter-channels' => ['soloud-soloud-play-filter-channels', LOFI6.'$e->play($w);'],
    'soloud-soloud-playclocked-filter-channels' => ['soloud-soloud-playclocked-filter-channels', LOFI6.'$e->playClocked(0.0, $w);'],
    'soloud-soloud-play3d-filter-channels' => ['soloud-soloud-play3d-filter-channels', LOFI6.'$e->play3d($w, 0.0, 0.0, 0.0);'],
    'soloud-soloud-play3dclocked-filter-channels' => ['soloud-soloud-play3dclocked-filter-channels', LOFI6.'$e->play3dClocked(0.0, $w, 0.0, 0.0, 0.0);'],
    'soloud-soloud-playbackground-filter-channels' => ['soloud-soloud-playbackground-filter-channels', LOFI6.'$e->playBackground($w);'],
    'soloud-bus-play-filter-channels' => ['soloud-bus-play-filter-channels', BUS8.LOFI6.'$bb->play($w);'],
    'soloud-bus-playclocked-filter-channels' => ['soloud-bus-playclocked-filter-channels', BUS8.LOFI6.'$bb->playClocked(0.0, $w);'],
    'soloud-bus-play3d-filter-channels' => ['soloud-bus-play3d-filter-channels', BUS8.LOFI6.'$bb->play3d($w, 0.0, 0.0, 0.0);'],
    'soloud-bus-play3dclocked-filter-channels' => ['soloud-bus-play3dclocked-filter-channels', BUS8.LOFI6.'$bb->play3dClocked(0.0, $w, 0.0, 0.0, 0.0);'],
    'soloud-soloud-setglobalfilter-channels' => ['soloud-soloud-setglobalfilter-channels', '$e->setGlobalFilter(0, new SoLoud\LofiFilter()); $e->play($w = $wav(1));'],
    'soloud-soloud-init-filter-channels' => ['soloud-soloud-init-filter-channels', <<<'PHP'
        $e->init(0, SoLoud\Soloud::NULLDRIVER, 44100, 512, 1);
        $e->setGlobalFilter(0, new SoLoud\EchoFilter());
        $w = $wav(1);
        $e->play($w);
        $mix();
        $e->init(0, SoLoud\Soloud::NULLDRIVER, 44100, 512, 8);
        $e->play($w);
    PHP],
]);

it('refuses the call', function (string $site, string $code) {
    $run = soloudChild(FILTER_CHANNELS_PRELUDE.$code."\n\$mix();\nreturn true;");
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('filter channel sites');

it('runs past the filter state with the check off', function (string $site, string $code) {
    soloudProbe();
    $run = soloudChild(FILTER_CHANNELS_PRELUDE.$code."\n\$mix();\nreturn true;", $site, gmalloc: true);
    expect($run['signal'])->not->toBeNull();
})->with('filter channel sites');

it('refuses init() past a LofiFilter global filter', function () {
    $run = soloudChild(<<<'PHP'
        $e = new SoLoud\Soloud();
        $e->setGlobalFilter(0, new SoLoud\LofiFilter());
        $e->init(0, SoLoud\Soloud::NULLDRIVER, 44100, 512, 4);
        return true;
    PHP);
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
});

it('mixes a LofiFilter on 2 channels and a re-init with the filter set again', function () {
    $run = soloudChild(FILTER_CHANNELS_PRELUDE.<<<'PHP'
        $w = $wav(2);
        $w->setFilter(0, new SoLoud\LofiFilter());
        $e->play($w);
        $mix();
        $e->deinit();
        $e->init(0, SoLoud\Soloud::NULLDRIVER, 44100, 512, 1);
        $e->setGlobalFilter(0, new SoLoud\EchoFilter());
        $e->play($wav(1));
        $mix();
        $e->deinit();
        $e->setGlobalFilter(0, new SoLoud\EchoFilter());
        $e->init(0, SoLoud\Soloud::NULLDRIVER, 44100, 512, 8);
        $e->play($wav(1));
        $mix();
        return true;
    PHP);
    expect($run['result'])->toBeTrue();
});
