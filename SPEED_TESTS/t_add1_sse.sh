#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add1_pure -DVECTOR_NO_SIMD t_add1.c ../vec_add.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add1_sse t_add1.c ../vec_add.c ../vec_simd.c frand.c

printf "sse "
./t_add1_sse
printf "pure "
./t_add1_pure

rm -f t_add1_pure t_add1_sse
