#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_math.h"
#include "v_angle.h"
#include "v_anglen.h"
#include "v_degreen.h"

float
vec_degreenormNf (const float *va, const float *vb, unsigned int n)
{
  return vec_anglenormNf (va, vb, n) * (180 / M_PI);
}

double
vec_degreenormNd (const double *va, const double *vb, unsigned int n)
{
  return vec_anglenormNd (va, vb, n) * (180 / M_PI);
}

float
vec_degreenormNf_aligned (const float *va, const float *vb, unsigned int n)
{
  return vec_anglenormNf_aligned (va, vb, n) * (180 / M_PI);
}

double
vec_degreenormNd_aligned (const double *va, const double *vb, unsigned int n)
{
  return vec_anglenormNd_aligned (va, vb, n) * (180 / M_PI);
}
