#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult4_pure -DVECTOR_NO_SIMD t_mult4.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult4_sse2 t_mult4.c ../vec_mult.c ../vec_simd.c frand.c

printf "sse2 "
./t_mult4_sse2
printf "pure "
./t_mult4_pure

rm -f t_mult4_pure t_mult4_sse2
