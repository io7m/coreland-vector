#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_sub2_pure -DVECTOR_NO_SIMD t_sub2.c ../vec_sub.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_sub2_alti t_sub2.c ../vec_sub.c ../vec_simd.c frand.c

printf "alti "
./t_sub2_alti
printf "pure "
./t_sub2_pure

rm -f t_sub2_pure t_sub2_alti
