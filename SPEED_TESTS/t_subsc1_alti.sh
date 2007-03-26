#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_subsc1_pure -DVECTOR_NO_SIMD t_subsc1.c ../vec_subsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_subsc1_alti t_subsc1.c ../vec_subsc.c ../vec_simd.c frand.c

alti=`./t_subsc1_alti`
pure=`./t_subsc1_pure`
printf "%12s %12s %12s\n" "t_subsc1" "${alti}" "${pure}"

rm -f t_subsc1_pure t_subsc1_alti
