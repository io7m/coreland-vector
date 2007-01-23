#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_assi1_pure -DVECTOR_NO_SIMD t_assi1.c ../vec_assi.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_assi1_alti t_assi1.c ../vec_assi.c ../vec_simd.c frand.c

printf "alti "
./t_assi1_alti
printf "pure "
./t_assi1_pure

rm -f t_assi1_pure t_assi1_alti
