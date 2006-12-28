#!/bin/sh

echo '#include "vector.h"'
echo
./vec_dist_C 2 float f
echo
./vec_dist_C 3 float f
echo
./vec_dist_C 4 float f
echo
./vec_dist_C 2 double d
echo
./vec_dist_C 3 double d
echo
./vec_dist_C 4 double d
echo
