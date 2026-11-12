---
type: Runbook
title: Build, install, test
description: Homebrew installer on the Mac, Debian installer on the Pi, generator and gen_stub, probe builds, support list.
resource: install-macos.sh
tags: [soloud, build]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-12T00:00:00Z }
sources:
  - id: mac
    resource: install-macos.sh
    title: Builds in a disposable copy, installs into each PHP
  - id: debian
    resource: install-debian-trixie.sh
    title: Debian 13 / Raspberry Pi OS
---

# Change a binding

1. Edit `tools/bindings.php` (or `tools/generate.php`, or `src/manual/<Group>.cpp`).
2. `php84 tools/generate.php`, then `php84 /opt/homebrew/opt/php@8.4/lib/php/build/gen_stub.php -f stubs`.
3. `php84 scripts/support.php`.

# Build and install

* Mac: `bash install-macos.sh` installs into Homebrew `php@8.4` and `php@8.4-zts`. Each run builds in a fresh
  copy, so no object survives a flag change.[^mac]
* Probe build: `SOLOUD_CONFIGURE="--enable-soloud-probes" bash install-macos.sh`. Reinstall the release build
  afterwards; never ship a probe build.
* Debian / Pi: copy the tree with `COPYFILE_DISABLE=1 tar --no-xattrs`, then `bash install-debian-trixie.sh`.[^debian]

# Test

`XDEBUG_MODE=off php -d memory_limit=128M vendor/bin/pest` (Composer installs Pest v4). Probe halves skip on a
release build. `tests/CoverageTest.php` runs `scripts/support.php --check`.

# Upstream bump

Replace `lib/soloud/` from a clone at the new commit, rebuild `tools/ast.cpp` and run `tools/extract.php`, diff
`tools/api.json`, regenerate, test, bump `PHP_SOLOUD_UPSTREAM_COMMIT`.
