#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_multsc.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_multsc.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_multsc.sse2"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_multsc.alti"
#endif

/* interface */

float *
vec_multscNf (float *va, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va)) return vec_multscNf_sse (va, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va)) return vec_multscNf_altivec (va, sc, n);
#endif
  vec_MULTSC (va, sc, n, float);
  return va;
}

float *
vec_multscNfx (const float *va, float *vr, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_multscNfx_sse (va, vr, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_multscNfx_altivec (va, vr, sc, n);
#endif
  vec_MULTSCX (va, vr, sc, n, float);
  return vr;
}

double *
vec_multscNd (double *va, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va)) return vec_multscNd_sse2 (va, sc, n);
#endif
  vec_MULTSC (va, sc, n, double);
  return va;
}

double *
vec_multscNdx (const double *va, double *vr, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_multscNdx_sse2 (va, vr, sc, n);
#endif
  vec_MULTSCX (va, vr, sc, n, double);
  return vr;
}

float *
vec_multscNf_aligned (float *va, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  return vec_multscNf_sse (va, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_multscNf_altivec (va, sc, n);
#endif
  vec_MULTSC (va, sc, n, float);
  return va;
}

float *
vec_multscNfx_aligned (const float *va, float *vr, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  return vec_multscNfx_sse (va, vr, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_multscNfx_altivec (va, vr, sc, n);
#endif
  vec_MULTSCX (va, vr, sc, n, float);
  return vr;
}

double *
vec_multscNd_aligned (double *va, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  return vec_multscNd_sse2 (va, sc, n);
#endif
  vec_MULTSC (va, sc, n, double);
  return va;
}

double *
vec_multscNdx_aligned (const double *va, double *vr, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  return vec_multscNdx_sse2 (va, vr, sc, n);
#endif
  vec_MULTSCX (va, vr, sc, n, double);
  return vr;
}
