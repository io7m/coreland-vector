#include <math.h>
#include "vec_dotp.h"
#include "vec_norm.h"
#include "vec_simd.h"
#include "vec_types.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_normNf_sse(float *va, float mag, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mrcp;
  unsigned int seg[3];
  float *pva;
  float rcp;
  unsigned int ind;

  pva = va;
  rcp = 1 / sqrtf(mag);
  vec_segments(seg, 3, ne);

  mrcp = _mm_set1_ps(rcp);
  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_mul_ps(mva1, mrcp);
    mva2 = _mm_mul_ps(mva2, mrcp);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_mul_ps(mva1, mrcp);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] *= rcp;

  return va;
}
static float *vec_normNfx_sse(const float *va, float *vr, float mag,
                              unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mrcp;
  unsigned int seg[3];
  const float *pva;
  float *pvr;
  float rcp;
  unsigned int ind;

  pvr = vr;
  pva = va;
  rcp = 1 / sqrtf(mag);
  vec_segments(seg, 3, ne);

  mrcp = _mm_set1_ps(rcp);
  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_mul_ps(mva1, mrcp);
    mva2 = _mm_mul_ps(mva2, mrcp);
    _mm_store_ps(pvr, mva1);
    _mm_store_ps(pvr + 4, mva2);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_mul_ps(mva1, mrcp);
    _mm_store_ps(pvr, mva1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] * rcp;

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double *vec_normNd_sse2(double *va, double mag, unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d mrcp;
  unsigned int seg[2];
  double *pva;
  double rcp;
  unsigned int ind;

  pva = va;
  rcp = 1 / sqrt(mag);
  vec_segments(seg, 2, ne);

  mrcp = _mm_set1_pd(rcp);
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mva1 = _mm_mul_pd(mva1, mrcp);
    mva2 = _mm_mul_pd(mva2, mrcp);
    _mm_store_pd(pva, mva1);
    _mm_store_pd(pva + 2, mva2);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] *= rcp;

  return va;
}
static double *vec_normNdx_sse2(const double *va, double *vr, double mag,
                                unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d mrcp;
  unsigned int seg[2];
  const double *pva;
  double *pvr;
  double rcp;
  unsigned int ind;

  pvr = vr;
  pva = va;
  rcp = 1 / sqrt(mag);
  vec_segments(seg, 2, ne);

  mrcp = _mm_set1_pd(rcp);
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mva1 = _mm_mul_pd(mva1, mrcp);
    mva2 = _mm_mul_pd(mva2, mrcp);
    _mm_store_pd(pvr, mva1);
    _mm_store_pd(pvr + 2, mva2);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] * rcp;

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_normNf_altivec(float *va, float mag, unsigned int ne)
{
  vector_4f vs;
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vnz;
  vector unsigned int vui;
  unsigned int seg[4];
  float *pva;
  float rcp;
  unsigned int ind;

  pva = va;
  rcp = 1 / sqrtf(mag);
  vec_segments(seg, 4, ne);

  /* using a vector of negative zeroes is faster than positive */
  vui = vec_splat_u32(-1);
  vnz = (vector float) vec_sl(vui, vui);
  vs.f[0] = rcp;
  vs.v = vec_splat(vs.v, 0);

  for (ind = 0; ind < seg[3]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vva1 = vec_madd(vva1, vs.v, vnz);
    vva2 = vec_madd(vva2, vs.v, vnz);
    vva3 = vec_madd(vva3, vs.v, vnz);
    vva4 = vec_madd(vva4, vs.v, vnz); 
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    vec_st(vva3, 0, pva + 8);
    vec_st(vva4, 0, pva + 12);
    pva += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva1 = vec_madd(vva1, vs.v, vnz);
    vva2 = vec_madd(vva2, vs.v, vnz);
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva1 = vec_madd(vva1, vs.v, vnz);
    vec_st(vva1, 0, pva);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] *= rcp;

  return va;
}
static float *vec_normNfx_altivec(const float *va, float *vr,
                                  float mag, unsigned int ne)
{
  vector_4f vs;
  vector float vvr1;
  vector float vvr2;
  vector float vvr3;
  vector float vvr4;
  vector float vnz;
  vector unsigned int vui;
  unsigned int seg[4];
  const float *pva;
  float *pvr;
  float rcp;
  unsigned int ind;

  /* using a vector of negative zeroes is faster than positive */
  rcp = 1 / sqrtf(mag);
  vui = vec_splat_u32(-1);
  vnz = (vector float) vec_sl(vui, vui);
  pva = va;
  pvr = vr;
  vs.f[0] = rcp;
  vs.v = vec_splat(vs.v, 0);
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    vvr1 = vec_ld(0, pva); 
    vvr2 = vec_ld(0, pva + 4);
    vvr3 = vec_ld(0, pva + 8);
    vvr4 = vec_ld(0, pva + 12);
    vvr1 = vec_madd(vvr1, vs.v, vnz);
    vvr2 = vec_madd(vvr2, vs.v, vnz);
    vvr3 = vec_madd(vvr3, vs.v, vnz);
    vvr4 = vec_madd(vvr4, vs.v, vnz);
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    vec_st(vvr3, 0, pvr + 8);
    vec_st(vvr4, 0, pvr + 12);
    pvr += 16;
    pva += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vvr1 = vec_ld(0, pva);
    vvr2 = vec_ld(0, pva + 4);
    vvr1 = vec_madd(vvr1, vs.v, vnz);
    vvr2 = vec_madd(vvr2, vs.v, vnz);
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    pvr += 8;
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vvr1 = vec_ld(0, pva);
    vvr1 = vec_madd(vvr1, vs.v, vnz);
    vec_st(vvr1, 0, pvr);
    pvr += 4;
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] * rcp;

  return vr;
}
#endif

/* interface */

float *vec_normNf(float *va, unsigned int n)
{
  float mag;
  float rcp;
  unsigned int ind;

  mag = vec_dotprodNf(va, va, n);
  if (mag) {
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va)) return vec_normNf_sse(va, mag, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va)) return vec_normNf_altivec(va, mag, n);
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

  mag = vec_dotprodNf(va, va, n);
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

  mag = vec_dotprodNd(va, va, n);
  if (mag) {
#ifdef SYS_HAVE_CPU_EXT_SSE2
    if (!vec_unaligned(va)) return vec_normNd_sse2(va, mag, n);
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

  mag = vec_dotprodNd(va, va, n);
  if (mag) {
#ifdef SYS_HAVE_CPU_EXT_SSE2
    if (!vec_unaligned(va) && !vec_unaligned(vr))
      return vec_normNdx_sse2(va, vr, mag, n);
#endif
    rcp = 1 / sqrt(mag);
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] * rcp;
  }
  return vr;
}
