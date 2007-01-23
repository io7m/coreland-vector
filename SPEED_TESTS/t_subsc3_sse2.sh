#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_subsc2_pure -DVECTOR_NO_SIMD t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_subsc2_sse2 t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c

printf "sse2 "
./t_subsc2_sse2
printf "pure "
./t_subsc2_pure

rm -f t_subsc2_pure t_subsc2_sse2