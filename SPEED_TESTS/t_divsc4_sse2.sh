#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_divsc4_pure -DVECTOR_NO_SIMD t_divsc4.c ../vec_divsc.c ../vec_simd.c ../vec_align.c frand.c
${CC} ${CFLAGS} ${SSE_FLAGS} ${MATH_FLAGS} \
  -o t_divsc4_sse2 t_divsc4.c ../vec_divsc.c ../vec_simd.c ../vec_align.c frand.c

sse2=`./t_divsc4_sse2`
pure=`./t_divsc4_pure`
printf "%12s %12s %12s\n" "t_divsc4" "${sse2}" "${pure}"

rm -f t_divsc4_pure t_divsc4_sse2
