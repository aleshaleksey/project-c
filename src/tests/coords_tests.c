#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
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

int test_add_coords() {
  struct Coords a = new_coords(5, 6, 7, 8);
  struct Coords b = new_coords(1, 10, 1000, 10000);
  struct Coords c = add_coords(&a, &b);
  return c.x==6 && c.y==16 && c.z==1007 && c.t==10008;
}

int test_sub_coords() {
  struct Coords a = new_coords(5, 6, 7, 8);
  struct Coords b = new_coords(1, 10, 1000, 10000);
  struct Coords c = sub_coords(&a, &b);
  return c.x==4 && c.y==-4 && c.z==-993 && c.t==-9992;
}

int test_mul_coords() {
  struct Coords a = new_coords(5, 65, 7, -800);
  struct Coords b = new_coords(1, 10, 1000, 10000);
  struct Coords c = mul_coords(&a, &b);
  return c.x==5 && c.y==650 && c.z==7000 && c.t==-8000000;
}

int test_div_coords() {
  struct Coords a = new_coords(5, 6, 7, -49069);
  struct Coords b = new_coords(1, 10, 1000, 70);
  struct Coords c = div_coords(&a, &b);
  return c.x==5 && c.y==0 && c.z==0 && c.t==-700;
}

int test_ds_coords_1() {
  struct Coords a = new_coords(1, 6, 6, -49069);
  struct Coords b = new_coords(1, 6, 6, 70);
  return ds_coords(&a, &b)==0;
}

int test_dt_coords_1() {
  struct Coords a = new_coords(1, 6, 6, -49069);
  struct Coords b = new_coords(1, 6, 6, 70);
  return dt_coords(&a, &b)==-49139;
}

int test_ds_coords_2() {
  // sqrt(8^2 + 20^2 + 30^2)=sqrt(64+400+900)=sqrt(1364)=36.9
  struct Coords a = new_coords(2, 0, 6, -49069);
  struct Coords b = new_coords(10, 20, 36, 70);
  return ds_coords(&a, &b)==37;
}

int test_dt_coords_2() {
  struct Coords a = new_coords(2, 0, 6, -49069);
  struct Coords b = new_coords(10, 20, 46, -49069);
  return dt_coords(&a, &b)==0;
}

int test_coords_str() {
  struct Coords a = new_coords(100456, 240023, -345, 0);
  char *exp = "Coords {\n  x: 100456,\n  y: 240023,\n  z: -345,\n  t: 0,\n}\n";
  char *out = coords_str(&a);
  if(strlen(out)!=strlen(exp)) { return 0; }
  for(int i=0; i<strlen(out); i++) {
    if(exp[i]!=out[i]) { return 0; }
  }
  return 1;
}

int coords_tests() {
  printf("\nRunning `coords_tests`.\n\n");
  test_and_ret(test_new_coords);
  test_and_ret(test_sqrt2_a);
  test_and_ret(test_sqrt2_b);
  test_and_ret(test_sqrt2_c);
  test_and_ret(test_sqrt2_d);
  test_and_ret(test_add_coords);
  test_and_ret(test_sub_coords);
  test_and_ret(test_mul_coords);
  test_and_ret(test_div_coords);
  test_and_ret(test_ds_coords_1);
  test_and_ret(test_dt_coords_1);
  test_and_ret(test_ds_coords_2);
  test_and_ret(test_dt_coords_2);
  test_and_ret(test_coords_str);
  printf("\n`coords_tests` finished succesfully\n");
  return 1;
}
