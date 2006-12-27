#!/bin/sh

echo '#include "vector.h"'
echo '#include "vec_add.h"'
echo
./vec_add_C 2 float f
echo
./vec_add_C 3 float f
echo
./vec_add_C 4 float f
echo
./vec_add_C 2 double d
echo
./vec_add_C 3 double d
echo
./vec_add_C 4 double d
echo
