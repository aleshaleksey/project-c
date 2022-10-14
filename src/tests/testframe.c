#include <stdio.h>

int testframe_run_test(char* test_name, int (*function)()) {
  printf("Running `%s`\n", test_name);
  if(function()==0) {
    printf("`%s` failed\n", test_name);
    return 0;
  }
  printf("`%s` finished successfully\n", test_name);

  return 1;
}
