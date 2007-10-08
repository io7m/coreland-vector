#include <math.h>
#include "v_mag.h"
#include "v_dotp.h"
#include "v_simd.h"
#include "v_math.h"

float vec_magNf(const float *va, unsigned int n)
{
  return sqrtf(vec_dotprodNf(va, va, n));
}
double vec_magNd(const double *va, unsigned int n)
{
  return sqrt(vec_dotprodNd(va, va, n));
}
