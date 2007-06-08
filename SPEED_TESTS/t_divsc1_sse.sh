#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_divsc1_pure -DVECTOR_NO_SIMD t_divsc1.c ../vec_divsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_divsc1_sse t_divsc1.c ../vec_divsc.c ../vec_simd.c ../vec_align.c frand.c

sse=`./t_divsc1_sse`
pure=`./t_divsc1_pure`
printf "%12s %12s %12s\n" "t_divsc1" "${sse}" "${pure}"

rm -f t_divsc1_pure t_divsc1_sse
