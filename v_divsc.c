#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_divsc.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_divsc.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_divsc.sse2"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_divsc.alti"
#endif

/* interface */

float *
vec_divscNf (float *va, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va)) return vec_divscNf_sse (va, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va)) return vec_divscNf_altivec (va, sc, n);
#endif
  vec_DIVSC (va, sc, n, float);
  return va;
}

float *
vec_divscNfx (const float *va, float *vr, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_divscNfx_sse (va, vr, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_divscNfx_altivec (va, vr, sc, n);
#endif
  vec_DIVSCX (va, vr, sc, n, float);
  return vr;
}

double *
vec_divscNd (double *va, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va)) return vec_divscNd_sse2 (va, sc, n);
#endif
  vec_DIVSC (va, sc, n, double);
  return va;
}

double *
vec_divscNdx (const double *va, double *vr, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_divscNdx_sse2 (va, vr, sc, n);
#endif
  vec_DIVSCX (va, vr, sc, n, double);
  return vr;
}
