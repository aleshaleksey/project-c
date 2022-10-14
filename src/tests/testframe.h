int testframe_run_test(char* test_name, int (*function)());

#define test_and_ret(fn) if(testframe_run_test(#fn, &fn)==0) { return 1; }
