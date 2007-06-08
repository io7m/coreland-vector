#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_mult4_pure -DVECTOR_NO_SIMD t_mult4.c ../vec_mult.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_mult4_sse2 t_mult4.c ../vec_mult.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_mult4_sse2`
pure=`./t_mult4_pure`
printf "%12s %12s %12s\n" "t_mult4" "${sse2}" "${pure}"

rm -f t_mult4_pure t_mult4_sse2
