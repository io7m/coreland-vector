#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_subsc1_pure -DVECTOR_NO_SIMD t_subsc1.c ../vec_subsc.c ../vec_simd.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_subsc1_sse t_subsc1.c ../vec_subsc.c ../vec_simd.c

printf "sse "
./t_subsc1_sse
printf "pure "
./t_subsc1_pure

rm -f t_subsc1_pure t_subsc1_sse
