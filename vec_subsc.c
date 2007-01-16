#include "sysinfo.h"
#include "vec_subsc.h"
#include "vec_simd.h"
#include "vec_types.h"

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
static double *vec_subscNdx_sse2(const double *va, double *vr, double sc,
                                 unsigned int ne)
{
  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_subscNf_altivec(float *va, float sc, unsigned int ne)
{
  vector_4f vs;
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  float *pva;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pva = va;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  vs.f[0] = sc;
  vs.v = vec_splat(vs.v, 0);

  for (ind = 0; ind < d16; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vva1 = vec_sub(vva1, vs.v);
    vva2 = vec_sub(vva2, vs.v);
    vva3 = vec_sub(vva3, vs.v);
    vva4 = vec_sub(vva4, vs.v); 
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    vec_st(vva3, 0, pva + 8);
    vec_st(vva4, 0, pva + 12);
    pva += 16;
  }
  for (ind = 0; ind < d8; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva1 = vec_sub(vva1, vs.v);
    vva2 = vec_sub(vva2, vs.v);
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    pva += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    vva1 = vec_ld(0, pva);
    vva1 = vec_sub(vva1, vs.v);
    vec_st(vva1, 0, pva);
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] -= sc;

  return va;
}
static float *vec_subscNfx_altivec(const float *va, float *vr, float sc,
                                   unsigned int ne)
{
  union align16v vs;
  vector float vvr1;
  vector float vvr2;
  vector float vvr3;
  vector float vvr4;
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

  vs.f[0] = sc;
  vs.v = vec_splat(vs.v, 0);

  for (ind = 0; ind < d16; ++ind) {
    vvr1 = vec_ld(0, pva); 
    vvr2 = vec_ld(0, pva + 4);
    vvr3 = vec_ld(0, pva + 8);
    vvr4 = vec_ld(0, pva + 12);
    vvr1 = vec_sub(vvr1, vs.v);
    vvr2 = vec_sub(vvr2, vs.v);
    vvr3 = vec_sub(vvr3, vs.v);
    vvr4 = vec_sub(vvr4, vs.v);
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    vec_st(vvr3, 0, pvr + 8);
    vec_st(vvr4, 0, pvr + 12);
    pvr += 16;
    pva += 16;
  }
  for (ind = 0; ind < d8; ++ind) {
    vvr1 = vec_ld(0, pva);
    vvr2 = vec_ld(0, pva + 4);
    vvr1 = vec_sub(vvr1, vs.v);
    vvr2 = vec_sub(vvr2, vs.v);
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    pvr += 8;
    pva += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    vvr1 = vec_ld(0, pva);
    vvr1 = vec_sub(vvr1, vs.v);
    vec_st(vvr1, 0, pvr);
    pvr += 4;
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pvr[ind] = pva[ind] - sc;

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
  if (!vec_unaligned(va)) return vec_subscNdx_sse2(va, vr, sc, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] - sc;
    return vr;
  }
}
