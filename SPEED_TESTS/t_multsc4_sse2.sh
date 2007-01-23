#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc4_pure -DVECTOR_NO_SIMD t_multsc4.c ../vec_multsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc4_sse2 t_multsc4.c ../vec_multsc.c ../vec_simd.c frand.c

printf "sse2 "
./t_multsc4_sse2
printf "pure "
./t_multsc4_pure

rm -f t_multsc4_pure t_multsc4_sse2
