#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add2_pure -DVECTOR_NO_SIMD t_add2.c ../vec_add.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add2_sse t_add2.c ../vec_add.c ../vec_simd.c frand.c

sse=`./t_add2_sse`
pure=`./t_add2_pure`
printf "%12s %12s %12s\n" "t_add2" "${sse}" "${pure}"

rm -f t_add2_pure t_add2_sse
