#!/bin/sh

cc -DNO_VECTOR_SIMD -c -o vec_add_pure.o vec_add.c
cc -faltivec -c -o vec_add_alti.o vec_add.c

cc -o t_pure t.c vec_add_pure.o
cc -o t_alti t.c vec_add_alti.o

printf "alti "
./t_alti
printf "pure "
./t_pure
