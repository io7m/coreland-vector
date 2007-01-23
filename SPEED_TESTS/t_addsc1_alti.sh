#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_addsc1_pure -DVECTOR_NO_SIMD t_addsc1.c ../vec_addsc.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_addsc1_alti t_addsc1.c ../vec_addsc.c ../vec_simd.c frand.c

printf "alti "
./t_addsc1_alti
printf "pure "
./t_addsc1_pure

rm -f t_addsc1_pure t_addsc1_alti
