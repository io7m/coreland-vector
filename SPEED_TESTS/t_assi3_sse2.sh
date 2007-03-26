#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_assi3_pure -DVECTOR_NO_SIMD t_assi3.c ../vec_assi.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_assi3_sse2 t_assi3.c ../vec_assi.c ../vec_simd.c frand.c

sse2=`./t_assi3_sse2`
pure=`./t_assi3_pure`
printf "%12s %12s %12s\n" "t_assi3" "${sse2}" "${pure}"

rm -f t_assi3_pure t_assi3_sse2
