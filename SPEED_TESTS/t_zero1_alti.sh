#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_zero1_pure -DVECTOR_NO_SIMD t_zero1.c ../vec_zero.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_zero1_alti t_zero1.c ../vec_zero.c ../vec_simd.c frand.c

printf "alti "
./t_zero1_alti
printf "pure "
./t_zero1_pure

rm -f t_zero1_pure t_zero1_alti
