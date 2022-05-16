#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "parser-obj.h"

// Inner function, scans line and appends the coordinate to Coordvec.
void parse_obj_line(int v, struct CoordVec *output, FILE **file, double scale) {
	double x, y, z;

	int read = 0;
	if(v) { read = fscanf(*file, " %lf%lf%lf ", &x, &y, &z); }
	else { read = fscanf(*file, "v %lf%lf%lf ", &x, &y, &z); }
	printf("x=%lf, y=%lf, z=%lf\n", x, y, z);
	printf("read=%d\n", read);
	if(read<3) { return; }
	struct Coords n = coords_new(rint(x*scale), rint(y*scale), rint(z*scale), 0);
	coordvec_push(output, n);
}

// Outer parsing function.
struct CoordVec parse_obj(char *file_name, double scale) {
	struct CoordVec output = coordvec_new_empty();
	FILE *obj_file = fopen(file_name, "r");
	if(!obj_file) {
		printf("Could not open file: \"%s\" (%ln)\n", file_name, (long *)obj_file);
		return output;
	}
	printf("Obj file (\"%s\") probably ok..\n", file_name);
	// Scan the file start to end.
	char c;
	while((c = fgetc(obj_file)) != EOF) {
		// Do work every time we hit a new line.
		// NB: We assume that the `parse_obj_line` function "eats" the file.
		// if(c == '\n') { continue; }
		putchar(c);
		if(c=='v') { parse_obj_line(1, &output, &obj_file, scale); }
		// else { parse_obj_line(0, &output, &obj_file, scale); }

	}
	fclose(obj_file);
	return output;
}
