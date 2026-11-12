<?php

declare(strict_types=1);

// Files that are not open (or null where SoLoud does not check), and mutex handles that are not live.
// Release build: refused. Probe build with that site off, under libgmalloc: SoLoud faults.

dataset('support sites', [
    'soloud-file-read8-closed' => ['soloud-file-read8-closed', '(new SoLoud\DiskFile())->read8();'],
    'soloud-file-read16-closed' => ['soloud-file-read16-closed', '(new SoLoud\DiskFile())->read16();'],
    'soloud-file-read32-closed' => ['soloud-file-read32-closed', '(new SoLoud\DiskFile())->read32();'],
    'soloud-file-eof-closed' => ['soloud-file-eof-closed', '(new SoLoud\DiskFile())->eof();'],
    'soloud-file-read-closed' => ['soloud-file-read-closed', '$b = \'\'; (new SoLoud\DiskFile())->read($b, 4);'],
    'soloud-file-seek-closed' => ['soloud-file-seek-closed', '(new SoLoud\DiskFile())->seek(4);'],
    'soloud-file-pos-closed' => ['soloud-file-pos-closed', '(new SoLoud\DiskFile())->pos();'],
    'soloud-memoryfile-openfiletomem-closed' => ['soloud-memoryfile-openfiletomem-closed', '(new SoLoud\MemoryFile())->openFileToMem(new SoLoud\DiskFile());'],
    'soloud-wav-loadfile-closed' => ['soloud-wav-loadfile-closed', '(new SoLoud\Wav())->loadFile(new SoLoud\DiskFile());'],
    'soloud-wavstream-loadfile-closed' => ['soloud-wavstream-loadfile-closed', '(new SoLoud\WavStream())->loadFile(new SoLoud\DiskFile());'],
    'soloud-wavstream-loadfiletomem-closed' => ['soloud-wavstream-loadfiletomem-closed', '(new SoLoud\WavStream())->loadFileToMem(new SoLoud\DiskFile());'],
    'soloud-wavstream-parse-closed' => ['soloud-wavstream-parse-closed', '(new SoLoud\WavStream())->parse(null);'],
    'soloud-sfxr-loadparamsfile-closed' => ['soloud-sfxr-loadparamsfile-closed', '(new SoLoud\Sfxr())->loadParamsFile(null);'],
    'soloud-monotone-loadfile-closed' => ['soloud-monotone-loadfile-closed', '(new SoLoud\Monotone())->loadFile(new SoLoud\DiskFile());'],
    'soloud-openmpt-loadfile-closed' => ['soloud-openmpt-loadfile-closed', '(new SoLoud\Openmpt())->loadFile(null);'],
    'soloud-thread-destroymutex-handle' => ['soloud-thread-destroymutex-handle', '$m = SoLoud\Thread\createMutex(); SoLoud\Thread\destroyMutex($m); SoLoud\Thread\destroyMutex($m);'],
    'soloud-thread-lockmutex-handle' => ['soloud-thread-lockmutex-handle', '$m = SoLoud\Thread\createMutex(); SoLoud\Thread\destroyMutex($m); SoLoud\Thread\lockMutex($m);'],
    'soloud-thread-unlockmutex-handle' => ['soloud-thread-unlockmutex-handle', '$m = SoLoud\Thread\createMutex(); SoLoud\Thread\destroyMutex($m); SoLoud\Thread\unlockMutex($m);'],
]);

it('refuses the call', function (string $site, string $code) {
    $run = soloudChild($code."\nreturn true;");
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('support sites');

it('faults with the check off', function (string $site, string $code) {
    soloudProbe();
    $run = soloudChild($code."\nreturn true;", $site, gmalloc: true);
    expect($run['signal'])->not->toBeNull();
})->with('support sites');

it('refuses a MemoryFile with no data', function () {
    $run = soloudChild('$b = \'\'; $f = new SoLoud\MemoryFile(); $f->seek(1000); $f->read($b, 4); return true;');
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
});
