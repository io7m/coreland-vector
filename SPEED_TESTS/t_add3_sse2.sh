#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_add3_pure -DVECTOR_NO_SIMD t_add3.c ../vec_add.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_add3_sse2 t_add3.c ../vec_add.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_add3_sse2`
pure=`./t_add3_pure`
printf "%12s %12s %12s\n" "t_add3" "${sse2}" "${pure}"

rm -f t_add3_pure t_add3_sse2
