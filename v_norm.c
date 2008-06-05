#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_math.h"
#include "v_dotp.h"
#include "v_norm.h"
#include "v_multsc.h"

float *
vec_normNf (float *va, unsigned int n)
{
  float mag;
  float rcp;

  mag = vec_dotprodNf (va, va, n);
  if (mag) {
    rcp = 1 / sqrtf (mag);
    vec_multscNf (va, rcp, n);
  }
  return va;
}

float *
vec_normNfx (const float *va, float *vr, unsigned int n)
{
  float mag;
  float rcp;

  mag = vec_dotprodNf (va, va, n);
  if (mag) {
    rcp = 1 / sqrtf (mag);
    vec_multscNfx (va, vr, rcp, n);
  }
  return vr;
}

double *
vec_normNd (double *va, unsigned int n)
{
  double mag;
  double rcp;

  mag = vec_dotprodNd (va, va, n);
  if (mag) {
    rcp = 1 / sqrt (mag);
    vec_multscNd (va, rcp, n);
  }
  return va;
}

double *
vec_normNdx (const double *va, double *vr, unsigned int n)
{
  double mag;
  double rcp;

  mag = vec_dotprodNd (va, va, n);
  if (mag) {
    rcp = 1 / sqrt (mag);
    vec_multscNdx (va, vr, rcp, n);
  }
  return vr;
}

float *
vec_normNf_aligned (float *va, unsigned int n)
{
  float mag;
  float rcp;

  mag = vec_dotprodNf_aligned (va, va, n);
  if (mag) {
    rcp = 1 / sqrtf (mag);
    vec_multscNf_aligned (va, rcp, n);
  }
  return va;
}

float *
vec_normNfx_aligned (const float *va, float *vr, unsigned int n)
{
  float mag;
  float rcp;

  mag = vec_dotprodNf_aligned (va, va, n);
  if (mag) {
    rcp = 1 / sqrtf (mag);
    vec_multscNfx_aligned (va, vr, rcp, n);
  }
  return vr;
}

double *
vec_normNd_aligned (double *va, unsigned int n)
{
  double mag;
  double rcp;

  mag = vec_dotprodNd_aligned (va, va, n);
  if (mag) {
    rcp = 1 / sqrt (mag);
    vec_multscNd_aligned (va, rcp, n);
  }
  return va;
}

double *
vec_normNdx_aligned (const double *va, double *vr, unsigned int n)
{
  double mag;
  double rcp;

  mag = vec_dotprodNd_aligned (va, va, n);
  if (mag) {
    rcp = 1 / sqrt (mag);
    vec_multscNdx_aligned (va, vr, rcp, n);
  }
  return vr;
}
