#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_add1_pure -DVECTOR_NO_SIMD t_add1.c ../vec_add.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_add1_sse t_add1.c ../vec_add.c ../vec_simd.c frand.c

sse=`./t_add1_sse`
pure=`./t_add1_pure`
printf "%12s %12s %12s\n" "t_add1" "${sse}" "${pure}"

rm -f t_add1_pure t_add1_sse
