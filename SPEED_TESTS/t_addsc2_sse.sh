#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc2_pure -DVECTOR_NO_SIMD t_addsc2.c ../vec_addsc.c ../vec_simd.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc2_sse t_addsc2.c ../vec_addsc.c ../vec_simd.c

printf "sse "
./t_addsc2_sse
printf "pure "
./t_addsc2_pure

rm -f t_addsc2_pure t_addsc2_sse
