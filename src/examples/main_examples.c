#include <stdio.h>
#include <stdint.h>
#include "../parser-obj/parse-obj.h"

// A simple test function to insert into the main function.
int run_sample() {
    struct Coords a = new_coords(0, 50, 100, 0);
    struct Coords b = new_coords(10, 15, 20, 10);
    struct Coords c = new_coords(10, 1, 0, 0);

    // char *printed = coords_str(&coords);
    printf("Coordinates `a` (l=%ld) are:\n%s", len_coords(&a), coords_str(&a));
    printf("Coordinates `b` (l=%ld) are:\n%s", len_coords(&b), coords_str(&b));
    printf("Coordinates `c` (l=%ld) are:\n%s", len_coords(&c), coords_str(&c));

    c = add_coords(&a, &b);
    printf("a + b are:\n%s", coords_str(&c));
    c = sub_coords(&a, &b);
    printf("a - b are:\n%s", coords_str(&c));
    c = mul_coords(&a, &b);
    printf("a * b are:\n%s", coords_str(&c));
    c = div_coords(&a, &b);
    printf("a / b are:\n%s", coords_str(&c));
    printf("ds(a,b): %ld\n", ds_coords(&a, &b));
    printf("dt(a,b): %ld\n", dt_coords(&a, &b));
    printf("Opening obj file.\n");
    char *fpath = "examples/sponza.obj";
    struct CoordVec example_points = parse_obj_from_file(fpath, 1000.0);
    printf("example_points.len=%ld\n", example_points.len);
    for(int i=0; i<example_points.len; i++) {
      coords_print(&example_points.coords[i]);
    }
    return 0;
}
