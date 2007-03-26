#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_mult2_pure -DVECTOR_NO_SIMD t_mult2.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_mult2_alti t_mult2.c ../vec_mult.c ../vec_simd.c frand.c

alti=`./t_mult2_alti`
pure=`./t_mult2_pure`
printf "%12s %12s %12s\n" "t_mult2" "${alti}" "${pure}"

rm -f t_mult2_pure t_mult2_alti
