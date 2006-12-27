#!/bin/sh

echo '#include "vector.h"'
echo '#include "vec_assi.h"'
echo
./vec_assi_C 2 float f
echo
./vec_assi_C 3 float f
echo
./vec_assi_C 4 float f
echo
./vec_assi_C 2 double d
echo
./vec_assi_C 3 double d
echo
./vec_assi_C 4 double d
echo
