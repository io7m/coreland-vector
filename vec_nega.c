#include "vec_nega.h"
#include "vec_simd.h"
#include "vec_types.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_negaNf_sse(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvz;
  unsigned int seg[3];
  float *pva;
  unsigned int ind;

  mvz = _mm_setzero_ps();
  pva = va;
  vec_segments(seg, 3, ne);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_sub_ps(mvz, mva1);
    mva2 = _mm_sub_ps(mvz, mva2);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = -pva[ind];

  return va;
}
static float *vec_negaNfx_sse(const float *va, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvz;
  __m128 mvr;
  unsigned int seg[3];
  const float *pva;
  float *pvr;
  unsigned int ind;

  mvz = _mm_setzero_ps();
  pva = va;
  pvr = vr;
  vec_segments(seg, 3, ne);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvr = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pvr, mvr);
    mvr = _mm_sub_ps(mvz, mva2);
    _mm_store_ps(pvr + 4, mvr);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvr = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pvr, mvr);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = -pva[ind];

  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double *vec_negaNd_sse2(double *va, unsigned int ne)
{
  return va;
}
static double *vec_negaNdx_sse2(const double *va, double *vr, unsigned int ne)
{
  return vr;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_negaNf_altivec(float *va, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vz;
  float *pva;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  vz = vec_ctf(vec_splat_u32(0), 0);
  pva = va;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  for (ind = 0; ind < d16; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vva1 = vec_sub(vz, vva1);
    vva2 = vec_sub(vz, vva2);
    vva3 = vec_sub(vz, vva3);
    vva4 = vec_sub(vz, vva4); 
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    vec_st(vva3, 0, pva + 8);
    vec_st(vva4, 0, pva + 12);
    pva += 16;
  }
  for (ind = 0; ind < d8; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva1 = vec_sub(vz, vva1);
    vva2 = vec_sub(vz, vva2);
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    pva += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    vva1 = vec_ld(0, pva);
    vva1 = vec_sub(vz, vva1);
    vec_st(vva1, 0, pva);
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] = -pva[ind];

  return va;
}
static float *vec_negaNfx_altivec(const float *va, float *vr, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vvr;
  vector float vz;
  const float *pva;
  float *pvr;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  vz = vec_ctf(vec_splat_u32(0), 0);
  pva = va;
  pvr = vr;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  for (ind = 0; ind < d16; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vvr = vec_sub(vz, vva1);
    vec_st(vvr, 0, pvr);
    vvr = vec_sub(vz, vva2);
    vec_st(vvr, 0, pvr + 4);
    vvr = vec_sub(vz, vva3);
    vec_st(vvr, 0, pvr + 8);
    vvr = vec_sub(vz, vva4); 
    vec_st(vvr, 0, pvr + 12);
    pva += 16;
    pvr += 16;
  }
  for (ind = 0; ind < d8; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vvr = vec_sub(vz, vva1);
    vec_st(vvr, 0, pvr);
    vvr = vec_sub(vz, vva2);
    vec_st(vvr, 0, pvr + 4);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    vva1 = vec_ld(0, pva);
    vvr = vec_sub(vz, vva1);
    vec_st(vvr, 0, pvr);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pvr[ind] = -pva[ind];

  return vr;
}
#endif

/* interface */

float *vec_negaNf(float *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va)) return vec_negaNf_sse(va, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va)) return vec_negaNf_altivec(va, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = -va[ind];
    return va;
  }
}
float *vec_negaNfx(const float *va, float *vr, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_negaNfx_sse(va, vr, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_negaNfx_altivec(va, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = -va[ind];
    return vr;
  }
}
double *vec_negaNd(double *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va)) return vec_negaNd_sse2(va, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = -va[ind];
    return va;
  }
}
double *vec_negaNdx(const double *va, double *vr, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_negaNdx_sse2(va, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = -va[ind];
    return vr;
  }
}
