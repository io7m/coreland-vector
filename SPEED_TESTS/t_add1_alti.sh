#!/bin/sh

. ./test-subs

cc ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_add1_pure -DNO_VECTOR_SIMD t_add1.c ../vec_add.c
cc ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_add1_alti -faltivec t_add1.c ../vec_add.c

printf "alti "
./t_add1_alti
printf "pure "
./t_add1_pure

rm -f t_add1_pure t_add1_alti
