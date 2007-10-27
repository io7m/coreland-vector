#include "v_align.h"
#include "v_nega.h"
#include "v_simd.h"
#include "v_types.h"

static inline float *
vec_negaNf_sse(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvz;
  unsigned int seg[3];
  float *pva;
  unsigned int ind;

  mvz = _mm_setzero_ps();
  pva = va;
  vec_segments(seg, 3, ne);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_sub_ps(mvz, mva1);
    mva2 = _mm_sub_ps(mvz, mva2);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = -pva[ind];

  return va;
}

static inline float *
vec_negaNfx_sse(const float *va, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvz;
  __m128 mvr;
  unsigned int seg[3];
  const float *pva;
  float *pvr;
  unsigned int ind;

  mvz = _mm_setzero_ps();
  pva = va;
  pvr = vr;
  vec_segments(seg, 3, ne);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvr = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pvr, mvr);
    mvr = _mm_sub_ps(mvz, mva2);
    _mm_store_ps(pvr + 4, mvr);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvr = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pvr, mvr);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = -pva[ind];

  return vr;
}
