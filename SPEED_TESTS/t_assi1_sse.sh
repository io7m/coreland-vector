#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_assi1_pure -DVECTOR_NO_SIMD t_assi1.c ../vec_assi.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_assi1_sse t_assi1.c ../vec_assi.c ../vec_simd.c frand.c

printf "sse "
./t_assi1_sse
printf "pure "
./t_assi1_pure

rm -f t_assi1_pure t_assi1_sse
