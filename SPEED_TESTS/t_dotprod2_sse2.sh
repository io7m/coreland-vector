#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_dotprod2_pure -DVECTOR_NO_SIMD t_dotprod1.c ../vec_dotp.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_dotprod2_sse2 t_dotprod1.c ../vec_dotp.c ../vec_simd.c frand.c

sse2=`./t_dotprod2_sse2`
pure=`./t_dotprod2_pure`
printf "%12s %12s %12s\n" "t_dotprod1" "${sse2}" "${pure}"

rm -f t_dotprod2_pure t_dotprod2_sse2
