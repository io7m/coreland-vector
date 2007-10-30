#include "v_assi.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline float *
vec_assignNf_sse_lt16(float *va, const float *vb, unsigned int ne)
{
  __m128 mvb1;
  float *pva;
  const float *pvb;
  unsigned int ind;
  unsigned int nv = ne / 4;
  unsigned int nc = ne % 4;

  pva = va;
  pvb = vb;

  for (ind = 0; ind < nv; ++ind) {
    mvb1 = _mm_load_ps(pvb);
    _mm_store_ps(pva, mvb1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < nc; ++ind)
    pva[ind] = pvb[ind];

  return va;
}

static inline float *
vec_assignNf_sse_gte16(float *va, const float *vb, unsigned int ne)
{
  __m128 mvb1;
  __m128 mvb2;
  __m128 mvb3;
  __m128 mvb4;
  float *pva;
  const float *pvb;
  unsigned int ind;
  unsigned int nv = ne / 16;
  unsigned int nc = ne % 16;

  pva = va;
  pvb = vb;

  for (ind = 0; ind < nv; ++ind) {
    mvb1 = _mm_load_ps(pvb + 0);
    mvb2 = _mm_load_ps(pvb + 4);
    mvb3 = _mm_load_ps(pvb + 8);
    mvb4 = _mm_load_ps(pvb + 12);
    _mm_store_ps(pva + 0, mvb1);
    _mm_store_ps(pva + 4, mvb2);
    _mm_store_ps(pva + 8, mvb3);
    _mm_store_ps(pva + 12, mvb4);
    pva += 16;
    pvb += 16;
  }

  vec_assignNf_sse_lt16(pva, pvb, nc);
  return va;
}

static inline float *
vec_assignNf_sse(float *va, const float *vb, unsigned int ne)
{
  return (ne >= 16) ? vec_assignNf_sse_gte16(va, vb, ne)
                    : vec_assignNf_sse_lt16(va, vb, ne);
}
