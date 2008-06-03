#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_mag.h"
#include "v_dist.h"
#include "v_sub.h"

float
vec_distNf (float *vt, const float *va, const float *vb, unsigned int n)
{
  return vec_magNf (vec_subNfx (va, vb, vt, n), n);
}

double
vec_distNd (double *vt, const double *va, const double *vb, unsigned int n)
{
  return vec_magNd (vec_subNdx (va, vb, vt, n), n);
}
