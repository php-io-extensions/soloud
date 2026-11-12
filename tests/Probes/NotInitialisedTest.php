<?php

declare(strict_types=1);

// Soloud::play* on an engine whose init() never succeeded: the voice is made, and stopping it reads the
// resample owners only postinit allocates. Release build: refused. Probe build with that site off: SoLoud faults
// on the stop.

dataset('not initialised sites', [
    'soloud-soloud-play-not-initialised' => ['soloud-soloud-play-not-initialised', '$h = $e->play($w);'],
    'soloud-soloud-playclocked-not-initialised' => ['soloud-soloud-playclocked-not-initialised', '$h = $e->playClocked(0.0, $w);'],
    'soloud-soloud-play3d-not-initialised' => ['soloud-soloud-play3d-not-initialised', '$h = $e->play3d($w, 0.0, 0.0, 0.0);'],
    'soloud-soloud-play3dclocked-not-initialised' => ['soloud-soloud-play3dclocked-not-initialised', '$h = $e->play3dClocked(0.0, $w, 0.0, 0.0, 0.0);'],
    'soloud-soloud-playbackground-not-initialised' => ['soloud-soloud-playbackground-not-initialised', '$h = $e->playBackground($w);'],
]);

$setup = '$e = new SoLoud\Soloud(); $w = new SoLoud\Wav(); $w->loadRawWave(pack(\'g*\', ...array_fill(0, 64, 0.0)), 64);';

it('refuses the call', function (string $site, string $play) use ($setup) {
    $run = soloudChild($setup.$play."\n\$e->stop(\$h);\nreturn true;");
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('not initialised sites');

it('refuses the call after a failed init()', function (string $site, string $play) use ($setup) {
    // SDL2 is not compiled in, so init() fails.
    $run = soloudChild($setup.'$e->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::SDL2);'.$play."\nreturn true;");
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('not initialised sites');

it('faults with the check off', function (string $site, string $play) use ($setup) {
    soloudProbe();
    $run = soloudChild($setup.$play."\n\$e->stop(\$h);\nreturn true;", $site);
    expect($run['signal'])->not->toBeNull();
})->with('not initialised sites');

it('plays after a successful init()', function () use ($setup) {
    $run = soloudChild($setup.'$e->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER); $h = $e->play($w); $e->stop($h); return true;');
    expect($run['threw'])->toBeNull()->and($run['result'])->toBeTrue();
});
