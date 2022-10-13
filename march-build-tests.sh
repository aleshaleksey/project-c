echo "Building tests for project-march..."
gcc \
  src/base-helper/base-helper.c \
  src/loci/coords.c \
  src/loci/coord_vec.c \
  src/parser-obj/parser-obj.c \
  src/tests/testframe.c \
  src/tests/base_tests.c \
  src/tests/coords_tests.c \
  src/tests/parse_tests.c \
  src/tests.c \
  -Wall \
  -O3 -o build/march-tests -lm
echo "Built tests for project-march."
