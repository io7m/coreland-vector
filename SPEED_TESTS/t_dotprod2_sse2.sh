#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_dotprod2_pure -DVECTOR_NO_SIMD t_dotprod1.c ../vec_dotp.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_dotprod2_sse t_dotprod1.c ../vec_dotp.c ../vec_simd.c frand.c

sse=`./t_dotprod2_sse`
pure=`./t_dotprod2_pure`
printf "%12s %12s %12s\n" "t_dotprod1" "${sse}" "${pure}"

rm -f t_dotprod2_pure t_dotprod2_sse
