#include "v_align.h"
#include "v_mult.h"
#include "v_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
#include "v_mult_sse.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
#include "v_mult_alti.c"
#endif

/* interface */

float *
vec_multNf(float *va, const float *vb, unsigned int n)
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

float *
vec_multNfx(const float *va, const float *vb, float *vr, unsigned int n)
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

double *
vec_multNd(double *va, const double *vb, unsigned int n)
{
  vec_MULT(va, vb, n, double);
  return va;
}

double *
vec_multNdx(const double *va, const double *vb, double *vr, unsigned int n)
{
  vec_MULTX(va, vb, vr, n, double);
  return vr;
}
