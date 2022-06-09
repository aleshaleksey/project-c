#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "coord_vec.h"
#include "../base-helper/base-helper.h"

struct CoordVec coordvec_new_empty() {
    struct CoordVec output;
    output.coords = (struct Coords *)malloc(sizeof(struct Coords) * 10);
    output.len = 0;
    return output;
}

struct CoordVec coordvec_new_with_cap(int64_t cap) {
    struct CoordVec output;
    output.coords = (struct Coords *)malloc(sizeof(struct Coords) * cap);
    output.len = 0;
    return output;
}

void coordvec_push(struct CoordVec *vec, struct Coords next_coord) {
    // TODO: allocate more!
    if(vec->len%20==0) {
      vec->coords = (struct Coords *)realloc(
        (void *)vec->coords,
        sizeof(struct Coords) * base_recalc_cap(vec->len)
      );
    }
    vec->coords[vec->len] = next_coord;
    vec->len++;
}

struct Coords *coordvec_pop(struct CoordVec *vec) {
    // Early return.
    if(vec->len == 0) { return NULL; }
    vec->len--;
    // Deallocate as necessary.
    if(vec->len%20 == 0) {
      long l = vec->len * sizeof(struct Coords);
        vec->coords = (struct Coords *)realloc((void *)vec->coords, l);
    }

    struct Coords last = vec->coords[vec->len];
    struct Coords *out = (struct Coords *)malloc(sizeof(struct Coords) * 1);
    out[0] = last;
    return out;
}

// Gets the physical length of the coordinate vector in its current order.
int64_t coordvec_s_len(struct CoordVec *vec) {
  if(vec->len < 2) { return 0; }
  int64_t output = 0;
  for(long i=0; i<vec->len - 1; i++) {
    output+= ds_coords(&vec->coords[i], &vec->coords[i+1]);
  }
  return output;
}

// Gets the temporal length of the coordinate vec based on the t value
// in its current order.
int64_t coordvec_t_len(struct CoordVec *vec) {
  if(vec->len < 2) { return 0; }
  int64_t output = 0;
  for(long i=0; i<vec->len - 1; i++) {
    output+= dt_coords(&vec->coords[i], &vec->coords[i+1]);
  }
  return output;
}

// This function is designed to create a shortest path between two points in a
// Coords set. One must specify the indices of the points in the vector.
struct CoordPath coordpath_create(
    struct CoordVec *vec,
    int64_t idx_s,
    int64_t idx_e
) {
  struct CoordPath path;
  // First if one of the indices are beyond the vector, we return an empty path.
  if(idx_s >= vec->len || idx_e >= vec->len) {
      path.len = 0;
      path.distance = 0;
      path.coords = NULL;
      return path;
  }

  return path;
}
