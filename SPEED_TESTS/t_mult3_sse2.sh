#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult2_pure -DVECTOR_NO_SIMD t_mult2.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult2_sse2 t_mult2.c ../vec_mult.c ../vec_simd.c frand.c

printf "sse2 "
./t_mult2_sse2
printf "pure "
./t_mult2_pure

rm -f t_mult2_pure t_mult2_sse2
