#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero2_pure -DVECTOR_NO_SIMD t_zero2.c ../vec_zero.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero2_sse2 t_zero2.c ../vec_zero.c ../vec_simd.c frand.c

printf "sse2 "
./t_zero2_sse2
printf "pure "
./t_zero2_pure

rm -f t_zero2_pure t_zero2_sse2
