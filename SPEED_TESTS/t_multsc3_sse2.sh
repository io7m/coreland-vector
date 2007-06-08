#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_multsc3_pure -DVECTOR_NO_SIMD t_multsc3.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_multsc3_sse2 t_multsc3.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_multsc3_sse2`
pure=`./t_multsc3_pure`
printf "%12s %12s %12s\n" "t_multsc3" "${sse2}" "${pure}"

rm -f t_multsc3_pure t_multsc3_sse2
