#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero1_pure -DVECTOR_NO_SIMD t_zero1.c ../vec_zero.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero1_sse t_zero1.c ../vec_zero.c ../vec_simd.c frand.c

sse=`./t_zero1_sse`
pure=`./t_zero1_pure`
printf "%12s %12s %12s\n" "t_zero1" "${sse}" "${pure}"

rm -f t_zero1_pure t_zero1_sse
