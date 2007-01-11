#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc1_pure -DVECTOR_NO_SIMD t_divsc1.c ../vec_divsc.c ../vec_simd.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc1_sse t_divsc1.c ../vec_divsc.c ../vec_simd.c

printf "sse "
./t_divsc1_sse
printf "pure "
./t_divsc1_pure

rm -f t_divsc1_pure t_divsc1_sse
