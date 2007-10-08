#include <math.h>
#include "v_dotp.h"
#include "v_norm.h"
#include "v_multsc.h"
#include "v_simd.h"
#include "v_types.h"
#include "v_math.h"

float *vec_normNf(float *va, unsigned int n)
{
  float mag;
  float rcp;

  mag = vec_dotprodNf(va, va, n);
  if (mag) {
    rcp = 1 / sqrtf(mag);
    vec_multscNf(va, rcp, n);
  }
  return va;
}
float *vec_normNfx(const float *va, float *vr, unsigned int n)
{
  float mag;
  float rcp;

  mag = vec_dotprodNf(va, va, n);
  if (mag) {
    rcp = 1 / sqrtf(mag);
    vec_multscNfx(va, vr, rcp, n);
  }
  return vr;
}
double *vec_normNd(double *va, unsigned int n)
{
  double mag;
  double rcp;

  mag = vec_dotprodNd(va, va, n);
  if (mag) {
    rcp = 1 / sqrt(mag);
    vec_multscNd(va, rcp, n);
  }
  return va;
}
double *vec_normNdx(const double *va, double *vr, unsigned int n)
{
  double mag;
  double rcp;

  mag = vec_dotprodNd(va, va, n);
  if (mag) {
    rcp = 1 / sqrt(mag);
    vec_multscNdx(va, vr, rcp, n);
  }
  return vr;
}
