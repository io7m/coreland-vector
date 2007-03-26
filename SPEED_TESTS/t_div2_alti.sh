#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_div2_pure -DVECTOR_NO_SIMD t_div2.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_div2_alti t_div2.c ../vec_div.c ../vec_simd.c frand.c

alti=`./t_div2_alti`
pure=`./t_div2_pure`
printf "%12s %12s %12s\n" "t_div2" "${alti}" "${pure}"

rm -f t_div2_pure t_div2_alti
