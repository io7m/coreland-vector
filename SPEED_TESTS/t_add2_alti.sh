#!/bin/sh

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_add2_pure -DVECTOR_NO_SIMD t_add2.c ../vec_add.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_add2_alti t_add2.c ../vec_add.c ../vec_simd.c frand.c

printf "alti "
./t_add2_alti
printf "pure "
./t_add2_pure

rm -f t_add2_pure t_add2_alti
