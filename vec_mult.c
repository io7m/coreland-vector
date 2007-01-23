#include "vec_mult.h"
#include "vec_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_multNf_sse(float *va, const float *vb, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvb1;
  __m128 mvb2;
  unsigned int seg[3];
  const float *pvb;
  float *pva;
  unsigned int ind;

  pva = va;
  pvb = vb;
  vec_segments(seg, 3, ne);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvb1 = _mm_load_ps(pvb);
    mvb2 = _mm_load_ps(pvb + 4);
    mva1 = _mm_mul_ps(mva1, mvb1);
    mva2 = _mm_mul_ps(mva2, mvb2);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mva1 = _mm_mul_ps(mva1, mvb1);
    _mm_store_ps(pva, mva1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] *= pvb[ind];

  return va;
}
static float *vec_multNfx_sse(const float *va, const float *vb,
                             float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvr;
  unsigned int seg[3];
  const float *pva;
  const float *pvb;
  float *pvr;
  unsigned int ind;

  pva = va;
  pvb = vb;
  pvr = vr;
  vec_segments(seg, 3, ne);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvb1 = _mm_load_ps(pvb);
    mvb2 = _mm_load_ps(pvb + 4);
    mvr = _mm_mul_ps(mva1, mvb1);
    _mm_store_ps(pvr, mvr);
    mvr = _mm_mul_ps(mva2, mvb2);
    _mm_store_ps(pvr + 4, mvr);
    pva += 8;
    pvb += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mvr = _mm_mul_ps(mva1, mvb1);
    _mm_store_ps(pvr, mvr);
    pva += 4;
    pvb += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] * pvb[ind];

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_multNf_altivec(float *va, const float *vb, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vvb1;
  vector float vvb2;
  vector float vvb3;
  vector float vvb4;
  vector float vnz;
  vector unsigned int vui;
  unsigned int seg[4];
  const float *pvb;
  float *pva;
  unsigned int ind;

  /* using a vector of negative zeroes is faster than positive */
  vui = vec_splat_u32(-1);
  vnz = (vector float) vec_sl(vui, vui);
  pva = va;
  pvb = vb;
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vvb3 = vec_ld(0, pvb + 8);
    vvb4 = vec_ld(0, pvb + 12);
    vva1 = vec_madd(vva1, vvb1, vnz);
    vva2 = vec_madd(vva2, vvb2, vnz);
    vva3 = vec_madd(vva3, vvb3, vnz);
    vva4 = vec_madd(vva4, vvb4, vnz); 
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    vec_st(vva3, 0, pva + 8);
    vec_st(vva4, 0, pva + 12);
    pva += 16;
    pvb += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vva1 = vec_madd(vva1, vvb1, vnz);
    vva2 = vec_madd(vva2, vvb2, vnz);
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1 = vec_ld(0, pva);
    vvb1 = vec_ld(0, pvb);
    vva1 = vec_madd(vva1, vvb1, vnz);
    vec_st(vva1, 0, pva);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] *= pvb[ind];

  return va;
}
static float *vec_multNfx_altivec(const float *va, const float *vb,
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
  vector float vnz;
  vector unsigned int vui;
  unsigned int seg[4];
  const float *pvb;
  const float *pva;
  float *pvr;
  unsigned int ind;

  /* using a vector of negative zeroes is faster than positive */
  vui = vec_splat_u32(-1);
  vnz = (vector float) vec_sl(vui, vui);
  pva = va;
  pvb = vb;
  pvr = vr;
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vvb3 = vec_ld(0, pvb + 8);
    vvb4 = vec_ld(0, pvb + 12);
    vvr = vec_madd(vva1, vvb1, vnz);
    vec_st(vvr, 0, pvr);
    vvr = vec_madd(vva2, vvb2, vnz);
    vec_st(vvr, 0, pvr + 4);
    vvr = vec_madd(vva3, vvb3, vnz);
    vec_st(vvr, 0, pvr + 8);
    vvr = vec_madd(vva4, vvb4, vnz);
    vec_st(vvr, 0, pvr + 12);
    pva += 16;
    pvb += 16;
    pvr += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vvr = vec_madd(vva1, vvb1, vnz);
    vec_st(vvr, 0, pvr);
    vvr = vec_madd(vva2, vvb2, vnz);
    vec_st(vvr, 0, pvr + 4);
    pva += 8;
    pvb += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1 = vec_ld(0, pva);
    vvb1 = vec_ld(0, pvb);
    vvr = vec_madd(vva1, vvb1, vnz);
    vec_st(vvr, 0, pvr);
    pva += 4;
    pvb += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] * pvb[ind];

  return vr;
}
#endif

/* interface */

float *vec_multNf(float *va, const float *vb, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_multNf_sse(va, vb, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_multNf_altivec(va, vb, n);
#endif
  vec_MULT(va, vb, n, float);
  return va;
}
float *vec_multNfx(const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb) && !vec_unaligned(vr))
    return vec_multNfx_sse(va, vb, vr, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb) && !vec_unaligned(vr))
    return vec_multNfx_altivec(va, vb, vr, n);
#endif
  vec_MULTX(va, vb, vr, n, float);
  return vr;
}
double *vec_multNd(double *va, const double *vb, unsigned int n)
{
  vec_MULT(va, vb, n, double);
  return va;
}
double *vec_multNdx(const double *va, const double *vb, double *vr, unsigned int n)
{
  vec_MULTX(va, vb, vr, n, double);
  return vr;
}
