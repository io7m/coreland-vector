#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc2_pure -DVECTOR_NO_SIMD t_addsc2.c ../vec_addsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc2_sse2 t_addsc2.c ../vec_addsc.c ../vec_simd.c frand.c

sse2=`./t_addsc3_sse2`
pure=`./t_addsc3_pure`
printf "%12s %12s %12s\n" "t_addsc3" "${sse2}" "${pure}"

rm -f t_addsc2_pure t_addsc2_sse2
