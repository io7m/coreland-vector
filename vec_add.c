#include "sysinfo.h"
#include "vector.h"
#include "vec_add.h"
#include "vec_simd.h"

#ifdef SYSINFO_HAVE_CPU_EXT_SSE
#include <xmmintrin.h>

static float *vec_addNf_sse(float *va, const float *vb, unsigned int n)
{
  __m128 mva;
  __m128 mvb;
  float *ova;
  unsigned int max;
  unsigned int rem;
  unsigned int ind;

  ova = va;
  max = n >> 2;
  rem = n - (max * 4);

  for (ind = 0; ind < max; ++ind) {
    mva = _mm_loadu_ps(va);
    mvb = _mm_loadu_ps(vb);
    mva = _mm_add_ps(mva, mvb);
    _mm_storeu_ps(va, mva);
    va += 4;
    vb += 4;
  }
  for (ind = 0; ind < rem; ++ind)
    va[ind] += vb[ind];

  return ova;
}
static float *vec_addNfx_sse(const float *va, const float *vb,
                             float *vr, unsigned int n)
{
  __m128 mva;
  __m128 mvb;
  float *ovr;
  unsigned int max;
  unsigned int rem;
  unsigned int ind;

  ovr = vr;
  max = n >> 2;
  rem = n - (max * 4);

  for (ind = 0; ind < max; ++ind) {
    mva = _mm_loadu_ps(va);
    mvb = _mm_loadu_ps(vb);
    mva = _mm_add_ps(mva, mvb);
    _mm_storeu_ps(vr, mva);
    va += 4;
    vb += 4;
    vr += 4;
  }
  for (ind = 0; ind < rem; ++ind)
    vr[ind] = va[ind] + vb[ind];

  return ovr;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
#include <xmmintrin.h>

static double *vec_addNd_sse2(double *va, const double *vb, unsigned int n)
{
  return va;
}
static double *vec_addNdx_sse2(const double *va, const double *vb,
                               double *vr, unsigned int n)
{
  return vr;
}
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
static void vsizes(unsigned int *pd16, unsigned int *pd8,
                   unsigned int *pd4,  unsigned int *pdr, unsigned int ne)
{
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  
  d16 = ne >> 4; ne -= d16 << 4;
  d8 = ne >> 3; ne -= d8 << 3;
  d4 = ne >> 2; ne -= d4 << 2;
  dr = ne;

  *pd16 = d16; *pd8 = d8; *pd4 = d4; *pdr = dr;
}
static float *vec_addNf_altivec(float *va, const float *vb, unsigned int ne)
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

  vsizes(&d16, &d8, &d4, &dr, ne);

  for (ind = 0; ind < d16; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vvb3 = vec_ld(0, pvb + 8);
    vvb4 = vec_ld(0, pvb + 12);
    vva1 = vec_add(vva1, vvb1);
    vva2 = vec_add(vva2, vvb2);
    vva3 = vec_add(vva3, vvb3);
    vva4 = vec_add(vva4, vvb4); 
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    vec_st(vva3, 0, pva + 8);
    vec_st(vva4, 0, pva + 12);
    pva += 16;
    pvb += 16;
  }

  for (ind = 0; ind < d8; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vva1 = vec_add(vva1, vvb1);
    vva2 = vec_add(vva2, vvb2);
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    pva += 8;
    pvb += 8;
  }

  for (ind = 0; ind < d4; ++ind) {
    vva1 = vec_ld(0, pva);
    vvb1 = vec_ld(0, pvb);
    vva1 = vec_add(vva1, vvb1);
    vec_st(vva1, 0, pva);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] += pvb[ind];

  return va;
}
static float *vec_addNfx_altivec(const float *va, const float *vb,
                                 float *vr, unsigned int n)
{
  vector float vva;
  vector float vvb;
  float *ovr;
  unsigned int max;
  unsigned int rem;
  unsigned int ind;

  return ovr;
}
#endif

/* interface */

float *vec_addNf(float *va, const float *vb, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE
  return vec_addNf_sse(va, vb, n);
#endif
#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
  return vec_addNf_altivec(va, vb, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] += vb[ind];
    return va;
  }
}
float *vec_addNfx(const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE
  return vec_addNfx_sse(va, vb, vr, n);
#endif
#ifdef SYSINFO_HAVE_CPU_EXT_ALTIVEC
  return vec_addNfx_altivec(va, vb, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] + vb[ind];
    return vr;
  }
}
double *vec_addNd(double *va, const double *vb, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
  return vec_addNd_sse2(va, vb, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] += vb[ind];
    return va;
  }
}
double *vec_addNdx(const double *va, const double *vb, double *vr, unsigned int n)
{
#ifdef SYSINFO_HAVE_CPU_EXT_SSE2
  return vec_addNdx_sse2(va, vb, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] + vb[ind];
    return vr;
  }
}
