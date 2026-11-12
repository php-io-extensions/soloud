---
okf_version: "0.2"
---

# ext-soloud

* [Binding surface](api/surface.md) - SoLoud's C++ API 1:1: classes, methods, fields, enums as int constants, namespace functions; buffers as packed strings; generated from clang's AST.

# Architecture

* [Lifetime](architecture/lifetime.md) - One PHP object per native address; holders keep what SoLoud points at alive; free handlers make each deletion safe in any order.
* [Callbacks](architecture/callbacks.md) - PHP subclasses through C++ trampolines; SoLoud's threads post to the owner thread's queue and wait at most one buffer.
* [Errors](architecture/errors.md) - Result codes pass through; the kept refusals, their sites and probes.

# Runbooks

* [Build, install, test](runbooks/build.md) - Homebrew installer on the Mac, Debian installer on the Pi, generator and gen_stub, probe builds, support list.
