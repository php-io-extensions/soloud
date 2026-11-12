<?php

declare(strict_types=1);

use SoLoud\Soloud;
use SoLoud\Wav;

/** An engine on the null backend: no device, mixed only by Soloud::mix(). */
function nullEngine(int $channels = 2): Soloud
{
    $engine = new Soloud();
    expect($engine->init(Soloud::CLIP_ROUNDOFF, Soloud::NULLDRIVER, 44100, 1024, $channels))->toBe(\SoLoud\SO_NO_ERROR);

    return $engine;
}

/** A mono Wav of $frames samples, every one $value. */
function constantWav(float $value, int $frames = 4096): Wav
{
    $wav = new Wav();
    expect($wav->loadRawWave(pack('g*', ...array_fill(0, $frames, $value)), $frames, 44100.0, 1, true, false))->toBe(\SoLoud\SO_NO_ERROR);

    return $wav;
}


it('initialises on the null backend', function () {
    $engine = nullEngine();

    expect($engine->getBackendId())->toBe(Soloud::NULLDRIVER)
        ->and($engine->getBackendChannels())->toBe(2)
        ->and($engine->getBackendSamplerate())->toBe(44100)
        ->and($engine->getBackendBufferSize())->toBe(1024)
        ->and($engine->getErrorString(\SoLoud\INVALID_PARAMETER))->toBeString()->not->toBe('');
});

it('mixes a constant source through the pan law and the roundoff clipper', function () {
    $engine = nullEngine();
    $wav = constantWav(0.5);
    $handle = $engine->play($wav, 1.0, 0.0);
    $buffer = '';
    $engine->mix($buffer, 256);
    $frames = unpack('g*', $buffer);

    // The linear resampler starts from silence: frame 0 is 0, the source's value arrives at frame 1.
    $expected = roundoff(0.5 * cos(M_PI / 4));
    expect(strlen($buffer))->toBe(256 * 2 * 4)
        ->and($frames[1])->toBe(0.0)
        ->and($frames[3])->toEqualWithDelta($expected, 1e-5)
        ->and($frames[4])->toEqualWithDelta($expected, 1e-5)
        ->and($engine->isValidVoiceHandle($handle))->toBeTrue()
        ->and($engine->getActiveVoiceCount())->toBe(1);
});

it('mixes signed 16-bit frames', function () {
    $engine = nullEngine();
    $wav = constantWav(0.5);
    $engine->play($wav, 1.0, 0.0);
    $buffer = '';
    $engine->mixSigned16($buffer, 64);
    $frames = unpack('s*', $buffer);

    expect(strlen($buffer))->toBe(64 * 2 * 2)
        ->and($frames[3])->toBe((int) floor(roundoff(0.5 * cos(M_PI / 4)) * 0x7fff));
});

it('reads and writes voice state by handle', function () {
    $engine = nullEngine();
    $wav = constantWav(0.5);
    $handle = $engine->play($wav, 0.25, 0.5, true);

    expect($engine->getVolume($handle))->toEqualWithDelta(0.25, 1e-6)
        ->and($engine->getPan($handle))->toEqualWithDelta(0.5, 1e-6)
        ->and($engine->getPause($handle))->toBeTrue();

    $engine->setPause($handle, false);
    $engine->setVolume($handle, 0.75);
    $engine->setRelativePlaySpeed($handle, 2.0);

    expect($engine->getPause($handle))->toBeFalse()
        ->and($engine->getVolume($handle))->toEqualWithDelta(0.75, 1e-6)
        ->and($engine->getRelativePlaySpeed($handle))->toEqualWithDelta(2.0, 1e-6);

    $engine->stop($handle);
    expect($engine->isValidVoiceHandle($handle))->toBeFalse();
});

it('groups voices', function () {
    $engine = nullEngine();
    $wav = constantWav(0.5);
    $group = $engine->createVoiceGroup();
    $engine->addVoiceToGroup($group, $engine->play($wav));
    $engine->addVoiceToGroup($group, $engine->play($wav));

    expect($engine->isVoiceGroup($group))->toBeTrue()
        ->and($engine->isVoiceGroupEmpty($group))->toBeFalse();

    $engine->stop($group);
    expect($engine->isVoiceGroupEmpty($group))->toBeTrue()
        ->and($engine->destroyVoiceGroup($group))->toBe(\SoLoud\SO_NO_ERROR);
});

it('fades a voice over stream time', function () {
    $engine = nullEngine();
    $wav = constantWav(0.5, 44100);
    $handle = $engine->play($wav);
    $engine->fadeVolume($handle, 0.0, 0.01);
    $buffer = '';
    $engine->mix($buffer, 1024);
    $engine->mix($buffer, 1024);

    expect($engine->getVolume($handle))->toEqualWithDelta(0.0, 1e-6)
        ->and($engine->getStreamTime($handle))->toBeGreaterThan(0.04);
});

it('attenuates a 3d voice by distance', function () {
    $engine = nullEngine();
    $wav = constantWav(0.5);
    $wav->set3dAttenuation(\SoLoud\AudioSource::INVERSE_DISTANCE, 1.0);
    $near = $engine->play3d($wav, 1.0, 0.0, 0.0);
    $far = $engine->play3d($wav, 100.0, 0.0, 0.0);
    $engine->update3dAudio();
    $buffer = '';
    $engine->mix($buffer, 256);

    expect($engine->getOverallVolume($far))->toBeLessThan($engine->getOverallVolume($near) / 10);
});

it('shows silence in getWave and calcFFT before init', function () {
    $engine = new Soloud();

    expect($engine->getWave())->toBe(str_repeat("\0", 1024))
        ->and($engine->calcFFT())->toBe(str_repeat("\0", 1024));
});

it('refuses a voice handle outside unsigned int', function () {
    nullEngine()->setVolume(-1, 1.0);
})->throws(ValueError::class);
