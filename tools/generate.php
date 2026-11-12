<?php

/*
 * Writes stubs/<Group>.stub.php and src/gen/<Group>.cpp for every group in tools/bindings.php, plus
 * src/gen/classes.h, from tools/api.json. Then run gen_stub.php on stubs/.
 *
 *   php84 tools/generate.php
 *
 * The rules (the spec's "Names and shapes"):
 *   SoLoud::X → class SoLoud\X; nested enums → int class constants (@cvalue); namespace enums → namespace
 *   constants. bool/float/double/time stay; int types are range-checked ints. const char * is a string.
 *   T * / T & of a bound class is that class (a pointer nullable). A returned T * is the PHP object for it.
 *   Public fields are properties read and written live: scalars read-write, everything else read-only.
 * A member whose types fall outside the rules is reported, unless tools/bindings.php binds it by hand.
 */

declare(strict_types=1);

$root = dirname(__DIR__);
$api = json_decode(file_get_contents("$root/tools/api.json"), true, 512, JSON_THROW_ON_ERROR);
$cfg = require "$root/tools/bindings.php";

$bound = [];
foreach ($cfg['groups'] as $group => $classes) {
    foreach ($classes as $fq) {
        $bound[$fq] = $group;
    }
}

$report = [];

// A check is emitted once bindings.json registers its site: the guard refuses a marker without one.
$sites = json_decode(file_get_contents("$root/bindings.json"), true, flags: JSON_THROW_ON_ERROR)['sites'];
foreach ($cfg['checks'] as $key => [$site]) {
    if (! isset($sites[$site])) {
        unset($cfg['checks'][$key]);
        $report[] = "$key: check $site not emitted, site not in bindings.json";
    }
}

function php_name(string $fq): string
{
    return str_replace('::', '\\', $fq);
}

function c_ident(string $fq): string
{
    return str_replace('::', '_', $fq);
}

const INTS = [
    'int' => ['INT_MIN', 'INT_MAX'],
    'unsigned int' => [null, null],
    'result' => [null, null],
    'handle' => [null, null],
    'short' => ['SHRT_MIN', 'SHRT_MAX'],
    'unsigned short' => ['0', 'USHRT_MAX'],
    'unsigned char' => ['0', 'UCHAR_MAX'],
    'char' => ['CHAR_MIN', 'CHAR_MAX'],
    'volatile int' => ['INT_MIN', 'INT_MAX'],
];

/** The bound class a type names (T *, T &, T), resolved from the scope outwards, or null. */
function class_of(string $name, string $scope, array $bound): ?string
{
    $parts = explode('::', $scope);
    while ($parts) {
        $fq = implode('::', $parts).'::'.$name;
        if (isset($bound[$fq])) {
            return $fq;
        }
        array_pop($parts);
    }

    return isset($bound['SoLoud::'.$name]) ? 'SoLoud::'.$name : null;
}

/**
 * How a type crosses: ['kind' => bool|float|int|cstr|obj|ref|value|void, ...] or null when no rule applies.
 */
function classify(string $type, string $scope, array $bound): ?array
{
    $t = trim(preg_replace('/\bconst\b/', '', $type));
    $t = preg_replace('/\s+/', ' ', $t);
    $t = preg_replace('/^SoLoud::/', '', $t);
    if ($t === 'void') {
        return ['kind' => 'void'];
    }
    if ($t === 'bool') {
        return ['kind' => 'bool'];
    }
    if ($t === 'float') {
        return ['kind' => 'float', 'c' => 'float'];
    }
    if ($t === 'double' || $t === 'time') {
        return ['kind' => 'float', 'c' => 'double'];
    }
    if (isset(INTS[$t])) {
        [$min, $max] = INTS[$t];
        $c = match ($t) {
            'volatile int' => 'int',
            'result', 'handle' => 'unsigned int',
            default => $t,
        };
        return ['kind' => 'int', 'c' => $c, 'min' => $min, 'max' => $max];
    }
    if ($t === 'char *') {
        return ['kind' => 'cstr'];
    }
    if (preg_match('/^([\w:]+) ?([*&])$/', $t, $m) && ($cls = class_of($m[1], $scope, $bound)) !== null) {
        return ['kind' => $m[2] === '*' ? 'obj' : 'ref', 'cls' => $cls];
    }
    if (preg_match('/^[\w:]+$/', $t) && ($cls = class_of($t, $scope, $bound)) !== null) {
        return ['kind' => 'value', 'cls' => $cls];
    }

    return null;
}

/** The PHP type a classified type takes as a parameter / returns. */
function php_type(array $k, bool $nullable): string
{
    $base = match ($k['kind']) {
        'bool' => 'bool',
        'float' => 'float',
        'int' => 'int',
        'cstr' => 'string',
        'obj', 'ref', 'value' => '\\'.php_name($k['cls']),
        'void' => 'void',
    };

    return $nullable && $k['kind'] !== 'void' ? '?'.$base : $base;
}

/** An enumerator name → the C++ expression and the PHP constant expression. */
function enum_ref(string $name, string $scope, array $api): array
{
    $parts = explode('::', $scope);
    while ($parts) {
        $fq = implode('::', $parts);
        foreach ($api['classes'][$fq]['enums'] ?? [] as $members) {
            if (in_array($name, $members, true)) {
                return [$fq.'::'.$name, '\\'.php_name($fq).'::'.$name];
            }
        }
        // A non-public enumerator: PHP cannot name it, so its value stands in.
        if (isset($api['classes'][$fq]['hiddenEnums'][$name])) {
            $v = (string) $api['classes'][$fq]['hiddenEnums'][$name];
            return [$v, $v];
        }
        array_pop($parts);
    }
    foreach ($api['enums'] as $fq => $members) {
        if (in_array($name, $members, true)) {
            $ns = substr($fq, 0, strrpos($fq, '::'));
            return [$ns.'::'.$name, '\\'.php_name($ns).'\\'.$name];
        }
    }
    // A qualified default (Soloud::WAVE_SQUARE): clang's reference names only the enumerator. Use the one
    // class that declares it.
    $owners = array_keys(array_filter($api['classes'], fn ($c) => array_filter($c['enums'], fn ($m) => in_array($name, $m, true))));
    if (count($owners) === 1) {
        return [$owners[0].'::'.$name, '\\'.php_name($owners[0]).'::'.$name];
    }
    throw new RuntimeException("unknown or ambiguous enumerator $name in $scope");
}

/** A default value as C++ and as PHP. */
function default_of(mixed $v, array $k, string $scope, array $api): array
{
    if (is_array($v)) {
        return enum_ref($v['const'], $scope, $api);
    }
    if ($v === null) {
        return ['NULL', 'null'];
    }
    return match ($k['kind']) {
        'bool' => [$v ? 'true' : 'false', $v ? 'true' : 'false'],
        'float' => [var_export((float) $v, true), var_export((float) $v, true)],
        default => [(string) $v, (string) $v],
    };
}

/**
 * One method or function: the stub line and the C++ body, or null with a reason.
 *
 * @return array{stub: string, body: string}|string
 */
function bind_call(array $m, string $owner, ?string $fq, array $api, array $bound, array $edges, array $buffers = [], array $checks = [], array $after = []): array|string
{
    $scope = $fq ?? $owner;
    $bufs = $buffers[$m['name']] ?? [];
    $cvars = [];
    $bufCode = [];
    $bufBack = [];
    $static = $fq === null || $m['static'];
    $ret = classify($m['return'], $scope, $bound);
    if ($ret === null || $ret['kind'] === 'value' || $ret['kind'] === 'ref') {
        return "return type {$m['return']}";
    }
    $decls = [];
    $parse = [];
    $convert = [];
    $args = [];
    $stubParams = [];
    $required = 0;
    $optional = false;
    foreach ($m['params'] as $i => $p) {
        if (isset($bufs[$p['name']]) && trim($p['type']) === 'float *') {
            $n = $i + 1;
            $required = $n;
            $stubParams[] = '?string &$'.$p['name'];
            $decls[] = "zval *p$i = NULL;";
            $parse[] = "\t\tZ_PARAM_ZVAL(p$i)";
            $bufCode[$i] = $bufs[$p['name']];
            $args[] = "reinterpret_cast<float *>(ZSTR_VAL(b$i))";
            $bufBack[] = "\tZEND_TRY_ASSIGN_REF_STR(p$i, b$i);\n";
            continue;
        }
        $k = classify($p['type'], $scope, $bound);
        if ($k === null || $k['kind'] === 'void' || $k['kind'] === 'value') {
            return "parameter {$p['type']} \${$p['name']}";
        }
        $n = $i + 1;
        $var = "p$i";
        $has = $p['hasDefault'] ?? false;
        $nullable = $k['kind'] === 'obj' || ($k['kind'] === 'cstr' && $has && $p['default'] === null);
        [$cdef, $phpdef] = $has ? default_of($p['default'], $k, $scope, $api) : [null, null];
        if ($has && ! $optional) {
            $parse[] = "\t\tZ_PARAM_OPTIONAL";
            $optional = true;
        }
        if (! $has) {
            $required = $n;
        }
        $stubParams[] = php_type($k, $nullable).' $'.$p['name'].($has ? ' = '.$phpdef : '');
        $cvars[$p['name']] = $k['kind'] === 'int' && $k['min'] === null ? "a$i" : "p$i";
        switch ($k['kind']) {
            case 'bool':
                $decls[] = "bool $var = ".($cdef ?? 'false').';';
                $parse[] = "\t\tZ_PARAM_BOOL($var)";
                $args[] = $var;
                break;
            case 'float':
                $decls[] = "double $var = ".($cdef ?? '0').';';
                $parse[] = "\t\tZ_PARAM_DOUBLE($var)";
                $args[] = "({$k['c']}) $var";
                break;
            case 'int':
                $decls[] = "zend_long $var = ".($cdef !== null ? "(zend_long) ($cdef)" : '0').';';
                $parse[] = "\t\tZ_PARAM_LONG($var)";
                if ($k['min'] === null) {
                    $convert[] = "unsigned int a$i;\n\tif (!soloud_uint_arg($var, $n, &a$i)) {\n\t\tRETURN_THROWS();\n\t}";
                    $args[] = "a$i";
                } else {
                    $convert[] = "if (!soloud_range_arg($var, {$k['min']}, {$k['max']}, $n)) {\n\t\tRETURN_THROWS();\n\t}";
                    $args[] = "({$k['c']}) $var";
                }
                break;
            case 'cstr':
                $decls[] = "char *$var = NULL;\n\tsize_t {$var}_len = 0;";
                $parse[] = $nullable ? "\t\tZ_PARAM_STRING_OR_NULL($var, {$var}_len)" : "\t\tZ_PARAM_PATH($var, {$var}_len)";
                $args[] = $var;
                break;
            case 'obj':
            case 'ref':
                $c = c_ident($k['cls']);
                $decls[] = "zend_object *$var = NULL;";
                $parse[] = $k['kind'] === 'obj'
                    ? "\t\tZ_PARAM_OBJ_OF_CLASS_OR_NULL($var, soloud_ce_$c)"
                    : "\t\tZ_PARAM_OBJ_OF_CLASS($var, soloud_ce_$c)";
                $convert[] = "{$k['cls']} *a$i = static_cast<{$k['cls']} *>(soloud_arg($var, $n, &soloud_class_$c));\n\tif ($var != NULL && a$i == NULL) {\n\t\tRETURN_THROWS();\n\t}";
                $args[] = $k['kind'] === 'ref' ? "*a$i" : "a$i";
                break;
        }
    }
    $count = count($m['params']);
    $body = '';
    if ($decls) {
        $body .= "\t".implode("\n\t", $decls)."\n";
    }
    if ($count === 0) {
        $body .= "\tZEND_PARSE_PARAMETERS_NONE();\n";
    } else {
        $body .= "\tZEND_PARSE_PARAMETERS_START($required, $count)\n".implode("\n", $parse)."\n\tZEND_PARSE_PARAMETERS_END();\n";
    }
    $callee = $fq === null ? $owner.'::' : '';
    if (! $static) {
        $c = c_ident($fq);
        $body .= "\t$fq *self = static_cast<$fq *>(soloud_this(ZEND_THIS, &soloud_class_$c));\n\tif (self == NULL) {\n\t\tRETURN_THROWS();\n\t}\n";
        $callee = 'self->';
    } elseif ($fq !== null) {
        $callee = $fq.'::';
    }
    foreach ($convert as $c) {
        $body .= "\t$c\n";
    }
    // $name in a check or after template: the native argument the call passes for that parameter.
    $native = array_combine(array_column($m['params'], 'name'), $args);
    $expand = fn (string $t) => preg_replace_callback('/\$(\w+)/', fn ($x) => $native[$x[1]], $t);
    $key = ($fq ?? $owner).'::'.$m['name'];
    if (isset($checks[$key])) {
        [$site, $fit] = $checks[$key];
        $body .= "\tchar why[192];\n\tif (!SOLOUD_PROBE_OFF(\"$site\") && !".$expand($fit).") {\n"
            ."\t\tzend_value_error(\"%s\", why); /* binding:$site */\n\t\tRETURN_THROWS();\n\t}\n";
    }
    foreach ($bufCode as $i => $expr) {
        $size = preg_replace_callback('/\$(\w+)/', fn ($x) => '(size_t) '.$cvars[$x[1]], $expr);
        $body .= "\tzend_string *b$i = soloud_float_buffer(p$i, $size);\n";
    }
    $call = $callee.$m['name'].'('.implode(', ', $args).')';
    // A non-pure virtual of a trampolined class, called on a PHP subclass: its trampoline would call PHP back
    // (parent::filter() inside filter()), so the binding calls the SoLoud implementation itself.
    if (! $static && ($m['virtual'] ?? false) && ! ($m['pure'] ?? false) && in_array($fq, $GLOBALS['cfg']['trampolines'], true)) {
        $call = "(soloud_from(Z_OBJ_P(ZEND_THIS))->php ? self->$fq::{$m['name']}(".implode(', ', $args).") : $call)";
    }
    $edge = implode('', $bufBack);
    if (isset($after[$key])) {
        $edge .= "\t".$expand($after[$key]).";\n";
    }
    if (isset($edges[$key])) {
        [$param, $role, $holder] = $edges[$key];
        $idx = array_search($param, array_column($m['params'], 'name'), true);
        // A role ending in ':' is one per held object: the object's handle completes it.
        $roleExpr = "\"$role\"";
        $roleDecl = '';
        if (str_ends_with($role, ':')) {
            $held = $holder === 'param' ? 'Z_OBJ_P(ZEND_THIS)' : "p$idx";
            $roleDecl = "\t\tchar role[32];\n\t\tsnprintf(role, sizeof role, \"$role%u\", ".$held."->handle);\n";
            $roleExpr = 'role';
        }
        $edge .= $holder === 'param'
            ? "\t{\n$roleDecl\t\tsoloud_hold(soloud_from(p$idx), $roleExpr, ZEND_THIS);\n\t}\n"
            : "\tif (p$idx != NULL) {\n$roleDecl\t\tzval held;\n\t\tZVAL_OBJ(&held, p$idx);\n\t\tsoloud_hold(soloud_from(Z_OBJ_P(ZEND_THIS)), $roleExpr, &held);\n\t}\n";
    }
    switch ($ret['kind']) {
        case 'void':
            $body .= "\t$call;\n$edge";
            break;
        case 'bool':
            $body .= "\tbool r = $call;\n{$edge}\tRETURN_BOOL(r);\n";
            break;
        case 'float':
            $body .= "\tdouble r = $call;\n{$edge}\tRETURN_DOUBLE(r);\n";
            break;
        case 'int':
            $body .= "\tzend_long r = (zend_long) $call;\n{$edge}\tRETURN_LONG(r);\n";
            break;
        case 'cstr':
            $body .= "\tconst char *r = $call;\n{$edge}\tif (r == NULL) {\n\t\tRETURN_NULL();\n\t}\n\tRETURN_STRING(r);\n";
            break;
        case 'obj':
            $body .= "\tvoid *r = $call;\n{$edge}\tsoloud_wrap(r, &soloud_class_".c_ident($ret['cls']).", NULL, return_value);\n";
            break;
    }
    $retType = php_type($ret, $ret['kind'] === 'obj' || $ret['kind'] === 'cstr');
    $prefix = $fq === null ? 'function ' : 'public '.($m['static'] ? 'static ' : '').'function ';

    return ['stub' => $prefix.$m['name'].'('.implode(', ', $stubParams).'): '.$retType, 'body' => $body];
}

/** Read and write bodies for one public field: [read, write] C++ statements, or a reason. */
function bind_field(array $f, string $fq, array $bound): array|string
{
    $name = $f['name'];
    $ref = $f['static'] ? "$fq::$name" : "self->$name";
    $t = trim($f['type']);
    $ro = "\t\tsoloud_field_arg(name, value, SOLOUD_FIELD_READONLY, 0, 0, NULL);\n\t\treturn true;";
    if (preg_match('/^(.*?) ?\[(\d+)\]$/', $t, $m)) {
        [$elem, $n] = [trim($m[1]), (int) $m[2]];
        $k = classify($elem, $fq, $bound);
        if ($elem === 'float' || $elem === 'unsigned char') {
            return ["\t\tZVAL_STRINGL(rv, (const char *) $ref, sizeof($ref));\n\t\treturn true;", $ro];
        }
        if ($k !== null && in_array($k['kind'], ['int', 'bool'], true)) {
            return ["\t\tarray_init_size(rv, $n);\n\t\tfor (size_t i = 0; i < $n; i++) {\n\t\t\tadd_next_index_long(rv, (zend_long) $ref"."[i]);\n\t\t}\n\t\treturn true;", $ro];
        }
        if ($k !== null && in_array($k['kind'], ['obj', 'value'], true)) {
            $c = c_ident($k['cls']);
            $addr = $k['kind'] === 'obj' ? "$ref"."[i]" : "&$ref"."[i]";
            return ["\t\tarray_init_size(rv, $n);\n\t\tfor (size_t i = 0; i < $n; i++) {\n\t\t\tzval e;\n\t\t\tsoloud_wrap((void *) $addr, &soloud_class_$c, &obj->std, &e);\n\t\t\tadd_next_index_zval(rv, &e);\n\t\t}\n\t\treturn true;", $ro];
        }
        return ["\t\tZVAL_LONG(rv, (zend_long) (uintptr_t) $ref);\n\t\treturn true;", $ro];
    }
    $k = classify($t, $fq, $bound);
    if ($k === null) {
        // Any other pointer or value: its address, for the pointer hand-off.
        $addr = str_contains($t, '*') || str_contains($t, '(') ? "(uintptr_t) $ref" : "(uintptr_t) &$ref";
        return ["\t\tZVAL_LONG(rv, (zend_long) $addr);\n\t\treturn true;", $ro];
    }
    switch ($k['kind']) {
        case 'bool':
            return ["\t\tZVAL_BOOL(rv, $ref);\n\t\treturn true;",
                "\t\tzval v;\n\t\tif (soloud_field_arg(name, value, SOLOUD_FIELD_BOOL, 0, 0, &v)) {\n\t\t\t$ref = Z_TYPE(v) == IS_TRUE;\n\t\t}\n\t\treturn true;"];
        case 'float':
            return ["\t\tZVAL_DOUBLE(rv, $ref);\n\t\treturn true;",
                "\t\tzval v;\n\t\tif (soloud_field_arg(name, value, SOLOUD_FIELD_FLOAT, 0, 0, &v)) {\n\t\t\t$ref = ({$k['c']}) Z_DVAL(v);\n\t\t}\n\t\treturn true;"];
        case 'int':
            $min = $k['min'] ?? '0';
            $max = $k['max'] ?? 'UINT32_MAX';
            return ["\t\tZVAL_LONG(rv, (zend_long) $ref);\n\t\treturn true;",
                "\t\tzval v;\n\t\tif (soloud_field_arg(name, value, SOLOUD_FIELD_INT, $min, $max, &v)) {\n\t\t\t$ref = ({$k['c']}) Z_LVAL(v);\n\t\t}\n\t\treturn true;"];
        case 'cstr':
            return ["\t\tif ($ref == NULL) {\n\t\t\tZVAL_NULL(rv);\n\t\t} else {\n\t\t\tZVAL_STRING(rv, $ref);\n\t\t}\n\t\treturn true;", $ro];
        case 'obj':
            return ["\t\tsoloud_wrap((void *) $ref, &soloud_class_".c_ident($k['cls']).", NULL, rv);\n\t\treturn true;", $ro];
        case 'value':
            return ["\t\tsoloud_wrap((void *) &$ref, &soloud_class_".c_ident($k['cls']).", &obj->std, rv);\n\t\treturn true;", $ro];
    }

    return "field type $t";
}

function field_php_type(array $f, string $fq, array $bound): string
{
    $t = trim($f['type']);
    if (preg_match('/^(.*?) ?\[\d+\]$/', $t, $m)) {
        $elem = trim($m[1]);
        return $elem === 'float' || $elem === 'unsigned char' ? 'string' : 'array';
    }
    $k = classify($t, $fq, $bound);
    if ($k === null) {
        return 'int';
    }

    return match ($k['kind']) {
        'bool' => 'bool', 'float' => 'float', 'int' => 'int', 'cstr' => '?string',
        'obj' => '?\\'.php_name($k['cls']), 'value' => '\\'.php_name($k['cls']),
    };
}

$classesH = "/* Generated by tools/generate.php. */\n\n#ifndef SOLOUD_GEN_CLASSES_H\n#define SOLOUD_GEN_CLASSES_H\n\n#include \"../runtime.h\"\n";
// Every header tools/ast.cpp reads: the generated code may name any of their types.
preg_match_all('/^#include "([^"]+)"/m', file_get_contents("$root/tools/ast.cpp"), $headers);
foreach ($headers[1] as $h) {
    $classesH .= "#include \"$h\"\n";
}
$classesH .= "\n";
$registers = [];

foreach ($cfg['groups'] as $group => $classes) {
    $stub = "<?php\n\n/** @generate-class-entries */\n\n";
    $cpp = "/* Generated by tools/generate.php from tools/api.json. Edit the generator, not this file. */\n\n#include \"classes.h\"\n#include \"../callbacks.h\"\n";
    $cpp .= "\nextern \"C\" {\n#include \"../../stubs/{$group}_arginfo.h\"\n}\n\n";
    $byNs = [];
    $register = "void soloud_register_$group(void)\n{\n";

    foreach ($cfg['namespace_enums'] as $enum => $g) {
        if ($g !== $group) {
            continue;
        }
        $ns = substr($enum, 0, strrpos($enum, '::'));
        foreach ($api['enums'][$enum] as $c) {
            $byNs[php_name($ns)]['consts'][] = "/** @var int\n * @cvalue $ns::$c\n */\nconst $c = UNKNOWN;";
        }
    }

    foreach ($classes as $fq) {
        $class = $api['classes'][$fq];
        $c = c_ident($fq);
        $short = substr($fq, strrpos($fq, '::') + 2);
        $ns = php_name(substr($fq, 0, strrpos($fq, '::')));
        $base = $class['bases'][0]['type'] ?? null;
        $baseFq = $base !== null ? class_of(preg_replace('/^SoLoud::/', '', $base), $fq, $bound) : null;
        if ($base !== null && $baseFq === null) {
            $report[] = "$fq: base $base is not bound";
        }
        $lines = [];
        foreach ($class['enums'] as $members) {
            foreach ($members as $e) {
                $lines[] = "    /** @cvalue $fq::$e */\n    public const int $e = UNKNOWN;";
            }
        }
        $readBody = '';
        $writeBody = '';
        foreach ($class['fields'] as $f) {
            $r = bind_field($f, $fq, $bound);
            if (is_string($r)) {
                $report[] = "$fq::{$f['name']}: $r";
                continue;
            }
            $lines[] = '    public '.field_php_type($f, $fq, $bound).' $'.$f['name'].';';
            $readBody .= "\tif (zend_string_equals_literal(name, \"{$f['name']}\")) {\n{$r[0]}\n\t}\n";
            $writeBody .= "\tif (zend_string_equals_literal(name, \"{$f['name']}\")) {\n{$r[1]}\n\t}\n";
        }
        // Constructors: one __construct; () and (Parent *) merge with the parent optional.
        $ctors = $class['constructors'];
        $canConstruct = ! $class['abstract'] && ! in_array($fq, $cfg['no_construct'] ?? [], true);
        if ($canConstruct) {
            $usable = array_values(array_filter($ctors, fn ($k) => ! array_filter($k['params'], fn ($p) => classify($p['type'], $fq, $bound) === null)));
            $withParent = array_values(array_filter($usable, fn ($k) => count($k['params']) === 1));
            $noArgs = $ctors === [] || array_filter($usable, fn ($k) => $k['params'] === []);
            $dropped = count($ctors) - count($usable);
            if ($dropped > 0) {
                $report[] = "$fq: $dropped constructor(s) with unbound parameter types";
            }
            if ($withParent) {
                $p = $withParent[0]['params'][0];
                $k = classify($p['type'], $fq, $bound);
                $pc = c_ident($k['cls']);
                $lines[] = '    public function __construct('.($noArgs ? '?' : '').'\\'.php_name($k['cls']).' $'.$p['name'].($noArgs ? ' = null' : '').') {}';
                $cpp .= "ZEND_METHOD($c, __construct)\n{\n\tzend_object *p0 = NULL;\n\tZEND_PARSE_PARAMETERS_START(".($noArgs ? 0 : 1).", 1)\n"
                    .($noArgs ? "\t\tZ_PARAM_OPTIONAL\n" : '')
                    ."\t\tZ_PARAM_OBJ_OF_CLASS_OR_NULL(p0, soloud_ce_$pc)\n\tZEND_PARSE_PARAMETERS_END();\n"
                    ."\tsoloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));\n\tif (!soloud_fresh(obj)) {\n\t\tRETURN_THROWS();\n\t}\n"
                    ."\t{$k['cls']} *a0 = static_cast<{$k['cls']} *>(soloud_arg(p0, 1, &soloud_class_$pc));\n\tif (p0 != NULL && a0 == NULL) {\n\t\tRETURN_THROWS();\n\t}\n"
                    .(in_array($fq, $cfg['trampolines'], true)
                        ? "\tsoloud_adopt(obj, soloud_new_".$short."(obj, a0), true);\n"
                        : "\tsoloud_adopt(obj, a0 != NULL ? new $fq(a0) : ".($noArgs ? "new $fq()" : 'NULL').", true);\n")
                    ."\tif (p0 != NULL) {\n\t\tzval held;\n\t\tZVAL_OBJ(&held, p0);\n\t\tsoloud_hold(obj, \"parent\", &held);\n\t}\n}\n\n";
            } elseif ($ctors === []) {
                // A struct with no constructor of its own: an aggregate constructor, one optional parameter per
                // scalar field in field order, zero by default (C's {0}).
                $params = [];
                $sets = '';
                $parse = '';
                $decls = '';
                $n = 0;
                foreach ($class['fields'] as $f) {
                    $k = $f['static'] ? null : classify(trim($f['type']), $fq, $bound);
                    if ($k === null || ! in_array($k['kind'], ['bool', 'float', 'int'], true)) {
                        continue;
                    }
                    $n++;
                    $v = 'f_'.$f['name'];
                    switch ($k['kind']) {
                        case 'bool':
                            $params[] = 'bool $'.$f['name'].' = false';
                            $decls .= "\tbool $v = false;\n";
                            $parse .= "\t\tZ_PARAM_BOOL($v)\n";
                            $sets .= "\tself->{$f['name']} = $v;\n";
                            break;
                        case 'float':
                            $params[] = 'float $'.$f['name'].' = 0.0';
                            $decls .= "\tdouble $v = 0;\n";
                            $parse .= "\t\tZ_PARAM_DOUBLE($v)\n";
                            $sets .= "\tself->{$f['name']} = ({$k['c']}) $v;\n";
                            break;
                        case 'int':
                            $params[] = 'int $'.$f['name'].' = 0';
                            $decls .= "\tzend_long $v = 0;\n";
                            $parse .= "\t\tZ_PARAM_LONG($v)\n";
                            $sets .= $k['min'] === null
                                ? "\tif (!soloud_uint_arg($v, $n, &self->{$f['name']})) {\n\t\tdelete self;\n\t\tRETURN_THROWS();\n\t}\n"
                                : "\tif (!soloud_range_arg($v, {$k['min']}, {$k['max']}, $n)) {\n\t\tdelete self;\n\t\tRETURN_THROWS();\n\t}\n\tself->{$f['name']} = ({$k['c']}) $v;\n";
                            break;
                    }
                }
                $lines[] = '    public function __construct('.implode(', ', $params).') {}';
                $cpp .= "ZEND_METHOD($c, __construct)\n{\n$decls"
                    .($n === 0 ? "\tZEND_PARSE_PARAMETERS_NONE();\n" : "\tZEND_PARSE_PARAMETERS_START(0, $n)\n\t\tZ_PARAM_OPTIONAL\n$parse\tZEND_PARSE_PARAMETERS_END();\n")
                    ."\tsoloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));\n\tif (!soloud_fresh(obj)) {\n\t\tRETURN_THROWS();\n\t}\n"
                    ."\t$fq *self = new $fq();\n$sets\tsoloud_adopt(obj, self, true);\n}\n\n";
            } elseif ($noArgs) {
                $lines[] = '    public function __construct() {}';
                $cpp .= "ZEND_METHOD($c, __construct)\n{\n\tZEND_PARSE_PARAMETERS_NONE();\n\tsoloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));\n\tif (!soloud_fresh(obj)) {\n\t\tRETURN_THROWS();\n\t}\n\tsoloud_adopt(obj, ".(in_array($fq, $cfg['trampolines'], true) ? "soloud_new_$short(obj)" : "new $fq()").", true);\n}\n\n";
            } else {
                $canConstruct = false;
            }
        } elseif ($class['abstract'] && in_array($fq, $cfg['trampolines'], true) && array_filter($ctors, fn ($k) => $k['params'] === [])) {
            // An abstract class's public constructor, reached through parent::__construct() from a PHP subclass:
            // builds the trampoline then rather than on first use.
            $lines[] = '    public function __construct() {}';
            $cpp .= "ZEND_METHOD($c, __construct)\n{\n\tZEND_PARSE_PARAMETERS_NONE();\n\tsoloud_object *obj = soloud_from(Z_OBJ_P(ZEND_THIS));\n\tif (!soloud_fresh(obj)) {\n\t\tRETURN_THROWS();\n\t}\n\tsoloud_trampoline(obj);\n}\n\n";
        }
        $seen = [];
        // Bases whose bound virtuals subclass overrides reach through virtual dispatch (tools/bindings.php 'inherit').
        $inherited = [];
        for ($b = $baseFq; $b !== null; $b = class_of(preg_replace('/^SoLoud::/', '', $api['classes'][$b]['bases'][0]['type'] ?? ''), $b, $bound)) {
            $inherited = array_merge($inherited, $cfg['inherit'][$b] ?? []);
            if (($api['classes'][$b]['bases'] ?? []) === []) {
                break;
            }
        }
        foreach ($class['methods'] as $m) {
            $key = "$fq::{$m['name']}";
            // SoLoud's mixer plumbing: not part of the bound API.
            if (str_ends_with($m['name'], '_internal') || in_array($m['name'], $inherited, true)) {
                continue;
            }
            if (isset($seen[$m['name']])) {
                $report[] = "$key: overload skipped";
                continue;
            }
            $seen[$m['name']] = true;
            if (isset($cfg['manual'][$key])) {
                $lines[] = '    '.$cfg['manual'][$key].' {}';
                continue;
            }
            $r = bind_call($m, $fq, $fq, $api, $bound, $cfg['edges'], $cfg['buffers'], $cfg['checks'], $cfg['after']);
            if (is_string($r)) {
                $report[] = "$key: $r";
                continue;
            }
            $lines[] = '    '.$r['stub'].' {}';
            $cpp .= "ZEND_METHOD($c, {$m['name']})\n{\n{$r['body']}}\n\n";
        }
        $abstract = $class['abstract'] || ! $canConstruct ? 'abstract ' : '';
        $extends = $baseFq !== null ? ' extends \\'.php_name($baseFq) : '';
        $byNs[$ns]['classes'][] = "/** @not-serializable */\n{$abstract}class $short$extends\n{\n".implode("\n\n", $lines)."\n}";

        $cpp .= "static bool soloud_read_$c(soloud_object *obj, zend_string *name, zval *rv)\n{\n"
            .($readBody !== '' ? "\t$fq *self = static_cast<$fq *>(obj->native);\n\t(void) self;\n$readBody" : "\t(void) obj; (void) name; (void) rv;\n")
            ."\treturn false;\n}\n\n";
        $cpp .= "static bool soloud_write_$c(soloud_object *obj, zend_string *name, zval *value)\n{\n"
            .($writeBody !== '' ? "\t$fq *self = static_cast<$fq *>(obj->native);\n\t(void) self;\n$writeBody" : "\t(void) obj; (void) name; (void) value;\n")
            ."\treturn false;\n}\n\n";
        $destroy = 'NULL';
        if ($canConstruct) {
            $cpp .= "static void soloud_destroy_$c(void *native)\n{\n\tdelete static_cast<$fq *>(native);\n}\n\n";
            $destroy = "soloud_destroy_$c";
        }
        $cpp .= "zend_class_entry *soloud_ce_$c;\n";
        $cpp .= "const soloud_class soloud_class_$c = {\"$fq\", &soloud_ce_$c, ".($baseFq !== null ? '&soloud_class_'.c_ident($baseFq) : 'NULL').", $destroy, soloud_read_$c, soloud_write_$c};\n\n";
        $classesH .= "extern zend_class_entry *soloud_ce_$c;\nextern const soloud_class soloud_class_$c;\n";
        $register .= "\tsoloud_ce_$c = register_class_$c(".($baseFq !== null ? 'soloud_ce_'.c_ident($baseFq) : '').");\n\tsoloud_register_class(&soloud_class_$c);\n";
    }
    // Free functions (tools/bindings.php 'functions'): SoLoud\FFT\fft() and the like. gen_stub puts them in this
    // group's ext_functions table, which the module entry takes through soloud_functions.
    foreach ($cfg['functions'][$group] ?? [] as $fq) {
        $ns = substr($fq, 0, strrpos($fq, '::'));
        $name = substr($fq, strrpos($fq, '::') + 2);
        if (isset($cfg['manual'][$fq])) {
            $byNs[php_name($ns)]['functions'][] = $cfg['manual'][$fq].' {}';
            continue;
        }
        $overloads = isset($api['functions'][$fq]['params']) ? [$api['functions'][$fq]] : $api['functions'][$fq];
        if (count($overloads) > 1) {
            $report[] = "$fq: overload skipped";
        }
        $r = bind_call($overloads[0] + ['name' => $name, 'static' => true], $ns, null, $api, $bound, $cfg['edges'], $cfg['buffers'], $cfg['checks'], $cfg['after']);
        if (is_string($r)) {
            $report[] = "$fq: $r";
            continue;
        }
        $byNs[php_name($ns)]['functions'][] = $r['stub'].' {}';
        $cpp .= 'ZEND_FUNCTION('.c_ident($fq).")\n{\n{$r['body']}}\n\n";
    }
    if (isset($cfg['functions'][$group])) {
        $cpp .= "const zend_function_entry *soloud_functions = ext_functions;\n\n";
        $classesH .= "extern const zend_function_entry *soloud_functions;\n";
    }
    $register .= "}\n";
    $hasConsts = false;
    foreach ($byNs as $ns => $parts) {
        $stub .= "namespace $ns {\n\n".implode("\n\n", array_merge($parts['consts'] ?? [], $parts['classes'] ?? [], $parts['functions'] ?? []))."\n\n}\n\n";
        $hasConsts = $hasConsts || isset($parts['consts']);
    }
    if ($hasConsts) {
        $register = str_replace("{\n", "{\n\tregister_{$group}_symbols(0);\n", $register);
    }
    $cpp .= $register;
    $registers[] = $group;
    @mkdir("$root/src/gen", 0777, true);
    file_put_contents("$root/stubs/$group.stub.php", rtrim($stub)."\n");
    file_put_contents("$root/src/gen/$group.cpp", $cpp);
}

foreach ($registers as $g) {
    $classesH .= "void soloud_register_$g(void);\n";
}
$classesH .= "\n#endif\n";
file_put_contents("$root/src/gen/classes.h", $classesH);
file_put_contents("$root/tools/report.txt", implode("\n", $report)."\n");
fwrite(STDERR, count($report)." members not generated: see tools/report.txt\n");
