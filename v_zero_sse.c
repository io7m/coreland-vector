#include "v_align.h"
#include "v_zero.h"
#include "v_simd.h"

static inline float *
vec_zeroNf_sse(float *va, unsigned int ne)
{
  __m128 mvz;
  unsigned int seg[3];
  float *pva;
  unsigned int ind;

  pva = va;
  vec_segments(seg, 3, ne);

  mvz = _mm_setzero_ps();
  for (ind = 0; ind < seg[2]; ++ind) {
    _mm_store_ps(pva, mvz);
    _mm_store_ps(pva + 4, mvz);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    _mm_store_ps(pva, mvz);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = 0;

  return va;
}
