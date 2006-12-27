#!/bin/sh

echo '#include "vector.h"'
echo '#include "vec_sub.h"'
echo
./vec_sub_C 2 float f
echo
./vec_sub_C 3 float f
echo
./vec_sub_C 4 float f
echo
./vec_sub_C 2 double d
echo
./vec_sub_C 3 double d
echo
./vec_sub_C 4 double d
echo
