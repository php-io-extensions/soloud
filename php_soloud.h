#ifndef PHP_SOLOUD_H
#define PHP_SOLOUD_H

extern zend_module_entry soloud_module_entry;
#define phpext_soloud_ptr &soloud_module_entry

#define PHP_SOLOUD_VERSION "0.11.0"

/* SoLoud master at this commit (no release tag since 2020). A newer SoLoud lands only by replacing lib/soloud/. */
#define PHP_SOLOUD_UPSTREAM_COMMIT "e82fd32c1f62183922f08c14c814a02b58db1873"

#if defined(ZTS) && defined(COMPILE_DL_SOLOUD)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
