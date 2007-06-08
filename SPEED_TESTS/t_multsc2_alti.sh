#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_multsc2_pure -DVECTOR_NO_SIMD t_multsc2.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_multsc2_alti t_multsc2.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_multsc2_alti`
pure=`./t_multsc2_pure`
printf "%12s %12s %12s\n" "t_multsc2" "${alti}" "${pure}"

rm -f t_multsc2_pure t_multsc2_alti
