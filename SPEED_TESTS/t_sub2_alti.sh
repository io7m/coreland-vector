#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_sub2_pure -DVECTOR_NO_SIMD t_sub2.c ../vec_sub.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_sub2_alti t_sub2.c ../vec_sub.c ../vec_simd.c frand.c

alti=`./t_sub2_alti`
pure=`./t_sub2_pure`
printf "%12s %12s %12s\n" "t_sub2" "${alti}" "${pure}"

rm -f t_sub2_pure t_sub2_alti
