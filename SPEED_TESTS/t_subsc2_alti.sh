#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_subsc2_pure -DVECTOR_NO_SIMD t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_subsc2_alti t_subsc2.c ../vec_subsc.c ../vec_simd.c frand.c

printf "alti "
./t_subsc2_alti
printf "pure "
./t_subsc2_pure

rm -f t_subsc2_pure t_subsc2_alti
