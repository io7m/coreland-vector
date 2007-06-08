#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_add1_pure -DVECTOR_NO_SIMD t_add1.c ../vec_add.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_add1_alti t_add1.c ../vec_add.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_add1_alti`
pure=`./t_add1_pure`
printf "%12s %12s %12s\n" "t_add1" "${alti}" "${pure}"

rm -f t_add1_pure t_add1_alti
