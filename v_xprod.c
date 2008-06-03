#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_xprod.h"

float *
vec_crossprod3fx (const float va[3], const float vb[3], float vr[3])
{
  vec_CROSSPROD3x (va, vb, vr);
  return vr;
}

double *
vec_crossprod3dx (const double va[3], const double vb[3], double vr[3])
{
  vec_CROSSPROD3x (va, vb, vr);
  return vr;
}

