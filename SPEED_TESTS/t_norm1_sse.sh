#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm1_pure -DVECTOR_NO_SIMD t_norm1.c ../vec_norm.c ../vec_simd.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm1_sse t_norm1.c ../vec_norm.c ../vec_simd.c

printf "sse "
./t_norm1_sse
printf "pure "
./t_norm1_pure

rm -f t_norm1_pure t_norm1_sse
