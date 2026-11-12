PHP_ARG_ENABLE([soloud],
  [whether to enable soloud support],
  [AS_HELP_STRING([--enable-soloud], [Enable the SoLoud bindings])],
  [no])

PHP_ARG_ENABLE([soloud-probes],
  [whether to build the soloud probe switch],
  [AS_HELP_STRING([--enable-soloud-probes],
    [Build the SOLOUD_PROBE_OFF switch that tests/Probes drives: env SOLOUD_PROBE_OFF=<site id> turns that kept refusal off. Never for a release build])],
  [no],
  [no])

if test "$PHP_SOLOUD" != "no"; then
  if test "$PHP_SOLOUD_PROBES" != "no"; then
    AC_DEFINE([SOLOUD_PROBES], [1], [Kept refusal sites can be turned off through env SOLOUD_PROBE_OFF])
  fi

  PHP_REQUIRE_CXX()

  soloud_binding_sources=" \
    src/soloud.cpp \
    src/runtime.cpp \
    src/gen/Core.cpp \
    src/gen/Wav.cpp \
    src/gen/AudioSources.cpp \
    src/gen/Filters.cpp \
    src/gen/Support.cpp \
    src/manual/Core.cpp \
    src/manual/Wav.cpp \
    src/manual/AudioSources.cpp \
    src/manual/Filters.cpp \
    src/manual/Support.cpp \
    src/manual/Thread.cpp \
    src/callbacks.cpp"

  dnl Upstream, unchanged. C++ at SoLoud's own standard; its two C files as C.
  soloud_upstream_cxx=" \
    lib/soloud/src/core/soloud.cpp \
    lib/soloud/src/core/soloud_audiosource.cpp \
    lib/soloud/src/core/soloud_bus.cpp \
    lib/soloud/src/core/soloud_core_3d.cpp \
    lib/soloud/src/core/soloud_core_basicops.cpp \
    lib/soloud/src/core/soloud_core_faderops.cpp \
    lib/soloud/src/core/soloud_core_filterops.cpp \
    lib/soloud/src/core/soloud_core_getters.cpp \
    lib/soloud/src/core/soloud_core_setters.cpp \
    lib/soloud/src/core/soloud_core_voicegroup.cpp \
    lib/soloud/src/core/soloud_core_voiceops.cpp \
    lib/soloud/src/core/soloud_fader.cpp \
    lib/soloud/src/core/soloud_fft.cpp \
    lib/soloud/src/core/soloud_fft_lut.cpp \
    lib/soloud/src/core/soloud_file.cpp \
    lib/soloud/src/core/soloud_filter.cpp \
    lib/soloud/src/core/soloud_misc.cpp \
    lib/soloud/src/core/soloud_queue.cpp \
    lib/soloud/src/core/soloud_thread.cpp \
    lib/soloud/src/audiosource/ay/chipplayer.cpp \
    lib/soloud/src/audiosource/ay/sndbuffer.cpp \
    lib/soloud/src/audiosource/ay/sndchip.cpp \
    lib/soloud/src/audiosource/ay/sndrender.cpp \
    lib/soloud/src/audiosource/ay/soloud_ay.cpp \
    lib/soloud/src/audiosource/monotone/soloud_monotone.cpp \
    lib/soloud/src/audiosource/noise/soloud_noise.cpp \
    lib/soloud/src/audiosource/openmpt/soloud_openmpt.cpp \
    lib/soloud/src/audiosource/sfxr/soloud_sfxr.cpp \
    lib/soloud/src/audiosource/speech/darray.cpp \
    lib/soloud/src/audiosource/speech/klatt.cpp \
    lib/soloud/src/audiosource/speech/resonator.cpp \
    lib/soloud/src/audiosource/speech/soloud_speech.cpp \
    lib/soloud/src/audiosource/speech/tts.cpp \
    lib/soloud/src/audiosource/tedsid/sid.cpp \
    lib/soloud/src/audiosource/tedsid/soloud_tedsid.cpp \
    lib/soloud/src/audiosource/tedsid/ted.cpp \
    lib/soloud/src/audiosource/vic/soloud_vic.cpp \
    lib/soloud/src/audiosource/vizsn/soloud_vizsn.cpp \
    lib/soloud/src/audiosource/wav/dr_impl.cpp \
    lib/soloud/src/audiosource/wav/soloud_wav.cpp \
    lib/soloud/src/audiosource/wav/soloud_wavstream.cpp \
    lib/soloud/src/backend/miniaudio/soloud_miniaudio.cpp \
    lib/soloud/src/backend/null/soloud_null.cpp \
    lib/soloud/src/filter/soloud_bassboostfilter.cpp \
    lib/soloud/src/filter/soloud_biquadresonantfilter.cpp \
    lib/soloud/src/filter/soloud_dcremovalfilter.cpp \
    lib/soloud/src/filter/soloud_duckfilter.cpp \
    lib/soloud/src/filter/soloud_echofilter.cpp \
    lib/soloud/src/filter/soloud_eqfilter.cpp \
    lib/soloud/src/filter/soloud_fftfilter.cpp \
    lib/soloud/src/filter/soloud_flangerfilter.cpp \
    lib/soloud/src/filter/soloud_freeverbfilter.cpp \
    lib/soloud/src/filter/soloud_lofifilter.cpp \
    lib/soloud/src/filter/soloud_robotizefilter.cpp \
    lib/soloud/src/filter/soloud_waveshaperfilter.cpp"

  soloud_upstream_c=" \
    lib/soloud/src/audiosource/wav/stb_vorbis.c \
    lib/soloud/src/audiosource/openmpt/soloud_openmpt_dll.c"

  PHP_NEW_EXTENSION([soloud],
    [$soloud_binding_sources],
    [$ext_shared],,
    [-std=c++17 -fvisibility=hidden -DWITH_MINIAUDIO -DWITH_NULL -DSOLOUD_NO_ASSERTS -I$ext_srcdir/lib/soloud/include -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1],
    [cxx])

  dnl SoLoud's own build flags: the miniaudio and null backends, headers from lib/soloud/include only.
  dnl SOLOUD_NO_ASSERTS is upstream's knob: its asserts abort(); a release build of SoLoud has them off.
  dnl What an assert stood in front of is refused by the binding where a probe shows it crashes.
  dnl Set after PHP_NEW_EXTENSION, which sets ext_srcdir.
  soloud_defs="-fvisibility=hidden -DWITH_MINIAUDIO -DWITH_NULL -DSOLOUD_NO_ASSERTS -I$ext_srcdir/lib/soloud/include"
  dnl SoLoud's miniaudio (0.10) dlopens "CoreFoundation.framework/CoreFoundation", a relative path current macOS
  dnl does not resolve, so its Core Audio backend never starts. On Darwin it links the frameworks at build
  dnl time instead: miniaudio's own MA_NO_RUNTIME_LINKING.
  case $host_os in
    darwin*) soloud_defs="$soloud_defs -DMA_NO_RUNTIME_LINKING" ;;
  esac

  dnl Upstream builds with its own flags, as ext/intl adds its C++ sources.
  if test "$ext_shared" = "no"; then
    PHP_ADD_SOURCES(PHP_EXT_DIR(soloud), [$soloud_upstream_cxx], [-std=c++11 $soloud_defs])
    PHP_ADD_SOURCES(PHP_EXT_DIR(soloud), [$soloud_upstream_c], [-std=gnu11 $soloud_defs])
  else
    PHP_ADD_SOURCES_X(PHP_EXT_DIR(soloud), [$soloud_upstream_cxx], [-std=c++11 $soloud_defs], [shared_objects_soloud], [yes])
    PHP_ADD_SOURCES_X(PHP_EXT_DIR(soloud), [$soloud_upstream_c], [-std=gnu11 $soloud_defs], [shared_objects_soloud], [yes])
  fi

  PHP_ADD_BUILD_DIR([$ext_builddir/src])
  PHP_ADD_BUILD_DIR([$ext_builddir/src/gen])
  PHP_ADD_BUILD_DIR([$ext_builddir/src/manual])
  for soloud_dir in core audiosource/ay audiosource/monotone audiosource/noise audiosource/openmpt audiosource/sfxr \
      audiosource/speech audiosource/tedsid audiosource/vic audiosource/vizsn audiosource/wav backend/miniaudio \
      backend/null filter; do
    PHP_ADD_BUILD_DIR([$ext_builddir/lib/soloud/src/$soloud_dir])
  done

  dnl Darwin's libSystem provides pthread, dl and m; libc++ comes with PHP_REQUIRE_CXX; the audio frameworks
  dnl are linked (MA_NO_RUNTIME_LINKING, above). Elsewhere miniaudio dlopens the audio backends at runtime.
  case $host_os in
    darwin*)
      SOLOUD_SHARED_LIBADD="$SOLOUD_SHARED_LIBADD -framework CoreFoundation -framework CoreAudio -framework AudioUnit -framework AudioToolbox"
      ;;
    *)
      PHP_ADD_LIBRARY([stdc++],, [SOLOUD_SHARED_LIBADD])
      PHP_ADD_LIBRARY([pthread],, [SOLOUD_SHARED_LIBADD])
      PHP_ADD_LIBRARY([m],, [SOLOUD_SHARED_LIBADD])
      PHP_ADD_LIBRARY([dl],, [SOLOUD_SHARED_LIBADD])
      ;;
  esac
  PHP_SUBST([SOLOUD_SHARED_LIBADD])
fi
