<?php

declare(strict_types=1);

it('loads as version 0.11.0', function () {
    expect(extension_loaded('soloud'))->toBeTrue()
        ->and(phpversion('soloud'))->toBe('0.11.0');
});

it('reports the upstream commit and SoLoud version in phpinfo', function () {
    ob_start();
    phpinfo(INFO_MODULES);
    $info = (string) ob_get_clean();

    expect($info)->toContain('e82fd32c1f62183922f08c14c814a02b58db1873')
        ->and($info)->toContain('SoLoud version => 202002');
});

it('declares SoLoudException as an Exception', function () {
    expect(class_exists(SoLoudException::class))->toBeTrue()
        ->and(is_subclass_of(SoLoudException::class, Exception::class))->toBeTrue();
});
