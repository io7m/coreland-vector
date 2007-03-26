#include <math.h>
#include "vec_dotp.h"
#include "vec_mag.h"
#include "vec_angle.h"
#include "vec_math.h"

float vec_angleNf(const float *va, const float *vb, unsigned int n)
{
  return acosf(vec_dotprodNf(va, vb, n)
               / ((vec_magNf(va, n) * vec_magNf(vb, n))));
}
double vec_angleNd(const double *va, const double *vb, unsigned int n)
{
  return acos(vec_dotprodNd(va, vb, n)
              / ((vec_magNd(va, n) * vec_magNd(vb, n))));
}
