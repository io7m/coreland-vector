#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_subsc2_pure -DVECTOR_NO_SIMD t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_subsc2_alti t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c

alti=`./t_subsc2_alti`
pure=`./t_subsc2_pure`
printf "%12s %12s %12s\n" "t_subsc2" "${alti}" "${pure}"

rm -f t_subsc2_pure t_subsc2_alti
