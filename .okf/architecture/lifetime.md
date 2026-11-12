---
type: Module
title: Lifetime
description: One PHP object per native address; holders keep what SoLoud points at alive; free handlers make each deletion safe in any order.
resource: src/runtime.cpp
tags: [soloud, zend, lifetime]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-12T00:00:00Z }
sources:
  - id: runtime
    resource: src/runtime.cpp
    title: Boxes, holds, free handler, per-slot records
  - id: header
    resource: src/runtime.h
    title: soloud_object
  - id: config
    resource: tools/bindings.php
    title: holds (which calls make one object point at another)
---

# Overview

`SOLOUD_G(boxes)` maps a native address to its PHP object, so a native returned twice is the same PHP object.
PHP deletes what it constructs (`owned`); a native SoLoud owns (an instance, a field's object) is wrapped
borrowed, with its owner held.[^runtime]

# Holds

SoLoud keeps raw pointers between objects. The holder keeps the held PHP object in its `held` table, keyed by
role:[^config]

| Native pointer | Holder |
|----------------|--------|
| source → engine (`Soloud::play*`, `Bus::play*`) | source |
| slot → filter (`setFilter`, `setGlobalFilter`) | source / engine; a slot reset does not release it, since a voice may still run its instance |
| queue → source (`Queue::play`) | queue, one role per source |
| source → collider, attenuator, file | source; replaced ones stay held until the source goes, since voices copy the pointer at play |
| `loadMem` bytes, neither flag set | source, until the next load |

# Free order

Request shutdown frees objects in store order. Each free handler makes its own deletion safe first:

* A source leaves every queue that holds it (`soloud_source_gone`); its C++ destructor stops its voices.
* A filter leaves every slot that holds it (`soloud_filter_gone`).
* An engine's destructor deinitialises it, joining the mixer thread; then `soloud_engine_gone` clears the
  engine from every source pointing at it.
* A `Thread\Pool` is destroyed while serving this thread's queue, since its workers may wait on a PHP task.
* A PHP subclass's trampoline is deleted as its own type; calls still queued for it become no-ops.

`tests/ShutdownTest.php` runs every order with everything live at exit.
