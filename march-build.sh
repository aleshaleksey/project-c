gcc \
-o build/project-march \
src/coords/coords.c \
src/coords/coordvec.c \
src/parsers/parser-obj.c \
src/examples/examples.c \
src/main.c \
-O3 -lm
