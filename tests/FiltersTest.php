<?php

declare(strict_types=1);

function filterEngine(): SoLoud\Soloud
{
    $engine = new SoLoud\Soloud();
    expect($engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::NULLDRIVER, 44100, 1024, 2))->toBe(\SoLoud\SO_NO_ERROR);

    return $engine;
}

/** Mono samples from a closure of the frame index. */
function shapedWav(callable $sample, int $frames = 44100): SoLoud\Wav
{
    $wav = new SoLoud\Wav();
    $wav->loadRawWave(pack('g*', ...array_map($sample, range(0, $frames - 1))), $frames, 44100.0, 1, true, false);

    return $wav;
}

function rms(string $buffer): float
{
    $s = unpack('g*', $buffer);

    return sqrt(array_sum(array_map(fn ($x) => $x * $x, $s)) / count($s));
}

it('reports each filter\'s parameters', function (string $class, int $count) {
    $filter = new $class();

    expect($filter->getParamCount())->toBe($count)
        ->and($filter->getParamName(0))->toBeString()->not->toBe('')
        ->and($filter->getParamMax(0))->toBeGreaterThanOrEqual($filter->getParamMin(0));
})->with([
    [SoLoud\BassboostFilter::class, 2],
    [SoLoud\BiquadResonantFilter::class, 4],
    [SoLoud\DCRemovalFilter::class, 1],
    [SoLoud\DuckFilter::class, 4],
    [SoLoud\EchoFilter::class, 4],
    [SoLoud\EqFilter::class, 9],
    [SoLoud\FFTFilter::class, 1],
    [SoLoud\FlangerFilter::class, 3],
    [SoLoud\FreeverbFilter::class, 5],
    [SoLoud\LofiFilter::class, 3],
    [SoLoud\RobotizeFilter::class, 3],
    [SoLoud\WaveShaperFilter::class, 2],
]);

it('low-passes a 10 kHz square wave', function () {
    $engine = filterEngine();
    $square = shapedWav(fn (int $i) => ($i % 4) < 2 ? 0.5 : -0.5);
    $plain = '';
    $h = $engine->play($square);
    $engine->mix($plain, 4096);
    $engine->stop($h);

    $lowpass = new SoLoud\BiquadResonantFilter();
    expect($lowpass->setParams(SoLoud\BiquadResonantFilter::LOWPASS, 100.0, 1.0))->toBe(\SoLoud\SO_NO_ERROR);
    $square->setFilter(0, $lowpass);
    $engine->play($square);
    $filtered = '';
    $engine->mix($filtered, 4096);

    expect(rms($filtered))->toBeLessThan(rms($plain) / 10);
});

it('removes a DC offset', function () {
    $engine = filterEngine();
    $dc = shapedWav(fn () => 0.5);
    $dc->setFilter(0, $removal = new SoLoud\DCRemovalFilter());
    $engine->play($dc);
    $buffer = '';
    for ($i = 0; $i < 8; $i++) {
        $engine->mix($buffer, 4096);
    }
    $last = unpack('g*', $buffer);

    expect(abs(end($last)))->toBeLessThan(0.05);
});

it('round-trips a live filter parameter', function () {
    $engine = filterEngine();
    $wav = shapedWav(fn () => 0.25);
    $wav->setFilter(1, $echo = new SoLoud\EchoFilter());
    $h = $engine->play($wav);
    $engine->setFilterParameter($h, 1, SoLoud\EchoFilter::WET, 0.25);

    expect($engine->getFilterParameter($h, 1, SoLoud\EchoFilter::WET))->toEqualWithDelta(0.25, 1e-6);
});

it('filters a PHP buffer in place, sized by the call', function () {
    $instance = new SoLoud\WaveShaperFilterInstance(new SoLoud\WaveShaperFilter());
    $buffer = pack('g*', ...array_fill(0, 64, 0.5));
    $instance->filter($buffer, 64, 64, 1, 44100.0, 0.0);

    expect(strlen($buffer))->toBe(64 * 4);

    $short = '';
    (new SoLoud\WaveShaperFilterInstance(new SoLoud\WaveShaperFilter()))->filter($short, 16, 32, 2, 44100.0, 0.0);
    expect(strlen($short))->toBe(32 * 2 * 4);
});

it('holds a filter after its slot is reset', function () {
    $wav = shapedWav(fn () => 0.25, 64);
    $filter = new SoLoud\DCRemovalFilter();
    $wav->setFilter(0, $filter);
    $wav->setFilter(0, null);
    $ref = WeakReference::create($filter);
    unset($filter);
    gc_collect_cycles();

    expect($ref->get())->not->toBeNull();
});
