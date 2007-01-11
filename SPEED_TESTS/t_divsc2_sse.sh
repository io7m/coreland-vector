#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc2_pure -DVECTOR_NO_SIMD t_divsc2.c ../vec_divsc.c ../vec_simd.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc2_sse t_divsc2.c ../vec_divsc.c ../vec_simd.c

printf "sse "
./t_divsc2_sse
printf "pure "
./t_divsc2_pure

rm -f t_divsc2_pure t_divsc2_sse
