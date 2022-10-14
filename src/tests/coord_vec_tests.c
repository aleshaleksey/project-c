#include <stdio.h>
// #include <stdlib.h>
#include <stdint.h>
#include "../loci/coord_vec.h"
#include "../base-helper/base-helper.h"
#include "coord_vec_tests.h"
#include "testframe.h"

int test_coordvec_new_with_cap1() {
  struct CoordVec a = coordvec_new_with_cap(100);
  return a.len==0 && a.cap==100;
}
int test_coordvec_new_with_cap2() {
  struct CoordVec a = coordvec_new_with_cap(55);
  return a.len==0 && a.cap==55;
}
int test_coordvec_new_with_cap3() {
  struct CoordVec a = coordvec_new_with_cap(550000);
  return a.len==0 && a.cap==550000;
}

int test_coordvec_push() {
  struct CoordVec a = coordvec_new_with_cap(10);
  struct Coords b = new_coords(5, 6, 7, 0);
  coordvec_push(&a, b);
  struct Coords b2 = new_coords(5, 6, 7, 0);

  return b2.x==a.coords[0].x
   && b2.y==a.coords[0].y
   && b2.z==a.coords[0].z
   && b2.t==a.coords[0].t;
}

int test_coordvec_pop() {
  struct CoordVec a = coordvec_new_with_cap(10);
  struct Coords b = new_coords(5, 6, 7, 0);
  coordvec_push(&a, b);
  struct Coords out = coordvec_pop(&a);
  struct Coords exp = new_coords(5, 6, 7, 0);

  return out.x==exp.x
    && out.y==exp.y
    && out.z==exp.z
    && out.t==exp.t;
}

int test_coordvec_s_len1() {
  struct CoordVec a = coordvec_new_with_cap(10);
  coordvec_push(&a, new_coords(5, 6, 7, 0));
  coordvec_push(&a, new_coords(15, 6, 7, 0));
  coordvec_push(&a, new_coords(15, 16, 7, 0));
  coordvec_push(&a, new_coords(15, 16, 17, 0));
  return 30==coordvec_s_len(&a);
}

int test_coordvec_s_len2() {
  struct CoordVec a = coordvec_new_with_cap(10);
  coordvec_push(&a, new_coords(5, 6, 7, 0));
  coordvec_push(&a, new_coords(5, 20, 7, 0));
  coordvec_push(&a, new_coords(20, 20, 7, 0));
  coordvec_push(&a, new_coords(20, 20, 20, 0));

  return 42==coordvec_s_len(&a);
}

int test_coordvec_t_len1() {
  struct CoordVec a = coordvec_new_with_cap(10);
  coordvec_push(&a, new_coords(5, 6, 7, 0));
  coordvec_push(&a, new_coords(5, 20, 7, 0));
  coordvec_push(&a, new_coords(20, 20, 7, 0));
  coordvec_push(&a, new_coords(20, 20, 20, 0));

  return 0==coordvec_t_len(&a);
}

int test_coordvec_t_len2() {
  struct CoordVec a = coordvec_new_with_cap(10);
  coordvec_push(&a, new_coords(5, 6, 7, 0));
  coordvec_push(&a, new_coords(5, 20, 7, 5));
  coordvec_push(&a, new_coords(20, 20, 7, 7));
  coordvec_push(&a, new_coords(20, 20, 20, 6));
  
  return 6==coordvec_t_len(&a);
}

int coord_vec_tests() {
  printf("\nRunning `coord_vec_tests`.\n\n");
  test_and_ret(test_coordvec_new_with_cap1);
  test_and_ret(test_coordvec_new_with_cap2);
  test_and_ret(test_coordvec_new_with_cap3);
  test_and_ret(test_coordvec_push);
  test_and_ret(test_coordvec_pop);
  test_and_ret(test_coordvec_s_len1);
  test_and_ret(test_coordvec_s_len2);
  test_and_ret(test_coordvec_t_len1);
  test_and_ret(test_coordvec_t_len2);

  printf("\n`coord_vec_tests` finished succesfully\n");
  return 1;
}
