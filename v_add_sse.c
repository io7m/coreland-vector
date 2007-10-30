#include "v_add.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline float *
vec_addNf_sse(float *va, const float *vb, unsigned int ne)
{
  __m128 mva1;
  __m128 mvb1;
  const float *pvb;
  float *pva;
  unsigned int ind;
  unsigned int nv = ne / 4;
  unsigned int nc = ne % 4;

  pva = va;
  pvb = vb;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mva1 = _mm_add_ps(mva1, mvb1);
    _mm_store_ps(pva, mva1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < nc; ++ind)
    pva[ind] += pvb[ind];

  return va;
}

static inline float *
vec_addNfx_sse_lt16(const float *va, const float *vb, float *vr, unsigned int ne)
{
  __m128 mva1;
  __m128 mvb1;
  const float *pva;
  const float *pvb;
  float *pvr;
  unsigned int ind;
  unsigned int nv = ne / 4;
  unsigned int nc = ne % 4;

  pva = va;
  pvb = vb;
  pvr = vr;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvb1 = _mm_load_ps(pvb);
    mva1 = _mm_add_ps(mva1, mvb1);
    _mm_store_ps(pvr, mva1);
    pva += 4;
    pvb += 4;
    pvr += 4;
  }
  for (ind = 0; ind < nc; ++ind)
    pvr[ind] = pva[ind] + pvb[ind];

  return vr;
}

static inline float *
vec_addNfx_sse_gte16(const float *va, const float *vb, float *vr, unsigned int ne)
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
  unsigned int nv = ne / 16;
  unsigned int nc = ne % 16;

  pva = va;
  pvb = vb;
  pvr = vr;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mvb1 = _mm_load_ps(pvb + 0);
    mvb2 = _mm_load_ps(pvb + 4);
    mvb3 = _mm_load_ps(pvb + 8);
    mvb4 = _mm_load_ps(pvb + 12);
    mva1 = _mm_add_ps(mva1, mvb1);
    mva2 = _mm_add_ps(mva2, mvb2);
    mva3 = _mm_add_ps(mva3, mvb3);
    mva4 = _mm_add_ps(mva4, mvb4);
    _mm_store_ps(pvr + 0, mva1);
    _mm_store_ps(pvr + 4, mva2);
    _mm_store_ps(pvr + 8, mva3);
    _mm_store_ps(pvr + 12, mva4);
    pva += 16;
    pvb += 16;
    pvr += 16;
  }

  vec_addNfx_sse_lt16(pva, pvb, pvr, nc);
  return vr;
}

static inline float *
vec_addNfx_sse(const float *va, const float *vb, float *vr, unsigned int ne)
{
  return (ne >= 16) ? vec_addNfx_sse_gte16(va, vb, vr, ne)
                    : vec_addNfx_sse_lt16(va, vb, vr, ne);
}
