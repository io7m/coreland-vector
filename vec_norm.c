#include <math.h>
#include "vec_norm.h"
#include "vec_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_normNf_sse(float *va, float mag, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mrcp;
  float *pva;
  float rcp;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pva = va;
  rcp = 1 / sqrtf(mag);
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  mrcp = _mm_set1_ps(rcp);
  for (ind = 0; ind < d8; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_mul_ps(mva1, mrcp);
    mva2 = _mm_mul_ps(mva2, mrcp);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_mul_ps(mva1, mrcp);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] *= rcp;

  return va;
}
static float *vec_normNfx_sse(const float *va, float *vr, float mag,
                              unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mrcp;
  const float *pva;
  float *pvr;
  float rcp;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pvr = vr;
  pva = va;
  rcp = 1 / sqrtf(mag);
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  mrcp = _mm_set1_ps(rcp);
  for (ind = 0; ind < d8; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_mul_ps(mva1, mrcp);
    mva2 = _mm_mul_ps(mva2, mrcp);
    _mm_store_ps(pvr, mva1);
    _mm_store_ps(pvr + 4, mva2);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_mul_ps(mva1, mrcp);
    _mm_store_ps(pvr, mva1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pvr[ind] = pva[ind] * rcp;

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double *vec_normNd_sse2(double *va, const double *vb, unsigned int n)
{
  return va;
}
static double *vec_normNdx_sse2(const double *va, const double *vb,
                               double *vr, unsigned int n)
{
  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_normNf_altivec(float *va, const float *vb, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vvb1;
  vector float vvb2;
  vector float vvb3;
  vector float vvb4;
  const float *pvb;
  float *pva;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pva = va;
  pvb = vb;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  return va;
}
static float *vec_normNfx_altivec(const float *va, const float *vb,
                                 float *vr, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vvb1;
  vector float vvb2;
  vector float vvb3;
  vector float vvb4;
  vector float vvr;
  const float *pvb;
  const float *pva;
  float *pvr;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pva = va;
  pvb = vb;
  pvr = vr;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  return vr;
}
#endif

/* interface */

float *vec_normNf(float *va, unsigned int n)
{
  float mag;
  float rcp;
  unsigned int ind;

  mag = 0;
  for (ind = 0; ind < n; ++ind)
    mag += va[ind] * va[ind];

  if (mag) {
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va))
    return vec_normNf_sse(va, mag, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va))
    return vec_normNf_altivec(va, mag, n);
#endif
    rcp = 1 / sqrtf(mag);
    for (ind = 0; ind < n; ++ind)
      va[ind] *= rcp;
  }
  return va;
}
float *vec_normNfx(const float *va, float *vr, unsigned int n)
{
  float mag;
  float rcp;
  unsigned int ind;

  mag = 0;
  for (ind = 0; ind < n; ++ind)
    mag += va[ind] * va[ind];

  if (mag) {
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_normNfx_sse(va, vr, mag, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_normNfx_altivec(va, vr, mag, n);
#endif
    rcp = 1 / sqrtf(mag);
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] * rcp;
  }
  return vr;
}
double *vec_normNd(double *va, unsigned int n)
{
  double mag;
  double rcp;
  unsigned int ind;

  mag = 0;
  for (ind = 0; ind < n; ++ind)
    mag += va[ind] * va[ind];

  if (mag) {
#ifdef SYS_HAVE_CPU_EXT_SSE2
    if (!vec_unaligned(va))
      return vec_normNd_sse2(va, n);
#endif
    rcp = 1 / sqrt(mag);
    for (ind = 0; ind < n; ++ind)
      va[ind] *= rcp;
  }
  return va;
}
double *vec_normNdx(const double *va, double *vr, unsigned int n)
{
  double mag;
  double rcp;
  unsigned int ind;

  mag = 0;
  for (ind = 0; ind < n; ++ind)
    mag += va[ind] * va[ind];

  if (mag) {
#ifdef SYS_HAVE_CPU_EXT_SSE2
    if (!vec_unaligned(va) && !vec_unaligned(vr))
      return vec_normNdx_sse2(va, vr, n);
#endif
    rcp = 1 / sqrt(mag);
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] * rcp;
  }
  return vr;
}
