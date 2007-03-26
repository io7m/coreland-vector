#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_add4_pure -DVECTOR_NO_SIMD t_add4.c ../vec_add.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_add4_sse2 t_add4.c ../vec_add.c ../vec_simd.c frand.c

sse2=`./t_add4_sse2`
pure=`./t_add4_pure`
printf "%12s %12s %12s\n" "t_add4" "${sse2}" "${pure}"

rm -f t_add4_pure t_add4_sse2
