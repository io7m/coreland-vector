#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_math.h"
#include "v_mag.h"
#include "v_dotp.h"

float
vec_magNf (const float *va, unsigned int n)
{
  return sqrtf (vec_dotprodNf (va, va, n));
}

double
vec_magNd (const double *va, unsigned int n)
{
  return sqrt (vec_dotprodNd (va, va, n));
}

float
vec_magNf_aligned (const float *va, unsigned int n)
{
  return sqrtf (vec_dotprodNf_aligned (va, va, n));
}

double
vec_magNd_aligned (const double *va, unsigned int n)
{
  return sqrt (vec_dotprodNd_aligned (va, va, n));
}
