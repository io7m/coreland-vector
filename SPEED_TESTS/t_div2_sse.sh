#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_div2_pure -DVECTOR_NO_SIMD t_div2.c ../vec_div.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_div2_sse t_div2.c ../vec_div.c ../vec_simd.c ../vec_align.c frand.c

sse=`./t_div2_sse`
pure=`./t_div2_pure`
printf "%12s %12s %12s\n" "t_div2" "${sse}" "${pure}"

rm -f t_div2_pure t_div2_sse
