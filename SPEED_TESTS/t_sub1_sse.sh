#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_sub1_pure -DVECTOR_NO_SIMD t_sub1.c ../vec_sub.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_sub1_sse t_sub1.c ../vec_sub.c ../vec_simd.c frand.c

printf "sse "
./t_sub1_sse
printf "pure "
./t_sub1_pure

rm -f t_sub1_pure t_sub1_sse
