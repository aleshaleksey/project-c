#include "coords.h"

struct CoordVec {
  struct Coords *coords;
  int64_t len;
};

struct CoordVec new_empty();
struct CoordVec new_with_cap(int64_t cap);
void push(struct CoordVec *vec, struct Coords next_coord);
struct Coords *pop(struct CoordVec *vec);
