<div align="center" id="header">

<h1>ext-soloud</h1>

<h3>SoLoud's C++ API bound 1:1 into PHP 8.4+, with the library compiled in</h3>

[![CI](https://img.shields.io/github/actions/workflow/status/php-io-extensions/soloud/ci.yml?style=flat-square&label=CI)](https://github.com/php-io-extensions/soloud/actions/workflows/ci.yml)
[![SoLoud API](https://img.shields.io/badge/SoLoud_API-100.0%25_%28789%2F789%29-blue?style=flat-square)](SUPPORT.md)
[![Packagist](https://img.shields.io/packagist/v/php-io-extensions/soloud?style=flat-square)](https://packagist.org/packages/php-io-extensions/soloud)
[![PHP](https://img.shields.io/packagist/dependency-v/php-io-extensions/soloud/php?style=flat-square&label=PHP)](https://packagist.org/packages/php-io-extensions/soloud)
[![License](https://img.shields.io/github/license/php-io-extensions/soloud?style=flat-square)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-linux_%7C_macos-blue?style=flat-square&logo=linux&logoColor=white)](https://solhsa.com/soloud/)
[![OKF](https://img.shields.io/badge/OKF-0.2-6f42c1?style=flat-square&label=knowledge%20bundle)](.okf/index.md)
[![PIE](https://img.shields.io/badge/PIE-installable-4f5b93?style=flat-square&logo=php&logoColor=white)](https://github.com/php/pie)

</div>

A game needs more than "play this file": dozens of voices at once, buses to group them, echo and reverb, 3D positions around a listener, a speech synth or a retro sound generator, and a mixer that keeps all of it in time. In PHP that has meant shelling out to a player, which mixes nothing.

<b>SoLoud</b> is that mixer. Jari Komppa's C++ audio engine plays WAV, OGG, FLAC and MP3 from memory or streamed, mixes voices through buses and queues, runs biquad, echo, flanger, freeverb, lofi, robotize and FFT filters per voice or globally, positions sound in 3D with attenuation and doppler, and carries its own generators: Sfxr, Speech, Noise, Monotone, TedSid, Ay, Vizsn.

<b>The only problem?</b> PHP can't reach it. SoLoud is C++, and its flat `soloud_c.h` is a lossy mirror its author generated for other languages: no subclassing, no file I/O classes, no public fields. This extension binds the C++ API itself, one to one: every public class, method, field, enum and free function in SoLoud's headers, with the library compiled into the module from an unchanged copy of upstream, so there is nothing to install from the system. C++ classes are PHP classes, PHP can extend SoLoud's abstract classes, and SoLoud's mixer thread hands every override call to the PHP thread that owns it. No defaults, no composites, no opinions: what SoLoud documents is what you call.

## Basic usage

```php
$engine = new SoLoud\Soloud();
$engine->init(SoLoud\Soloud::CLIP_ROUNDOFF, SoLoud\Soloud::MINIAUDIO);

$wav = new SoLoud\Wav();
$wav->load('blip.wav');
$voice = $engine->play($wav);
$engine->setPan($voice, -0.5);

$echo = new SoLoud\EchoFilter();
$echo->setParams(0.25, 0.5);
$wav->setFilter(0, $echo);
```

A PHP source:

```php
final class Tone extends SoLoud\AudioSource
{
    public function __construct()
    {
        parent::__construct();
        $this->mChannels = 1;
        $this->mBaseSamplerate = 44100.0;
    }

    public function createInstance(): ?SoLoud\AudioSourceInstance
    {
        return new ToneInstance();
    }
}

final class ToneInstance extends SoLoud\AudioSourceInstance
{
    private int $t = 0;

    public function getAudio(?string &$aBuffer, int $aSamplesToRead, int $aBufferSize): int
    {
        $s = [];
        for ($i = 0; $i < $aBufferSize; $i++) {
            $s[] = 0.2 * sin(2 * M_PI * 440 * $this->t++ / 44100);
        }
        $aBuffer = pack('g*', ...$s);

        return $aSamplesToRead;
    }

    public function hasEnded(): bool
    {
        return false;
    }
}
```

## Requirements

| | |
|---|---|
| PHP | 8.4 or newer, NTS or ZTS |
| OS | Linux, macOS |
| Build | a C++17 compiler, `phpize` and `php-config` for the PHP you install into |
| Runtime | nothing extra: Core Audio on macOS (linked), ALSA / PulseAudio / JACK on Linux (loaded at runtime when present). The null backend (`SoLoud\Soloud::NULLDRIVER`) needs no device. |

```bash
# Debian, Ubuntu, Raspberry Pi OS
sudo apt install build-essential php8.4-dev

# macOS: Xcode Command Line Tools, and Homebrew's PHP ships phpize and php-config
xcode-select --install
```

## Installation

### With PHP PIE (recommended)

```bash
pie install php-io-extensions/soloud
```

PIE builds the module against the PHP it runs under and enables it.

### Manually (install script)

The repository ships two installers. Each builds for its PHP, installs `soloud.so` into that PHP's `extension_dir`, writes `30-soloud.ini`, and checks the module loads. The macOS one builds in a temporary copy for Homebrew `php@8.4` and `php@8.4-zts` and ad-hoc signs the module; the Debian one builds in the checkout, writes the ini into every `conf.d` of that PHP (CLI, FPM, Apache) and cleans the build products out afterwards. SoLoud compiles with the module, so the build takes a few minutes.

```bash
git clone https://github.com/php-io-extensions/soloud.git
cd soloud
./install-macos.sh            # macOS
./install-debian-trixie.sh    # Debian 13, Raspberry Pi OS
```

### Manually (phpize)

```bash
phpize
./configure --enable-soloud
make -j"$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
sudo make install
echo "extension=soloud" | sudo tee "$(php -r 'echo PHP_CONFIG_FILE_SCAN_DIR;')/30-soloud.ini"
```

### Verify

```bash
php --ri soloud
```

```console
soloud support => enabled
Extension version => 0.11.0
SoLoud version => 202002
Upstream commit => e82fd32c1f62183922f08c14c814a02b58db1873
```

## API

789 members, all bound: SoLoud's 75 classes with their public constructors, methods and fields, and the `SoLoud::FFT`, `SoLoud::Misc` and `SoLoud::Thread` free functions. [SUPPORT.md](SUPPORT.md) lists each one. [SoLoud's documentation](https://solhsa.com/soloud/) and its headers in [`lib/soloud/include/`](lib/soloud/include) document every call; the stubs in [`stubs/`](stubs) give the PHP signature of each.

### Translations

- **Names.** `SoLoud::X` is `SoLoud\X`; nested scopes are namespaces (`SoLoud::Thread::Pool` → `SoLoud\Thread\Pool`). Free functions are functions in their namespace: `SoLoud\FFT\fft()`, `SoLoud\Thread\sleep()`, `SoLoud\Misc\generateWaveform()`.
- **Enums** are `int` constants: SoLoud's enums are unscoped and its methods take `unsigned int`. A class's enumerators are class constants (`SoLoud\Soloud::CLIP_ROUNDOFF`), namespace enums are namespace constants (`SoLoud\SO_NO_ERROR`).
- **Results** (`SoLoud::result`) are returned as SoLoud returns them, never thrown. `SoLoud\Soloud::getErrorString()` names them.
- **Fields** are typed properties read and written live on the C++ object, as in C++. A field SoLoud uses as internal state can be written too (`$wav->mChannels`); a value that contradicts the data makes the mixer read past it, as it does in C++.
- **Buffers.** Bytes are `string`. Samples are strings of packed floats (`pack('g*', …)`) or packed int16. An in-out buffer (`Soloud::mix()`, `FFT\fft()`, `FilterInstance::filter()`) is a by-reference string, sized by the binding from the call's own counts and written back.
- **`loadMem` ownership** follows SoLoud's flags. With `aCopy` and `aTakeOwnership` both false, the object keeps the PHP string until its next load or until it is freed.
- **Addresses.** `FILE *`, mutex and thread handles are `int` addresses.

Not bound: `soloud_c.h` (the flat C mirror of this API); methods SoLoud names `*_internal` (its mixer's own entry points); `DiskFile(FILE *)` (PHP cannot make a valid `FILE *`, and two `DiskFile`s sharing one would both close it; `DiskFile::open()` is bound); SoLoud's private third-party code and backends other than miniaudio and null.

### Lifetime

PHP deletes the C++ objects it constructs. Where SoLoud keeps a pointer from one object to another (a source to its engine, a slot to its filter, a queue to its sources, a source to its collider, attenuator or file), the holder keeps the PHP object alive. Request shutdown frees objects in its own order, so each object makes its own deletion safe first: an engine stops its voices and deinitialises (joining the mixer thread), a source stops its voices and leaves every queue that holds it, a filter leaves every slot that holds it. No order of `unset()` or shutdown crashes the process.

### Errors

The extension declines a call only where SoLoud would read or write memory it does not own. Every such check has a probe test that crashes with the check off ([`tests/Probes`](tests/Probes)). A refused call throws `ValueError`, except an FFT helper called before its state exists, which throws `SoLoudException`:

- a length past the PHP string, in every `loadMem` / `loadRawWave*` / `openMem`;
- `Soloud::mix()` / `mixSigned16()` asking for more samples than the engine's scratch, or before `init()`;
- `Soloud::play*()` on an engine whose `init()` has not succeeded (SoLoud makes the voice, and stopping it later reads state only a successful `init()` allocates);
- a filter instance called with more channels than its state was built for, an FFT helper before its state exists, `FilterInstance::initParams()` below its parameter count;
- playing a source with more than 2 channels through a `LofiFilter`, a `LofiFilter` as a global filter on an engine with more than 2 channels, and `init()` with more channels than a global filter's state holds;
- reading or loading through a `File` that is not open;
- a mutex or thread handle that was never created, or was already destroyed, joined or released;
- `Thread\Pool::addWork(null)`.

### Threads and callbacks

`AudioSource`, `AudioSourceInstance`, `Filter`, `FilterInstance`, `FFTFilterInstance`, `AudioCollider`, `AudioAttenuator`, `File` and `Thread\PoolTask` can be extended in PHP. SoLoud's mixer, pool workers and threads from `SoLoud\Thread\createThread()` never run PHP: each call is handed to the PHP thread that created the object, which runs it at its next VM interrupt. A mixer call PHP does not finish within one device buffer plays silence. Run PHP while sound plays: a thread blocked in `usleep()` runs no opcodes and serves nothing. An exception thrown in an override is rethrown on that PHP thread.

### Platform notes

- **Openmpt** loads `libopenmpt` at run time and fails when it is missing. On macOS it always fails: upstream calls `dlopen("libopenmpt.so")`, a name macOS never has. `lib/soloud/` is not patched.
- **macOS output.** SoLoud's miniaudio (0.10) loads Core Audio by a path current macOS does not resolve. `config.m4` builds it with miniaudio's own `MA_NO_RUNTIME_LINKING` and links the audio frameworks instead.

## Extensions you might use with this one

* [php-io-extensions/box2d](https://github.com/php-io-extensions/box2d): 2D physics, for the collisions your sounds follow.
* [php-io-extensions/miniaudio](https://github.com/php-io-extensions/miniaudio): miniaudio's own API, device and node level. The two load side by side: SoLoud's private miniaudio copy is not exported.

## Agentic Documentation

This repository carries an [Open Knowledge Format](https://github.com/GoogleCloudPlatform/knowledge-catalog/blob/main/okf/SPEC.md) bundle at [`.okf/`](.okf/index.md): Markdown with YAML frontmatter, readable by you and loadable by a coding agent. It records what the README doesn't: the binding surface and how it is generated, the lifetime model, the callback queue, every refusal, and how to build and test.

## Resources

* [SoLoud documentation](https://solhsa.com/soloud/): the manual for every call this extension binds; this README only adds what PHP changes.
* [jarikomppa/soloud at `e82fd32`](https://github.com/jarikomppa/soloud/tree/e82fd32c1f62183922f08c14c814a02b58db1873): the master commit vendored in [`lib/soloud/`](lib/soloud), unchanged. The last tag, `RELEASE_20200207`, is four years older.
* [PIE](https://github.com/php/pie): the PHP Foundation's extension installer.
* [`gen_stub.php`](https://github.com/php/php-src/blob/master/build/gen_stub.php): the php-src stub format. [`stubs/`](stubs) holds the API declarations; each `*_arginfo.h` is generated from its stub.
* [Open Knowledge Format](https://github.com/GoogleCloudPlatform/knowledge-catalog/blob/main/okf/SPEC.md): the spec the [`.okf/`](.okf/index.md) bundle follows.

## Running the test suite

Pest v4: every stub group, every shutdown order with everything live at exit, PHP sources, filters, attenuators, files and pool tasks, the support list, and one test that runs SoLoud's real mixer thread at volume 0 (it skips without an output device). Engines otherwise use the null backend; nothing is audible. Enable the module through an ini scan directory so the child processes the shutdown tests spawn load it too:

```bash
git clone https://github.com/php-io-extensions/soloud.git
cd soloud
phpize && ./configure --enable-soloud && make -j"$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
composer install
mkdir -p /tmp/soloud-ini && echo "extension=$PWD/modules/soloud.so" > /tmp/soloud-ini/soloud.ini
PHP_INI_SCAN_DIR=":/tmp/soloud-ini" php -d memory_limit=128M vendor/bin/pest
```

```console
Tests:    53 skipped, 150 passed (554 assertions)
```

The skipped tests are probe halves: they run only on a probe build (`./configure --enable-soloud --enable-soloud-probes`, never shipped), where each refusal's check can be switched off to show the crash it prevents.

## Contributing

Open an issue first for anything beyond a typo. The stubs and `src/gen/` are generated: change `tools/bindings.php` or `tools/generate.php`, run `php tools/generate.php`, regenerate arginfo with gen_stub, run `php scripts/support.php` (it rewrites [SUPPORT.md](SUPPORT.md) and the API badge; `--check` exits 1 when either is stale), and add a Pest test. `lib/soloud/` is upstream and is never edited. CI must be green on every cell of the matrix, NTS and ZTS alike. Read [`AGENTS.md`](AGENTS.md) for the rules the code follows.

## Security

ext-soloud runs SoLoud's C++ and its mixer thread inside the PHP process. See [SECURITY.md](SECURITY.md) for what it guards against and how to report a vulnerability.

## License

MIT. See [LICENSE](LICENSE). SoLoud is zlib/libpng, Copyright (c) Jari Komppa: [`lib/soloud/LICENSE`](lib/soloud/LICENSE).
