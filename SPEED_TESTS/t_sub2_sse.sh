#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_sub2_pure -DVECTOR_NO_SIMD t_sub2.c ../vec_sub.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_sub2_sse t_sub2.c ../vec_sub.c ../vec_simd.c ../vec_align.c frand.c

sse=`./t_sub2_sse`
pure=`./t_sub2_pure`
printf "%12s %12s %12s\n" "t_sub2" "${sse}" "${pure}"

rm -f t_sub2_pure t_sub2_sse
