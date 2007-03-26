#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_zero1_pure -DVECTOR_NO_SIMD t_zero1.c ../vec_zero.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_zero1_alti t_zero1.c ../vec_zero.c ../vec_simd.c frand.c

alti=`./t_zero1_alti`
pure=`./t_zero1_pure`
printf "%12s %12s %12s\n" "t_zero1" "${alti}" "${pure}"

rm -f t_zero1_pure t_zero1_alti
