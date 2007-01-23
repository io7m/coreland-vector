#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_div2_pure -DVECTOR_NO_SIMD t_div2.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_div2_alti t_div2.c ../vec_div.c ../vec_simd.c frand.c

printf "alti "
./t_div2_alti
printf "pure "
./t_div2_pure

rm -f t_div2_pure t_div2_alti
