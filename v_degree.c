#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_math.h"
#include "v_angle.h"
#include "v_degree.h"

float
vec_degreeNf (const float *va, const float *vb, unsigned int n)
{
  return vec_angleNf (va, vb, n) * (180 / M_PI);
}

double
vec_degreeNd (const double *va, const double *vb, unsigned int n)
{
  return vec_angleNd (va, vb, n) * (180 / M_PI);
}
