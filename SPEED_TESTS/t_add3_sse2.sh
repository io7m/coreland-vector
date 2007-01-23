#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add2_pure -DVECTOR_NO_SIMD t_add2.c ../vec_add.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_add2_sse2 t_add2.c ../vec_add.c ../vec_simd.c frand.c

sse2=`./t_add3_sse2`
pure=`./t_add3_pure`
printf "%12s %12s %12s\n" "t_add3" "${sse2}" "${pure}"

rm -f t_add2_pure t_add2_sse2
