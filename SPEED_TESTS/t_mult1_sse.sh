#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult1_pure -DVECTOR_NO_SIMD t_mult1.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult1_sse t_mult1.c ../vec_mult.c ../vec_simd.c frand.c

sse=`./t_mult1_sse`
pure=`./t_mult1_pure`
printf "%12s %12s %12s\n" "t_mult1" "${sse}" "${pure}"

rm -f t_mult1_pure t_mult1_sse
