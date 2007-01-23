#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_subsc2_pure -DVECTOR_NO_SIMD t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_subsc2_sse2 t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c

sse2=`./t_subsc3_sse2`
pure=`./t_subsc3_pure`
printf "%12s %12s %12s\n" "t_subsc3" "${sse2}" "${pure}"

rm -f t_subsc2_pure t_subsc2_sse2
