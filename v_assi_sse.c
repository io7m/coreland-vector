#include "v_assi.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline float *
vec_assignNf_sse(float *va, const float *vb, unsigned int ne)
{
  __m128 mvb1;
  unsigned int seg[5];
  const float *pvb;
  float *pva;
  unsigned int ind;

  pva = va;
  pvb = vb;
  vec_segments(seg, 5, ne);

  for (ind = 0; ind < seg[4]; ++ind) {
    mvb1 = _mm_load_ps(pvb);
    _mm_store_ps(pva, mvb1);
    mvb1 = _mm_load_ps(pvb + 4);
    _mm_store_ps(pva + 4, mvb1);
    mvb1 = _mm_load_ps(pvb + 8);
    _mm_store_ps(pva + 8, mvb1);
    mvb1 = _mm_load_ps(pvb + 12);
    _mm_store_ps(pva + 12, mvb1);
    mvb1 = _mm_load_ps(pvb + 16);
    _mm_store_ps(pva + 16, mvb1);
    mvb1 = _mm_load_ps(pvb + 20);
    _mm_store_ps(pva + 20, mvb1);
    mvb1 = _mm_load_ps(pvb + 24);
    _mm_store_ps(pva + 24, mvb1);
    mvb1 = _mm_load_ps(pvb + 28);
    _mm_store_ps(pva + 28, mvb1);
    pva += 32;
    pvb += 32;
  }
  for (ind = 0; ind < seg[3]; ++ind) {
    mvb1 = _mm_load_ps(pvb);
    _mm_store_ps(pva, mvb1);
    mvb1 = _mm_load_ps(pvb + 4);
    _mm_store_ps(pva + 4, mvb1);
    mvb1 = _mm_load_ps(pvb + 8);
    _mm_store_ps(pva + 8, mvb1);
    mvb1 = _mm_load_ps(pvb + 12);
    _mm_store_ps(pva + 12, mvb1);
    pva += 16;
    pvb += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    mvb1 = _mm_load_ps(pvb);
    _mm_store_ps(pva, mvb1);
    mvb1 = _mm_load_ps(pvb + 4);
    _mm_store_ps(pva + 4, mvb1);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mvb1 = _mm_load_ps(pvb);
    _mm_store_ps(pva, mvb1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = pvb[ind];

  return va;
}
