#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_norm2_pure -DVECTOR_NO_SIMD t_norm2.c ../vec_norm.c ../vec_dotp.c ../vec_multsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_norm2_sse t_norm2.c ../vec_norm.c ../vec_dotp.c ../vec_multsc.c ../vec_simd.c frand.c

sse=`./t_norm2_sse`
pure=`./t_norm2_pure`
printf "%12s %12s %12s\n" "t_norm2" "${sse}" "${pure}"

rm -f t_norm2_pure t_norm2_sse
