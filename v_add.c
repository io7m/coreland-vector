#include "v_add.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
#include "v_add_sse.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
#include "v_add_sse2.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
#include "v_add_alti.c"
#endif

float *
vec_addNf(float *va, const float *vb, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_addNf_sse(va, vb, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_addNf_altivec(va, vb, n);
#endif
  vec_ADD(va, vb, n, float);
  return va;
}

float *
vec_addNfx(const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb) && !vec_unaligned(vr))
    return vec_addNfx_sse(va, vb, vr, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb) && !vec_unaligned(vr))
    return vec_addNfx_altivec(va, vb, vr, n);
#endif
  vec_ADDX(va, vb, vr, n, float);
  return vr;
}

double *
vec_addNd(double *va, const double *vb, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_addNd_sse2(va, vb, n);
#endif
  vec_ADD(va, vb, n, double);
  return va;
}

double *
vec_addNdx(const double *va, const double *vb, double *vr, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vb) && !vec_unaligned(vr))
    return vec_addNdx_sse2(va, vb, vr, n);
#endif
  vec_ADDX(va, vb, vr, n, double);
  return vr;
}
