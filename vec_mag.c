#include <math.h>
#include "vec_mag.h"
#include "vec_dotp.h"
#include "vec_simd.h"

float vec_magNf(const float *va, unsigned int n)
{
  return sqrtf(vec_dotprodNf(va, va, n));
}
double vec_magNd(const double *va, unsigned int n)
{
  return sqrt(vec_dotprodNf(va, va, n));
}
