---
type: API
title: Binding surface
description: SoLoud's C++ API 1:1, generated from clang's AST of lib/soloud/include.
resource: stubs/
tags: [soloud, api]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-12T00:00:00Z }
sources:
  - id: api
    resource: tools/api.json
    title: clang AST of lib/soloud/include (tools/ast.cpp, tools/extract.php)
  - id: config
    resource: tools/bindings.php
    title: Stub groups, trampolines, manual members, buffers, holds, checks
  - id: support
    resource: SUPPORT.md
    title: Every public member and whether a stub binds it
---

# Overview

The surface is SoLoud's C++ headers at commit `e82fd32`: 75 classes, their constructors, methods and public
fields, and the `SoLoud::FFT`, `SoLoud::Misc` and `SoLoud::Thread` free functions. `SUPPORT.md` counts 789
members, all bound.[^support]

# Names

* `SoLoud::X` → `SoLoud\X`; nested scopes are namespaces (`SoLoud\Thread\Pool`, `SoLoud\Misc\Prg`).
* Free functions are namespace functions (`SoLoud\FFT\fft()`).
* Enumerators are `int` constants: class enums on their class (`SoLoud\Soloud::NULLDRIVER`), namespace enums in
  the namespace (`SoLoud\SO_NO_ERROR`). SoLoud's enums are unscoped and taken as `unsigned int`.
* `result` and `handle` are `int`, `time` is `float`. Unsigned and narrow ints are range-checked (`ValueError`).

# Shapes

* Abstract C++ classes are PHP abstract classes. Those in `bindings.php` `trampolines` can be extended
  ([Callbacks](../architecture/callbacks.md)); their public constructor builds the trampoline when called through
  `parent::__construct()`, otherwise it is built on first use.
* A struct without a constructor gets an aggregate constructor, one optional parameter per scalar field.
  `BQRStateData` has none: ext-guard cannot read its one-line field list. It is read through
  `BiquadResonantFilterInstance::mState`.
* Fields are typed properties read and written live, as in C++, including fields SoLoud uses as state.
* Overloads: the one the native name keeps, with native defaults. `DiskFile(FILE *)` is not bound.

# Buffers

* Bytes: `string` plus its length; the length past the string is refused.
* Samples: packed floats (`pack('g*')`) or packed int16 strings.
* In-out buffers (`bindings.php` `buffers`): a by-reference string the binding pads with zeros to the count the
  call implies, then writes back.
* `loadMem` ownership follows the flags: `aCopy` copies; `aTakeOwnership` passes a `new[]` copy SoLoud
  `delete[]`s; neither keeps the PHP string on the object until its next load or its free.
* `FILE *`, mutex and thread handles: `int` addresses. Mutex and thread handles are tracked while live.

# Generation

`tools/generate.php` writes `stubs/*.stub.php`, `src/gen/*.cpp` and `src/gen/classes.h` from
`tools/api.json` and `tools/bindings.php`.[^config] Raw-buffer members are hand-bound in `src/manual/`.
`tools/report.txt` lists anything left out.

[^api]: tools/api.json
[^config]: tools/bindings.php
[^support]: SUPPORT.md
