/*
 * ext-soloud: the module. Registers every class and shows the bound SoLoud in phpinfo().
 */

#include "gen/classes.h"
#include "callbacks.h"

extern "C" {
#include "../stubs/soloud_arginfo.h"
}

zend_class_entry *soloud_ce_exception;

void soloud_runtime_mshutdown(void);

static PHP_GINIT_FUNCTION(soloud)
{
#if defined(ZTS) && defined(COMPILE_DL_SOLOUD)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	zend_hash_init(&soloud_globals->boxes, 64, NULL, NULL, 1);
	zend_hash_init(&soloud_globals->mutexes, 8, NULL, NULL, 1);
	zend_hash_init(&soloud_globals->threads, 8, NULL, NULL, 1);
}

static PHP_GSHUTDOWN_FUNCTION(soloud)
{
	zend_hash_destroy(&soloud_globals->boxes);
	zend_hash_destroy(&soloud_globals->mutexes);
	zend_hash_destroy(&soloud_globals->threads);
}

static PHP_MINIT_FUNCTION(soloud)
{
#if defined(ZTS) && defined(COMPILE_DL_SOLOUD)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	soloud_ce_exception = register_class_SoLoudException(zend_ce_exception);
	soloud_register_Core();
	soloud_register_Wav();
	soloud_register_AudioSources();
	soloud_register_Filters();
	soloud_register_Support();
	soloud_callbacks_minit();
#ifdef SOLOUD_PROBES
	REGISTER_BOOL_CONSTANT("SOLOUD_PROBES", true, CONST_PERSISTENT);
#endif
	return SUCCESS;
}

static PHP_MSHUTDOWN_FUNCTION(soloud)
{
	soloud_runtime_mshutdown();
	return SUCCESS;
}

static PHP_RINIT_FUNCTION(soloud)
{
#if defined(ZTS) && defined(COMPILE_DL_SOLOUD)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	soloud_callbacks_rinit();
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(soloud)
{
	soloud_callbacks_rshutdown();
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(soloud)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "soloud support", "enabled");
	php_info_print_table_row(2, "Extension version", PHP_SOLOUD_VERSION);
	char version[16];
	snprintf(version, sizeof version, "%d", SOLOUD_VERSION);
	php_info_print_table_row(2, "SoLoud version", version);
	php_info_print_table_row(2, "Upstream commit", PHP_SOLOUD_UPSTREAM_COMMIT);
	php_info_print_table_end();
}

zend_module_entry soloud_module_entry = {
	STANDARD_MODULE_HEADER,
	"soloud",
	soloud_functions,
	PHP_MINIT(soloud),
	PHP_MSHUTDOWN(soloud),
	PHP_RINIT(soloud),
	PHP_RSHUTDOWN(soloud),
	PHP_MINFO(soloud),
	PHP_SOLOUD_VERSION,
	PHP_MODULE_GLOBALS(soloud),
	PHP_GINIT(soloud),
	PHP_GSHUTDOWN(soloud),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SOLOUD
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
extern "C" {
ZEND_GET_MODULE(soloud)
}
#endif
