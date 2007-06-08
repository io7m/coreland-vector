#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_sub4_pure -DVECTOR_NO_SIMD t_sub4.c ../vec_sub.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_sub4_sse2 t_sub4.c ../vec_sub.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_sub4_sse2`
pure=`./t_sub4_pure`
printf "%12s %12s %12s\n" "t_sub4" "${sse2}" "${pure}"

rm -f t_sub4_pure t_sub4_sse2
