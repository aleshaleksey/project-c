echo "Building project-march..."
gcc src/loci/coords.c \
  src/loci/coord_vec.c \
  src/parser-obj/parser-obj.c \
  src/examples/main_examples.c \
  src/main.c \
  -Wall \
  -O3 -o build/project-march -lm
echo "Build project-march. Running..."
build/project-march
