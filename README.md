# ext-soloud

[![CI](https://img.shields.io/github/actions/workflow/status/php-io-extensions/soloud/ci.yml?style=flat-square&label=CI)](https://github.com/php-io-extensions/soloud/actions/workflows/ci.yml)
[![SoLoud API](https://img.shields.io/badge/SoLoud_API-100.0%25_%28789%2F789%29-blue?style=flat-square)](SUPPORT.md)

1:1 PHP bindings of [SoLoud](https://github.com/jarikomppa/soloud), the C++ audio engine, at its C++ API.
Each PHP class is its C++ counterpart (`SoLoud\Soloud`, `SoLoud\Wav`, `SoLoud\EchoFilter`, …) and each method
is one SoLoud call under its native name and signature. SoLoud is compiled into the extension, so it needs no
system audio packages.

```php
$engine = new SoLoud\Soloud();
$engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::MINIAUDIO);

$wav = new SoLoud\Wav();
$wav->load('blip.wav');
$voice = $engine->play($wav);
$engine->setPan($voice, -0.5);
```

## Requirements

- PHP 8.4 or newer, NTS or ZTS.
- A C++17 compiler: Xcode Command Line Tools on macOS, `g++` on Linux.
- macOS or Linux. Output goes through SoLoud's bundled miniaudio (Core Audio on macOS; ALSA, PulseAudio or JACK
  on Linux, opened at run time). The null backend (`SoLoud\Soloud::NULLDRIVER`) runs with no device.

## Install

With PIE:

```sh
pie install php-io-extensions/soloud
```

From a checkout:

```sh
bash install-macos.sh            # Homebrew php@8.4 and php@8.4-zts
bash install-debian-trixie.sh    # Debian 13, Raspberry Pi OS
```

By hand:

```sh
phpize
./configure --enable-soloud
make
```

`php --ri soloud` shows the extension version, SoLoud's version and the upstream commit it carries.

## Mapping

- **Names.** `SoLoud::X` is `SoLoud\X`; nested scopes are namespaces (`SoLoud::Thread::Pool` →
  `SoLoud\Thread\Pool`). Free functions are functions in their namespace: `SoLoud\FFT\fft()`,
  `SoLoud\Thread\sleep()`, `SoLoud\Misc\generateWaveform()`.
- **Enums** are `int` constants: SoLoud's enums are unscoped and its methods take `unsigned int`. A class's
  enumerators are class constants (`SoLoud\Soloud::CLIP_ROUNDOFF`, `SoLoud\BiquadResonantFilter::LOWPASS`),
  namespace enums are namespace constants (`SoLoud\SO_NO_ERROR`).
- **Results** (`SoLoud::result`) are returned as SoLoud returns them, never thrown.
  `SoLoud\Soloud::getErrorString()` is bound.
- **Fields** are typed properties read and written live on the C++ object, as in C++. A field SoLoud uses as
  internal state can be written too (`$wav->mChannels`, `$engine->mChannels`); a value that contradicts the
  data makes the mixer read past it, as it does in C++.
- **Buffers.** Bytes are `string`. Samples are strings of packed floats (`pack('g*', …)`) or packed int16. An
  in-out buffer (`Soloud::mix()`, `FFT\fft()`, `FilterInstance::filter()`) is a by-reference string, sized by
  the binding from the call's own counts and written back.
- **`loadMem` ownership** follows SoLoud's flags. With `aCopy` and `aTakeOwnership` both false, the object
  keeps the PHP string until its next load or until it is freed.
- **Addresses.** `FILE *`, mutex and thread handles are `int` addresses.
- **Subclassing.** `AudioSource`, `AudioSourceInstance`, `Filter`, `FilterInstance`, `FFTFilterInstance`,
  `AudioCollider`, `AudioAttenuator`, `File` and `Thread\PoolTask` can be extended in PHP. SoLoud's mixer and
  worker threads never run PHP: each call is handed to the PHP thread that created the object, which runs it at
  its next VM interrupt. A mixer call PHP does not start within one buffer plays silence. An exception thrown
  in an override is rethrown on that PHP thread.

## Lifetime

PHP deletes the C++ objects it constructs. Where SoLoud keeps a pointer from one object to another (a source to
its engine, a slot to its filter, a queue to its sources, a source to its collider, attenuator or file), the
holder keeps the PHP object alive. Request shutdown frees objects in its own order, so each object makes its own
deletion safe first: an engine stops its voices and deinitialises (joining the mixer thread), a source stops its
voices and leaves every queue that holds it, a filter leaves every slot that holds it. No order of `unset()` or
shutdown crashes the process.

## Refusals

The extension declines a call only where SoLoud would read or write memory it does not own. Every such check
has a probe test that crashes with the check off (`tests/Probes`). A refused call throws `ValueError`, except an
FFT helper called before its state exists, which throws `SoLoudException`:

- a length past the PHP string, in every `loadMem` / `loadRawWave*` / `openMem`;
- `Soloud::mix()` / `mixSigned16()` asking for more samples than the engine's scratch, or before `init()`;
- a filter instance called with more channels than its state was built for, an FFT helper before its state
  exists, `FilterInstance::initParams()` below its parameter count;
- playing a source with more than 2 channels through a `LofiFilter`, a `LofiFilter` as a global filter on an
  engine with more than 2 channels, and `init()` with more channels than a global filter's state holds;
- reading or loading through a `File` that is not open;
- a mutex or thread handle that was never created, or was already destroyed, joined or released;
- `Thread\Pool::addWork(null)`.

## Not bound

- `soloud_c.h`: the flat C mirror SoLoud generates from this API.
- Methods SoLoud names `*_internal`: its mixer's own entry points.
- `DiskFile(FILE *)`: PHP cannot make a valid `FILE *`, and two `DiskFile`s sharing one would both close it.
  `DiskFile::open()` is bound.
- SoLoud's private third-party code (dr_wav, dr_mp3, dr_flac, stb_vorbis, its miniaudio copy) and backends
  other than miniaudio and null.

## Platform notes

- **Openmpt** loads `libopenmpt` at run time and fails when it is missing. On macOS it always fails: upstream
  calls `dlopen("libopenmpt.so")`, a name macOS never has. `lib/soloud/` is not patched.
- **macOS output.** SoLoud's miniaudio (0.10) loads Core Audio by a path current macOS does not resolve.
  `config.m4` builds it with miniaudio's own `MA_NO_RUNTIME_LINKING` and links the audio frameworks instead.

## Support

[SUPPORT.md](SUPPORT.md) lists every public member of SoLoud's C++ API and whether a stub binds it; the API badge
is computed from it. Regenerate both after a binding change, and check them:

```sh
php84 scripts/support.php           # writes SUPPORT.md and the badge
php84 scripts/support.php --check   # exits 1 when either is out of date
```

## Tests

```sh
composer install
XDEBUG_MODE=off php -d memory_limit=128M vendor/bin/pest
```

Engines in the suite use the null backend; the one test that runs SoLoud's real mixer thread plays zeros at
volume 0, and skips with no output device. Probe tests run only on a probe build
(`./configure --enable-soloud --enable-soloud-probes`, never shipped).

## Upstream

SoLoud master at `e82fd32c1f62183922f08c14c814a02b58db1873` (2024-08-13), copied unchanged into `lib/soloud/`:
`include/`, `src/core/`, `src/audiosource/`, `src/filter/`, `src/backend/miniaudio/`, `src/backend/null/`. SoLoud
is © Jari Komppa, zlib/libpng license (`lib/soloud/LICENSE`).

## License

MIT, see [LICENSE](LICENSE).
