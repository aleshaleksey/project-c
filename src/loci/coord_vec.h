#include "coords.h"

struct CoordVec {
  struct Coords *coords;
  int64_t len;
  int64_t cap;
};

struct CoordPath {
  struct Coords *coords;
  int64_t len;
  int64_t cap;
  int64_t distance;
};

struct CoordVec coordvec_new_empty();
struct CoordVec coordvec_new_with_cap(int64_t cap);
void coordvec_push(struct CoordVec *vec, struct Coords next_coord);
struct Coords coordvec_pop(struct CoordVec *vec);
int64_t coordvec_s_len(struct CoordVec *vec);
int64_t coordvec_t_len(struct CoordVec *vec);
// struct CoordPath coordpath_create(
//     struct CoordVec *vec,
//     int64_t idx_s,
//     int64_t idx_e
// );
