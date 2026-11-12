<?php

declare(strict_types=1);

// Aliased: a bare "use SoLoud\Soloud;" would also capture every SoLoud\... name (PHP matches aliases
// case-insensitively).
use SoLoud\Soloud as Engine;

/** A PHP source whose instances produce $value on every channel, counting getAudio calls. */
final class ConstantSource extends SoLoud\AudioSource
{
    public int $calls = 0;

    public ?Throwable $throw = null;

    public function __construct(public float $value = 0.25)
    {
        $this->mChannels = 1;
        $this->mBaseSamplerate = 44100.0;
    }

    public function createInstance(): ?SoLoud\AudioSourceInstance
    {
        return new ConstantInstance($this);
    }
}

final class ConstantInstance extends SoLoud\AudioSourceInstance
{
    public function __construct(private ConstantSource $source) {}

    public function getAudio(?string &$aBuffer, int $aSamplesToRead, int $aBufferSize): int
    {
        $this->source->calls++;
        if ($this->source->throw !== null) {
            throw $this->source->throw;
        }
        $aBuffer = pack('g*', ...array_fill(0, $aBufferSize, $this->source->value));

        return $aSamplesToRead;
    }

    public function hasEnded(): bool
    {
        return false;
    }
}

final class HalvingFilter extends SoLoud\Filter
{
    public function createInstance(): ?SoLoud\FilterInstance
    {
        return new HalvingInstance();
    }
}

final class HalvingInstance extends SoLoud\FilterInstance
{
    public function filterChannel(?string &$aBuffer, int $aSamples, float $aSamplerate, float $aTime, int $aChannel, int $aChannels): void
    {
        $aBuffer = pack('g*', ...array_map(fn (float $s) => $s / 2, array_values(unpack('g*', $aBuffer))));
    }
}

final class HalfAttenuator extends SoLoud\AudioAttenuator
{
    public function attenuate(float $aDistance, float $aMinDistance, float $aMaxDistance, float $aRolloffFactor): float
    {
        return 0.5;
    }
}

/** A File serving $bytes from memory. */
final class StringFile extends SoLoud\File
{
    private int $at = 0;

    public function __construct(private string $bytes) {}

    public function eof(): int
    {
        return $this->at >= strlen($this->bytes) ? 1 : 0;
    }

    public function read(?string &$aDst, int $aBytes): int
    {
        $aDst = substr($this->bytes, $this->at, $aBytes);
        $this->at += strlen($aDst);

        return strlen($aDst);
    }

    public function length(): int
    {
        return strlen($this->bytes);
    }

    public function seek(int $aOffset): void
    {
        $this->at = max(0, min(strlen($this->bytes), $aOffset));
    }

    public function pos(): int
    {
        return $this->at;
    }
}

final class CountingTask extends SoLoud\Thread\PoolTask
{
    public static int $ran = 0;

    public function work(): void
    {
        self::$ran++;
    }
}

function callbackEngine(): Engine
{
    $engine = new Engine();
    expect($engine->init(Engine::CLIP_ROUNDOFF, Engine::NULLDRIVER, 44100, 1024, 2))->toBe(0);

    return $engine;
}

function mixed(Engine $engine, int $frames = 256): array
{
    $b = '';
    $engine->mix($b, $frames);

    return array_values(unpack('g*', $b));
}

it('mixes a PHP source on the owner thread', function () {
    $engine = callbackEngine();
    $source = new ConstantSource(0.25);
    $engine->play($source, 1.0, 0.0);
    $frames = mixed($engine);

    expect($source->calls)->toBeGreaterThan(0)
        ->and($frames[10])->toEqualWithDelta(roundoff(0.25 * cos(M_PI / 4)), 1e-5);
});

it('constructs the native base through parent::__construct()', function () {
    $source = new class extends SoLoud\AudioSource {
        public function __construct()
        {
            parent::__construct();
            $this->mChannels = 1;
        }

        public function createInstance(): ?SoLoud\AudioSourceInstance
        {
            return new class extends SoLoud\AudioSourceInstance {
                public function __construct()
                {
                    parent::__construct();
                }

                public function getAudio(?string &$aBuffer, int $aSamplesToRead, int $aBufferSize): int
                {
                    $aBuffer = pack('g*', ...array_fill(0, $aBufferSize, 0.5));

                    return $aSamplesToRead;
                }

                public function hasEnded(): bool
                {
                    return false;
                }
            };
        }
    };
    $filter = new class extends SoLoud\Filter {
        public function __construct()
        {
            parent::__construct();
        }

        public function createInstance(): ?SoLoud\FilterInstance
        {
            return new HalvingInstance();
        }
    };
    $engine = callbackEngine();
    $source->setFilter(0, $filter);
    $engine->play($source, 1.0, 0.0);

    expect(mixed($engine)[10])->toEqualWithDelta(roundoff(0.25 * cos(M_PI / 4)), 1e-5)
        ->and(fn () => $source->__construct())->toThrow(Error::class, 'already constructed');
});

it('surfaces an exception from getAudio and keeps mixing silence', function () {
    $engine = callbackEngine();
    $source = new ConstantSource(0.25);
    $source->throw = new RuntimeException('x');
    $engine->play($source, 1.0, 0.0);

    expect(fn () => mixed($engine))->toThrow(RuntimeException::class, 'x');

    $source->throw = null;
    expect($engine->getActiveVoiceCount())->toBe(1);
});

it('filters through a PHP filter', function () {
    $engine = callbackEngine();
    $source = new ConstantSource(0.25);
    $source->setFilter(0, new HalvingFilter());
    $engine->play($source, 1.0, 0.0);
    $frames = mixed($engine);

    expect($frames[10])->toEqualWithDelta(roundoff(0.125 * cos(M_PI / 4)), 1e-5);
});

it('attenuates through a PHP attenuator', function () {
    $engine = callbackEngine();
    $source = new ConstantSource(0.25);
    $source->set3dAttenuator(new HalfAttenuator());
    $handle = $engine->play3d($source, 10.0, 0.0, 0.0);
    $engine->update3dAudio();

    expect($engine->getOverallVolume($handle))->toEqualWithDelta(0.5, 1e-5);
});

it('loads a Wav through a PHP File', function () {
    $wav = new SoLoud\Wav();
    expect($wav->loadFile(new StringFile(supportWav())))->toBe(0)
        ->and($wav->getLength())->toBeGreaterThan(0.0);
});

it('runs a thread function on the owner thread', function () {
    $ran = null;
    $handle = SoLoud\Thread\createThread(function ($parameter) use (&$ran) {
        $ran = $parameter;
    }, 7);
    SoLoud\Thread\wait($handle);
    SoLoud\Thread\release($handle);

    expect($ran)->toBe(7);
});

it('runs PHP pool tasks', function () {
    CountingTask::$ran = 0;
    $pool = new SoLoud\Thread\Pool();
    $pool->init(2);
    $tasks = [new CountingTask(), new CountingTask(), new CountingTask(), new CountingTask()];
    foreach ($tasks as $task) {
        $pool->addWork($task);
    }
    for ($i = 0; $i < 200 && CountingTask::$ran < 4; $i++) {
        usleep(5000);
    }
    unset($pool);

    expect(CountingTask::$ran)->toBe(4);
});

it('refuses a createInstance that does not return a PHP instance', function () {
    $source = new class extends SoLoud\AudioSource {
        public function createInstance(): ?SoLoud\AudioSourceInstance
        {
            return null;
        }
    };
    $engine = callbackEngine();

    expect(fn () => $engine->play($source))->toThrow(TypeError::class);
});

it('serves a PHP source from the mixer thread', function () {
    $engine = new Engine();
    if ($engine->init(Engine::CLIP_ROUNDOFF, Engine::MINIAUDIO, 44100, 1024, 2) !== 0) {
        $this->markTestSkipped('no audio device');
    }
    // Silence at volume 0: the device runs, nothing is heard.
    $source = new ConstantSource(0.0);
    $engine->play($source, 0.0);
    // The owner serves the mixer from its VM interrupt, so it waits running opcodes: a usleep() longer than one
    // device buffer (480 frames on a Pi 5) would let every request be withdrawn.
    $deadline = microtime(true) + 2.0;
    while ($source->calls === 0 && microtime(true) < $deadline) {
    }
    // Then busy elsewhere: the mixer withdraws its requests and deinit() still returns.
    $start = microtime(true);
    usleep(500000);
    $engine->deinit();

    expect($source->calls)->toBeGreaterThan(0)
        ->and(microtime(true) - $start)->toBeLessThan(2.5);
});
