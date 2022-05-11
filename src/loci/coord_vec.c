#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "coord_vec.h"

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
    vec->coords = (struct Coords *)realloc((void *)vec->coords, vec->len + 1);
    vec->coords[vec->len] = next_coord;
    vec->len++;
}

struct Coords *coordvec_pop(struct CoordVec *vec) {
    // Early return.
    if(vec->len == 0) { return NULL; }
    vec->len--;
    // Deallocate as necessary.
    if(vec->len%20 == 0) {
        vec->coords = (struct Coords *)realloc((void *)vec->coords, vec->len);
    }

    struct Coords last = vec->coords[vec->len];
    struct Coords *out = (struct Coords *)malloc(sizeof(struct Coords) * 1);
    out[0] = last;
    return out;
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
