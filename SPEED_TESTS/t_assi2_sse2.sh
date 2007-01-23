#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_assi2_pure -DVECTOR_NO_SIMD t_assi2.c ../vec_assi.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_assi2_sse2 t_assi2.c ../vec_assi.c ../vec_simd.c frand.c

printf "sse2 "
./t_assi2_sse2
printf "pure "
./t_assi2_pure

rm -f t_assi2_pure t_assi2_sse2
