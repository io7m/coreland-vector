#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc4_pure -DVECTOR_NO_SIMD t_divsc4.c ../vec_divsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc4_sse2 t_divsc4.c ../vec_divsc.c ../vec_simd.c frand.c

printf "sse2 "
./t_divsc4_sse2
printf "pure "
./t_divsc4_pure

rm -f t_divsc4_pure t_divsc4_sse2
