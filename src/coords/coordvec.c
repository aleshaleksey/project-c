// A module for manipulating basic collections of coordinates.
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

// Create new coordinate vector.
struct CoordVec coordvec_new_empty() {
	struct CoordVec new;
	new.len = 0;
	new.coords = (struct Coords *)calloc(24 * sizeof(struct Coords));
	return new;
}

struct CoordVec coordvec_new_with_cap(int64_t cap) {
	struct CoordVec new;
	new.len = 0;
	new.coords = (struct Coords *)calloc(cap * sizeof(struct Coords));
}

// Add coordinates.
void coordvec_push(struct CoordVec *vec, struct Coords new_coord) {
	// Allocate more if needed.
	if(vec.len % 24 == 0) {
		realloc((void *)vec.coords, vec.len + 24);
	}
	vec.coords[vec.len+1] = new_coord;
	vec.len+= 1;
}

// Add coordinate, return new length.
int64_t coordvec_add(struct CoordVec *vec, struct Coords new_coord) {
	coordvec_push_coord(vec, new_coord);
	return vec.len;
}

// Get the last coord.
struct Coord coordvec_pop(struct CoordVec *vec) {
	vec.len -= 1;
	struct Coords output = vec.coords[vec.len];
	return output;
}

// NB: Assumes that the length of the vector is correct.
int64_t coordvec_pathlength(struct CoordVec *vec) {
	int64_t output = 0;
	if(vec.len==0) { return output; }
	for(int i; i<(vec.len - 1); i++) {
		output += coords_distance(&vec.coords[i], &vec.coords[i+1]);
	}
	return output;
}
