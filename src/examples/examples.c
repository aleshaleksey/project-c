#include "../coords/coordvec.h"
#include "../parsers/parser-obj.h"
#include <stdlib.h>
#include <stdio.h>

void examples_basic_work(){
	struct Coords a = coords_new(10, 20, 30, 0);
	struct Coords b = coords_new(20, 300, -50, 1);
	coords_print(&a);
	coords_print(&b);
	coords_print(coords_sum(&a, &b));
	coords_print(coords_dif(&a, &b));
	coords_print(coords_prod(&a, &b));
	coords_print(coords_divd(&a, &b));
	coords_print(coords_distance(&a, &b));
	coords_print(coords_distance(&b, &a));
}

void examples_parse_obj(char *file_path) {}
