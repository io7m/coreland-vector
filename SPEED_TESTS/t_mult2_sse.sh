#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_mult2_pure -DVECTOR_NO_SIMD t_mult2.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_mult2_sse t_mult2.c ../vec_mult.c ../vec_simd.c frand.c

sse=`./t_mult2_sse`
pure=`./t_mult2_pure`
printf "%12s %12s %12s\n" "t_mult2" "${sse}" "${pure}"

rm -f t_mult2_pure t_mult2_sse
