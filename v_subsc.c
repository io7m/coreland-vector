#include "v_align.h"
#include "v_subsc.h"
#include "v_simd.h"
#include "v_types.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
#include "v_subsc_sse.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
#include "v_subsc_sse2.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
#include "v_subsc_alti.c"
#endif

/* interface */

float *
vec_subscNf(float *va, float sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va)) return vec_subscNf_sse(va, sc, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va)) return vec_subscNf_altivec(va, sc, n);
#endif
  vec_SUBSC(va, sc, n, float);
  return va;
}

float *
vec_subscNfx(const float *va, float *vr, float sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_subscNfx_sse(va, vr, sc, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_subscNfx_altivec(va, vr, sc, n);
#endif
  vec_SUBSCX(va, vr, sc, n, float);
  return vr;
}

double *
vec_subscNd(double *va, double sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va)) return vec_subscNd_sse2(va, sc, n);
#endif
  vec_SUBSC(va, sc, n, double);
  return va;
}

double *
vec_subscNdx(const double *va, double *vr, double sc, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vr))
    return vec_subscNdx_sse2(va, vr, sc, n);
#endif
  vec_SUBSCX(va, vr, sc, n, double);
  return vr;
}
