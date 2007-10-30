#include "v_align.h"
#include "v_nega.h"
#include "v_simd.h"
#include "v_types.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
#include "v_nega_sse.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
#include "v_nega_sse2.c"
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
#include "v_nega_alti.c"
#endif

/* interface */

float *
vec_negaNf(float *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (vec_aligned(va)) return vec_negaNf_sse(va, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned(va)) return vec_negaNf_altivec(va, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = -va[ind];
    return va;
  }
}

float *
vec_negaNfx(const float *va, float *vr, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (vec_aligned(va) && vec_aligned(vr))
    return vec_negaNfx_sse(va, vr, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (vec_aligned(va) && vec_aligned(vr))
    return vec_negaNfx_altivec(va, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = -va[ind];
    return vr;
  }
}

double *
vec_negaNd(double *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (vec_aligned(va)) return vec_negaNd_sse2(va, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = -va[ind];
    return va;
  }
}

double *
vec_negaNdx(const double *va, double *vr, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (vec_aligned(va) && vec_aligned(vr))
    return vec_negaNdx_sse2(va, vr, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = -va[ind];
    return vr;
  }
}
