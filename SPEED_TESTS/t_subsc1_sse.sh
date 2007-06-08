#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc1_pure -DVECTOR_NO_SIMD t_subsc1.c ../vec_subsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_subsc1_sse t_subsc1.c ../vec_subsc.c ../vec_simd.c ../vec_align.c frand.c

sse=`./t_subsc1_sse`
pure=`./t_subsc1_pure`
printf "%12s %12s %12s\n" "t_subsc1" "${sse}" "${pure}"

rm -f t_subsc1_pure t_subsc1_sse
