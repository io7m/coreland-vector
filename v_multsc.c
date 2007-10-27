#include "v_align.h"
#include "v_multsc.h"
#include "v_simd.h"
#include "v_types.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_multscNf_sse(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 vsc;
  unsigned int seg[3];
  float *pva;
  unsigned int ind;

  vec_segments(seg, 3, ne);
  pva = va;
  vsc = _mm_set1_ps(sc);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_mul_ps(mva1, vsc);
    mva2 = _mm_mul_ps(mva2, vsc);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_mul_ps(mva1, vsc);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] *= sc;

  return va;
}
static float *vec_multscNfx_sse(const float *va, float *vr, float sc,
                                unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvr1;
  __m128 vsc;
  unsigned int seg[3];
  const float *pva;
  float *pvr;
  unsigned int ind;

  vec_segments(seg, 3, ne);
  pva = va;
  pvr = vr;
  vsc = _mm_set1_ps(sc);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvr1 = _mm_mul_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    mvr1 = _mm_mul_ps(mva2, vsc);
    _mm_store_ps(pvr + 4, mvr1);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvr1 = _mm_mul_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] * sc;

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double *vec_multscNd_sse2(double *va, double sc, unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d vsc;
  unsigned int seg[2];
  double *pva;
  unsigned int ind;

  vsc = _mm_set1_pd(sc);
  pva = va;
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mva1 = _mm_mul_pd(mva1, vsc);
    mva2 = _mm_mul_pd(mva2, vsc);
    _mm_store_pd(pva, mva1);
    _mm_store_pd(pva + 2, mva2);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] *= sc;

  return va;
}
static double *vec_multscNdx_sse2(const double *va, double *vr, double sc,
                                  unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d mvr;
  __m128d vsc;
  unsigned int seg[2];
  const double *pva;
  double *pvr;
  unsigned int ind;

  pva = va;
  pvr = vr;
  vsc = _mm_set1_pd(sc);
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mvr = _mm_mul_pd(mva1, vsc);
    _mm_store_pd(pvr, mvr);
    mvr = _mm_mul_pd(mva2, vsc);
    _mm_store_pd(pvr + 2, mvr);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] * sc;

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_multscNf_altivec(float *va, float sc, unsigned int ne)
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
  unsigned int ind;

  pva = va;
  vec_segments(seg, 4, ne);

  /* using a vector of negative zeroes is faster than positive */
  vui = vec_splat_u32(-1);
  vnz = (vector float) vec_sl(vui, vui);
  vs.f[0] = sc;
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
    pva[ind] *= sc;

  return va;
}
static float *vec_multscNfx_altivec(const float *va, float *vr, float sc,
                                   unsigned int ne)
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
  unsigned int ind;

  /* using a vector of negative zeroes is faster than positive */
  vui = vec_splat_u32(-1);
  vnz = (vector float) vec_sl(vui, vui);
  pva = va;
  pvr = vr;
  vs.f[0] = sc;
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
    pvr[ind] = pva[ind] * sc;

  return vr;
}
#endif

/* interface */

float *vec_multscNf(float *va, float sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va)) return vec_multscNf_sse(va, sc, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va)) return vec_multscNf_altivec(va, sc, n);
#endif
  vec_MULTSC(va, sc, n, float);
  return va;
}
float *vec_multscNfx(const float *va, float *vr, float sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_multscNfx_sse(va, vr, sc, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_multscNfx_altivec(va, vr, sc, n);
#endif
  vec_MULTSCX(va, vr, sc, n, float);
  return vr;
}
double *vec_multscNd(double *va, double sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va)) return vec_multscNd_sse2(va, sc, n);
#endif
  vec_MULTSC(va, sc, n, double);
  return va;
}
double *vec_multscNdx(const double *va, double *vr, double sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_multscNdx_sse2(va, vr, sc, n);
#endif
  vec_MULTSCX(va, vr, sc, n, double);
  return vr;
}