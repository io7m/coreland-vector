#include <math.h>
#include "vec_mag.h"
#include "vec_simd.h"

/* interface */

float vec_magNf(const float *va, unsigned int n)
{
  unsigned int seg[2];
  const float *pva;
  float f = 0;
  unsigned int ind;

  pva = va;
  vec_segments(seg, 2, n);

  for (ind = 0; ind < seg[1]; ++ind) {
    f += (pva[0] * pva[0]) +
         (pva[1] * pva[1]) +
         (pva[2] * pva[2]) +
         (pva[3] * pva[3]);
  }
  for (ind = 0; ind < seg[0]; ++ind)
    f += pva[ind] * pva[ind]; 

  return sqrtf(f);
}
double vec_magNd(const double *va, unsigned int n)
{
  unsigned int seg[2];
  const double *pva;
  double d = 0;
  unsigned int ind;

  pva = va;
  vec_segments(seg, 2, n);

  for (ind = 0; ind < seg[1]; ++ind) {
    d += (pva[0] * pva[0]) +
         (pva[1] * pva[1]) +
         (pva[2] * pva[2]) +
         (pva[3] * pva[3]);
  }
  for (ind = 0; ind < seg[0]; ++ind)
    d += pva[ind] * pva[ind]; 

  return sqrt(d);
}
