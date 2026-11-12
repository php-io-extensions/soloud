---
type: Module
title: Errors
description: Result codes pass through; the kept refusals, their sites and probes.
resource: bindings.json
tags: [soloud, refusals, probes]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-12T00:00:00Z }
sources:
  - id: bindings
    resource: bindings.json
    title: sites
  - id: checks
    resource: src/runtime.cpp
    title: Check predicates the generated calls use
  - id: probes
    resource: tests/Probes/
    title: One probe per site
---

# Overview

SoLoud reports errors as `result` codes; they are returned, never thrown. Marshalling throws `TypeError` /
`ValueError` (out-of-range ints, a second `__construct()`, a bad override return). Everything else is a kept
refusal: a call SoLoud does not check that would crash.[^bindings]

# Sites

| Sites | Refused | Crash |
|-------|---------|-------|
| `*-loadmem-length`, `*-loadrawwave*-length`, `sfxr-loadparamsmem-length`, `memoryfile-openmem-length` | a length past the PHP string | read past the string |
| `soloud-mix-samples`, `soloud-mixsigned16-samples` | more samples than the engine's scratch (none before `init()`) | heap overflow |
| `soloud-*play*-not-initialised` | `Soloud::play*` before an `init()` succeeded | stopping the voice (stop, stopAll, a destructor, shutdown) reads the NULL `mResampleDataOwner` |
| `filterinstance-filter-channels`, `filterinstance-filterchannel-channels` | more channels than the instance's state, a channel past the count, an FFT instance with no parent | write past the state |
| `fftfilterinstance-*-state` | an FFT helper before `filterChannel()` allocated its state, past its channels, past 256 samples | NULL or past-the-end read (`SoLoudException`) |
| `filterinstance-initparams-count` | a count below the instance's, or above 256 | read past `mParam`; abort |
| `*-play*-filter-channels`, `soloud-setglobalfilter-channels`, `soloud-init-filter-channels` | a `LofiFilter` on more than 2 channels; `init()` with more channels than a global filter's state | the mixer writes past the filter state |
| `file-*-closed`, `*-loadfile-closed`, `*-loadfiletomem-closed`, `wavstream-parse-closed`, `memoryfile-openfiletomem-closed` | a `File` that is not open (or null where SoLoud does not check) | NULL `FILE *`, read past a `MemoryFile` |
| `thread-*mutex-handle`, `thread-wait-handle`, `thread-release-handle` | a handle not live, already joined or released | freed memory |
| `pool-addwork-null` | a null task | NULL call |

Not refused: writing a field SoLoud uses as state (`mChannels`), as in C++.

# Probes

Each site has a test in `tests/Probes` that runs the call in a child with `SOLOUD_PROBE_OFF=<id>` on a probe
build, under libgmalloc on macOS, and expects a fault; the release half expects the refusal.[^probes] A
candidate that does not fault gets no site.
