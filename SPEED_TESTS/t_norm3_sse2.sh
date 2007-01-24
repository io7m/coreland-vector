#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm3_pure -DVECTOR_NO_SIMD t_norm3.c ../vec_norm.c ../vec_dotp.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_norm3_sse2 t_norm3.c ../vec_norm.c ../vec_dotp.c ../vec_simd.c frand.c

sse2=`./t_norm3_sse2`
pure=`./t_norm3_pure`
printf "%12s %12s %12s\n" "t_norm3" "${sse2}" "${pure}"

rm -f t_norm3_pure t_norm3_sse2
