#include <stdio.h>
#include <stdint.h>
#include "../loci/coords.h"

// A simple test function to insert into the main function.
int run_sample() {
    struct Coords a = new_coords(0, 50, 100, 0);
    struct Coords b = new_coords(10, 15, 20, 10);

    // char *printed = print_coords(&coords);
    printf("Coordinates `a` are:\n%s", print_coords(&a));
    printf("Coordinates `b` are:\n%s", print_coords(&b));

    struct Coords c = add_coords(&a, &b);
    printf("a + b are:\n%s", print_coords(&c));
    c = sub_coords(&a, &b);
    printf("a - b are:\n%s", print_coords(&c));
    c = mul_coords(&a, &b);
    printf("a * b are:\n%s", print_coords(&c));
    c = div_coords(&a, &b);
    printf("a / b are:\n%s", print_coords(&c));
    printf("ds(a,b): %ld\n", ds_coords(&a, &b));
    printf("dt(a,b): %ld\n", dt_coords(&a, &b));
    return 0;
}
