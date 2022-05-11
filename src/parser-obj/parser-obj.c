#define __STDC_WANT_LIB_EXT1__ 1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "parse-obj.h"

// A bit for processing a line of text and converting to coordinates.
int process_chunk(
  FILE **file,
  struct CoordVec *output,
  double scale,
  int *taken
) {
  double x = 0;
  double y = 0;
  double z = 0;
  // These should be small.
  char *v = (char *)calloc(100, 0);
  char *rem = (char *)calloc(100, 0);
  // Scan
  #ifdef __STDC_LIB_EXT1_
  *taken = sscanf_s(*file, "%s %lf %lf %lf %s\n", v, &x, &y, &z, rem);
  #endif

  // TODO look up double to int64_t conversion.
  struct Coords coords;
  coords.t = 0;
  coords.x = rint(x * scale);
  coords.y = rint(y * scale);
  coords.z = rint(z * scale);
  print_coords(&coords);
  coordvec_push(output, coords);
  return 0;
}

// This function parses an obj file.
// `obj` is the input text (need to change to pointer).
// `scale` is the factor for converting floats to ints (multiply by `scale`).
struct CoordVec parse_obj_from_file(char *obj, double scale) {
  printf("Proceeding to open and parse %s.\n", obj);
  FILE *file = fopen(obj, "r");
  printf("Opened %s\n", obj);
  char c;
  // Define the start index and end index.
  struct CoordVec output = coordvec_new_with_cap(1000);
  int taken = 0;
  // While not at the end keep going.
  printf("About to start with working on the file.\n");
  while((c = fgetc(file)) != EOF) {
    printf("Not end of file.\n");
    if(c =='v') { continue; }
    printf("Proceeding to parse the next `v` line\n");
    process_chunk(&file, &output, scale, &taken);
    // file += taken;
  }
  return output;
}
