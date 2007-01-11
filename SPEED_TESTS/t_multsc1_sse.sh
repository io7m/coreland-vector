#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc1_pure -DVECTOR_NO_SIMD t_multsc1.c ../vec_multsc.c ../vec_simd.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc1_sse t_multsc1.c ../vec_multsc.c ../vec_simd.c

printf "sse "
./t_multsc1_sse
printf "pure "
./t_multsc1_pure

rm -f t_multsc1_pure t_multsc1_sse
