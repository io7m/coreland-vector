#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_mult2_pure -DVECTOR_NO_SIMD t_mult2.c ../vec_mult.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_mult2_alti t_mult2.c ../vec_mult.c ../vec_simd.c frand.c

printf "alti "
./t_mult2_alti
printf "pure "
./t_mult2_pure

rm -f t_mult2_pure t_mult2_alti
