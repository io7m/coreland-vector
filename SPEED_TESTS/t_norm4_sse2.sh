#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_norm4_pure -DVECTOR_NO_SIMD t_norm4.c ../vec_norm.c ../vec_dotp.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_norm4_sse2 t_norm4.c ../vec_norm.c ../vec_dotp.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_norm4_sse2`
pure=`./t_norm4_pure`
printf "%12s %12s %12s\n" "t_norm4" "${sse2}" "${pure}"

rm -f t_norm4_pure t_norm4_sse2
