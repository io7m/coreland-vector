#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_sub.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_sub.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_sub.sse2"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_sub.alti"
#endif

/* interface */

float *
vec_subNf (float *va, const float *vb, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_subNf_sse (va, vb, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_subNf_altivec (va, vb, n);
#endif
  vec_SUB (va, vb, n, float);
  return va;
}

float *
vec_subNfx (const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vb) && vec_aligned (vr))
    return vec_subNfx_sse (va, vb, vr, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vb) && vec_aligned (vr))
    return vec_subNfx_altivec (va, vb, vr, n);
#endif
  vec_SUBX (va, vb, vr, n, float);
  return vr;
}

double *
vec_subNd (double *va, const double *vb, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_subNd_sse2 (va, vb, n);
#endif
  vec_SUB (va, vb, n, double);
  return va;
}

double *
vec_subNdx (const double *va, const double *vb, double *vr, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vb) && vec_aligned (vr))
    return vec_subNdx_sse2 (va, vb, vr, n);
#endif
  vec_SUBX (va, vb, vr, n, double);
  return vr;
}

float *
vec_subNf_aligned (float *va, const float *vb, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  return vec_subNf_sse (va, vb, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_subNf_altivec (va, vb, n);
#endif
  vec_SUB (va, vb, n, float);
  return va;
}

float *
vec_subNfx_aligned (const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  return vec_subNfx_sse (va, vb, vr, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_subNfx_altivec (va, vb, vr, n);
#endif
  vec_SUBX (va, vb, vr, n, float);
  return vr;
}

double *
vec_subNd_aligned (double *va, const double *vb, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  return vec_subNd_sse2 (va, vb, n);
#endif
  vec_SUB (va, vb, n, double);
  return va;
}

double *
vec_subNdx_aligned (const double *va, const double *vb, double *vr, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  return vec_subNdx_sse2 (va, vb, vr, n);
#endif
  vec_SUBX (va, vb, vr, n, double);
  return vr;
}

