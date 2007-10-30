#include "v_mult.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline float *
vec_multNf_sse_lt16(float *va, const float *vb, unsigned int ne)
{
  __m128 mva1;
  __m128 mvb1;
  const float *pvb;
  float *pva;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  pva = va;
  pvb = vb;

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    pvb += 4;
    mva1 = _mm_mul_ps(mva1, mvb1);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pva[ind] *= pvb[ind];

  return va;
}

static inline float *
vec_multNf_sse_gte16(float *va, const float *vb, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvb3;
  __m128 mvb4;
  const float *pvb;
  float *pva;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  pva = va;
  pvb = vb;

  for (ind = 0; ind < n16; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mvb1 = _mm_load_ps(pvb); pvb += 4;
    mva1 = _mm_mul_ps(mva1, mvb1);
    mvb2 = _mm_load_ps(pvb); pvb += 4;
    mva2 = _mm_mul_ps(mva2, mvb2);
    mvb3 = _mm_load_ps(pvb); pvb += 4;
    mva3 = _mm_mul_ps(mva3, mvb3);
    mvb4 = _mm_load_ps(pvb); pvb += 4;
    mva4 = _mm_mul_ps(mva4, mvb4);
    _mm_store_ps(pva, mva1); pva += 4;
    _mm_store_ps(pva, mva2); pva += 4;
    _mm_store_ps(pva, mva3); pva += 4;
    _mm_store_ps(pva, mva4); pva += 4;
  }

  vec_multNf_sse_lt16(pva, pvb, nr);
  return va;
}

static inline float *
vec_multNf_sse(float *va, const float *vb, unsigned int ne)
{
  return (ne >= 16) ? vec_multNf_sse_gte16(va, vb, ne)
                    : vec_multNf_sse_lt16(va, vb, ne);
}

static inline float *
vec_multNfx_sse_lt16(const float *va, const float *vb, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mvb1;
  const float *pva;
  const float *pvb;
  float *pvr;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  pva = va;
  pvb = vb;
  pvr = vr;

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva); pva += 4;
    mvb1 = _mm_load_ps(pvb); pvb += 4;
    mva1 = _mm_mul_ps(mva1, mvb1);
    _mm_store_ps(pvr, mva1);
    pvr += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pvr[ind] = pva[ind] * pvb[ind];

  return vr;
}

static inline float *
vec_multNfx_sse_gte16(const float *va, const float *vb, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvb3;
  __m128 mvb4;
  const float *pva;
  const float *pvb;
  float *pvr;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  pva = va;
  pvb = vb;
  pvr = vr;

  for (ind = 0; ind < n16; ++ind) {
    mva1 = _mm_load_ps(pva); pva += 4;
    mva2 = _mm_load_ps(pva); pva += 4;
    mva3 = _mm_load_ps(pva); pva += 4;
    mva4 = _mm_load_ps(pva); pva += 4;
    mvb1 = _mm_load_ps(pvb); pvb += 4;
    mvb2 = _mm_load_ps(pvb); pvb += 4;
    mvb3 = _mm_load_ps(pvb); pvb += 4;
    mvb4 = _mm_load_ps(pvb); pvb += 4;
    mva1 = _mm_mul_ps(mva1, mvb1);
    _mm_store_ps(pvr, mva1); pvr += 4;
    mva2 = _mm_mul_ps(mva2, mvb2);
    _mm_store_ps(pvr, mva2); pvr += 4;
    mva3 = _mm_mul_ps(mva3, mvb3);
    _mm_store_ps(pvr, mva3); pvr += 4;
    mva4 = _mm_mul_ps(mva4, mvb4);
    _mm_store_ps(pvr, mva4); pvr += 4;
  }

  vec_multNfx_sse_lt16(pva, pvb, pvr, nr);
  return vr;
}

static inline float *
vec_multNfx_sse(const float *va, const float *vb, float *vr, unsigned int ne)
{
  return (ne >= 16) ? vec_multNfx_sse_gte16(va, vb, vr, ne)
                    : vec_multNfx_sse_lt16(va, vb, vr, ne);
}
