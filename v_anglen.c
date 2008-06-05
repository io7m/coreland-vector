#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_math.h"
#include "v_dotp.h"
#include "v_anglen.h"

float
vec_anglenormNf (const float *va, const float *vb, unsigned int n)
{
  return acosf (vec_dotprodNf (va, vb, n));
}

double
vec_anglenormNd (const double *va, const double *vb, unsigned int n)
{
  return acos (vec_dotprodNd (va, vb, n));
}

float
vec_anglenormNf_aligned (const float *va, const float *vb, unsigned int n)
{
  return acosf (vec_dotprodNf_aligned (va, vb, n));
}

double
vec_anglenormNd_aligned (const double *va, const double *vb, unsigned int n)
{
  return acos (vec_dotprodNd_aligned (va, vb, n));
}
