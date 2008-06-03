#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_abs.h"
#include "v_math.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_abs.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_abs.sse2"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_abs.alti"
#endif

float *
vec_absNf (float *va, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va)) return vec_absNf_sse (va, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va)) return vec_absNf_altivec (va, n);
#endif
  vec_ABS (va, n, float, fabsf);
  return va;
}

float *
vec_absNfx (const float *va, float *vr, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vr)) return vec_absNfx_sse (va, vr, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vr)) return vec_absNfx_altivec (va, vr, n);
#endif
  vec_ABSX (va, vr, n, float, fabsf);
  return vr;
}

double *
vec_absNd (double *va, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va)) return vec_absNd_sse2 (va, n);
#endif
  vec_ABS (va, n, double, fabs);
  return va;
}

double *
vec_absNdx (const double *va, double *vr, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vr)) return vec_absNdx_sse2 (va, vr, n);
#endif
  vec_ABSX (va, vr, n, double, fabs);
  return vr;
}
