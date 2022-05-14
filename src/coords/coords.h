// Module to deal with basic functions related to the coordinates.
#include <stdint.h>

struct Coords {
	int64_t x;
	int64_t y;
	int64_t z;
	int64_t t;
};

// Functions for creating and displaying coordinates.
struct Coords coords_new(int64_t x, int64_t y, int64_t y, int64_t t);
char *coords_as_string(struct Coords *in);
void coords_print(struct Coords *in);

// Functions for manipulating coordinates and getting a new point.
struct Coords coords_sum(struct Coords *a, struct Coords *b);
struct Coords coords_dif(struct Coords *a, struct Coords *b);
struct Coords coords_prod(struct Coords *a, struct Coords *b);
struct Coords coords_divd(struct Coords *a, struct Coords *b);

// Functions for modifying coordinates (the four basic)..
void coords_add(struct Coords *a, struct Coords *b);
void coords_sub(struct Coords *a, struct Coords *b);
void coords_mul(struct Coords *a, struct Coords *b);
void coords_div(struct Coords *a, struct Coords *b);

// Used to calculate the distance between points.
int64_t coords_distance(struct Coords *a, struct Coords *b);
