// A module for manipulating basic collections of coordinates.
#include "coords.h"
#include <stdint.h>

struct CoordVec {
	struct Coords *coords;
	int64_t len;
};

// Create new coordinate vector.
struct CoordVec coordvec_new_empty();
struct CoordVec coordvec_new_with_cap(int64_t cap);

// Add coordinates.
void coordvec_push(struct CoordVec *vec, struct Coords new_coord);
int64_t coordvec_add(struct CoordVec *vec, struct Coords new_coord);

// Get the last coord.
struct Coords coordvec_pop(struct CoordVec *vec);

// Get the length of the coordinate vector.
// NB: This interface will chnge.
int64_t coordvec_pathlength(struct CoordVec *vec);
