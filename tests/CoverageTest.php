<?php

declare(strict_types=1);

it('keeps SUPPORT.md and the README badge current, at 100%', function () {
    $root = dirname(__DIR__);
    exec(escapeshellarg(PHP_BINARY) . ' ' . escapeshellarg("{$root}/scripts/support.php") . ' --check 2>&1', $out, $code);

    expect($code)->toBe(0, implode("\n", $out))
        ->and(file_get_contents("{$root}/SUPPORT.md"))->toMatch('/— (\d+) \/ \1 members bound \(100\.0%\)/');
});
