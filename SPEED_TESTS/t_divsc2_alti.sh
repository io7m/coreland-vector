#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_divsc2_pure -DVECTOR_NO_SIMD t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_divsc2_alti t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c

alti=`./t_divsc2_alti`
pure=`./t_divsc2_pure`
printf "%12s %12s %12s\n" "t_divsc2" "${alti}" "${pure}"

rm -f t_divsc2_pure t_divsc2_alti
