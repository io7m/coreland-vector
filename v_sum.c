#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_sum.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_sum.sse"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_sum.sse2"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_sum.alti"
#endif

float
vec_sumNf (const float *va, unsigned int n)
{
  float sum = 0;
#if 0
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_sumNf_sse (va, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_sumNf_altivec (va, n);
#endif
#endif
  vec_SUM (va, sum, n);
  return sum;
}

double
vec_sumNd (const double *va, unsigned int n)
{
  double sum = 0;
#if 0
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned (va) && vec_aligned (vb))
    return vec_sumNd_sse2 (va, n);
#endif
#endif
  vec_SUM (va, sum, n);
  return sum;
}

float
vec_sumNf_aligned (const float *va, unsigned int n)
{
  float sum = 0;
#if 0
#ifdef HAVE_CPU_EXT_SSE
  return vec_sumNf_sse (va, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  return vec_sumNf_altivec (va, n);
#endif
#endif
  vec_SUM (va, sum, n);
  return sum;
}

double
vec_sumNd_aligned (const double *va, unsigned int n)
{
  double sum = 0;
#if 0
#ifdef HAVE_CPU_EXT_SSE2
  return vec_sumNd_sse2 (va, n);
#endif
#endif
  vec_SUM (va, sum, n);
  return sum;
}
