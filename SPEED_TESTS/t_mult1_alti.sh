#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_mult1_pure -DVECTOR_NO_SIMD t_mult1.c ../vec_mult.c ../vec_simd.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_mult1_alti t_mult1.c ../vec_mult.c ../vec_simd.c

printf "alti "
./t_mult1_alti
printf "pure "
./t_mult1_pure

rm -f t_mult1_pure t_mult1_alti
