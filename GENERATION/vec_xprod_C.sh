#!/bin/sh

echo '#include "vector.h"'
echo '#include "vec_xprod.h"'
echo
./vec_xprod_C 3 float f
echo
./vec_xprod_C 3 double d
echo
