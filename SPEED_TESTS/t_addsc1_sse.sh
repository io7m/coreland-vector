#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc1_pure -DVECTOR_NO_SIMD t_addsc1.c ../vec_addsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_addsc1_sse t_addsc1.c ../vec_addsc.c ../vec_simd.c frand.c

sse=`./t_addsc1_sse`
pure=`./t_addsc1_pure`
printf "%12s %12s %12s\n" "t_addsc1" "${sse}" "${pure}"

rm -f t_addsc1_pure t_addsc1_sse
