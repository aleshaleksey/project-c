// Module to deal with basic functions related to the coordinates.
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Coords coords_new(int64_t x, int64_t y, int64_t z, int64_t t) {
	struct Coords out;
	out.x = x;
	out.y = y;
	out.z = z;
	out.t = t;
	return out;
}

char *coords_as_string(struct Coords *in) {
	char *out = (char *)malloc(200 * sizeof(char));
	sprintf(
		&out,
		"Coords {\n    x:%ld\n    y:%ld\n    z:%ld\n    t:%ld\n}\n",
		in.x, in->y, in->z, in->t
	);
	return out;
}

void coords_print(struct Coords *in) {
	printf(
		"Coords {\n    x:%ld\n    y:%ld\n    z:%ld\n    t:%ld\n}\n",
		in->x, in->y, in->z, in->t
	);
}

struct Coords coords_sum(struct Coords *a, struct Coords *b) {
	struct Coords out;
	out.x = a->x + b->x;
	out.y = a->y + b->y;
	out.z = a->z + b->z;
	out.t = a->t + b->t;
	return out;
}

struct Coords coords_dif(struct Coords *a, struct Coords *b) {
	struct Coords out;
	out.x = a->x - b->x;
	out.y = a->y - b->y;
	out.z = a->z - b->z;
	out.t = a->t - b->t;
	return out;
}
struct Coords coords_prod(struct Coords *a, struct Coords *b) {
	struct Coords out;
	out.x = a->x * b->x;
	out.y = a->y * b->y;
	out.z = a->z * b->z;
	out.t = a->t * b->t;
	return out;
}

struct Coords coords_divd(struct Coords *a, struct Coords *b) {
	struct Coords out;
	out.x = a->x / b->x;
	out.y = a->y / b->y;
	out.z = a->z / b->z;
	out.t = a->t / b->t;
	return out;
}
void coords_add(struct Coords *a, struct Coords *b) {
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	a->t += b->t;
}

void coords_sub(struct Coords *a, struct Coords *b)
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	a->t -= b->t;
}

void coords_mul(struct Coords *a, struct Coords *b) {
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
	a->t *= b->t;
}

void coords_div(struct Coords *a, struct Coords *b) {
	a->x /= b->x;
	a->y /= b->y;
	a->z /= b->z;
	a->t /= b->t;
}

int64_t coords_distance(struct Coords *a, struct Coords *b) {
	int64_t diff_x = (a->x - b->x) * (a->x - b->x);
	int64_t diff_y = (a->y - b->y) * (a->y - b->y);
	int64_t diff_z = (a->z - b->z) * (a->z - b->z);
	int64_t sumsq1 = diff_x + diff_y + diff_z;
	int64_t dist = sqrtl(sumsql);

	// Before returning, we run a check for rounding error,
	// in order to return the most loyal result possible.
	int64_t sq_small = dist * dist;
	if(sq_small==sumsq1) { return dist; }

	// Run te second half of the check as required.
	int64_t sq_big = (dist + 1) * (dist + 1);
	// We need to run a check for rounding error, and return
	if(sq_big - sumsq1 > sumsql - sq_small) {
		return dist;
	} else {
		return dist + 1;
	}
}
