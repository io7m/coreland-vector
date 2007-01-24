#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero3_pure -DVECTOR_NO_SIMD t_zero3.c ../vec_zero.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_zero3_sse2 t_zero3.c ../vec_zero.c ../vec_simd.c frand.c

sse2=`./t_zero3_sse2`
pure=`./t_zero3_pure`
printf "%12s %12s %12s\n" "t_zero3" "${sse2}" "${pure}"

rm -f t_zero3_pure t_zero3_sse2
