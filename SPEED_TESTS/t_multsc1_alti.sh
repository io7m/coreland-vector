#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_multsc1_pure -DVECTOR_NO_SIMD t_multsc1.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_multsc1_alti t_multsc1.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_multsc1_alti`
pure=`./t_multsc1_pure`
printf "%12s %12s %12s\n" "t_multsc1" "${alti}" "${pure}"

rm -f t_multsc1_pure t_multsc1_alti
