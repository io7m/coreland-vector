#!/bin/sh

echo '#ifndef VECTOR_H'
echo '#define VECTOR_H'
echo
echo '#include "vec_add.h"'
echo '#include "vec_assi.h"'
echo '#include "vec_div.h"'
echo '#include "vec_dotp.h"'
echo '#include "vec_mult.h"'
echo '#include "vec_nega.h"'
echo '#include "vec_sub.h"'
echo '#include "vec_xprod.h"'
echo '#include "vec_zero.h"'
echo
./vec_add_D.sh
echo
./vec_sub_D.sh
echo
./vec_div_D.sh
echo
./vec_mult_D.sh
echo
./vec_assi_D.sh
echo
./vec_zero_D.sh
echo
./vec_nega_D.sh
echo
./vec_mag_D.sh
echo
./vec_norm_D.sh
echo
./vec_dotp_D.sh
echo
./vec_xprod_D.sh
echo
./vec_dist_D.sh
echo
./vec_ang_D.sh
echo
./vec_angn_D.sh
echo
echo '#endif'
