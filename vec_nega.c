
#include "sysinfo.h"
#include "vec_nega.h"
#include "vec_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_negaNf_sse(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvb1;
  __m128 mvb2;
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
static float *vec_negaNfx_sse(const float *va, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvr;
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

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double *vec_negaNd_sse2(const double *va, double *vr, unsigned int ne)
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
static float *vec_negaNfx_altivec(const float *va, float *vr, unsigned int ne)
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
  pvr = vr;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  return vr;
}
#endif

/* interface */

float *vec_negaNf(float *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va))
    return vec_negaNf_sse(va, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va))
    return vec_negaNf_altivec(va, n);
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
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_negaNd_sse2(va, n);
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
