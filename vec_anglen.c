#include <math.h>
#include "vec_dotp.h"
#include "vec_anglen.h"
#include "vec_math.h"

float vec_anglenormNf(const float *va, const float *vb, unsigned int n)
{
  return acosf(vec_dotprodNf(va, vb, n));
}
double vec_anglenormNd(const double *va, const double *vb, unsigned int n)
{
  return acos(vec_dotprodNd(va, vb, n));
}
