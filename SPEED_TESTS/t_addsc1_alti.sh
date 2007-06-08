#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_addsc1_pure -DVECTOR_NO_SIMD t_addsc1.c ../vec_addsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_addsc1_alti t_addsc1.c ../vec_addsc.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_addsc1_alti`
pure=`./t_addsc1_pure`
printf "%12s %12s %12s\n" "t_addsc1" "${alti}" "${pure}"

rm -f t_addsc1_pure t_addsc1_alti
