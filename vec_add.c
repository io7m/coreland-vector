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
static float *vec_addNf_altivec(float *va, const float *vb, unsigned int n)
{
  union aligned4f ava;
  union aligned4f avb;
  float *ova;
  unsigned int max;
  unsigned int rem;
  unsigned int ind;

  ova = va;
  max = n >> 2;
  rem = n - (max * 4);

  for (ind = 0; ind < max; ++ind) {
    memcpy(ava.f, va, 4 * sizeof(float));
    memcpy(avb.f, vb, 4 * sizeof(float));
    ava.v = vec_add(ava.v, avb.v);
    memcpy(va, ava.f, 4 * sizeof(float));
    va += 4;
    vb += 4;
  }
  if (rem) {
    memcpy(ava.f, va, rem * sizeof(float));
    memcpy(avb.f, vb, rem * sizeof(float));
    ava.v = vec_add(ava.v, avb.v);
    memcpy(va, ava.f, rem * sizeof(float));
  }
  return ova;
}
static float *vec_addNfx_altivec(const float *va, const float *vb,
                                 float *vr, unsigned int n)
{
  union aligned4f ava;
  union aligned4f avb;
  float *ovr;
  unsigned int max;
  unsigned int rem;
  unsigned int ind;

  ovr = vr;
  max = n >> 2;
  rem = n - (max * 4);

  for (ind = 0; ind < max; ++ind) {
    memcpy(ava.f, va, 4 * sizeof(float));
    memcpy(avb.f, vb, 4 * sizeof(float));
    ava.v = vec_add(ava.v, avb.v);
    memcpy(vr, ava.f, 4 * sizeof(float));
    va += 4;
    vb += 4;
    vr += 4;
  }
  if (rem) {
    memcpy(ava.f, va, rem * sizeof(float));
    memcpy(avb.f, vb, rem * sizeof(float));
    ava.v = vec_add(ava.v, avb.v);
    memcpy(vr, ava.f, 4 * sizeof(float));
  }
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
