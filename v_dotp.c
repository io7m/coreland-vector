#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_dotp.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_dotp.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_dotp.sse2"
#endif

#ifdef HAVE_CPU_EXT_SSE3
#include "v_dotp.sse3"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_dotp.alti"
#endif

/* interface */

float
vec_dotprodNf (const float *va, const float *vb, unsigned int n)
{
  float f;
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_dotprodNf_sse (va, vb, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_dotprodNf_altivec (va, vb, n);
#endif
  vec_DOTPROD (va, vb, &f, n, float);
  return f;
}

double
vec_dotprodNd (const double *va, const double *vb, unsigned int n)
{
  double d;
/*
Not implemented
#ifdef HAVE_CPU_EXT_SSE3
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_dotprodNd_sse3 (va, vb, n);
#endif
*/
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_dotprodNd_sse2 (va, vb, n);
#endif
  vec_DOTPROD (va, vb, &d, n, double);
  return d;
}

float
vec_dotprodNf_aligned (const float *va, const float *vb, unsigned int n)
{
  float f;
#ifdef HAVE_CPU_EXT_SSE
  return vec_dotprodNf_sse (va, vb, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_dotprodNf_altivec (va, vb, n);
#endif
  vec_DOTPROD (va, vb, &f, n, float);
  return f;
}

double
vec_dotprodNd_aligned (const double *va, const double *vb, unsigned int n)
{
  double d;
/*
Not implemented
#ifdef HAVE_CPU_EXT_SSE3
  return vec_dotprodNd_sse3 (va, vb, n);
#endif
*/
#ifdef HAVE_CPU_EXT_SSE2
  return vec_dotprodNd_sse2 (va, vb, n);
#endif
  vec_DOTPROD (va, vb, &d, n, double);
  return d;
}
