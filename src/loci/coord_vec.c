#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "coord_vec.h"

struct CoordVec new_empty() {
    struct CoordVec output;
    output.coords = (struct Coords *)malloc(sizeof(struct Coords) * 10);
    output.len = 0;
    return output;
}

struct CoordVec new_with_cap(int64_t cap) {
    struct CoordVec output;
    output.coords = (struct Coords *)malloc(sizeof(struct Coords) * cap);
    output.len = 0;
    return output;
}

void push(struct CoordVec *vec, struct Coords next_coord) {
    // TODO: allocate more!
    vec->coords = (struct Coords *)realloc((void *)vec->coords, vec->len + 1);
    vec->coords[vec->len] = next_coord;
    vec->len++;
}

struct Coords *pop(struct CoordVec *vec) {
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
