#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_addsc2_pure -DVECTOR_NO_SIMD t_addsc2.c ../vec_addsc.c ../vec_simd.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_addsc2_alti t_addsc2.c ../vec_addsc.c ../vec_simd.c

printf "alti "
./t_addsc2_alti
printf "pure "
./t_addsc2_pure

rm -f t_addsc2_pure t_addsc2_alti
