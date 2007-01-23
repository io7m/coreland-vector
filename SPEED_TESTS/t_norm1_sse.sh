#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm1_pure -DVECTOR_NO_SIMD t_norm1.c ../vec_norm.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm1_sse t_norm1.c ../vec_norm.c ../vec_simd.c frand.c

sse=`./t_norm1_sse`
pure=`./t_norm1_pure`
printf "%12s %12s %12s\n" "t_norm1" "${sse}" "${pure}"

rm -f t_norm1_pure t_norm1_sse
