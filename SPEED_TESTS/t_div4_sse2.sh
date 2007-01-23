#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div4_pure -DVECTOR_NO_SIMD t_div4.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div4_sse2 t_div4.c ../vec_div.c ../vec_simd.c frand.c

printf "sse2 "
./t_div4_sse2
printf "pure "
./t_div4_pure

rm -f t_div4_pure t_div4_sse2
