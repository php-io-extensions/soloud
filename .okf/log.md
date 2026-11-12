# Log

## 2026-11-13

* CI (Ubuntu, no sound card): `Soloud::play()` after a failed `init()` returned a voice, and request shutdown segfaulted stopping it: `stopVoice_internal` reads `mResampleDataOwner`, which only a successful init allocates. Refused on the five `Soloud::play*` (sites `soloud-soloud-*-not-initialised`, probes in `tests/Probes/NotInitialisedTest.php`). `Bus::play*` reaches the engine only through a voice the bus already holds, so it needs none.
* Test children load the module a scanned ini loads (CI's `PHP_INI_SCAN_DIR`), not only `extension_dir/soloud.so`.

## 2026-11-12

* `SUPPORT.md` (`scripts/support.php`, from `tools/api.json`): 789 / 789 members bound. `tests/CoverageTest.php` runs `--check`.
* Abstract `AudioSource`, `AudioSourceInstance` and `Filter` bind their public constructor: `parent::__construct()` builds the trampoline then, not on first use.
* Docs, `.okf`, CI (Ubuntu 24.04 and macOS 15, PHP 8.4 / 8.5, NTS / ZTS), `install-debian-trixie.sh`.
* Pi 5 (Debian trixie, PHP 8.4 ZTS, aarch64): built with `install-debian-trixie.sh`, suite green (150 passed). SoLoud's miniaudio opens the HDMI sink with a 480-frame buffer.
* A PHP thread in `usleep()` runs no opcodes, so it never reaches its VM interrupt and every mixer request is withdrawn after one buffer (10.9 ms on the Pi). The real-mixer test waits in a busy PHP loop.
* Shared test helpers (`roundoff`, `supportWav`) live in `tests/Pest.php`: each test file runs alone.

## 2026-11-11

* SoLoud master `e82fd32` vendored unchanged in `lib/soloud/`; bound at its C++ API, not `soloud_c.h`. Stubs and C++ generated from clang's AST (`tools/`).
* `SOLOUD_NO_ASSERTS` (upstream's switch): with asserts on, a Freeverb on a mono source aborts the process during normal playback.
* SoLoud's miniaudio 0.10 never opened Core Audio on current macOS (it dlopens a relative framework path). Built with `MA_NO_RUNTIME_LINKING` and the audio frameworks linked on Darwin.
* Fields stay writable as in C++, including state such as `mChannels`; a value against the data makes the mixer read past it. Not refused.
* `DiskFile(FILE *)` not bound: PHP cannot make a valid `FILE *`, and two `DiskFile`s sharing one both close it.
* `BQRStateData` has no PHP constructor: ext-guard cannot read its one-line field list. Read through `BiquadResonantFilterInstance::mState`.
* `*_internal` members not bound: SoLoud's mixer entry points.
* Filter subclasses reach `filter()` / `filterChannel()` through the base binding (virtual dispatch), so the channel sites sit on the base.
* LofiFilter keeps state for 2 channels; SoLoud's mixer runs it with the source's or engine's channel count. Refused at play, `setGlobalFilter` and `init` (sites `*-filter-channels`). `init()` with more channels than a global filter's state was sized for is refused the same way: SoLoud keeps global filter instances across a re-init.
* Candidates that did not fault under libgmalloc got no site: `TedSid` / `Ay` file loads, `AlignedFloatBuffer::init`, a second `Pool::init`, mix before `init` (the samples check covers it), the fork check (a hang is not a crash).
* Probe children run plain libgmalloc. `MALLOC_STRICT_SIZE=1` crashes PHP itself, so it proves nothing.
