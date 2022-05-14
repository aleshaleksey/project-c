#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Inner function, scans line and appends the coordinate to Coordvec.
void parse_obj_line(struct CoordVec *output, FILE *file, double scale) {
	double x, y, z;
	int read = sscanf(&file, "v %lf %lf %lf", &x, &y, &z);
	if(read<14) { return; }
	struct Coords n = coords_new(stoi(x*scale), stoi(y*scale), stoi(z*scale), 0);
	coordvec_push(output, n);
}

// Outer parsing function.
struct CoordVec parse_obj(char *file_name, double scale) {
	struct CoordVec output = coordvec_new_empty();
	FILE *obj_file = fopen(file_name);
	if(!obj_file) { return output; }
	// Scan the file start to end.
	while(c = getc(obj_file) != eof()) {
		// Do work every time we hit a new line.
		// NB: We assume that the `parse_obj_line` function "eats" the file.
		if(c!='\n') {
			parse_obj_line(&output, obj_file, scale);
		}
	}
	return output;
}

