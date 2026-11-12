<?php

/*
 * Reads clang's JSON AST of the headers tools/ast.cpp includes and writes tools/api.json: every public
 * class (bases, abstract, constructors, methods, fields, nested enums), namespace function, namespace
 * enum and typedef under SoLoud::. Members are public ones only, in declaration order.
 *
 *   clang++ -std=c++11 -Ilib/soloud/include -Xclang -ast-dump=json -Xclang -ast-dump-filter=SoLoud \
 *       -fsyntax-only tools/ast.cpp | php84 tools/extract.php tools/api.json
 */

declare(strict_types=1);

$text = stream_get_contents(STDIN);
// -ast-dump-filter prints one JSON object per matching declaration, each starting at column 0.
$docs = preg_split('/^(?=\{)/m', $text, -1, PREG_SPLIT_NO_EMPTY);

$api = ['classes' => [], 'functions' => [], 'enums' => [], 'typedefs' => []];

/** The type a node declares, as written, and its desugared form when it differs. */
function type_of(array $node): array
{
    $t = $node['type'] ?? [];
    $out = ['type' => $t['qualType'] ?? ''];
    if (isset($t['desugaredQualType'])) {
        $out['canonical'] = $t['desugaredQualType'];
    }

    return $out;
}

/** A default argument as a literal: int, float, bool, null, or a constant name. */
function default_of(array $parm): mixed
{
    if (($parm['init'] ?? null) === null) {
        return null;
    }
    $expr = $parm['inner'][0] ?? null;

    return ['value' => literal($expr)];
}

function literal(?array $e): mixed
{
    if ($e === null) {
        return null;
    }
    switch ($e['kind']) {
        case 'IntegerLiteral':
            return (int) $e['value'];
        case 'FloatingLiteral':
            return (float) $e['value'];
        case 'CXXBoolLiteralExpr':
            return (bool) $e['value'];
        case 'CXXNullPtrLiteralExpr':
        case 'GNUNullExpr':
            return null;
        case 'UnaryOperator':
            $v = literal($e['inner'][0] ?? null);
            return $e['opcode'] === '-' && is_numeric($v) ? -$v : $v;
        case 'DeclRefExpr':
            return ['const' => $e['referencedDecl']['name']];
        case 'ImplicitCastExpr':
        case 'ParenExpr':
        case 'CStyleCastExpr':
        case 'MaterializeTemporaryExpr':
        case 'ExprWithCleanups':
        case 'ConstantExpr':
            $inner = literal($e['inner'][0] ?? null);
            // A literal 0 cast to a pointer is NULL.
            if ($e['kind'] === 'ImplicitCastExpr' && ($e['castKind'] ?? '') === 'NullToPointer') {
                return null;
            }
            return $inner;
    }
    throw new RuntimeException('unhandled default argument expression '.$e['kind']);
}

function params_of(array $fn): array
{
    $out = [];
    foreach ($fn['inner'] ?? [] as $p) {
        if ($p['kind'] !== 'ParmVarDecl') {
            continue;
        }
        $param = ['name' => $p['name'] ?? ''] + type_of($p);
        if (array_key_exists('init', $p)) {
            $param['default'] = default_of($p)['value'];
            $param['hasDefault'] = true;
        }
        $out[] = $param;
    }

    return $out;
}

/** "result (float *, unsigned int)" → "result"; "float *(unsigned int) const" → "float *". */
function return_of(string $fnType): string
{
    $depth = 0;
    for ($i = strlen($fnType) - 1; $i >= 0; $i--) {
        $c = $fnType[$i];
        if ($c === ')') {
            $depth++;
        } elseif ($c === '(') {
            $depth--;
            if ($depth === 0) {
                return rtrim(substr($fnType, 0, $i));
            }
        }
    }

    return $fnType;
}

function enum_of(array $node): array
{
    $names = [];
    foreach ($node['inner'] ?? [] as $c) {
        if ($c['kind'] === 'EnumConstantDecl') {
            $names[] = $c['name'];
        }
    }

    return $names;
}

/** An enum's constants with their values: explicit initialisers, else one more than the last. */
function enum_values(array $node): array
{
    $values = [];
    $next = 0;
    foreach ($node['inner'] ?? [] as $c) {
        if ($c['kind'] !== 'EnumConstantDecl') {
            continue;
        }
        foreach ($c['inner'] ?? [] as $e) {
            if ($e['kind'] === 'ConstantExpr' && isset($e['value'])) {
                $next = (int) $e['value'];
            }
        }
        $values[$c['name']] = $next++;
    }

    return $values;
}

function record(array $node, string $fq, array &$api): void
{
    $access = ($node['tagUsed'] ?? 'class') === 'class' ? 'private' : 'public';
    $class = [
        'kind' => $node['tagUsed'] ?? 'class',
        'bases' => array_map(fn ($b) => ['type' => $b['type']['qualType'], 'access' => $b['access']], $node['bases'] ?? []),
        'abstract' => (bool) ($node['definitionData']['isAbstract'] ?? false),
        'constructors' => [],
        'methods' => [],
        'fields' => [],
        'enums' => [],
        // Non-public enums, with values: a public default argument may still name one.
        'hiddenEnums' => [],
    ];
    $anon = 0;
    foreach ($node['inner'] ?? [] as $c) {
        $kind = $c['kind'];
        if ($kind === 'AccessSpecDecl') {
            $access = $c['access'];
            continue;
        }
        if ($kind === 'EnumDecl' && $access !== 'public') {
            $class['hiddenEnums'] += enum_values($c);
            continue;
        }
        if (($c['isImplicit'] ?? false) || $access !== 'public') {
            continue;
        }
        switch ($kind) {
            case 'CXXConstructorDecl':
                $class['constructors'][] = ['params' => params_of($c)];
                break;
            case 'CXXMethodDecl':
                if (str_starts_with($c['name'], 'operator')) {
                    break;
                }
                $class['methods'][] = [
                    'name' => $c['name'],
                    'return' => return_of($c['type']['qualType']),
                    'params' => params_of($c),
                    'static' => ($c['storageClass'] ?? '') === 'static',
                    'virtual' => (bool) ($c['virtual'] ?? false),
                    'pure' => (bool) ($c['pure'] ?? false),
                    'const' => str_ends_with($c['type']['qualType'], ' const'),
                ];
                break;
            case 'FieldDecl':
                $class['fields'][] = ['name' => $c['name'], 'static' => false] + type_of($c);
                break;
            case 'VarDecl':
                $class['fields'][] = ['name' => $c['name'], 'static' => true] + type_of($c);
                break;
            case 'EnumDecl':
                $class['enums'][$c['name'] ?? ('anonymous'.$anon++)] = enum_of($c);
                break;
            case 'CXXRecordDecl':
                if ($c['completeDefinition'] ?? false) {
                    record($c, $fq.'::'.$c['name'], $api);
                }
                break;
        }
    }
    $api['classes'][$fq] = $class;
}

function scope(array $node, string $ns, array &$api): void
{
    foreach ($node['inner'] ?? [] as $c) {
        $name = $c['name'] ?? '';
        switch ($c['kind']) {
            case 'NamespaceDecl':
                scope($c, $ns.'::'.$name, $api);
                break;
            case 'CXXRecordDecl':
                if ($c['completeDefinition'] ?? false) {
                    record($c, $ns.'::'.$name, $api);
                }
                break;
            case 'FunctionDecl':
                $api['functions'][$ns.'::'.$name][] = [
                    'return' => return_of($c['type']['qualType']),
                    'params' => params_of($c),
                ];
                break;
            case 'EnumDecl':
                $api['enums'][$ns.'::'.($name !== '' ? $name : 'anonymous')] = enum_of($c);
                break;
            case 'TypedefDecl':
            case 'TypeAliasDecl':
                $api['typedefs'][$ns.'::'.$name] = type_of($c);
                break;
        }
    }
}

foreach ($docs as $doc) {
    $node = json_decode($doc, true, 4096, JSON_THROW_ON_ERROR);
    // Only the namespace blocks themselves: a filtered dump also prints every nested SoLoud-named declaration.
    if ($node['kind'] !== 'NamespaceDecl' || ($node['name'] ?? '') !== 'SoLoud') {
        continue;
    }
    scope($node, 'SoLoud', $api);
}

ksort($api['classes']);
ksort($api['functions']);
file_put_contents(
    $argv[1] ?? 'php://stdout',
    json_encode($api, JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES | JSON_PRESERVE_ZERO_FRACTION | JSON_THROW_ON_ERROR)."\n",
);
