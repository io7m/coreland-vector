#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc2_pure -DVECTOR_NO_SIMD t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc2_sse2 t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c

printf "sse2 "
./t_divsc2_sse2
printf "pure "
./t_divsc2_pure

rm -f t_divsc2_pure t_divsc2_sse2
