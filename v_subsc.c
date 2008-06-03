#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_subsc.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_subsc.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_subsc.sse2"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_subsc.alti"
#endif

/* interface */

float *
vec_subscNf (float *va, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va)) return vec_subscNf_sse (va, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va)) return vec_subscNf_altivec (va, sc, n);
#endif
  vec_SUBSC (va, sc, n, float);
  return va;
}

float *
vec_subscNfx (const float *va, float *vr, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_subscNfx_sse (va, vr, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_subscNfx_altivec (va, vr, sc, n);
#endif
  vec_SUBSCX (va, vr, sc, n, float);
  return vr;
}

double *
vec_subscNd (double *va, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va)) return vec_subscNd_sse2 (va, sc, n);
#endif
  vec_SUBSC (va, sc, n, double);
  return va;
}

double *
vec_subscNdx (const double *va, double *vr, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_subscNdx_sse2 (va, vr, sc, n);
#endif
  vec_SUBSCX (va, vr, sc, n, double);
  return vr;
}
