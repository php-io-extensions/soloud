<?php

declare(strict_types=1);

// The script ends with SoLoud objects live. Request shutdown frees them in object-store order, which
// ignores who points at whom; every order must leave the process clean.

$engineFirst = <<<'PHP'
    $engine = new SoLoud\Soloud();
    $engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2);
    $wav = new SoLoud\Wav();
    $wav->loadRawWave(pack('g*', ...array_fill(0, 4096, 0.5)), 4096, 44100.0, 1, true, false);
    $engine->play($wav);
    $GLOBALS['keep'] = [$engine, $wav];
    return true;
PHP;

$sourceFirst = <<<'PHP'
    $wav = new SoLoud\Wav();
    $wav->loadRawWave(pack('g*', ...array_fill(0, 4096, 0.5)), 4096, 44100.0, 1, true, false);
    $engine = new SoLoud\Soloud();
    $engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2);
    $engine->play($wav);
    $GLOBALS['keep'] = [$wav, $engine];
    return true;
PHP;

$engineDropped = <<<'PHP'
    $engine = new SoLoud\Soloud();
    $engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2);
    $wav = new SoLoud\Wav();
    $wav->loadRawWave(pack('g*', ...array_fill(0, 4096, 0.5)), 4096, 44100.0, 1, true, false);
    $engine->play($wav);
    unset($engine);
    gc_collect_cycles();
    $GLOBALS['keep'] = [$wav];
    return true;
PHP;

$queued = fn (string $order) => <<<PHP
    \$make = [
        'engine' => function () {
            \$e = new SoLoud\Soloud();
            \$e->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2);
            return \$e;
        },
        'bus' => fn () => new SoLoud\Bus(),
        'queue' => fn () => new SoLoud\Queue(),
        'wav' => function () {
            \$w = new SoLoud\Wav();
            \$w->loadRawWave(pack('g*', ...array_fill(0, 4096, 0.5)), 4096, 44100.0, 1, true, false);
            return \$w;
        },
    ];
    \$o = [];
    foreach (explode(',', '$order') as \$k) {
        \$o[\$k] = \$make[\$k]();
    }
    \$o['engine']->play(\$o['bus']);
    \$o['queue']->setParamsFromAudioSource(\$o['wav']);
    \$o['bus']->play(\$o['queue']);
    \$o['queue']->play(\$o['wav']);
    \$o['queue']->play(\$o['wav']);
    \$buffer = '';
    \$o['engine']->mix(\$buffer, 256);
    \$GLOBALS['keep'] = \$o;
    return true;
PHP;

$filtered = fn (string $order) => <<<PHP
    \$o = [];
    foreach (explode(',', '$order') as \$k) {
        \$o[\$k] = match (\$k) {
            'engine' => new SoLoud\Soloud(),
            'wav' => new SoLoud\Wav(),
            'dc' => new SoLoud\DCRemovalFilter(),
            'echo' => new SoLoud\EchoFilter(),
        };
    }
    \$o['engine']->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2);
    \$o['wav']->loadRawWave(pack('g*', ...array_fill(0, 4096, 0.5)), 4096, 44100.0, 1, true, false);
    \$o['wav']->setFilter(0, \$o['dc']);
    \$o['engine']->setGlobalFilter(0, \$o['echo']);
    \$o['engine']->play(\$o['wav']);
    \$o['wav']->setFilter(0, null);
    \$buffer = '';
    \$o['engine']->mix(\$buffer, 256);
    \$GLOBALS['keep'] = \$o;
    return true;
PHP;

// A PHP source and a PHP filter playing at exit. On miniaudio the mixer thread is asking this thread for
// getAudio() when the request ends (silence at volume 0: nothing is heard).
$phpLive = fn (string $order, string $backend) => <<<PHP
    final class ShutInstance extends SoLoud\AudioSourceInstance {
        public function getAudio(?string &\$aBuffer, int \$aSamplesToRead, int \$aBufferSize): int { return \$aSamplesToRead; }
        public function hasEnded(): bool { return false; }
    }
    final class ShutSource extends SoLoud\AudioSource {
        public function createInstance(): ?SoLoud\AudioSourceInstance { return new ShutInstance(); }
    }
    final class ShutFilterInstance extends SoLoud\FilterInstance {
        public function filterChannel(?string &\$aBuffer, int \$aSamples, float \$aSamplerate, float \$aTime, int \$aChannel, int \$aChannels): void {}
    }
    final class ShutFilter extends SoLoud\Filter {
        public function createInstance(): ?SoLoud\FilterInstance { return new ShutFilterInstance(); }
    }
    \$o = [];
    foreach (explode(',', '$order') as \$name) {
        \$o[\$name] = match (\$name) {
            'engine' => new SoLoud\Soloud(),
            'source' => new ShutSource(),
            'filter' => new ShutFilter(),
        };
    }
    \$o['engine']->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::$backend, 44100, 1024, 2);
    \$o['source']->setFilter(0, \$o['filter']);
    \$o['engine']->play(\$o['source'], 0.0);
    \$buffer = '';
    if (SoLoud\Soloud::$backend === SoLoud\Soloud::NULLDRIVER) {
        \$o['engine']->mix(\$buffer, 256);
    } else {
        usleep(100000);
    }
    \$GLOBALS['keep'] = \$o;
    return true;
PHP;

it('exits cleanly with an engine and a playing Wav live', function (string $code) {
    $run = soloudChild($code);

    expect($run['threw'])->toBeNull()
        ->and($run['result'])->toBeTrue()
        ->and($run['signal'])->toBeNull()
        ->and($run['exit'])->toBe(0)
        ->and($run['stderr'])->toBe('')
        ->and($run['survived'])->toBeTrue();
})->with([
    'engine created first' => [$engineFirst],
    'source created first' => [$sourceFirst],
    'engine dropped first' => [$engineDropped],
    'queue in a bus, engine first' => [$queued('engine,bus,queue,wav')],
    'queue in a bus, wav first' => [$queued('wav,queue,bus,engine')],
    'queue in a bus, queue first' => [$queued('queue,wav,engine,bus')],
    'filters, filters first' => [$filtered('dc,echo,wav,engine')],
    'filters, engine first' => [$filtered('engine,wav,dc,echo')],
    'PHP source and filter, engine first' => [$phpLive('engine,source,filter', 'NULLDRIVER')],
    'PHP source and filter, source first' => [$phpLive('source,filter,engine', 'NULLDRIVER')],
    'PHP source on the mixer thread, engine first' => [$phpLive('engine,source,filter', 'MINIAUDIO')],
    'PHP source on the mixer thread, source first' => [$phpLive('filter,source,engine', 'MINIAUDIO')],
]);
