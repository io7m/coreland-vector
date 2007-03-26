#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc4_pure -DVECTOR_NO_SIMD t_subsc4.c ../vec_subsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc4_sse2 t_subsc4.c ../vec_subsc.c ../vec_simd.c frand.c

sse2=`./t_subsc4_sse2`
pure=`./t_subsc4_pure`
printf "%12s %12s %12s\n" "t_subsc4" "${sse2}" "${pure}"

rm -f t_subsc4_pure t_subsc4_sse2
