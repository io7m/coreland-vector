#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_assi1_pure -DVECTOR_NO_SIMD t_assi1.c ../vec_assi.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_assi1_alti t_assi1.c ../vec_assi.c ../vec_simd.c frand.c

alti=`./t_assi1_alti`
pure=`./t_assi1_pure`
printf "%12s %12s %12s\n" "t_assi1" "${alti}" "${pure}"

rm -f t_assi1_pure t_assi1_alti
