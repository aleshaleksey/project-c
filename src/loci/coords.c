#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <tgmath.h>
#include "coords.h"

// This is a checked square root function for integers, which does not
// automatically cut off the remainder if the result is not a whole number
// but simulates rounding up or down, hence giving higher precision.
int64_t sqrt2(int64_t x2) {
  int64_t x = sqrt(x2);
  int64_t xp2 = (x + 1) * (x + 1);
  int64_t x22 = x * x;
  if(xp2 - x2 > x2 - x22) {
    return x;
  } else {
    return x + 1;
  }
}

// Represents a coordinate point in space and time.
struct Coords new_coords(int64_t x, int64_t y, int64_t z, int64_t t) {
    struct Coords output;
    output.x = x;
    output.y = y;
    output.z = z;
    output.t = t;
    return output;
}

struct Coords add_coords(struct Coords *a, struct Coords *b) {
  struct Coords output;
  output.x = a->x + b->x;
  output.y = a->y + b->y;
  output.z = a->z + b->z;
  output.t = a->t + b->t;
  return output;
}

struct Coords sub_coords(struct Coords *a, struct Coords *b) {
  struct Coords output;
  output.x = a->x - b->x;
  output.y = a->y - b->y;
  output.z = a->z - b->z;
  output.t = a->t - b->t;
  return output;
}

struct Coords mul_coords(struct Coords *a, struct Coords *b) {
  struct Coords output;
  output.x = a->x * b->x;
  output.y = a->y * b->y;
  output.z = a->z * b->z;
  output.t = a->t * b->t;
  return output;
}

struct Coords div_coords(struct Coords *a, struct Coords *b) {
  struct Coords output;
  output.x = a->x / b->x;
  output.y = a->y / b->y;
  output.z = a->z / b->z;
  output.t = a->t / b->t;
  return output;
}

int64_t ds_coords(struct Coords *a, struct Coords *b) {
    int64_t ds2 = (a->x - b->x) * (a->x - b->x)
        + (a->y - b->y) * (a->y - b->y)
        + (a->z - b->z) * (a->z - b->z);
    int64_t ds = sqrt2(ds2);
    return ds;
}

int64_t dt_coords(struct Coords *a, struct Coords *b) {
  return a->t - b->t;
}

int64_t len_coords(struct Coords *a) {
    int64_t l2 = a->x * a->x + a->y *a->y + a->z * a->z;
    int64_t l = sqrt2(l2);
    return l;
}

// Display a coordinate point.
char *coords_str(struct Coords *coords) {
    char *output = (char *)malloc(sizeof(char) * 1000);
    sprintf(
      output,
"Coords {\n  x: %ld,\n  y: %ld,\n  z: %ld,\n  t: %ld,\n}\n",
        coords->x,
        coords->y,
        coords->z,
        coords->t
    );
    return output;
}

// Display a coordinate point.
void coords_print(struct Coords *coords) {
    printf(
"Coords {\n  x: %ld,\n  y: %ld,\n  z: %ld,\n  t: %ld,\n}\n",
        coords->x,
        coords->y,
        coords->z,
        coords->t
    );
    return;
}
