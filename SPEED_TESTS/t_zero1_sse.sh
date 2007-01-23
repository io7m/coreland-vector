#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero1_pure -DVECTOR_NO_SIMD t_zero1.c ../vec_zero.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero1_sse t_zero1.c ../vec_zero.c ../vec_simd.c frand.c

printf "sse "
./t_zero1_sse
printf "pure "
./t_zero1_pure

rm -f t_zero1_pure t_zero1_sse
