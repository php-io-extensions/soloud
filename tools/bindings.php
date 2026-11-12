<?php

/*
 * What tools/api.json cannot say. Everything not listed here follows the rules in tools/generate.php.
 */

return [
    // Stub group => the classes it binds, in registration order (bases first). One stubs/<Group>.stub.php
    // and src/gen/<Group>.cpp each.
    'groups' => [
        'Core' => [
            'SoLoud::Fader',
            'SoLoud::AudioSourceInstance3dData',
            'SoLoud::AudioCollider',
            'SoLoud::AudioAttenuator',
            'SoLoud::AudioSourceInstance',
            'SoLoud::AudioSource',
            'SoLoud::Soloud',
        ],
        'Wav' => [
            'SoLoud::Wav',
            'SoLoud::WavInstance',
            'SoLoud::WavStream',
            'SoLoud::WavStreamInstance',
        ],
        // An instance class before its source: X::createInstance() returns XInstance, and PHP checks that
        // override's covariance when it registers X.
        'AudioSources' => [
            'SoLoud::BusInstance',
            'SoLoud::Bus',
            'SoLoud::QueueInstance',
            'SoLoud::Queue',
            'SoLoud::SpeechInstance',
            'SoLoud::Speech',
            'SoLoud::SfxrParams',
            'SoLoud::SfxrInstance',
            'SoLoud::Sfxr',
            'SoLoud::NoiseInstance',
            'SoLoud::Noise',
            'SoLoud::MonotoneChannel',
            'SoLoud::MonotoneHardwareChannel',
            'SoLoud::MonotoneSong',
            'SoLoud::MonotoneInstance',
            'SoLoud::Monotone',
            'SoLoud::TedSidInstance',
            'SoLoud::TedSid',
            'SoLoud::VicInstance',
            'SoLoud::Vic',
            'SoLoud::VizsnResonator',
            'SoLoud::VizsnBank',
            'SoLoud::VizsnInstance',
            'SoLoud::Vizsn',
            'SoLoud::AyInstance',
            'SoLoud::Ay',
            'SoLoud::OpenmptInstance',
            'SoLoud::Openmpt',
        ],
        'Filters' => [
            'SoLoud::FilterInstance',
            'SoLoud::Filter',
            'SoLoud::FFTFilterInstance',
            'SoLoud::FFTFilter',
            'SoLoud::BassboostFilterInstance',
            'SoLoud::BassboostFilter',
            'SoLoud::BQRStateData',
            'SoLoud::BiquadResonantFilterInstance',
            'SoLoud::BiquadResonantFilter',
            'SoLoud::DCRemovalFilterInstance',
            'SoLoud::DCRemovalFilter',
            'SoLoud::DuckFilterInstance',
            'SoLoud::DuckFilter',
            'SoLoud::EchoFilterInstance',
            'SoLoud::EchoFilter',
            'SoLoud::EqFilterInstance',
            'SoLoud::EqFilter',
            'SoLoud::FlangerFilterInstance',
            'SoLoud::FlangerFilter',
            'SoLoud::FreeverbFilterInstance',
            'SoLoud::FreeverbFilter',
            'SoLoud::LofiChannelData',
            'SoLoud::LofiFilterInstance',
            'SoLoud::LofiFilter',
            'SoLoud::RobotizeFilterInstance',
            'SoLoud::RobotizeFilter',
            'SoLoud::WaveShaperFilterInstance',
            'SoLoud::WaveShaperFilter',
        ],
        'Support' => [
            'SoLoud::File',
            'SoLoud::DiskFile',
            'SoLoud::MemoryFile',
            'SoLoud::AlignedFloatBuffer',
            'SoLoud::TinyAlignedFloatBuffer',
            'SoLoud::Misc::Prg',
            'SoLoud::Thread::PoolTask',
            'SoLoud::Thread::Pool',
        ],
    ],

    // Classes a PHP subclass extends through a C++ trampoline (src/callbacks.cpp).
    'trampolines' => [
        'SoLoud::AudioSource',
        'SoLoud::AudioSourceInstance',
        'SoLoud::Filter',
        'SoLoud::FilterInstance',
        'SoLoud::FFTFilterInstance',
        'SoLoud::AudioCollider',
        'SoLoud::AudioAttenuator',
        'SoLoud::File',
        'SoLoud::Thread::PoolTask',
    ],

    // Namespace functions: stub group that binds them. createThread, wait and release take a PHP callback
    // and its thread handle (Task 6).
    'functions' => [
        'Support' => [
            'SoLoud::FFT::fft1024',
            'SoLoud::FFT::fft256',
            'SoLoud::FFT::ifft256',
            'SoLoud::FFT::fft',
            'SoLoud::FFT::ifft',
            'SoLoud::Misc::generateWaveform',
            'SoLoud::Thread::createMutex',
            'SoLoud::Thread::destroyMutex',
            'SoLoud::Thread::lockMutex',
            'SoLoud::Thread::unlockMutex',
            'SoLoud::Thread::sleep',
            'SoLoud::Thread::getTimeMillis',
            'SoLoud::Thread::createThread',
            'SoLoud::Thread::wait',
            'SoLoud::Thread::release',
        ],
    ],

    // Structs bound without a PHP constructor: ext-guard cannot read their fields (BQRStateData declares
    // "float mY1, mY2, mX1, mX2;" on one line), so it cannot check an aggregate constructor. Read through
    // the owner's field (BiquadResonantFilterInstance::mState).
    'no_construct' => ['SoLoud::BQRStateData'],

    // Namespace enums: stub group that declares them.
    'namespace_enums' => [
        'SoLoud::SOLOUD_ERRORS' => 'Core',
        'SoLoud::WAVSTREAM_FILETYPE' => 'Wav',
    ],

    // Members bound by hand in src/manual/<Group>.cpp: their PHP signature, as the stub declares it.
    // These take or return raw buffers, whose sizes the header does not state.
    'manual' => [
        'SoLoud::Soloud::mix' => 'public function mix(?string &$aBuffer, int $aSamples): void',
        'SoLoud::Soloud::mixSigned16' => 'public function mixSigned16(?string &$aBuffer, int $aSamples): void',
        'SoLoud::Soloud::getWave' => 'public function getWave(): string',
        'SoLoud::Soloud::calcFFT' => 'public function calcFFT(): string',
        'SoLoud::Soloud::getSpeakerPosition' => 'public function getSpeakerPosition(int $aChannel, ?float &$aX, ?float &$aY, ?float &$aZ): int',
        'SoLoud::Wav::loadMem' => 'public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
        'SoLoud::Wav::loadRawWave8' => 'public function loadRawWave8(string $aMem, int $aLength, float $aSamplerate = 44100.0, int $aChannels = 1): int',
        'SoLoud::Wav::loadRawWave16' => 'public function loadRawWave16(string $aMem, int $aLength, float $aSamplerate = 44100.0, int $aChannels = 1): int',
        'SoLoud::Wav::loadRawWave' => 'public function loadRawWave(string $aMem, int $aLength, float $aSamplerate = 44100.0, int $aChannels = 1, bool $aCopy = false, bool $aTakeOwnership = true): int',
        'SoLoud::WavStream::loadMem' => 'public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
        'SoLoud::Bus::calcFFT' => 'public function calcFFT(): string',
        'SoLoud::Bus::getWave' => 'public function getWave(): string',
        'SoLoud::Ay::loadMem' => 'public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
        'SoLoud::Monotone::loadMem' => 'public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
        'SoLoud::Openmpt::loadMem' => 'public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
        'SoLoud::TedSid::loadMem' => 'public function loadMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
        // File I/O on raw bytes; FILE * is an address; mutex handles are addresses the binding tracks.
        'SoLoud::File::read' => 'public function read(?string &$aDst, int $aBytes): int',
        'SoLoud::File::getMemPtr' => 'public function getMemPtr(): ?string',
        'SoLoud::File::getFilePtr' => 'public function getFilePtr(): int',
        'SoLoud::MemoryFile::openMem' => 'public function openMem(string $aData, int $aDataLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
        'SoLoud::Thread::createMutex' => 'function createMutex(): int',
        'SoLoud::Thread::destroyMutex' => 'function destroyMutex(int $aHandle): void',
        'SoLoud::Thread::lockMutex' => 'function lockMutex(int $aHandle): void',
        'SoLoud::Thread::unlockMutex' => 'function unlockMutex(int $aHandle): void',
        // The thread function is a PHP callable, run on the calling thread when the new thread asks; a thread
        // handle is an address the binding tracks.
        'SoLoud::Thread::createThread' => 'function createThread(callable $aThreadFunction, int $aParameter): int',
        'SoLoud::Thread::wait' => 'function wait(int $aThreadHandle): void',
        'SoLoud::Thread::release' => 'function release(int $aThreadHandle): void',
        // initParams: kept refusal on the count; FFTFilterInstance::init: resets the tracked channel state.
        'SoLoud::FilterInstance::initParams' => 'public function initParams(int $aNumParams): int',
        'SoLoud::FFTFilterInstance::init' => 'public function init(): void',
        'SoLoud::FilterInstance::filter' =>'public function filter(?string &$aBuffer, int $aSamples, int $aBufferSize, int $aChannels, float $aSamplerate, float $aTime): void',
        'SoLoud::FilterInstance::filterChannel' => 'public function filterChannel(?string &$aBuffer, int $aSamples, float $aSamplerate, float $aTime, int $aChannel, int $aChannels): void',
        'SoLoud::FFTFilterInstance::fftFilterChannel' => 'public function fftFilterChannel(?string &$aFFTBuffer, int $aSamples, float $aSamplerate, float $aTime, int $aChannel, int $aChannels): void',
        'SoLoud::FFTFilterInstance::magPhase2MagFreq' => 'public function magPhase2MagFreq(?string &$aFFTBuffer, int $aSamples, float $aSamplerate, int $aChannel): void',
        'SoLoud::FFTFilterInstance::magFreq2MagPhase' => 'public function magFreq2MagPhase(?string &$aFFTBuffer, int $aSamples, float $aSamplerate, int $aChannel): void',
        'SoLoud::Sfxr::loadParamsMem' => 'public function loadParamsMem(string $aMem, int $aLength, bool $aCopy = false, bool $aTakeOwnership = true): int',
    ],

    // Virtuals bound once, on the class that declares them, with the kept refusals in front of them (src/manual/
    // Filters.cpp). A subclass override is reached through virtual dispatch and gets no binding of its own.
    'inherit' => [
        'SoLoud::FilterInstance' => ['filter', 'filterChannel'],
        'SoLoud::FFTFilterInstance' => ['fftFilterChannel'],
        'SoLoud::File' => ['eof', 'read', 'length', 'seek', 'pos', 'getFilePtr', 'getMemPtr'],
        'SoLoud::AudioSourceInstance' => ['getAudio', 'seek'],
    ],

    // In-out float buffers: method name (on any class) => [parameter => element count, a C++ expression over
    // the call's other parameters ($name) and the object (self)]. PHP passes a by-reference string; the
    // binding pads it with zeros to that many floats, makes the call, and writes the buffer back.
    'buffers' => [
        'comp2MagPhase' => ['aFFTBuffer' => '$aSamples * 2'],
        'magPhase2Comp' => ['aFFTBuffer' => '$aSamples * 2'],
        // An instance writes every channel it has (WavInstance: its parent's) at i * aBufferSize; seek()'s
        // generic form reads mScratchSize / 2 frames of every channel into the scratch.
        'getAudio' => ['aBuffer' => '(MAX_CHANNELS - 1) * $aBufferSize + std::max($aSamplesToRead, $aBufferSize)'],
        'seek' => ['mScratch' => 'MAX_CHANNELS * $mScratchSize'],
        'fft' => ['aBuffer' => '$aBufferLength'],
        'ifft' => ['aBuffer' => '$aBufferLength'],
        'fft1024' => ['aBuffer' => '1024'],
        'fft256' => ['aBuffer' => '256'],
        'ifft256' => ['aBuffer' => '256'],
    ],

    // Calls after which one object points at another. method => [param, role, holder]: holder 'param'
    // keeps $this alive under role; holder 'this' keeps the param alive.
    // Kept refusals in front of a generated call: method => [site, fit check], or a list of them, checked in
    // order. The check fills why and returns false to refuse; $name is the native argument for that parameter.
    // src/runtime.cpp holds the checks.
    // Soloud::play* before a successful init(): the voice is created, but stopping it (stop(), stopAll(), the
    // source's or engine's destructor) reads mResampleDataOwner, which only postinit allocates.
    'checks' => [
        'SoLoud::Soloud::play' => [
            ['soloud-soloud-play-not-initialised', 'soloud_engine_initialised(self, why, sizeof why)'],
            ['soloud-soloud-play-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        ],
        'SoLoud::Soloud::playClocked' => [
            ['soloud-soloud-playclocked-not-initialised', 'soloud_engine_initialised(self, why, sizeof why)'],
            ['soloud-soloud-playclocked-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        ],
        'SoLoud::Soloud::play3d' => [
            ['soloud-soloud-play3d-not-initialised', 'soloud_engine_initialised(self, why, sizeof why)'],
            ['soloud-soloud-play3d-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        ],
        'SoLoud::Soloud::play3dClocked' => [
            ['soloud-soloud-play3dclocked-not-initialised', 'soloud_engine_initialised(self, why, sizeof why)'],
            ['soloud-soloud-play3dclocked-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        ],
        'SoLoud::Soloud::playBackground' => [
            ['soloud-soloud-playbackground-not-initialised', 'soloud_engine_initialised(self, why, sizeof why)'],
            ['soloud-soloud-playbackground-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        ],
        'SoLoud::Bus::play' => ['soloud-bus-play-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        'SoLoud::Bus::playClocked' => ['soloud-bus-playclocked-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        'SoLoud::Bus::play3d' => ['soloud-bus-play3d-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        'SoLoud::Bus::play3dClocked' => ['soloud-bus-play3dclocked-filter-channels', 'soloud_voice_filters_fit(&$aSound, why, sizeof why)'],
        'SoLoud::Soloud::setGlobalFilter' => ['soloud-soloud-setglobalfilter-channels', 'soloud_global_filter_fits(self, $aFilterId, $aFilter, why, sizeof why)'],
        'SoLoud::Soloud::init' => ['soloud-soloud-init-filter-channels', 'soloud_init_filters_fit(soloud_from(Z_OBJ_P(ZEND_THIS)), self, $aChannels, why, sizeof why)'],
        // A DiskFile before open() reads through a NULL FILE *; a MemoryFile with no data seeks to any offset
        // and then reads 0 - offset bytes.
        'SoLoud::File::read8' => ['soloud-file-read8-closed', 'soloud_file_open(self, why, sizeof why)'],
        'SoLoud::File::read16' => ['soloud-file-read16-closed', 'soloud_file_open(self, why, sizeof why)'],
        'SoLoud::File::read32' => ['soloud-file-read32-closed', 'soloud_file_open(self, why, sizeof why)'],
        'SoLoud::File::eof' => ['soloud-file-eof-closed', 'soloud_file_open(self, why, sizeof why)'],
        'SoLoud::File::seek' => ['soloud-file-seek-closed', 'soloud_file_open(self, why, sizeof why)'],
        'SoLoud::File::pos' => ['soloud-file-pos-closed', 'soloud_file_open(self, why, sizeof why)'],
        'SoLoud::MemoryFile::openFileToMem' => ['soloud-memoryfile-openfiletomem-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::Wav::loadFile' => ['soloud-wav-loadfile-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::WavStream::loadFile' => ['soloud-wavstream-loadfile-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::WavStream::loadFileToMem' => ['soloud-wavstream-loadfiletomem-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::WavStream::parse' => ['soloud-wavstream-parse-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::Sfxr::loadParamsFile' => ['soloud-sfxr-loadparamsfile-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::Monotone::loadFile' => ['soloud-monotone-loadfile-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::Openmpt::loadFile' => ['soloud-openmpt-loadfile-closed', 'soloud_file_open($aFile, why, sizeof why)'],
        'SoLoud::Thread::Pool::addWork' => ['soloud-pool-addwork-null', 'soloud_task_given($aTask, why, sizeof why)'],
    ],

    // Statements after a generated call (r: its result).
    'after' => [
        'SoLoud::Soloud::setGlobalFilter' => 'soloud_global_filter_set(soloud_from(Z_OBJ_P(ZEND_THIS)), self, $aFilterId)',
        'SoLoud::Soloud::init' => 'if (r == 0) soloud_init_filters_ran(soloud_from(Z_OBJ_P(ZEND_THIS)), self)',
    ],

    'edges' => [
        'SoLoud::Soloud::play' => ['aSound', 'engine', 'param'],
        'SoLoud::Soloud::playClocked' => ['aSound', 'engine', 'param'],
        'SoLoud::Soloud::play3d' => ['aSound', 'engine', 'param'],
        'SoLoud::Soloud::play3dClocked' => ['aSound', 'engine', 'param'],
        'SoLoud::Soloud::playBackground' => ['aSound', 'engine', 'param'],
        // A source played in a bus plays on the bus's engine; holding the bus holds the chain.
        'SoLoud::Bus::play' => ['aSound', 'bus', 'param'],
        'SoLoud::Bus::playClocked' => ['aSound', 'bus', 'param'],
        'SoLoud::Bus::play3d' => ['aSound', 'bus', 'param'],
        'SoLoud::Bus::play3dClocked' => ['aSound', 'bus', 'param'],
        // A queue keeps instances of every source it was given.
        'SoLoud::Queue::play' => ['aSound', 'queued:', 'this'],
        // A filter set in a slot stays held after the slot is reset: a playing voice may still run an
        // instance of it that reads its parent (DCRemovalFilterInstance).
        'SoLoud::AudioSource::setFilter' => ['aFilter', 'filter:', 'this'],
        'SoLoud::Bus::setFilter' => ['aFilter', 'filter:', 'this'],
        'SoLoud::Soloud::setGlobalFilter' => ['aFilter', 'filter:', 'this'],
        // A WavStream loaded from a File streams from it on the mixer thread.
        'SoLoud::WavStream::loadFile' => ['aFile', 'file', 'this'],
        // A source hands its collider and attenuator to every 3d voice it plays, which keeps them after the
        // source is given another: held per object until the source goes (and stops its voices).
        'SoLoud::AudioSource::set3dCollider' => ['aCollider', 'collider:', 'this'],
        'SoLoud::AudioSource::set3dAttenuator' => ['aAttenuator', 'attenuator:', 'this'],
        // A pool keeps the tasks it was given until a worker runs them.
        'SoLoud::Thread::Pool::addWork' => ['aTask', 'task:', 'this'],
    ],
];
