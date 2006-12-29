#!/bin/sh

echo '#include <math.h>'
echo '#include "vector.h"'
echo
./vec_ang_C 2 float f
echo
./vec_ang_C 3 float f
echo
./vec_ang_C 4 float f
echo
./vec_ang_C 2 double d
echo
./vec_ang_C 3 double d
echo
./vec_ang_C 4 double d
echo
