#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero_pure -DVECTOR_NO_SIMD t_zero.c ../vec_zero.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero_sse t_zero.c ../vec_zero.c ../vec_simd.c frand.c

printf "sse "
./t_zero_sse
printf "pure "
./t_zero_pure

rm -f t_zero_pure t_zero_sse
