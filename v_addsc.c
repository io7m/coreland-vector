#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_addsc.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_addsc.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_addsc.sse2"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_addsc.alti"
#endif

float *
vec_addscNf (float *va, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va)) return vec_addscNf_sse (va, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va)) return vec_addscNf_altivec (va, sc, n);
#endif
  vec_ADDSC (va, sc, n, float);
  return va;
}

float *
vec_addscNfx (const float *va, float *vr, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_addscNfx_sse (va, vr, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_addscNfx_altivec (va, vr, sc, n);
#endif
  vec_ADDSCX (va, vr, sc, n, float);
  return vr;
}

double *
vec_addscNd (double *va, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va)) return vec_addscNd_sse2 (va, sc, n);
#endif
  vec_ADDSC (va, sc, n, double);
  return va;
}

double *
vec_addscNdx (const double *va, double *vr, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vr))
    return vec_addscNdx_sse2 (va, vr, sc, n);
#endif
  vec_ADDSCX (va, vr, sc, n, double);
  return vr;
}

float *
vec_addscNf_aligned (float *va, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  return vec_addscNf_sse (va, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_addscNf_altivec (va, sc, n);
#endif
  vec_ADDSC (va, sc, n, float);
  return va;
}

float *
vec_addscNfx_aligned (const float *va, float *vr, float sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  return vec_addscNfx_sse (va, vr, sc, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_addscNfx_altivec (va, vr, sc, n);
#endif
  vec_ADDSCX (va, vr, sc, n, float);
  return vr;
}

double *
vec_addscNd_aligned (double *va, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  return vec_addscNd_sse2 (va, sc, n);
#endif
  vec_ADDSC (va, sc, n, double);
  return va;
}

double *
vec_addscNdx_aligned (const double *va, double *vr, double sc, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  return vec_addscNdx_sse2 (va, vr, sc, n);
#endif
  vec_ADDSCX (va, vr, sc, n, double);
  return vr;
}
