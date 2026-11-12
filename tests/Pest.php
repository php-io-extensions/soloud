<?php

declare(strict_types=1);

if (! extension_loaded('soloud')) {
    throw new RuntimeException('The soloud extension is not loaded; run pest with -d extension=/path/to/soloud.so');
}

/** SoLoud's CLIP_ROUNDOFF curve, then the default post-clip scaler. */
function roundoff(float $x): float
{
    $y = $x <= -1.65 ? -0.9862875 : ($x >= 1.65 ? 0.9862875 : 0.87 * $x - 0.1 * $x * $x * $x);

    return $y * 0.95;
}

/** A 16-bit PCM mono RIFF/WAVE file of 64 silent samples. */
function supportWav(): string
{
    $data = pack('s*', ...array_fill(0, 64, 0));

    return 'RIFF'.pack('V', 36 + strlen($data)).'WAVE'
        .'fmt '.pack('VvvVVvv', 16, 1, 1, 44100, 88200, 2, 16)
        .'data'.pack('V', strlen($data)).$data;
}

/** Skips the calling test unless ext-soloud is a probe build (configure --enable-soloud-probes). */
function soloudProbe(): void
{
    if (! defined('SOLOUD_PROBES')) {
        test()->markTestSkipped('ext-soloud is not a probe build (configure --enable-soloud-probes): SOLOUD_PROBES is undefined');
    }
}

/**
 * The .so a child process loads: env SOLOUD_PROBE_EXT; else the path a scanned ini loads it by (a build enabled
 * through PHP_INI_SCAN_DIR, as CI does); else the file in this PHP's extension_dir.
 */
function soloudExtension(): string
{
    $given = getenv('SOLOUD_PROBE_EXT');
    if (is_string($given) && $given !== '') {
        return $given;
    }
    foreach (array_filter(array_map('trim', explode(',', (string) php_ini_scanned_files()))) as $ini) {
        if (preg_match('/^\s*extension\s*=\s*"?(\/[^"\s]*soloud\.so)"?\s*$/m', (string) @file_get_contents($ini), $m) && is_file($m[1])) {
            return $m[1];
        }
    }

    return ini_get('extension_dir').'/soloud.so';
}

/**
 * Runs $code, a function body, in a child of this PHP with only ext-soloud loaded. What it returns comes back
 * as 'result' (JSON), a throw as 'threw' ("Class: message"). $siteOff names the kept site env SOLOUD_PROBE_OFF
 * turns off (a probe build only); null keeps every site. 'signal' is the signal that ended the child, or null.
 * $gmalloc runs the child under macOS libgmalloc with Zend's allocator off: every allocation ends at a guard
 * page, so a write one element past a buffer faults at once.
 *
 * @return array{signal: ?int, exit: ?int, result: mixed, threw: ?string, survived: bool, stdout: string, stderr: string}
 */
function soloudChild(string $code, ?string $siteOff = null, float $limit = 30.0, bool $gmalloc = false): array
{
    $script = <<<PHP
    <?php
    declare(strict_types=1);
    try {
        \$result = (static function () {
    {$code}
        })();
        echo "\\nRESULT ", json_encode(\$result, JSON_PRESERVE_ZERO_FRACTION | JSON_PARTIAL_OUTPUT_ON_ERROR), "\\n";
    } catch (Throwable \$t) {
        echo "\\nREFUSED ", get_class(\$t), ': ', \$t->getMessage(), "\\n";
    }
    echo "SURVIVED\\n";
    PHP;

    $base = tempnam(sys_get_temp_dir(), 'soloud-child');
    $file = $base.'.php';
    $out = tempnam(sys_get_temp_dir(), 'soloud-child-out');
    $err = tempnam(sys_get_temp_dir(), 'soloud-child-err');
    file_put_contents($file, $script);

    $env = getenv();
    unset($env['SOLOUD_PROBE_OFF'], $env['DYLD_INSERT_LIBRARIES'], $env['USE_ZEND_ALLOC']);
    $env['XDEBUG_MODE'] = 'off';
    if ($siteOff !== null) {
        $env['SOLOUD_PROBE_OFF'] = $siteOff;
    }
    if ($gmalloc && PHP_OS_FAMILY === 'Darwin') {
        $env['DYLD_INSERT_LIBRARIES'] = '/usr/lib/libgmalloc.dylib';
        $env['USE_ZEND_ALLOC'] = '0';
    }

    $command = [PHP_BINARY, '-n', '-d', 'memory_limit=128M', '-d', 'extension='.soloudExtension(), $file];
    $process = proc_open($command, [0 => ['file', '/dev/null', 'r'], 1 => ['file', $out, 'w'], 2 => ['file', $err, 'w']], $pipes, null, $env);
    $deadline = microtime(true) + $limit;
    $killed = false;
    do {
        $status = proc_get_status($process);
        if ($status['running'] && microtime(true) > $deadline) {
            proc_terminate($process, 9);
            $killed = true;
        }
        if ($status['running']) {
            usleep(20_000);
        }
    } while ($status['running']);
    proc_close($process);

    $stdout = (string) file_get_contents($out);
    $stderr = (string) file_get_contents($err);
    @unlink($file);
    @unlink($base);
    @unlink($out);
    @unlink($err);

    $result = preg_match('/^RESULT (.*)$/m', $stdout, $m) === 1 ? json_decode($m[1], true) : null;
    $threw = preg_match('/^REFUSED (.*)$/m', $stdout, $m) === 1 ? $m[1] : null;

    return [
        'signal' => $status['signaled'] && ! $killed ? $status['termsig'] : null,
        'exit' => $status['signaled'] ? null : $status['exitcode'],
        'result' => $result,
        'threw' => $threw,
        'survived' => str_contains($stdout, 'SURVIVED'),
        'stdout' => $stdout,
        'stderr' => $stderr,
    ];
}
