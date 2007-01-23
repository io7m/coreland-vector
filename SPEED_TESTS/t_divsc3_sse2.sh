#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc2_pure -DVECTOR_NO_SIMD t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} \
  -o t_divsc2_sse2 t_divsc2.c ../vec_divsc.c ../vec_simd.c frand.c

sse2=`./t_divsc3_sse2`
pure=`./t_divsc3_pure`
printf "%12s %12s %12s\n" "t_divsc3" "${sse2}" "${pure}"

rm -f t_divsc2_pure t_divsc2_sse2
