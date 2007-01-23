#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_addsc2_pure -DVECTOR_NO_SIMD t_addsc2.c ../vec_addsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_addsc2_alti t_addsc2.c ../vec_addsc.c ../vec_simd.c frand.c

alti=`./t_addsc2_alti`
pure=`./t_addsc2_pure`
printf "%12s %12s %12s\n" "t_addsc2" "${alti}" "${pure}"

rm -f t_addsc2_pure t_addsc2_alti
