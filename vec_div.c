#include "vec_div.h"
#include "vec_simd.h"

#ifdef SYSINFO_HAVE_CPU_EXT_SSE
static float *vec_divNf_sse(float *va, const float *vb, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvb1;
  __m128 mvb2;
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

  for (ind = 0; ind < d8; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvb1 = _mm_load_ps(pvb);
    mvb2 = _mm_load_ps(pvb + 4);
    mva1 = _mm_div_ps(mva1, mvb1);
    mva2 = _mm_div_ps(mva2, mvb2);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mva1 = _mm_div_ps(mva1, mvb1);
    _mm_store_ps(pva, mva1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] /= pvb[ind];

  return va;
}
static float *vec_divNfx_sse(const float *va, const float *vb,
                             float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvr;
  const float *pva;
  const float *pvb;
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

  for (ind = 0; ind < d8; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvb1 = _mm_load_ps(pvb);
    mvb2 = _mm_load_ps(pvb + 4);
    mvr = _mm_div_ps(mva1, mvb1);
    _mm_store_ps(pvr, mvr);
    mvr = _mm_div_ps(mva2, mvb2);
    _mm_store_ps(pvr + 4, mvr);
    pva += 8;
    pvb += 8;
    pvr += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mvr = _mm_div_ps(mva1, mvb1);
    _mm_store_ps(pvr, mvr);
    pva += 4;
    pvb += 4;
    pvr += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pvr[ind] = pva[ind] / pvb[ind];

  return vr;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
static double *vec_divNd_sse2(double *va, const double *vb, unsigned int n)
{
  return va;
}
static double *vec_divNdx_sse2(const double *va, const double *vb,
                               double *vr, unsigned int n)
{
  return vr;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
static float *vec_divNf_altivec(float *va, const float *vb, unsigned int ne)
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
static float *vec_divNfx_altivec(const float *va, const float *vb,
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

float *vec_divNf(float *va, const float *vb, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_divNf_sse(va, vb, n);
#endif
#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_divNf_altivec(va, vb, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] /= vb[ind];
    return va;
  }
}
float *vec_divNfx(const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_divNfx_sse(va, vb, vr, n);
#endif
#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_divNfx_altivec(va, vb, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] / vb[ind];
    return vr;
  }
}
double *vec_divNd(double *va, const double *vb, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_divNd_sse2(va, vb, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] /= vb[ind];
    return va;
  }
}
double *vec_divNdx(const double *va, const double *vb, double *vr, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_divNdx_sse2(va, vb, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] / vb[ind];
    return vr;
  }
}
