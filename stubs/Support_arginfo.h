/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8a63fa5d8eb7685bb18d30a358552688dbce8450 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_Misc_generateWaveform, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, aWaveform, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, p, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_Thread_createMutex, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_Thread_destroyMutex, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_SoLoud_Thread_lockMutex arginfo_SoLoud_Thread_destroyMutex

#define arginfo_SoLoud_Thread_unlockMutex arginfo_SoLoud_Thread_destroyMutex

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_Thread_sleep, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aMSec, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_SoLoud_Thread_getTimeMillis arginfo_SoLoud_Thread_createMutex

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_Thread_createThread, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aThreadFunction, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, aParameter, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_Thread_wait, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aThreadHandle, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_SoLoud_Thread_release arginfo_SoLoud_Thread_wait

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_FFT_fft1024, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aBuffer, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_SoLoud_FFT_fft256 arginfo_SoLoud_FFT_fft1024

#define arginfo_SoLoud_FFT_ifft256 arginfo_SoLoud_FFT_fft1024

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SoLoud_FFT_fft, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, aBuffer, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aBufferLength, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_SoLoud_FFT_ifft arginfo_SoLoud_FFT_fft

#define arginfo_class_SoLoud_File_read8 arginfo_SoLoud_Thread_createMutex

#define arginfo_class_SoLoud_File_read16 arginfo_SoLoud_Thread_createMutex

#define arginfo_class_SoLoud_File_read32 arginfo_SoLoud_Thread_createMutex

#define arginfo_class_SoLoud_File_eof arginfo_SoLoud_Thread_createMutex

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_File_read, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, aDst, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, aBytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_File_length arginfo_SoLoud_Thread_createMutex

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_File_seek, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_File_pos arginfo_SoLoud_Thread_createMutex

#define arginfo_class_SoLoud_File_getFilePtr arginfo_SoLoud_Thread_createMutex

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_File_getMemPtr, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SoLoud_DiskFile___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_DiskFile_open, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFilename, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_MemoryFile___construct arginfo_class_SoLoud_DiskFile___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_MemoryFile_openMem, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aData, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, aDataLength, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aCopy, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, aTakeOwnership, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_MemoryFile_openToMem arginfo_class_SoLoud_DiskFile_open

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_MemoryFile_openFileToMem, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, aFile, SoLoud\\File, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_AlignedFloatBuffer___construct arginfo_class_SoLoud_DiskFile___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AlignedFloatBuffer_init, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, aFloats, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_AlignedFloatBuffer_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_TinyAlignedFloatBuffer___construct arginfo_class_SoLoud_DiskFile___construct

#define arginfo_class_SoLoud_Misc_Prg___construct arginfo_class_SoLoud_DiskFile___construct

#define arginfo_class_SoLoud_Misc_Prg_rand arginfo_SoLoud_Thread_createMutex

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Misc_Prg_rand_float, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Misc_Prg_srand, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aSeed, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_SoLoud_Thread_PoolTask_work arginfo_class_SoLoud_AlignedFloatBuffer_clear

#define arginfo_class_SoLoud_Thread_Pool___construct arginfo_class_SoLoud_DiskFile___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Thread_Pool_init, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, aThreadCount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_SoLoud_Thread_Pool_addWork, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, aTask, SoLoud\\Thread\\PoolTask, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_SoLoud_Thread_Pool_getWork, 0, 0, SoLoud\\Thread\\PoolTask, 1)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(SoLoud_Misc_generateWaveform);
ZEND_FUNCTION(SoLoud_Thread_createMutex);
ZEND_FUNCTION(SoLoud_Thread_destroyMutex);
ZEND_FUNCTION(SoLoud_Thread_lockMutex);
ZEND_FUNCTION(SoLoud_Thread_unlockMutex);
ZEND_FUNCTION(SoLoud_Thread_sleep);
ZEND_FUNCTION(SoLoud_Thread_getTimeMillis);
ZEND_FUNCTION(SoLoud_Thread_createThread);
ZEND_FUNCTION(SoLoud_Thread_wait);
ZEND_FUNCTION(SoLoud_Thread_release);
ZEND_FUNCTION(SoLoud_FFT_fft1024);
ZEND_FUNCTION(SoLoud_FFT_fft256);
ZEND_FUNCTION(SoLoud_FFT_ifft256);
ZEND_FUNCTION(SoLoud_FFT_fft);
ZEND_FUNCTION(SoLoud_FFT_ifft);
ZEND_METHOD(SoLoud_File, read8);
ZEND_METHOD(SoLoud_File, read16);
ZEND_METHOD(SoLoud_File, read32);
ZEND_METHOD(SoLoud_File, eof);
ZEND_METHOD(SoLoud_File, read);
ZEND_METHOD(SoLoud_File, length);
ZEND_METHOD(SoLoud_File, seek);
ZEND_METHOD(SoLoud_File, pos);
ZEND_METHOD(SoLoud_File, getFilePtr);
ZEND_METHOD(SoLoud_File, getMemPtr);
ZEND_METHOD(SoLoud_DiskFile, __construct);
ZEND_METHOD(SoLoud_DiskFile, open);
ZEND_METHOD(SoLoud_MemoryFile, __construct);
ZEND_METHOD(SoLoud_MemoryFile, openMem);
ZEND_METHOD(SoLoud_MemoryFile, openToMem);
ZEND_METHOD(SoLoud_MemoryFile, openFileToMem);
ZEND_METHOD(SoLoud_AlignedFloatBuffer, __construct);
ZEND_METHOD(SoLoud_AlignedFloatBuffer, init);
ZEND_METHOD(SoLoud_AlignedFloatBuffer, clear);
ZEND_METHOD(SoLoud_TinyAlignedFloatBuffer, __construct);
ZEND_METHOD(SoLoud_Misc_Prg, __construct);
ZEND_METHOD(SoLoud_Misc_Prg, rand);
ZEND_METHOD(SoLoud_Misc_Prg, rand_float);
ZEND_METHOD(SoLoud_Misc_Prg, srand);
ZEND_METHOD(SoLoud_Thread_PoolTask, work);
ZEND_METHOD(SoLoud_Thread_Pool, __construct);
ZEND_METHOD(SoLoud_Thread_Pool, init);
ZEND_METHOD(SoLoud_Thread_Pool, addWork);
ZEND_METHOD(SoLoud_Thread_Pool, getWork);

static const zend_function_entry ext_functions[] = {
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Misc", "generateWaveform"), zif_SoLoud_Misc_generateWaveform, arginfo_SoLoud_Misc_generateWaveform, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "createMutex"), zif_SoLoud_Thread_createMutex, arginfo_SoLoud_Thread_createMutex, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "destroyMutex"), zif_SoLoud_Thread_destroyMutex, arginfo_SoLoud_Thread_destroyMutex, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "lockMutex"), zif_SoLoud_Thread_lockMutex, arginfo_SoLoud_Thread_lockMutex, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "unlockMutex"), zif_SoLoud_Thread_unlockMutex, arginfo_SoLoud_Thread_unlockMutex, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "sleep"), zif_SoLoud_Thread_sleep, arginfo_SoLoud_Thread_sleep, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "getTimeMillis"), zif_SoLoud_Thread_getTimeMillis, arginfo_SoLoud_Thread_getTimeMillis, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "createThread"), zif_SoLoud_Thread_createThread, arginfo_SoLoud_Thread_createThread, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "wait"), zif_SoLoud_Thread_wait, arginfo_SoLoud_Thread_wait, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\Thread", "release"), zif_SoLoud_Thread_release, arginfo_SoLoud_Thread_release, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\FFT", "fft1024"), zif_SoLoud_FFT_fft1024, arginfo_SoLoud_FFT_fft1024, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\FFT", "fft256"), zif_SoLoud_FFT_fft256, arginfo_SoLoud_FFT_fft256, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\FFT", "ifft256"), zif_SoLoud_FFT_ifft256, arginfo_SoLoud_FFT_ifft256, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\FFT", "fft"), zif_SoLoud_FFT_fft, arginfo_SoLoud_FFT_fft, 0, NULL, NULL)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("SoLoud\\FFT", "ifft"), zif_SoLoud_FFT_ifft, arginfo_SoLoud_FFT_ifft, 0, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_File_methods[] = {
	ZEND_ME(SoLoud_File, read8, arginfo_class_SoLoud_File_read8, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, read16, arginfo_class_SoLoud_File_read16, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, read32, arginfo_class_SoLoud_File_read32, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, eof, arginfo_class_SoLoud_File_eof, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, read, arginfo_class_SoLoud_File_read, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, length, arginfo_class_SoLoud_File_length, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, seek, arginfo_class_SoLoud_File_seek, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, pos, arginfo_class_SoLoud_File_pos, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, getFilePtr, arginfo_class_SoLoud_File_getFilePtr, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_File, getMemPtr, arginfo_class_SoLoud_File_getMemPtr, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_DiskFile_methods[] = {
	ZEND_ME(SoLoud_DiskFile, __construct, arginfo_class_SoLoud_DiskFile___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_DiskFile, open, arginfo_class_SoLoud_DiskFile_open, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_MemoryFile_methods[] = {
	ZEND_ME(SoLoud_MemoryFile, __construct, arginfo_class_SoLoud_MemoryFile___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_MemoryFile, openMem, arginfo_class_SoLoud_MemoryFile_openMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_MemoryFile, openToMem, arginfo_class_SoLoud_MemoryFile_openToMem, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_MemoryFile, openFileToMem, arginfo_class_SoLoud_MemoryFile_openFileToMem, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_AlignedFloatBuffer_methods[] = {
	ZEND_ME(SoLoud_AlignedFloatBuffer, __construct, arginfo_class_SoLoud_AlignedFloatBuffer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AlignedFloatBuffer, init, arginfo_class_SoLoud_AlignedFloatBuffer_init, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_AlignedFloatBuffer, clear, arginfo_class_SoLoud_AlignedFloatBuffer_clear, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_TinyAlignedFloatBuffer_methods[] = {
	ZEND_ME(SoLoud_TinyAlignedFloatBuffer, __construct, arginfo_class_SoLoud_TinyAlignedFloatBuffer___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Misc_Prg_methods[] = {
	ZEND_ME(SoLoud_Misc_Prg, __construct, arginfo_class_SoLoud_Misc_Prg___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Misc_Prg, rand, arginfo_class_SoLoud_Misc_Prg_rand, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Misc_Prg, rand_float, arginfo_class_SoLoud_Misc_Prg_rand_float, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Misc_Prg, srand, arginfo_class_SoLoud_Misc_Prg_srand, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Thread_PoolTask_methods[] = {
	ZEND_ME(SoLoud_Thread_PoolTask, work, arginfo_class_SoLoud_Thread_PoolTask_work, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SoLoud_Thread_Pool_methods[] = {
	ZEND_ME(SoLoud_Thread_Pool, __construct, arginfo_class_SoLoud_Thread_Pool___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Thread_Pool, init, arginfo_class_SoLoud_Thread_Pool_init, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Thread_Pool, addWork, arginfo_class_SoLoud_Thread_Pool_addWork, ZEND_ACC_PUBLIC)
	ZEND_ME(SoLoud_Thread_Pool, getWork, arginfo_class_SoLoud_Thread_Pool_getWork, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_SoLoud_File(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "File", class_SoLoud_File_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_DiskFile(zend_class_entry *class_entry_SoLoud_File)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "DiskFile", class_SoLoud_DiskFile_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_File, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mFileHandle_default_value;
	ZVAL_UNDEF(&property_mFileHandle_default_value);
	zend_string *property_mFileHandle_name = zend_string_init("mFileHandle", sizeof("mFileHandle") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFileHandle_name, &property_mFileHandle_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFileHandle_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_MemoryFile(zend_class_entry *class_entry_SoLoud_File)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "MemoryFile", class_SoLoud_MemoryFile_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_SoLoud_File, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mDataPtr_default_value;
	ZVAL_UNDEF(&property_mDataPtr_default_value);
	zend_string *property_mDataPtr_name = zend_string_init("mDataPtr", sizeof("mDataPtr") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDataPtr_name, &property_mDataPtr_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mDataPtr_name);

	zval property_mDataLength_default_value;
	ZVAL_UNDEF(&property_mDataLength_default_value);
	zend_string *property_mDataLength_name = zend_string_init("mDataLength", sizeof("mDataLength") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDataLength_name, &property_mDataLength_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mDataLength_name);

	zval property_mOffset_default_value;
	ZVAL_UNDEF(&property_mOffset_default_value);
	zend_string *property_mOffset_name = zend_string_init("mOffset", sizeof("mOffset") - 1, 1);
	zend_declare_typed_property(class_entry, property_mOffset_name, &property_mOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mOffset_name);

	zval property_mDataOwned_default_value;
	ZVAL_UNDEF(&property_mDataOwned_default_value);
	zend_string *property_mDataOwned_name = zend_string_init("mDataOwned", sizeof("mDataOwned") - 1, 1);
	zend_declare_typed_property(class_entry, property_mDataOwned_name, &property_mDataOwned_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_mDataOwned_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_AlignedFloatBuffer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "AlignedFloatBuffer", class_SoLoud_AlignedFloatBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mData_default_value;
	ZVAL_UNDEF(&property_mData_default_value);
	zend_string *property_mData_name = zend_string_init("mData", sizeof("mData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mData_name, &property_mData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mData_name);

	zval property_mBasePtr_default_value;
	ZVAL_UNDEF(&property_mBasePtr_default_value);
	zend_string *property_mBasePtr_name = zend_string_init("mBasePtr", sizeof("mBasePtr") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBasePtr_name, &property_mBasePtr_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBasePtr_name);

	zval property_mFloats_default_value;
	ZVAL_UNDEF(&property_mFloats_default_value);
	zend_string *property_mFloats_name = zend_string_init("mFloats", sizeof("mFloats") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFloats_name, &property_mFloats_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFloats_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_TinyAlignedFloatBuffer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud", "TinyAlignedFloatBuffer", class_SoLoud_TinyAlignedFloatBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mData_default_value;
	ZVAL_UNDEF(&property_mData_default_value);
	zend_string *property_mData_name = zend_string_init("mData", sizeof("mData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mData_name, &property_mData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mData_name);

	zval property_mActualData_default_value;
	ZVAL_UNDEF(&property_mActualData_default_value);
	zend_string *property_mActualData_name = zend_string_init("mActualData", sizeof("mActualData") - 1, 1);
	zend_declare_typed_property(class_entry, property_mActualData_name, &property_mActualData_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_mActualData_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Misc_Prg(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud\\Misc", "Prg", class_SoLoud_Misc_Prg_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mState_default_value;
	ZVAL_UNDEF(&property_mState_default_value);
	zend_string *property_mState_name = zend_string_init("mState", sizeof("mState") - 1, 1);
	zend_declare_typed_property(class_entry, property_mState_name, &property_mState_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mState_name);

	zval property_mIndex_default_value;
	ZVAL_UNDEF(&property_mIndex_default_value);
	zend_string *property_mIndex_name = zend_string_init("mIndex", sizeof("mIndex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mIndex_name, &property_mIndex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mIndex_name);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Thread_PoolTask(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud\\Thread", "PoolTask", class_SoLoud_Thread_PoolTask_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_SoLoud_Thread_Pool(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "SoLoud\\Thread", "Pool", class_SoLoud_Thread_Pool_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	zval property_mThreadCount_default_value;
	ZVAL_UNDEF(&property_mThreadCount_default_value);
	zend_string *property_mThreadCount_name = zend_string_init("mThreadCount", sizeof("mThreadCount") - 1, 1);
	zend_declare_typed_property(class_entry, property_mThreadCount_name, &property_mThreadCount_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mThreadCount_name);

	zval property_mThread_default_value;
	ZVAL_UNDEF(&property_mThread_default_value);
	zend_string *property_mThread_name = zend_string_init("mThread", sizeof("mThread") - 1, 1);
	zend_declare_typed_property(class_entry, property_mThread_name, &property_mThread_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mThread_name);

	zval property_mWorkMutex_default_value;
	ZVAL_UNDEF(&property_mWorkMutex_default_value);
	zend_string *property_mWorkMutex_name = zend_string_init("mWorkMutex", sizeof("mWorkMutex") - 1, 1);
	zend_declare_typed_property(class_entry, property_mWorkMutex_name, &property_mWorkMutex_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mWorkMutex_name);

	zval property_mTaskArray_default_value;
	ZVAL_UNDEF(&property_mTaskArray_default_value);
	zend_string *property_mTaskArray_name = zend_string_init("mTaskArray", sizeof("mTaskArray") - 1, 1);
	zend_declare_typed_property(class_entry, property_mTaskArray_name, &property_mTaskArray_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_mTaskArray_name);

	zval property_mMaxTask_default_value;
	ZVAL_UNDEF(&property_mMaxTask_default_value);
	zend_string *property_mMaxTask_name = zend_string_init("mMaxTask", sizeof("mMaxTask") - 1, 1);
	zend_declare_typed_property(class_entry, property_mMaxTask_name, &property_mMaxTask_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mMaxTask_name);

	zval property_mRobin_default_value;
	ZVAL_UNDEF(&property_mRobin_default_value);
	zend_string *property_mRobin_name = zend_string_init("mRobin", sizeof("mRobin") - 1, 1);
	zend_declare_typed_property(class_entry, property_mRobin_name, &property_mRobin_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mRobin_name);

	zval property_mRunning_default_value;
	ZVAL_UNDEF(&property_mRunning_default_value);
	zend_string *property_mRunning_name = zend_string_init("mRunning", sizeof("mRunning") - 1, 1);
	zend_declare_typed_property(class_entry, property_mRunning_name, &property_mRunning_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mRunning_name);

	return class_entry;
}
