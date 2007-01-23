#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_sub4_pure -DVECTOR_NO_SIMD t_sub4.c ../vec_sub.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_sub4_sse2 t_sub4.c ../vec_sub.c ../vec_simd.c frand.c

printf "sse2 "
./t_sub4_sse2
printf "pure "
./t_sub4_pure

rm -f t_sub4_pure t_sub4_sse2
