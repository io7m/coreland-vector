#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_multsc1_pure -DVECTOR_NO_SIMD t_multsc1.c ../vec_multsc.c ../vec_simd.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_multsc1_alti t_multsc1.c ../vec_multsc.c ../vec_simd.c

printf "alti "
./t_multsc1_alti
printf "pure "
./t_multsc1_pure

rm -f t_multsc1_pure t_multsc1_alti
