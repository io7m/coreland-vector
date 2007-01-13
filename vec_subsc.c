#include "sysinfo.h"
#include "vec_subsc.h"
#include "vec_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_subscNf_sse(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
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
    mva1 = _mm_sub_ps(mva1, vsc);
    mva2 = _mm_sub_ps(mva2, vsc);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 4;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_sub_ps(mva1, vsc);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] -= sc;

  return va;
}
static float *vec_subscNfx_sse(const float *va, float *vr, float sc,
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
    mvr1 = _mm_sub_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    mva2 = _mm_sub_ps(mva2, vsc);
    _mm_store_ps(pvr + 4, mvr1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < d4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvr1 = _mm_sub_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pvr[ind] = pva[ind] - sc;

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double *vec_subscNd_sse2(double *va, double sc, unsigned int ne)
{
  return va;
}
static double *vec_subscNdx_sse2(const double *vr, double *va, double sc,
                                 unsigned int ne)
{
  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_subscNf_altivec(float *va, float sc, unsigned int ne)
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
static float *vec_subscNfx_altivec(const float *va, float *vr, float sc,
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

float *vec_subscNf(float *va, float sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va)) return vec_subscNf_sse(va, sc, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va)) return vec_subscNf_altivec(va, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] -= sc;
    return va;
  }
}
float *vec_subscNfx(const float *va, float *vr, float sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va)) return vec_subscNfx_sse(va, vr, sc, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va)) return vec_subscNfx_altivec(va, vr, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] - sc;
    return vr;
  }
}
double *vec_subscNd(double *va, double sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va)) return vec_subscNd_sse2(va, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] -= sc;
    return va;
  }
}
double *vec_subscNdx(const double *va, double *vr, double sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va)) return vec_subscNdx_sse2(vr, va, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] - sc;
    return vr;
  }
}
