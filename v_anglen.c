#include "v_math.h"
#include "v_dotp.h"
#include "v_anglen.h"

float
vec_anglenormNf(const float *va, const float *vb, unsigned int n)
{
  return acosf(vec_dotprodNf(va, vb, n));
}

double
vec_anglenormNd(const double *va, const double *vb, unsigned int n)
{
  return acos(vec_dotprodNd(va, vb, n));
}
