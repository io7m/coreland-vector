#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc2_pure -DVECTOR_NO_SIMD t_multsc2.c ../vec_multsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_multsc2_sse2 t_multsc2.c ../vec_multsc.c ../vec_simd.c frand.c

sse2=`./t_multsc3_sse2`
pure=`./t_multsc3_pure`
printf "%12s %12s %12s\n" "t_multsc3" "${sse2}" "${pure}"

rm -f t_multsc2_pure t_multsc2_sse2
