#include "v_align.h"
#include "v_zero.h"
#include "v_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
#include "v_zero_sse.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
#include "v_zero_sse2.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
#include "v_zero_alti.c"
#endif

/* interface */

float *
vec_zeroNf(float *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (vec_aligned(va)) return vec_zeroNf_sse(va, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned(va)) return vec_zeroNf_altivec(va, n);
#endif
  vec_ZERO(va, n, float);
  return va;
}

double *
vec_zeroNd(double *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (vec_aligned(va)) return vec_zeroNd_sse2(va, n);
#endif
  vec_ZERO(va, n, double);
  return va;
}
