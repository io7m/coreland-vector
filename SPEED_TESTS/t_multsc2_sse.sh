#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc2_pure -DVECTOR_NO_SIMD t_multsc2.c ../vec_multsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc2_sse t_multsc2.c ../vec_multsc.c ../vec_simd.c frand.c

printf "sse "
./t_multsc2_sse
printf "pure "
./t_multsc2_pure

rm -f t_multsc2_pure t_multsc2_sse
