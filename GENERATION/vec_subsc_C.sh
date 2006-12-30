#!/bin/sh

echo '#include "vector.h"'
echo '#include "vec_subsc.h"'
echo
./vec_subsc_C 2 float f
echo
./vec_subsc_C 3 float f
echo
./vec_subsc_C 4 float f
echo
./vec_subsc_C 2 double d
echo
./vec_subsc_C 3 double d
echo
./vec_subsc_C 4 double d
echo
