#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <tgmath.h>
#include "../loci/coords.h"
#include "testframe.h"

int test_new_coords() {
  struct Coords out = new_coords(5, 6, 7, 8);
  return out.x==5 && out.y==6 && out.z==7 && out.t==8;
}

int test_sqrt2_a() {
  return coords_sqrt2(16)==4;
}
int test_sqrt2_b() {
  return coords_sqrt2(17)==4;
}
int test_sqrt2_c() {
  return coords_sqrt2(15)==4;
}
int test_sqrt2_d() {
  return coords_sqrt2(25)==5;
}

int coords_tests() {
  printf("Running `coords_tests`.\n\n");
  test_and_ret(test_new_coords);
  test_and_ret(test_sqrt2_a);
  test_and_ret(test_sqrt2_b);
  test_and_ret(test_sqrt2_c);
  test_and_ret(test_sqrt2_d);
  printf("\n`coords_tests` finished succesfully\n");
  return 1;
}
