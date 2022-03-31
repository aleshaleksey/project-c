#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <tgmath.h>
#include "coords.h"

// Represents a coordinate point.
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
    int64_t ds = sqrt(ds2);
    return ds;
}

int64_t dt_coords(struct Coords *a, struct Coords *b) {
  return a->t - b->t;
}

// Display a coordinate point.
char *print_coords(struct Coords *coords) {
    char *output = (char *)malloc(sizeof(char) * 200);
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
