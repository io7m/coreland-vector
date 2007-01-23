#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult2_pure -DVECTOR_NO_SIMD t_mult2.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_mult2_sse2 t_mult2.c ../vec_mult.c ../vec_simd.c frand.c

sse2=`./t_mult3_sse2`
pure=`./t_mult3_pure`
printf "%12s %12s %12s\n" "t_mult3" "${sse2}" "${pure}"

rm -f t_mult2_pure t_mult2_sse2
