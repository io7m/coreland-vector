#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div3_pure -DVECTOR_NO_SIMD t_div3.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_div3_sse2 t_div3.c ../vec_div.c ../vec_simd.c frand.c

sse2=`./t_div3_sse2`
pure=`./t_div3_pure`
printf "%12s %12s %12s\n" "t_div3" "${sse2}" "${pure}"

rm -f t_div3_pure t_div3_sse2
