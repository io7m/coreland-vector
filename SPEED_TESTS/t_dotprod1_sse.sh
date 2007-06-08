#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_dotprod1_pure -DVECTOR_NO_SIMD t_dotprod1.c ../vec_dotp.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_dotprod1_sse t_dotprod1.c ../vec_dotp.c ../vec_simd.c ../vec_align.c frand.c

sse=`./t_dotprod1_sse`
pure=`./t_dotprod1_pure`
printf "%12s %12s %12s\n" "t_dotprod1" "${sse}" "${pure}"

rm -f t_dotprod1_pure t_dotprod1_sse
