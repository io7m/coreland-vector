#include "v_align.h"
#include "v_zero.h"
#include "v_simd.h"

#ifdef HAVE_CPU_EXT_SSE2

static inline double *
vec_zeroNd_sse2(double *va, unsigned int ne)
{
  __m128d mvz;
  unsigned int seg[2];
  double *pva;
  unsigned int ind;

  pva = va;
  mvz = _mm_setzero_pd();
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    _mm_store_pd(pva, mvz);
    _mm_store_pd(pva + 2, mvz);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = 0;

  return va;
}

#endif
