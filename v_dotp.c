#include "v_align.h"
#include "v_dotp.h"

#include "v_simd.h"
#include "v_types.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_dotp_sse.c"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_dotp_sse2.c"
#endif

#ifdef HAVE_CPU_EXT_SSE3
#include "v_dotp_sse3.c"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_dotp_alti.c"
#endif

/* interface */

float
vec_dotprodNf(const float *va, const float *vb, unsigned int n)
{
  float f;
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned(va) && vec_aligned(vb))
    return vec_dotprodNf_sse(va, vb, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned(va) && vec_aligned(vb))
    return vec_dotprodNf_altivec(va, vb, n);
#endif
  vec_DOTPROD(va, vb, &f, n, float);
  return f;
}

double
vec_dotprodNd(const double *va, const double *vb, unsigned int n)
{
  double d;
/*
Not implemented
#ifdef HAVE_CPU_EXT_SSE3
  if (vec_aligned(va) && vec_aligned(vb))
    return vec_dotprodNd_sse3(va, vb, n);
#endif
*/
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned(va) && vec_aligned(vb))
    return vec_dotprodNd_sse2(va, vb, n);
#endif
  vec_DOTPROD(va, vb, &d, n, double);
  return d;
}
