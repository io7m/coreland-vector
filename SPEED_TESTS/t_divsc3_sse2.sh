#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc3_pure -DVECTOR_NO_SIMD t_divsc3.c ../vec_divsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc3_sse2 t_divsc3.c ../vec_divsc.c ../vec_simd.c frand.c

sse2=`./t_divsc3_sse2`
pure=`./t_divsc3_pure`
printf "%12s %12s %12s\n" "t_divsc3" "${sse2}" "${pure}"

rm -f t_divsc3_pure t_divsc3_sse2
