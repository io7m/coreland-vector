#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div1_pure -DVECTOR_NO_SIMD t_div1.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div1_sse t_div1.c ../vec_div.c ../vec_simd.c frand.c

printf "sse "
./t_div1_sse
printf "pure "
./t_div1_pure

rm -f t_div1_pure t_div1_sse
