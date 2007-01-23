#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div2_pure -DVECTOR_NO_SIMD t_div2.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div2_sse t_div2.c ../vec_div.c ../vec_simd.c frand.c

printf "sse "
./t_div2_sse
printf "pure "
./t_div2_pure

rm -f t_div2_pure t_div2_sse