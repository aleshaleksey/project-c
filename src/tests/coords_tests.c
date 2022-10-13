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

int coords_tests() {
  printf("Running `coords_tests`.\n\n");
  if(testframe_run_test("test_new_coords", &test_new_coords)==0) {
    return 1;
  }

  printf("\n`coords_tests` finished succesfully\n");
  return 1;
}
