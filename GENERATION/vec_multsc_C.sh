#!/bin/sh

echo '#include "vector.h"'
echo '#include "vec_multsc.h"'
echo
./vec_multsc_C 2 float f
echo
./vec_multsc_C 3 float f
echo
./vec_multsc_C 4 float f
echo
./vec_multsc_C 2 double d
echo
./vec_multsc_C 3 double d
echo
./vec_multsc_C 4 double d
echo
