/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: cb46b749da08814e087f1492284b886a384eeea6 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_Wav___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Wav_load, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFilename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Wav_loadMem, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aMem, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, aLength, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aCopy, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aTakeOwnership, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Wav_loadFile, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aFile, SoLoud\\File, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Wav_loadRawWave8, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aMem, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, aLength, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aSamplerate, IS_DOUBLE, 0, "44100.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aChannels, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Wav_loadRawWave16 arginfo_class_SoLoud_Wav_loadRawWave8

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Wav_loadRawWave, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aMem, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, aLength, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aSamplerate, IS_DOUBLE, 0, "44100.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aChannels, IS_LONG, 0, "1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aCopy, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aTakeOwnership, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_Wav_createInstance, 0, 0, SoLoud\\AudioSourceInstance, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Wav_getLength, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_WavInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\Wav, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_WavInstance_rewind, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_WavInstance_hasEnded, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_WavStream___construct arginfo_class_SoLoud_Wav___construct

#define arginfo_class_SoLoud_WavStream_load arginfo_class_SoLoud_Wav_load

#define arginfo_class_SoLoud_WavStream_loadMem arginfo_class_SoLoud_Wav_loadMem

#define arginfo_class_SoLoud_WavStream_loadToMem arginfo_class_SoLoud_Wav_load

#define arginfo_class_SoLoud_WavStream_loadFile arginfo_class_SoLoud_Wav_loadFile

#define arginfo_class_SoLoud_WavStream_loadFileToMem arginfo_class_SoLoud_Wav_loadFile

#define arginfo_class_SoLoud_WavStream_createInstance arginfo_class_SoLoud_Wav_createInstance

#define arginfo_class_SoLoud_WavStream_getLength arginfo_class_SoLoud_Wav_getLength

#define arginfo_class_SoLoud_WavStream_parse arginfo_class_SoLoud_Wav_loadFile

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_WavStreamInstance___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aParent, SoLoud\\WavStream, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_WavStreamInstance_rewind arginfo_class_SoLoud_WavInstance_rewind

#define arginfo_class_SoLoud_WavStreamInstance_hasEnded arginfo_class_SoLoud_WavInstance_hasEnded

ZEND_METHOD(SoLoud_Wav, __construct);
ZEND_METHOD(SoLoud_Wav, load);
ZEND_METHOD(SoLoud_Wav, loadMem);
ZEND_METHOD(SoLoud_Wav, loadFile);
ZEND_METHOD(SoLoud_Wav, loadRawWave8);
ZEND_METHOD(SoLoud_Wav, loadRawWave16);
ZEND_METHOD(SoLoud_Wav, loadRawWave);
ZEND_METHOD(SoLoud_Wav, createInstance);
ZEND_METHOD(SoLoud_Wav, getLength);
ZEND_METHOD(SoLoud_WavInstance, __construct);
ZEND_METHOD(SoLoud_WavInstance, rewind);
ZEND_METHOD(SoLoud_WavInstance, hasEnded);
ZEND_METHOD(SoLoud_WavStream, __construct);
ZEND_METHOD(SoLoud_WavStream, load);
ZEND_METHOD(SoLoud_WavStream, loadMem);
ZEND_METHOD(SoLoud_WavStream, loadToMem);
ZEND_METHOD(SoLoud_WavStream, loadFile);
ZEND_METHOD(SoLoud_WavStream, loadFileToMem);
ZEND_METHOD(SoLoud_WavStream, createInstance);
ZEND_METHOD(SoLoud_WavStream, getLength);
ZEND_METHOD(SoLoud_WavStream, parse);
ZEND_METHOD(SoLoud_WavStreamInstance, __construct);
ZEND_METHOD(SoLoud_WavStreamInstance, rewind);
ZEND_METHOD(SoLoud_WavStreamInstance, hasEnded);

static const zend_function_entry class_SoLoud_Wav_methods[] = {
	ZEND_ME(SoLoud_Wav, __construct, arginfo_class_SoLoud_Wav___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, load, arginfo_class_SoLoud_Wav_load, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, loadMem, arginfo_class_SoLoud_Wav_loadMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, loadFile, arginfo_class_SoLoud_Wav_loadFile, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, loadRawWave8, arginfo_class_SoLoud_Wav_loadRawWave8, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, loadRawWave16, arginfo_class_SoLoud_Wav_loadRawWave16, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, loadRawWave, arginfo_class_SoLoud_Wav_loadRawWave, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, createInstance, arginfo_class_SoLoud_Wav_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Wav, getLength, arginfo_class_SoLoud_Wav_getLength, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_WavInstance_methods[] = {
	ZEND_ME(SoLoud_WavInstance, __construct, arginfo_class_SoLoud_WavInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavInstance, rewind, arginfo_class_SoLoud_WavInstance_rewind, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavInstance, hasEnded, arginfo_class_SoLoud_WavInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_WavStream_methods[] = {
	ZEND_ME(SoLoud_WavStream, __construct, arginfo_class_SoLoud_WavStream___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, load, arginfo_class_SoLoud_WavStream_load, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, loadMem, arginfo_class_SoLoud_WavStream_loadMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, loadToMem, arginfo_class_SoLoud_WavStream_loadToMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, loadFile, arginfo_class_SoLoud_WavStream_loadFile, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, loadFileToMem, arginfo_class_SoLoud_WavStream_loadFileToMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, createInstance, arginfo_class_SoLoud_WavStream_createInstance, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, getLength, arginfo_class_SoLoud_WavStream_getLength, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStream, parse, arginfo_class_SoLoud_WavStream_parse, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_WavStreamInstance_methods[] = {
	ZEND_ME(SoLoud_WavStreamInstance, __construct, arginfo_class_SoLoud_WavStreamInstance___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStreamInstance, rewind, arginfo_class_SoLoud_WavStreamInstance_rewind, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_WavStreamInstance, hasEnded, arginfo_class_SoLoud_WavStreamInstance_hasEnded, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_Wav_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("SoLoud\\WAVSTREAM_WAV", SoLoud::WAVSTREAM_WAV, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\WAVSTREAM_OGG", SoLoud::WAVSTREAM_OGG, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\WAVSTREAM_FLAC", SoLoud::WAVSTREAM_FLAC, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("SoLoud\\WAVSTREAM_MP3", SoLoud::WAVSTREAM_MP3, CONST_PERSISTENT);
}

static zend_class_entry *register_class_SoLoud_Wav(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "Wav", class_SoLoud_Wav_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mData_default_value;
	ZVAL_UNDEF(&property_mData_default_value);
	zend_string *property_mData_name = zend_string_init("mData", sizeof("mData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mData_name, &property_mData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mData_name);

	zval property_mSampleCount_default_value;
	ZVAL_UNDEF(&property_mSampleCount_default_value);
	zend_string *property_mSampleCount_name = zend_string_init("mSampleCount", sizeof("mSampleCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSampleCount_name, &property_mSampleCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mSampleCount_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_WavInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "WavInstance", class_SoLoud_WavInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_WavStream(zend_class_entry *class_entry_SoLoud_AudioSource)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "WavStream", class_SoLoud_WavStream_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSource, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mFiletype_default_value;
	ZVAL_UNDEF(&property_mFiletype_default_value);
	zend_string *property_mFiletype_name = zend_string_init("mFiletype", sizeof("mFiletype") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFiletype_name, &property_mFiletype_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFiletype_name);

	zval property_mFilename_default_value;
	ZVAL_UNDEF(&property_mFilename_default_value);
	zend_string *property_mFilename_name = zend_string_init("mFilename", sizeof("mFilename") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFilename_name, &property_mFilename_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_mFilename_name);

	zval property_mMemFile_default_value;
	ZVAL_UNDEF(&property_mMemFile_default_value);
	zend_string *property_mMemFile_name = zend_string_init("mMemFile", sizeof("mMemFile") - 1, 1);
	zend_string *property_mMemFile_class_SoLoud_File = zend_string_init("SoLoud\\File", sizeof("SoLoud\\File")-1, 1);
	zend_declare_typed_property(class_entry, property_mMemFile_name, &property_mMemFile_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mMemFile_class_SoLoud_File, 0, MAY_BE_NULL));
	zend_string_release(property_mMemFile_name);

	zval property_mStreamFile_default_value;
	ZVAL_UNDEF(&property_mStreamFile_default_value);
	zend_string *property_mStreamFile_name = zend_string_init("mStreamFile", sizeof("mStreamFile") - 1, 1);
	zend_string *property_mStreamFile_class_SoLoud_File = zend_string_init("SoLoud\\File", sizeof("SoLoud\\File")-1, 1);
	zend_declare_typed_property(class_entry, property_mStreamFile_name, &property_mStreamFile_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_mStreamFile_class_SoLoud_File, 0, MAY_BE_NULL));
	zend_string_release(property_mStreamFile_name);

	zval property_mSampleCount_default_value;
	ZVAL_UNDEF(&property_mSampleCount_default_value);
	zend_string *property_mSampleCount_name = zend_string_init("mSampleCount", sizeof("mSampleCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSampleCount_name, &property_mSampleCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mSampleCount_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_WavStreamInstance(zend_class_entry *class_entry_SoLoud_AudioSourceInstance)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "WavStreamInstance", class_SoLoud_WavStreamInstance_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_AudioSourceInstance, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
