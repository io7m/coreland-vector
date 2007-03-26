#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_divsc2_pure -DVECTOR_NO_SIMD t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_divsc2_sse t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c

sse=`./t_divsc2_sse`
pure=`./t_divsc2_pure`
printf "%12s %12s %12s\n" "t_divsc2" "${sse}" "${pure}"

rm -f t_divsc2_pure t_divsc2_sse
