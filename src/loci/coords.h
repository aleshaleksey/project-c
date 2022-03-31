struct Coords {
  int64_t x;
  int64_t y;
  int64_t z;
  int64_t t;
};

struct Coords new_coords(int64_t x, int64_t y, int64_t z, int64_t t);
struct Coords add_coords(struct Coords *a, struct Coords *b);
struct Coords sub_coords(struct Coords *a, struct Coords *b);
struct Coords mul_coords(struct Coords *a, struct Coords *b);
struct Coords div_coords(struct Coords *a, struct Coords *b);
int64_t ds_coords(struct Coords *a, struct Coords *b);
int64_t dt_coords(struct Coords *a, struct Coords *b);
char *print_coords(struct Coords *coords);
