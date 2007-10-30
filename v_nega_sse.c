#include "v_nega.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_types.h"
#include "v_inline.h"

static inline float *
vec_negaNf_sse_lt16(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mvz;
  float *pva;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  mvz = _mm_setzero_ps();
  pva = va;

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pva[ind] = -pva[ind];

  return va;
}

static inline float *
vec_negaNf_sse_gte16(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvz;
  float *pva;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  mvz = _mm_setzero_ps();
  pva = va;

  for (ind = 0; ind < n16; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mva1 = _mm_sub_ps(mvz, mva1);
    mva2 = _mm_sub_ps(mvz, mva2);
    mva3 = _mm_sub_ps(mvz, mva3);
    mva4 = _mm_sub_ps(mvz, mva4);
    _mm_store_ps(pva, mva1); pva += 4;
    _mm_store_ps(pva, mva2); pva += 4;
    _mm_store_ps(pva, mva3); pva += 4;
    _mm_store_ps(pva, mva4); pva += 4;
  }

  if (nr) vec_negaNf_sse_lt16(pva, nr);
  return va;
}

static inline float *
vec_negaNf_sse(float *va, unsigned int ne)
{
  return (ne >= 16) ? vec_negaNf_sse_gte16(va, ne)
                    : vec_negaNf_sse_lt16(va, ne);
}

static inline float *
vec_negaNfx_sse_lt16(const float *va, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mvz;
  const float *pva;
  float *pvr;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  mvz = _mm_setzero_ps();
  pva = va;
  pvr = vr;

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva); pva += 4;
    mva1 = _mm_sub_ps(mvz, mva1);
    _mm_store_ps(pvr, mva1); pvr += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pvr[ind] = -pva[ind];

  return vr;
}

static inline float *
vec_negaNfx_sse_gte16(const float *va, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvz;
  const float *pva;
  float *pvr;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  mvz = _mm_setzero_ps();
  pva = va;
  pvr = vr;

  for (ind = 0; ind < n16; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mva1 = _mm_sub_ps(mvz, mva1);
    mva2 = _mm_sub_ps(mvz, mva2);
    mva3 = _mm_sub_ps(mvz, mva3);
    mva4 = _mm_sub_ps(mvz, mva4);
    _mm_store_ps(pvr, mva1);
    _mm_store_ps(pvr + 4, mva2);
    _mm_store_ps(pvr + 8, mva3);
    _mm_store_ps(pvr + 12, mva4);
    pva += 16;
    pvr += 16; 
  }

  if (nr) vec_negaNfx_sse_lt16(pva, pvr, nr);
  return vr;
}

static inline float *
vec_negaNfx_sse(const float *va, float *vr, unsigned int ne)
{
  return (ne >= 16) ? vec_negaNfx_sse_gte16(va, vr, ne)
                    : vec_negaNfx_sse_lt16(va, vr, ne);
}
