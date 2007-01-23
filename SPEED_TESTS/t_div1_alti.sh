#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_div1_pure -DVECTOR_NO_SIMD t_div1.c ../vec_div.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_div1_alti t_div1.c ../vec_div.c ../vec_simd.c frand.c

printf "alti "
./t_div1_alti
printf "pure "
./t_div1_pure

rm -f t_div1_pure t_div1_alti
