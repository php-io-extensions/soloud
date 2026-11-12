<?php

declare(strict_types=1);

/** A 2-channel engine on the null backend. */
function sourceEngine(): SoLoud\Soloud
{
    $engine = new SoLoud\Soloud();
    expect($engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2))->toBe(\SoLoud\SO_NO_ERROR);

    return $engine;
}

/** The largest absolute sample of $frames mixed frames. */
function peak(SoLoud\Soloud $engine, int $frames = 2048): float
{
    $buffer = '';
    $engine->mix($buffer, $frames);

    return max(array_map('abs', unpack('g*', $buffer)));
}

function constant05(): SoLoud\Wav
{
    $wav = new SoLoud\Wav();
    $wav->loadRawWave(pack('g*', ...array_fill(0, 4096, 0.5)), 4096, 44100.0, 1, true, false);

    return $wav;
}

it('mixes a source played inside a bus', function () {
    $engine = sourceEngine();
    $bus = new SoLoud\Bus();
    $engine->play($bus);
    $wav = constant05();
    $bus->play($wav, 1.0, 0.0);

    // Two constant-power pans at centre (the voice in the bus, the bus on the engine), then the roundoff clipper.
    $x = 0.5 * cos(M_PI / 4) * cos(M_PI / 4);
    expect($bus->getActiveVoiceCount())->toBe(1)
        ->and(peak($engine))->toEqualWithDelta((0.87 * $x - 0.1 * $x ** 3) * 0.95, 1e-5);
});

it('queues sources', function () {
    $engine = sourceEngine();
    $queue = new SoLoud\Queue();
    $wav = constant05();
    expect($queue->setParamsFromAudioSource($wav))->toBe(\SoLoud\SO_NO_ERROR);
    $engine->play($queue);
    $queue->play($wav);
    $queue->play($wav);

    expect($queue->getQueueCount())->toBe(2)
        ->and(peak($engine))->toBeGreaterThan(0.25);
});

it('speaks text', function () {
    $engine = sourceEngine();
    $speech = new SoLoud\Speech();
    expect($speech->setText('hello'))->toBe(\SoLoud\SO_NO_ERROR);
    $engine->play($speech);

    expect(peak($engine, 4096))->toBeGreaterThan(0.0);
});

it('plays an sfxr preset and exposes its parameters', function () {
    $engine = sourceEngine();
    $sfxr = new SoLoud\Sfxr();
    expect($sfxr->loadPreset(SoLoud\Sfxr::COIN, 3))->toBe(\SoLoud\SO_NO_ERROR);
    $sfxr->mParams->p_base_freq = 0.5;
    $engine->play($sfxr);

    expect($sfxr->mParams->p_base_freq)->toEqualWithDelta(0.5, 1e-6)
        ->and(peak($engine))->toBeGreaterThan(0.0);
});

it('builds a struct through its aggregate constructor, zero by default', function () {
    $song = new SoLoud\MonotoneSong(3, 4);

    expect($song->mVersion)->toBe(3)
        ->and($song->mTotalPatterns)->toBe(4)
        ->and($song->mTotalTracks)->toBe(0)
        ->and($song->mCellSize)->toBe(0);
});

it('refuses an aggregate field out of its C type', function () {
    new SoLoud\MonotoneSong(256);
})->throws(ValueError::class);

it('generates white noise', function () {
    $engine = sourceEngine();
    $noise = new SoLoud\Noise();
    $noise->setType(SoLoud\Noise::WHITE);
    $engine->play($noise);

    expect(peak($engine))->toBeGreaterThan(0.0);
});

it('reads and writes VIC registers', function () {
    $vic = new SoLoud\Vic();
    $vic->setRegister(SoLoud\Vic::BASS, 200);

    expect($vic->getRegister(SoLoud\Vic::BASS))->toBe(200);
});

it('speaks through vizsn', function () {
    $engine = sourceEngine();
    $vizsn = new SoLoud\Vizsn();
    $vizsn->setText('test');
    $engine->play($vizsn);

    expect(peak($engine, 4096))->toBeGreaterThan(0.0);
});

it('reports missing music files', function (string $class) {
    expect((new $class())->load('/nonexistent/soloud.mod'))->not->toBe(\SoLoud\SO_NO_ERROR);
})->with([SoLoud\Monotone::class, SoLoud\TedSid::class, SoLoud\Ay::class, SoLoud\Openmpt::class]);

it('streams from memory it borrows, after the PHP string is gone', function () {
    $engine = sourceEngine();
    $data = pack('s*', ...array_fill(0, 8820, 16384));
    $file = 'RIFF'.pack('V', 36 + strlen($data)).'WAVE'.'fmt '.pack('VvvVVvv', 16, 1, 1, 44100, 88200, 2, 16).'data'.pack('V', strlen($data)).$data;
    $stream = new SoLoud\WavStream();
    expect($stream->loadMem($file, strlen($file), false, false))->toBe(\SoLoud\SO_NO_ERROR);
    unset($file, $data);
    gc_collect_cycles();
    $engine->play($stream, 1.0, 0.0);

    expect(peak($engine))->toBeGreaterThan(0.25);
});
