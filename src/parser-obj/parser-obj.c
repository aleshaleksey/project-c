#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "parse-obj.h"
#include "../base-helper/base-helper.h"

// A bit for processing a line of text and converting to coordinates.
int process_chunk(
  char *line,
  struct CoordVec *output,
  double scale
) {
  double x = 0;
  double y = 0;
  double z = 0;
  // Scan
  int taken = sscanf(line, "v %lf %lf %lf", &x, &y, &z);
  if(taken < 3) {
    // printf("Line too short (%d)\n", taken);
    return 1;
  }
  // TODO look up double to int64_t conversion.
  struct Coords coords;
  coords.t = 0;
  coords.x = rint(x * scale);
  coords.y = rint(y * scale);
  coords.z = rint(z * scale);
  // printf("About to push..\n");
  coordvec_push(output, coords);
  // printf("Pushed..\n");
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
  struct CoordVec output = coordvec_new_empty();
  // While not at the end keep going.
  printf("About to start with working on the file.\n");
  int alloc_len = 400;
  char *input_str = (char *)calloc(alloc_len, sizeof(char));
  int n = 0;
  while((c = fgetc(file)) != EOF) {
    if(n>=alloc_len) {
      alloc_len = base_recalc_cap(alloc_len);
      input_str = (char *)realloc((void *) input_str, alloc_len);
    }
    if(c =='\n') {
      // Process the line and clear the string.
      process_chunk(input_str, &output, scale);
      for(int i=0;i<n;i++) { input_str[i] = 0; }
      n = 0;
    } else {
      // Add character to the input string.
      input_str[n] = c;
      n++;
    }
  }
  printf("Parsing is done.\n");
  return output;
}
