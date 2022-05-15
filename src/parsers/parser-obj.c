#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "parser-obj.h"

// Inner function, scans line and appends the coordinate to Coordvec.
void parse_obj_line(struct CoordVec *output, FILE *file, double scale) {
	double x, y, z;
	
	int read = fscanf(file, "v %lf %lf %lf", &x, &y, &z);
	if(read<14) { return; }
	struct Coords n = coords_new(rint(x*scale), rint(y*scale), rint(z*scale), 0);
	coordvec_push(output, n);
}

// Outer parsing function.
struct CoordVec parse_obj(char *file_name, double scale) {
	char c;

	struct CoordVec output = coordvec_new_empty();
	FILE *obj_file = fopen(file_name, "r");
	if(!obj_file) { return output; }
	// Scan the file start to end.
	while(c = getc(obj_file) != EOF) {
		// Do work every time we hit a new line.
		// NB: We assume that the `parse_obj_line` function "eats" the file.
		if(c!='\n') {
			parse_obj_line(&output, obj_file, scale);
		}
	}
	return output;
}
