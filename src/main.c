#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "examples/examples.h"

int main(int argc, char **argv) {
	printf("Testing testing.\n");
	examples_basic_work();
	char *fpath = "examples/mit-teapot.obj";
	examples_parse_obj(fpath);
}
