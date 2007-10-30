#include "v_abs.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline float *
vec_absNf_sse_lt16(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mvx; 
  const union { unsigned int i; float f; } sb = { 0x7fffffff };
  float *pva;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  mvx = _mm_set1_ps(sb.f);
  pva = va;
  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_and_ps(mva1, mvx);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pva[ind] = fabs(pva[ind]);

  return va;
}

static inline float *
vec_absNf_sse_gte16(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvx; 
  const union { unsigned int i; float f; } sb = { 0x7fffffff };
  float *pva;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  mvx = _mm_set1_ps(sb.f);
  pva = va;
  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  for (ind = 0; ind < n16; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_and_ps(mva1, mvx);
    mva2 = _mm_load_ps(pva + 4);
    mva2 = _mm_and_ps(mva2, mvx);
    mva3 = _mm_load_ps(pva + 8);
    mva3 = _mm_and_ps(mva3, mvx);
    mva4 = _mm_load_ps(pva + 12);
    mva4 = _mm_and_ps(mva4, mvx);
    _mm_store_ps(pva, mva1); pva += 4;
    _mm_store_ps(pva, mva2); pva += 4;
    _mm_store_ps(pva, mva3); pva += 4;
    _mm_store_ps(pva, mva4); pva += 4;
  }

  vec_absNf_sse_lt16(pva, nr);
  return va;
}

static inline float *
vec_absNf_sse(float *va, unsigned int ne)
{
  return (ne >= 16) ? vec_absNf_sse_gte16(va, ne) : vec_absNf_sse_lt16(va, ne);
}

static inline float *
vec_absNfx_sse(const float *va, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mvx; 
  const union { unsigned int i; float f; } sb = { 0x7fffffff };
  const float *pva;
  float *pvr;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  mvx = _mm_set1_ps(sb.f);
  pva = va;
  pvr = vr;
  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_and_ps(mva1, mvx);
    _mm_store_ps(pvr, mva1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pvr[ind] = fabs(pva[ind]);

  return vr;
}
