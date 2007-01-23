#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc4_pure -DVECTOR_NO_SIMD t_addsc4.c ../vec_addsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc4_sse2 t_addsc4.c ../vec_addsc.c ../vec_simd.c frand.c

printf "sse2 "
./t_addsc4_sse2
printf "pure "
./t_addsc4_pure

rm -f t_addsc4_pure t_addsc4_sse2
