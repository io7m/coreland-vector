#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_add2_pure -DVECTOR_NO_SIMD t_add2.c ../vec_add.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_add2_alti t_add2.c ../vec_add.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_add2_alti`
pure=`./t_add2_pure`
printf "%12s %12s %12s\n" "t_add2" "${alti}" "${pure}"

rm -f t_add2_pure t_add2_alti
