#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_zero2_pure -DVECTOR_NO_SIMD t_zero2.c ../vec_zero.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_zero2_sse2 t_zero2.c ../vec_zero.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_zero2_sse2`
pure=`./t_zero2_pure`
printf "%12s %12s %12s\n" "t_zero2" "${sse2}" "${pure}"

rm -f t_zero2_pure t_zero2_sse2
