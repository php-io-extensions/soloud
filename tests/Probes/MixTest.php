<?php

declare(strict_types=1);

// Soloud::mix / mixSigned16 write mChannels rows of the sample count rounded up to 16 into scratch buffers of
// mScratchSize * MAX_CHANNELS floats (soloud.cpp:597-601). A 2-channel engine with a 1024-frame buffer has
// mScratchSize 4096: 16384 samples fit, 16400 do not. Before init() the scratch is empty: 0 samples fit.

$mix = fn (string $call, int $samples) => <<<PHP
    \$engine = new SoLoud\Soloud();
    \$engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2);
    \$wav = new SoLoud\Wav();
    \$wav->loadRawWave(pack('g*', ...array_fill(0, 4096, 0.5)), 4096, 44100.0, 1, true, false);
    \$engine->play(\$wav);
    \$buffer = '';
    \$engine->$call(\$buffer, $samples);
    return strlen(\$buffer);
PHP;

$uninitialised = fn (string $call) => <<<PHP
    \$engine = new SoLoud\Soloud();
    \$buffer = '';
    \$engine->$call(\$buffer, 256);
    return strlen(\$buffer);
PHP;

dataset('mix sites', [
    'soloud-mix-samples' => ['soloud-mix-samples', 'mix', 4],
    'soloud-mixsigned16-samples' => ['soloud-mixsigned16-samples', 'mixSigned16', 2],
]);

it('mixes exactly the scratch size', function (string $site, string $call, int $bytes) use ($mix) {
    $run = soloudChild($mix($call, 16384));
    expect($run['result'])->toBe(16384 * 2 * $bytes);
})->with('mix sites');

it('refuses one block more than the scratch holds', function (string $site, string $call) use ($mix) {
    $run = soloudChild($mix($call, 16400));
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('mix sites');

it('refuses a mix before init', function (string $site, string $call) use ($uninitialised) {
    $run = soloudChild($uninitialised($call));
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('mix sites');

it('writes past the scratch with the check off', function (string $site, string $call) use ($mix) {
    soloudProbe();
    $run = soloudChild($mix($call, 16400), $site, gmalloc: true);
    expect($run['signal'])->not->toBeNull();
})->with('mix sites');

it('dereferences the empty scratch before init with the check off', function (string $site, string $call) use ($uninitialised) {
    soloudProbe();
    $run = soloudChild($uninitialised($call), $site, gmalloc: true);
    expect($run['signal'])->not->toBeNull();
})->with('mix sites');
