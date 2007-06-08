#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_divsc1_pure -DVECTOR_NO_SIMD t_divsc1.c ../vec_divsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} ${MATH_FLAGS} \
  -o t_divsc1_alti t_divsc1.c ../vec_divsc.c ../vec_simd.c ../vec_align.c frand.c

alti=`./t_divsc1_alti`
pure=`./t_divsc1_pure`
printf "%12s %12s %12s\n" "t_divsc1" "${alti}" "${pure}"

rm -f t_divsc1_pure t_divsc1_alti
