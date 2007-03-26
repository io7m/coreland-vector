#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc2_pure -DVECTOR_NO_SIMD t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc2_sse t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c

sse=`./t_subsc2_sse`
pure=`./t_subsc2_pure`
printf "%12s %12s %12s\n" "t_subsc2" "${sse}" "${pure}"

rm -f t_subsc2_pure t_subsc2_sse
