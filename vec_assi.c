#include "sysinfo.h"
#include "vector.h"
#include "vec_assi.h"
#include "vec_simd.h"

#ifdef SYSINFO_HAVE_CPU_EXT_SSE
static float *vec_assignNf_sse(float *va, const float *vb, unsigned int ne)
{
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
    mvb1 = _mm_load_ps(pvb);
    mvb2 = _mm_load_ps(pvb + 4);
    _mm_store_ps(pva, mvb1);
    _mm_store_ps(pva + 4, mvb2);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    mvb1 = _mm_load_ps(pvb);
    _mm_store_ps(pva, mvb1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] = pvb[ind];

  return va;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
static double *vec_assignNd_sse2(double *va, const double *vb, unsigned int n)
{
  return va;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
static float *vec_assignNf_altivec(float *va, const float *vb, unsigned int ne)
{
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

  for (ind = 0; ind < d16; ++ind) {
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vvb3 = vec_ld(0, pvb + 8);
    vvb4 = vec_ld(0, pvb + 12);
    vec_st(vvb1, 0, pva);
    vec_st(vvb2, 0, pva + 4);
    vec_st(vvb3, 0, pva + 8);
    vec_st(vvb4, 0, pva + 12);
    pva += 16;
    pvb += 16;
  }
  for (ind = 0; ind < d8; ++ind) {
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vec_st(vvb1, 0, pva);
    vec_st(vvb2, 0, pva + 4);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    vvb1 = vec_ld(0, pvb);
    vec_st(vvb1, 0, pva);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] = pvb[ind];

  return va;
}
#endif

/* interface */

float *vec_assignNf(float *va, const float *vb, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_assignNf_sse(va, vb, n);
#endif
#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_assignNf_altivec(va, vb, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = vb[ind];
    return va;
  }
}
double *vec_assignNd(double *va, const double *vb, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_assignNd_sse2(va, vb, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = vb[ind];
    return va;
  }
}
