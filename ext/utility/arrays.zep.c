
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Utility_Arrays) {

	ZEPHIR_REGISTER_CLASS(Utility, Arrays, utility, arrays, utility_arrays_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Utility_Arrays, append) {

	zval *result_param = NULL, *value = NULL, value_sub, __$null;
	zval result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &result_param, &value);

	zephir_get_arrval(&result, result_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	zephir_array_append(&result, value, PH_SEPARATE, "utility/Arrays.zep", 10);
	RETURN_CTOR(&result);

}

