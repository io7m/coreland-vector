#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_sub1_pure -DVECTOR_NO_SIMD t_sub1.c ../vec_sub.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_sub1_alti t_sub1.c ../vec_sub.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_sub1_alti`
pure=`./t_sub1_pure`
printf "%12s %12s %12s\n" "t_sub1" "${alti}" "${pure}"

rm -f t_sub1_pure t_sub1_alti
