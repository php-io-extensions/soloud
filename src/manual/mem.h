/*
 * Raw memory handed to SoLoud's loaders. aCopy / aTakeOwnership follow the native flags: SoLoud may keep the
 * pointer it gets (aCopy false) and may delete[] it (aTakeOwnership true). A PHP string can be neither, so:
 *   aCopy true                        → the string's bytes; SoLoud copies them.
 *   aCopy false, aTakeOwnership true  → a new[] copy; SoLoud deletes it, as in C++.
 *   aCopy false, aTakeOwnership false → the string's bytes; the object holds the string until its next load.
 */

#ifndef SOLOUD_MANUAL_MEM_H
#define SOLOUD_MANUAL_MEM_H

#include "../gen/classes.h"

template <class T>
static T *soloud_mem(zval *self, zend_string *mem, size_t count, bool aCopy, bool aTakeOwnership)
{
	T *data = reinterpret_cast<T *>(ZSTR_VAL(mem));
	if (aCopy) {
		return data;
	}
	if (aTakeOwnership) {
		T *owned = new T[count > 0 ? count : 1];
		memcpy(owned, data, count * sizeof(T));
		return owned;
	}
	zval held;
	ZVAL_STR(&held, mem);
	soloud_hold(soloud_from(Z_OBJ_P(self)), "mem", &held);
	return data;
}

#define SOLOUD_LOAD_PARAMS(mem, length, copy, own) \
	ZEND_PARSE_PARAMETERS_START(2, 4) \
		Z_PARAM_STR(mem) \
		Z_PARAM_LONG(length) \
		Z_PARAM_OPTIONAL \
		Z_PARAM_BOOL(copy) \
		Z_PARAM_BOOL(own) \
	ZEND_PARSE_PARAMETERS_END()

#endif
