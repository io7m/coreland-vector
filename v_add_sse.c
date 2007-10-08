#include "v_add.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline float
*vec_addNf_sse(float *va, const float *vb, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvb3;
  __m128 mvb4;
  unsigned int seg[4] = {0, 0, 0, 0};
  const float *pvb;
  float *pva;
  unsigned int ind;

  pva = va;
  pvb = vb;
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mva1 = _mm_add_ps(mva1, mvb1);
    mva2 = _mm_load_ps(pva + 4);
    mvb2 = _mm_load_ps(pvb + 4);
    mva2 = _mm_add_ps(mva2, mvb2);
    mva3 = _mm_load_ps(pva + 8);
    mvb3 = _mm_load_ps(pvb + 8);
    mva3 = _mm_add_ps(mva3, mvb3);
    mva4 = _mm_load_ps(pva + 12);
    mvb4 = _mm_load_ps(pvb + 12);
    mva4 = _mm_add_ps(mva4, mvb4);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    _mm_store_ps(pva + 8, mva3);
    _mm_store_ps(pva + 12, mva4);
    pva += 16;
    pvb += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mva1 = _mm_add_ps(mva1, mvb1);
    mva2 = _mm_load_ps(pva + 4);
    mvb2 = _mm_load_ps(pvb + 4);
    mva2 = _mm_add_ps(mva2, mvb2);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mva1 = _mm_add_ps(mva1, mvb1);
    _mm_store_ps(pva, mva1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] += pvb[ind];

  return va;
}

static inline float *
vec_addNfx_sse(const float *va, const float *vb, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvb3;
  __m128 mvb4;
  __m128 mvr;
  unsigned int seg[4] = {0, 0, 0, 0};
  const float *pva;
  const float *pvb;
  float *pvr;
  unsigned int ind;

  pva = va;
  pvb = vb;
  pvr = vr;
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mvb1 = _mm_load_ps(pvb);
    mvb2 = _mm_load_ps(pvb + 4);
    mvb3 = _mm_load_ps(pvb + 8);
    mvb4 = _mm_load_ps(pvb + 12);
    mvr = _mm_add_ps(mva1, mvb1);
    _mm_store_ps(pvr, mvr);
    mvr = _mm_add_ps(mva2, mvb2);
    _mm_store_ps(pvr + 4, mvr);
    mvr = _mm_add_ps(mva3, mvb3);
    _mm_store_ps(pvr + 8, mvr);
    mvr = _mm_add_ps(mva4, mvb4);
    _mm_store_ps(pvr + 12, mvr);
    pva += 16;
    pvb += 16;
    pvr += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvb1 = _mm_load_ps(pvb);
    mvb2 = _mm_load_ps(pvb + 4);
    mvr = _mm_add_ps(mva1, mvb1);
    _mm_store_ps(pvr, mvr);
    mvr = _mm_add_ps(mva2, mvb2);
    _mm_store_ps(pvr + 4, mvr);
    pva += 8;
    pvb += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mvr = _mm_add_ps(mva1, mvb1);
    _mm_store_ps(pvr, mvr);
    pva += 4;
    pvb += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] + pvb[ind];

  return vr;
}
