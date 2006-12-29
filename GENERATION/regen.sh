#!/bin/sh -x

./vec_add_C.sh > ../vec_add.c
./vec_add_H.sh > ../vec_add.h
./vec_assi_C.sh > ../vec_assi.c
./vec_assi_H.sh > ../vec_assi.h
./vec_div_C.sh > ../vec_div.c
./vec_div_H.sh > ../vec_div.h
./vec_dist_C.sh > ../vec_dist.c
./vec_dotp_C.sh > ../vec_dotp.c
./vec_dotp_H.sh > ../vec_dotp.h
./vec_mag_C.sh > ../vec_mag.c
./vec_mult_C.sh > ../vec_mult.c
./vec_mult_H.sh > ../vec_mult.h
./vec_nega_C.sh > ../vec_nega.c
./vec_nega_H.sh > ../vec_nega.h
./vec_ang_C.sh > ../vec_angle.c
./vec_angn_C.sh > ../vec_anglen.c
./vec_norm_C.sh > ../vec_norm.c
./vec_sub_C.sh > ../vec_sub.c
./vec_sub_H.sh > ../vec_sub.h
./vec_zero_C.sh > ../vec_zero.c
./vec_zero_H.sh > ../vec_zero.h
./vec_xprod_C.sh > ../vec_xprod.c
./vec_xprod_H.sh > ../vec_xprod.h

./vector_H.sh > ../vector.h
