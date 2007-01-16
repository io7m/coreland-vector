#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_divsc1_pure -DVECTOR_NO_SIMD t_divsc1.c ../vec_divsc.c ../vec_simd.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_divsc1_alti t_divsc1.c ../vec_divsc.c ../vec_simd.c

printf "alti "
./t_divsc1_alti
printf "pure "
./t_divsc1_pure

rm -f t_divsc1_pure t_divsc1_alti
