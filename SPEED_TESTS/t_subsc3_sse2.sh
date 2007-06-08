#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc3_pure -DVECTOR_NO_SIMD t_subsc3.c ../vec_subsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc3_sse2 t_subsc3.c ../vec_subsc.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_subsc3_sse2`
pure=`./t_subsc3_pure`
printf "%12s %12s %12s\n" "t_subsc3" "${sse2}" "${pure}"

rm -f t_subsc3_pure t_subsc3_sse2
