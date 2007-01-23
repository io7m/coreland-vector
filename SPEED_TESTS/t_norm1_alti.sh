#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_norm1_pure -DVECTOR_NO_SIMD t_norm1.c ../vec_norm.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_norm1_alti t_norm1.c ../vec_norm.c ../vec_simd.c frand.c

printf "alti "
./t_norm1_alti
printf "pure "
./t_norm1_pure

rm -f t_norm1_pure t_norm1_alti
