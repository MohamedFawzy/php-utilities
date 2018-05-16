
extern zend_class_entry *utility_arrays_ce;

ZEPHIR_INIT_CLASS(Utility_Arrays);

PHP_METHOD(Utility_Arrays, append);

ZEND_BEGIN_ARG_INFO_EX(arginfo_utility_arrays_append, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, result, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(utility_arrays_method_entry) {
	PHP_ME(Utility_Arrays, append, arginfo_utility_arrays_append, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
