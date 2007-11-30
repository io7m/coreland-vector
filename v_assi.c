#include "v_assi.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

#ifdef HAVE_CPU_EXT_SSE
#include "v_assi_sse.c"
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include "v_assi_sse2.c"
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
#include "v_assi_alti.c"
#endif

float *
vec_assignNf(float *va, const float *vb, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE
  if (vec_aligned(va) && vec_aligned(vb))
    return vec_assignNf_sse(va, vb, n);
#endif
#ifdef HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned(va) && vec_aligned(vb))
    return vec_assignNf_altivec(va, vb, n);
#endif
  vec_ASSIGN(va, vb, n, float);
  return va;
}

double *
vec_assignNd(double *va, const double *vb, unsigned int n)
{
#ifdef HAVE_CPU_EXT_SSE2
  if (vec_aligned(va) && vec_aligned(vb))
    return vec_assignNd_sse2(va, vb, n);
#endif
  vec_ASSIGN(va, vb, n, double);
  return va;
}
