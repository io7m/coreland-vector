#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_multsc1_pure -DVECTOR_NO_SIMD t_multsc1.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_multsc1_sse t_multsc1.c ../vec_multsc.c ../vec_simd.c ../vec_align.c frand.c

sse=`./t_multsc1_sse`
pure=`./t_multsc1_pure`
printf "%12s %12s %12s\n" "t_multsc1" "${sse}" "${pure}"

rm -f t_multsc1_pure t_multsc1_sse
