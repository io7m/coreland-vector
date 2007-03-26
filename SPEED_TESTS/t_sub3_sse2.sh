#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_sub3_pure -DVECTOR_NO_SIMD t_sub3.c ../vec_sub.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_sub3_sse2 t_sub3.c ../vec_sub.c ../vec_simd.c frand.c

sse2=`./t_sub3_sse2`
pure=`./t_sub3_pure`
printf "%12s %12s %12s\n" "t_sub3" "${sse2}" "${pure}"

rm -f t_sub3_pure t_sub3_sse2
