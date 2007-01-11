#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add2_pure -DVECTOR_NO_SIMD t_add2.c ../vec_add.c ../vec_simd.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add2_sse t_add2.c ../vec_add.c ../vec_simd.c

printf "sse "
./t_add2_sse
printf "pure "
./t_add2_pure

rm -f t_add2_pure t_add2_sse
