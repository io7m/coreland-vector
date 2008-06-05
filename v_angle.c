#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_math.h"
#include "v_dotp.h"
#include "v_mag.h"
#include "v_angle.h"

float
vec_angleNf (const float *va, const float *vb, unsigned int n)
{
  return acosf (vec_dotprodNf (va, vb, n)
    / ((vec_magNf (va, n) * vec_magNf (vb, n))));
}

double
vec_angleNd (const double *va, const double *vb, unsigned int n)
{
  return acos (vec_dotprodNd (va, vb, n)
    / ((vec_magNd (va, n) * vec_magNd (vb, n))));
}

float
vec_angleNf_aligned (const float *va, const float *vb, unsigned int n)
{
  return acosf (vec_dotprodNf_aligned (va, vb, n)
    / ((vec_magNf_aligned (va, n) * vec_magNf_aligned (vb, n))));
}

double
vec_angleNd_aligned (const double *va, const double *vb, unsigned int n)
{
  return acos (vec_dotprodNd_aligned (va, vb, n)
    / ((vec_magNd_aligned (va, n) * vec_magNd_aligned (vb, n))));
}
