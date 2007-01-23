#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc2_pure -DVECTOR_NO_SIMD t_multsc2.c ../vec_multsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc2_sse t_multsc2.c ../vec_multsc.c ../vec_simd.c frand.c

sse=`./t_multsc2_sse`
pure=`./t_multsc2_pure`
printf "%12s %12s %12s\n" "t_multsc2" "${sse}" "${pure}"

rm -f t_multsc2_pure t_multsc2_sse
