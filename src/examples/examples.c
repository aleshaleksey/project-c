#include "../parsers/parser-obj.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void examples_basic_work(){
	struct Coords a = coords_new(10, 20, 30, 0);
	struct Coords b = coords_new(20, 300, -50, 1);
	struct Coords new_val;
	coords_print(&a);
	coords_print(&b);
	new_val = coords_sum(&a, &b);
	coords_print(&new_val);
	new_val = coords_dif(&a, &b);
	coords_print(&new_val);
	new_val = coords_prod(&a, &b);
	coords_print(&new_val);
	new_val = coords_divd(&a, &b);
	coords_print(&new_val);
	printf("a-b distance = %ld\n", coords_distance(&a, &b));
	printf("b-a distance = %ld\n", coords_distance(&b, &a));
}

void examples_parse_obj(char *file_path) {
	struct CoordVec teapot = parse_obj(file_path, 1000.0);
	printf("teapot point count = %ld\n", teapot.len);
	for(int i = 0; i < teapot.len; i++) {
		coords_print(&teapot.coords[i]);
	}
}
