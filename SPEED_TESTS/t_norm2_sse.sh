#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm2_pure -DVECTOR_NO_SIMD t_norm2.c ../vec_norm.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm2_sse t_norm2.c ../vec_norm.c ../vec_simd.c frand.c

printf "sse "
./t_norm2_sse
printf "pure "
./t_norm2_pure

rm -f t_norm2_pure t_norm2_sse
