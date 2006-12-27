#!/bin/sh

echo '#include "vector.h"'
echo '#include "vec_dotp.h"'
echo
./vec_dotp_C 2 float f
echo
./vec_dotp_C 3 float f
echo
./vec_dotp_C 4 float f
echo
./vec_dotp_C 2 double d
echo
./vec_dotp_C 3 double d
echo
./vec_dotp_C 4 double d
echo
