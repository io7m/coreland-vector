#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_norm2_pure -DVECTOR_NO_SIMD t_norm2.c ../vec_norm.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_norm2_alti t_norm2.c ../vec_norm.c ../vec_simd.c frand.c

alti=`./t_norm2_alti`
pure=`./t_norm2_pure`
printf "%12s %12s %12s\n" "t_norm2" "${alti}" "${pure}"

rm -f t_norm2_pure t_norm2_alti
