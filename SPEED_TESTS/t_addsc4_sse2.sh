#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc4_pure -DVECTOR_NO_SIMD t_addsc4.c ../vec_addsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc4_sse2 t_addsc4.c ../vec_addsc.c ../vec_simd.c frand.c

sse2=`./t_addsc4_sse2`
pure=`./t_addsc4_pure`
printf "%12s %12s %12s\n" "t_addsc4" "${sse2}" "${pure}"

rm -f t_addsc4_pure t_addsc4_sse2
