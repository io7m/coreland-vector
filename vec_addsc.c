#include "sysinfo.h"
#include "vector.h"
#include "vec_addsc.h"
#include "vec_simd.h"

#ifdef SYSINFO_HAVE_CPU_EXT_SSE
static float *vec_addscNf_sse(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvb1;
  __m128 mvb2;
  __m128 vsc;
  float *pva;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  vec_simd_segments(&d16, &d8, &d4, &dr, ne);
  pva = va;
  vsc = _mm_set1_ps(sc);

  for (ind = 0; ind < d8; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_add_ps(mva1, vsc);
    mva2 = _mm_add_ps(mva2, vsc);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 4;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_add_ps(mva1, vsc);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] += sc;

  return va;
}
static float *vec_addscNfx_sse(const float *va, float *vr, float sc,
                               unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvr1;
  __m128 vsc;
  const float *pva;
  float *pvr;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  vec_simd_segments(&d16, &d8, &d4, &dr, ne);
  pva = va;
  pvr = vr;
  vsc = _mm_set1_ps(sc);

  for (ind = 0; ind < d8; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvr1 = _mm_add_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    mva2 = _mm_add_ps(mva2, vsc);
    _mm_store_ps(pvr + 4, mvr1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvr1 = _mm_add_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pvr[ind] = pva[ind] + sc;

  return vr;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
static double *vec_addscNd_sse2(double *va, const double *vb, unsigned int n)
{
  return va;
}
static double *vec_addscNdx_sse2(const double *va, const double *vb,
                                 double *vr, unsigned int n)
{
  return vr;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
static float *vec_addscNf_altivec(float *va, float sc, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vvb1;
  vector float vvb2;
  vector float vvb3;
  vector float vvb4;
  float *pva;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pva = va;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  return va;
}
static float *vec_addscNfx_altivec(const float *va, float *vr, float sc,
                                   unsigned int ne)
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
  const float *pva;
  float *pvr;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pva = va;
  pvr = vr;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  return vr;
}
#endif

/* interface */

float *vec_addscNf(float *va, float sc, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE
  return vec_addscNf_sse(va, sc, n);
#endif
#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
  return vec_addscNf_altivec(va, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] += sc;
    return va;
  }
}
float *vec_addscNfx(const float *va, float *vr, float sc, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE
  return vec_addscNfx_sse(va, vr, sc, n);
#endif
#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
  return vec_addscNfx_altivec(va, vr, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] + sc;
    return vr;
  }
}
double *vec_addscNd(double *va, double sc, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
  return vec_addscNd_sse2(va, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] += sc;
    return va;
  }
}
double *vec_addscNdx(const double *va, double *vr, double sc, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
  return vec_addscNdx_sse2(vr, va, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] + sc;
    return vr;
  }
}
