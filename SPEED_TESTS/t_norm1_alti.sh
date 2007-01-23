#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_norm1_pure -DVECTOR_NO_SIMD t_norm1.c ../vec_norm.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_norm1_alti t_norm1.c ../vec_norm.c ../vec_simd.c frand.c

alti=`./t_norm1_alti`
pure=`./t_norm1_pure`
printf "%12s %12s %12s\n" "t_norm1" "${alti}" "${pure}"

rm -f t_norm1_pure t_norm1_alti
