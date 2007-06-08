#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_div4_pure -DVECTOR_NO_SIMD t_div4.c ../vec_div.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_div4_sse2 t_div4.c ../vec_div.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_div4_sse2`
pure=`./t_div4_pure`
printf "%12s %12s %12s\n" "t_div4" "${sse2}" "${pure}"

rm -f t_div4_pure t_div4_sse2
