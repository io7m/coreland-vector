#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div1_pure -DVECTOR_NO_SIMD t_div1.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div1_sse t_div1.c ../vec_div.c ../vec_simd.c frand.c

sse=`./t_div1_sse`
pure=`./t_div1_pure`
printf "%12s %12s %12s\n" "t_div1" "${sse}" "${pure}"

rm -f t_div1_pure t_div1_sse
