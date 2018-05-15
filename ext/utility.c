
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "utility.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *utility_arrays_ce;

ZEND_DECLARE_MODULE_GLOBALS(utility)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(utility)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Utility_Arrays);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(utility)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_utility_globals *utility_globals TSRMLS_DC)
{
	utility_globals->initialized = 0;

	/* Memory options */
	utility_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	utility_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	utility_globals->cache_enabled = 1;

	/* Recursive Lock */
	utility_globals->recursive_lock = 0;

	/* Static cache */
	memset(utility_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_utility_globals *utility_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(utility)
{

	zend_utility_globals *utility_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	utility_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(utility_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(utility_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(utility)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(utility)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_UTILITY_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_UTILITY_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_UTILITY_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_UTILITY_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_UTILITY_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(utility)
{
	php_zephir_init_globals(utility_globals TSRMLS_CC);
	php_zephir_init_module_globals(utility_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(utility)
{

}


zend_function_entry php_utility_functions[] = {
ZEND_FE_END

};

zend_module_entry utility_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_UTILITY_EXTNAME,
	php_utility_functions,
	PHP_MINIT(utility),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(utility),
#else
	NULL,
#endif
	PHP_RINIT(utility),
	PHP_RSHUTDOWN(utility),
	PHP_MINFO(utility),
	PHP_UTILITY_VERSION,
	ZEND_MODULE_GLOBALS(utility),
	PHP_GINIT(utility),
	PHP_GSHUTDOWN(utility),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_UTILITY
ZEND_GET_MODULE(utility)
#endif
