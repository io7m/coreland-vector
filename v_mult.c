#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_mult.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_mult.sse"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_mult.alti"
#endif

/* interface */

float *
vec_multNf (float *va, const float *vb, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_multNf_sse (va, vb, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_multNf_altivec (va, vb, n);
#endif
  vec_MULT (va, vb, n, float);
  return va;
}

float *
vec_multNfx (const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vb) && vec_aligned (vr))
    return vec_multNfx_sse (va, vb, vr, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vb) && vec_aligned (vr))
    return vec_multNfx_altivec (va, vb, vr, n);
#endif
  vec_MULTX (va, vb, vr, n, float);
  return vr;
}

double *
vec_multNd (double *va, const double *vb, unsigned int n)
{
  vec_MULT (va, vb, n, double);
  return va;
}

double *
vec_multNdx (const double *va, const double *vb, double *vr, unsigned int n)
{
  vec_MULTX (va, vb, vr, n, double);
  return vr;
}
