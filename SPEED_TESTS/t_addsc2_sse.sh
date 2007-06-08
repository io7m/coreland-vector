#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_addsc2_pure -DVECTOR_NO_SIMD t_addsc2.c ../vec_addsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_addsc2_sse t_addsc2.c ../vec_addsc.c ../vec_simd.c ../vec_align.c frand.c

sse=`./t_addsc2_sse`
pure=`./t_addsc2_pure`
printf "%12s %12s %12s\n" "t_addsc2" "${sse}" "${pure}"

rm -f t_addsc2_pure t_addsc2_sse
