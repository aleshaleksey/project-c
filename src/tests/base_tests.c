#include <stdio.h>
#include "../base-helper/base-helper.h"
#include "testframe.h"
// The tests here exist to test this function.
// long base_recalc_cap(long old_l) {
//   if(old_l < 1024) {
//     return old_l * 2;
//   } else {
//     return old_l + old_l / 4;
//   }
// }

int test_recalc_1() {
  long new_value = base_recalc_cap(100);
  return new_value==200;
}

int test_recalc_2() {
  long new_value = base_recalc_cap(1023);
  return new_value==2046;
}

int test_recalc_3() {
  long new_value = base_recalc_cap(1024);
  return new_value==1280;
}

int test_recalc_4() {
  long new_value = base_recalc_cap(4000000);
  return new_value==5000000;
}

int recalc_tests() {
  printf("\nRunning `base-helper` tests\n\n");
  test_and_ret(test_recalc_1);
  test_and_ret(test_recalc_2);
  test_and_ret(test_recalc_3);
  test_and_ret(test_recalc_4);
  printf("\nAll `base-helper` tests complete successfully.\n");
  return 0;
}
