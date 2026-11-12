---
type: Module
title: Callbacks
description: PHP subclasses through C++ trampolines; SoLoud's threads post to the owner thread's queue and wait at most one buffer.
resource: src/callbacks.cpp
tags: [soloud, threads, callbacks]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-12T00:00:00Z }
sources:
  - id: callbacks
    resource: src/callbacks.cpp
    title: Trampolines, owner queue, thread functions
  - id: header
    resource: src/callbacks.h
    title: The model
---

# Overview

A PHP class extending `AudioSource`, `AudioSourceInstance`, `Filter`, `FilterInstance`, `FFTFilterInstance`,
`AudioCollider`, `AudioAttenuator`, `File` or `Thread\PoolTask` gets a C++ trampoline as its native: a
subclass of the SoLoud class whose virtuals call the PHP methods.[^callbacks]

# Threads

* SoLoud's mixer, pool workers and threads from `Thread\createThread()` never enter PHP. The trampoline posts
  the call to the owner thread's queue (the PHP thread that made the object), raises its `EG(vm_interrupt)` and
  waits. The owner runs it from `zend_interrupt_function`, or from its next binding call.
* Calls on the owner thread run inline (a `File::read` during `load`, a PHP-called `filter`).
* A mixer call waits at most one buffer's duration, then returns SoLoud's no-op: silence, the buffer
  unchanged, `0`. The mixer holds the engine's audio mutex, which a PHP callback may need. PHP works on a copy
  of the buffer, so a late result is dropped.
* Thread functions and pool tasks hold no SoLoud lock; they wait until PHP has run them or the owner's request
  ends. `Thread\wait()` and pool destruction serve the queue while they block.

# Results

* An override's return value is checked against the virtual's type (`soloud_callback_result`): `TypeError`
  otherwise. `createInstance()` must return a fresh PHP instance of the matching base.
* An exception thrown in an override is kept and rethrown on the owner thread when the interrupt returns; the
  failed call returns its no-op.

# macOS output

SoLoud's miniaudio (0.10) dlopens `CoreFoundation.framework/CoreFoundation`, which current macOS does not
resolve. `config.m4` builds it with `MA_NO_RUNTIME_LINKING` and links the audio frameworks on Darwin.
