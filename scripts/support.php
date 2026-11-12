<?php

declare(strict_types=1);

/*
 * The support list: every public member of SoLoud's C++ API, marked bound when a stub declares its PHP name.
 *
 *   php84 scripts/support.php           writes SUPPORT.md and the README badge
 *   php84 scripts/support.php --check   exits 1 when either differs (the date is not compared)
 *
 * The API is tools/api.json: clang++'s AST of lib/soloud/include, written by tools/extract.php. A member is a
 * constructor, method or field of a SoLoud:: class, or a SoLoud:: namespace function; overloads count once.
 * Not members: destructors, operators, and methods SoLoud names *_internal (its mixer's own entry points).
 * Enumerators are bound as constants and not listed.
 *
 * A member is bound when the class's stub, or a stub class it extends, declares the PHP name: SoLoud::X::X is
 * SoLoud\X::__construct, a field mY is the property $mY, and an override reached through its base's binding
 * counts as bound.
 */

const SUPPORT_LABEL = 'SoLoud API';

/** @return array<string, list<string>> C++ class (or namespace, for functions) => sorted member keys */
function support_counted(array $api): array
{
    $counted = [];
    foreach ($api['classes'] as $class => $c) {
        $short = substr($class, strrpos($class, '::') + 2);
        $keys = [];
        if ($c['constructors'] !== []) {
            $keys[] = "{$class}::{$short}";
        }
        foreach ($c['methods'] as $m) {
            if (!str_ends_with($m['name'], '_internal') && !str_starts_with($m['name'], 'operator')) {
                $keys[] = "{$class}::{$m['name']}";
            }
        }
        foreach ($c['fields'] as $f) {
            $keys[] = "{$class}::{$f['name']}";
        }
        $counted[$class] = $keys;
    }
    foreach (array_keys($api['functions']) as $function) {
        $counted[substr($function, 0, strrpos($function, '::'))][] = $function;
    }
    foreach ($counted as &$keys) {
        $keys = array_values(array_unique($keys));
        sort($keys, SORT_STRING);
    }
    unset($keys);
    ksort($counted, SORT_STRING);

    return $counted;
}

/**
 * Every class, property and function the stubs declare.
 * @return array{classes: array<string, array{parent: ?string, names: array<string, true>}>, functions: array<string, true>}
 */
function support_declared(string $stubDir): array
{
    $out = ['classes' => [], 'functions' => []];
    foreach (glob("{$stubDir}/*.stub.php") as $file) {
        $tokens = token_get_all(file_get_contents($file));
        $namespace = '';
        $class = null;
        $depth = 0;
        $classDepth = -1;
        $count = count($tokens);
        for ($i = 0; $i < $count; $i++) {
            $t = $tokens[$i];
            if ($t === '{') {
                $depth++;
            } elseif ($t === '}') {
                $depth--;
                if ($depth === $classDepth) {
                    $class = null;
                    $classDepth = -1;
                }
            } elseif (is_array($t) && $t[0] === T_CURLY_OPEN) {
                $depth++;
            } elseif (is_array($t) && $t[0] === T_NAMESPACE) {
                $namespace = support_next_name($tokens, $i);
            } elseif (is_array($t) && in_array($t[0], [T_CLASS, T_INTERFACE], true)) {
                $class = ltrim($namespace . '\\' . support_next_name($tokens, $i), '\\');
                $parent = null;
                for ($j = $i + 1; $j < $count && $tokens[$j] !== '{'; $j++) {
                    if (is_array($tokens[$j]) && $tokens[$j][0] === T_EXTENDS) {
                        $parent = ltrim(support_next_name($tokens, $j), '\\');
                    }
                }
                $out['classes'][$class] = ['parent' => $parent, 'names' => []];
                $classDepth = $depth;
            } elseif (is_array($t) && $t[0] === T_FUNCTION) {
                $name = support_next_name($tokens, $i);
                if ($class !== null) {
                    $out['classes'][$class]['names'][$name] = true;
                } else {
                    $out['functions'][ltrim("{$namespace}\\{$name}", '\\')] = true;
                }
            } elseif (is_array($t) && $t[0] === T_VARIABLE && $class !== null && $depth === $classDepth + 1) {
                $out['classes'][$class]['names'][$t[1]] = true;
            }
        }
    }

    return $out;
}

/** The name after token $i (a namespace, class or function name). */
function support_next_name(array $tokens, int $i): string
{
    for ($j = $i + 1; $j < count($tokens); $j++) {
        if (is_array($tokens[$j]) && in_array($tokens[$j][0], [T_STRING, T_NAME_QUALIFIED, T_NAME_FULLY_QUALIFIED], true)) {
            return $tokens[$j][1];
        }
    }

    return '';
}

/** Whether the stubs bind a member key (SoLoud::Wav::loadMem, SoLoud::FFT::fft). */
function support_is_bound(array $api, array $declared, string $key): bool
{
    $php = str_replace('::', '\\', $key);
    if (isset($declared['functions'][$php])) {
        return true;
    }
    $class = substr($key, 0, strrpos($key, '::'));
    $member = substr($key, strrpos($key, '::') + 2);
    if (!isset($api['classes'][$class])) {
        return false;
    }
    $short = substr($class, strrpos($class, '::') + 2);
    $isField = in_array($member, array_column($api['classes'][$class]['fields'], 'name'), true);
    $name = $member === $short ? '__construct' : ($isField ? "\${$member}" : $member);
    for ($c = str_replace('::', '\\', $class); $c !== null && isset($declared['classes'][$c]); $c = $declared['classes'][$c]['parent']) {
        if (isset($declared['classes'][$c]['names'][$name])) {
            return true;
        }
        if ($name === '__construct') {
            return false; // a constructor is not inherited
        }
    }

    return false;
}

function support_render(array $api, array $counted, array $declared, string $date): string
{
    $hits = 0;
    $total = 0;
    $sections = '';
    foreach ($counted as $scope => $keys) {
        $lines = '';
        $bound = 0;
        foreach ($keys as $key) {
            $is = support_is_bound($api, $declared, $key);
            $bound += $is ? 1 : 0;
            $lines .= '- [' . ($is ? 'x' : ' ') . "] `{$key}`\n";
        }
        $hits += $bound;
        $total += count($keys);
        $sections .= "\n## {$scope} ({$bound} / " . count($keys) . ")\n\n{$lines}";
    }

    return "# SoLoud API support\n\n" . support_summary($hits, $total, $date) . "\n\n"
        . "Generated by `php84 scripts/support.php` from `tools/api.json` (clang++'s AST of `lib/soloud/include`) and `stubs/`. "
        . "One line per member name: `[x]` bound (any overload), `[ ]` not bound.\n" . $sections;
}

function support_summary(int $hits, int $total, string $date): string
{
    $commit = support_commit();

    return sprintf('SoLoud %s — %d / %d members bound (%.1f%%) — %s', $commit, $hits, $total, $total === 0 ? 0 : 100 * $hits / $total, $date);
}

/** The pinned upstream commit, short form, from php_soloud.h. */
function support_commit(): string
{
    preg_match('/PHP_SOLOUD_UPSTREAM_COMMIT "([0-9a-f]{7})/', file_get_contents(dirname(__DIR__) . '/php_soloud.h'), $m);

    return $m[1] ?? 'unknown';
}

function support_badge(int $bound, int $total): string
{
    $percent = sprintf('%.1f', $total === 0 ? 0 : 100 * $bound / $total);
    $message = str_replace('%20', '_', rawurlencode("{$percent}% ({$bound}/{$total})"));

    return '[![' . SUPPORT_LABEL . '](https://img.shields.io/badge/' . str_replace(' ', '_', SUPPORT_LABEL) . "-{$message}-blue?style=flat-square)](SUPPORT.md)";
}

/** The README with the badge line set: replaced where it is, else after the CI badge. */
function support_readme(string $readme, string $badge): string
{
    $lines = explode("\n", $readme);
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![' . SUPPORT_LABEL . ']')) {
            $lines[$i] = $badge;

            return implode("\n", $lines);
        }
    }
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![CI]')) {
            array_splice($lines, $i + 1, 0, [$badge]);

            return implode("\n", $lines);
        }
    }
    throw new RuntimeException('The README has no CI badge line to put the API badge after.');
}

function support_same(string $a, string $b): bool
{
    $undated = static fn (string $s): string => preg_replace('/ — \d{4}-\d{2}-\d{2}$/m', '', $s);

    return $undated($a) === $undated($b);
}

function support_main(array $argv): int
{
    $root = dirname(__DIR__);
    $api = json_decode(file_get_contents("{$root}/tools/api.json"), true, flags: JSON_THROW_ON_ERROR);
    $md = support_render($api, support_counted($api), support_declared("{$root}/stubs"), date('Y-m-d'));
    preg_match('/(\d+) \/ (\d+) members bound/', $md, $m);
    $readme = support_readme(file_get_contents("{$root}/README.md"), support_badge((int) $m[1], (int) $m[2]));

    if (in_array('--check', $argv, true)) {
        $current = is_file("{$root}/SUPPORT.md") ? file_get_contents("{$root}/SUPPORT.md") : '';
        $same = support_same($current, $md) && $readme === file_get_contents("{$root}/README.md");
        fwrite(STDOUT, $same ? "SUPPORT.md and the badge are current.\n" : "SUPPORT.md or the badge differs: run php84 scripts/support.php.\n");

        return $same ? 0 : 1;
    }
    file_put_contents("{$root}/SUPPORT.md", $md);
    file_put_contents("{$root}/README.md", $readme);
    fwrite(STDOUT, "{$m[1]} / {$m[2]} members bound.\n");

    return 0;
}

exit(support_main($argv));
