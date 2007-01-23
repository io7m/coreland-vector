#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add4_pure -DVECTOR_NO_SIMD t_add4.c ../vec_add.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add4_sse2 t_add4.c ../vec_add.c ../vec_simd.c frand.c

printf "sse2 "
./t_add4_sse2
printf "pure "
./t_add4_pure

rm -f t_add4_pure t_add4_sse2
