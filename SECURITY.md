# Security Policy

## Supported versions

ext-soloud is pre-1.0. No 0.x release receives security fixes or advisories; fixes land in the next release
line. Security support starts with 1.0.

| Version | Security fixes |
|---------|----------------|
| < 1.0   | No             |

## Reporting a vulnerability

Please don't open a public issue for a security problem.

Report it privately through GitHub: the **Report a vulnerability** button on the
[php-io-extensions/soloud](https://github.com/php-io-extensions/soloud) repository's **Security** tab. If that
isn't available, email **info@projectsaturnstudios.com**.

Include what you found, the affected version, your platform and audio backend, PHP build (NTS or ZTS), and steps
to reproduce (`php --ri soloud` shows the extension version and the SoLoud commit it carries). Reports are read
and weighed for the release line in development; before 1.0 there is no response-time commitment.

A defect in SoLoud itself belongs with [jarikomppa/soloud](https://github.com/jarikomppa/soloud). Report it here
as well when ext-soloud should guard against it.

## Security model

ext-soloud runs SoLoud in the PHP process. SoLoud reads the files and memory it is asked to load, and its
miniaudio backend opens the platform's audio output and runs a mixer thread. `Openmpt` dlopens `libopenmpt`. It
opens no sockets.

- **Inputs.** Integer arguments are range-checked against their C++ types. Every byte or sample length is
  checked against the PHP string it names. In-out buffers are sized by the binding from the call's own counts,
  never by PHP. Decoders (dr_wav, dr_mp3, dr_flac, stb_vorbis) parse untrusted file data as SoLoud ships them.
- **Calls SoLoud does not check.** Mixing past the engine's scratch, filter instances called with more
  channels than their state, filters on more channels than they hold, reads through a `File` that is not open,
  and mutex or thread handles that are not live are refused before SoLoud is called. Each refusal has a probe
  that crashes with the check off.
- **Fields.** Public fields are writable as in C++. A field that is internal state (`mChannels`,
  `mSampleCount`) set against the data makes the mixer read past it; that is SoLoud's behaviour and is not
  guarded.
- **Threads.** SoLoud's mixer, pool workers and created threads never run PHP. A call into a PHP override is
  handed to the PHP thread that owns the object; a mixer call not finished within one buffer is withdrawn and
  plays silence, and its late result is dropped.
- **Lifetime.** Objects SoLoud points at are kept alive by the objects pointing at them. Each object makes its
  own deletion safe first, so request shutdown in any order stops voices and joins the mixer thread before
  memory is freed.

A report is in scope when ext-soloud itself reads or writes memory it should not, leaks, races, deadlocks or
crashes: a buffer copied past its size, a SoLoud thread touching PHP, an override called after its object is
freed, a mixer thread left running after request end.
