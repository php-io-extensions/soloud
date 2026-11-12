<?php

declare(strict_types=1);

// Thread handles that are not live, and a null pool task.
// Release build: refused. Probe build with that site off, under libgmalloc: SoLoud faults.

dataset('thread sites', [
    'soloud-thread-wait-handle' => ['soloud-thread-wait-handle', '$h = SoLoud\Thread\createThread(fn () => null, 0); SoLoud\Thread\wait($h); SoLoud\Thread\release($h); SoLoud\Thread\wait($h);'],
    'soloud-thread-release-handle' => ['soloud-thread-release-handle', '$h = SoLoud\Thread\createThread(fn () => null, 0); SoLoud\Thread\wait($h); SoLoud\Thread\release($h); SoLoud\Thread\release($h);'],
    'soloud-pool-addwork-null' => ['soloud-pool-addwork-null', '(new SoLoud\Thread\Pool())->addWork(null);'],
]);

it('refuses the call', function (string $site, string $code) {
    $run = soloudChild($code."\nreturn true;");
    expect($run['threw'])->toStartWith('ValueError')->and($run['survived'])->toBeTrue();
})->with('thread sites');

it('faults with the check off', function (string $site, string $code) {
    soloudProbe();
    $run = soloudChild($code."\nreturn true;", $site, gmalloc: true);
    expect($run['signal'])->not->toBeNull();
})->with('thread sites');
