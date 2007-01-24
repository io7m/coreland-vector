#!/bin/sh 

. ./test-subs

${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_dotprod1_pure -DVECTOR_NO_SIMD t_dotprod1.c ../vec_dotp.c ../vec_simd.c frand.c
${CC} ${CFLAGS} ${ALTIVEC_FLAGS} \
  -o t_dotprod1_alti t_dotprod1.c ../vec_dotp.c ../vec_simd.c frand.c

alti=`./t_dotprod1_alti`
pure=`./t_dotprod1_pure`
printf "%12s %12s %12s\n" "t_dotprod1" "${alti}" "${pure}"

rm -f t_dotprod1_pure t_dotprod1_alti
