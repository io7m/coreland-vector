#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_mult1_pure -DVECTOR_NO_SIMD t_mult1.c ../vec_mult.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_mult1_alti t_mult1.c ../vec_mult.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_mult1_alti`
pure=`./t_mult1_pure`
printf "%12s %12s %12s\n" "t_mult1" "${alti}" "${pure}"

rm -f t_mult1_pure t_mult1_alti
