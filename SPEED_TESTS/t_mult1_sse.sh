#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult1_pure -DVECTOR_NO_SIMD t_mult1.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult1_sse t_mult1.c ../vec_mult.c ../vec_simd.c frand.c

printf "sse "
./t_mult1_sse
printf "pure "
./t_mult1_pure

rm -f t_mult1_pure t_mult1_sse
