#include "v_assi.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

#ifdef HAVE_CPU_EXT_SSE

static inline float *
vec_assignNf_sse_lt16(float *va, const float *vb, unsigned int ne)
{
  __m128 mvb1;
  float *pva;
  const float *pvb;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  pva = va;
  pvb = vb;

  for (ind = 0; ind < n4; ++ind) {
    mvb1 = _mm_load_ps(pvb);
    _mm_store_ps(pva, mvb1);
    pvb += 4;
    pva += 4;
  }
  for (ind = 0; ind < nr; ++ind)
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
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  pva = va;
  pvb = vb;

  for (ind = 0; ind < n16; ++ind) {
    mvb1 = _mm_load_ps(pvb); pvb += 4;
    mvb2 = _mm_load_ps(pvb); pvb += 4;
    mvb3 = _mm_load_ps(pvb); pvb += 4;
    mvb4 = _mm_load_ps(pvb); pvb += 4;
    _mm_store_ps(pva, mvb1); pva += 4;
    _mm_store_ps(pva, mvb2); pva += 4;
    _mm_store_ps(pva, mvb3); pva += 4;
    _mm_store_ps(pva, mvb4); pva += 4;
    _mm_pause();
  }

  if (nr) vec_assignNf_sse_lt16(pva, pvb, nr);
  return va;
}

static inline float *
vec_assignNf_sse(float *va, const float *vb, unsigned int ne)
{
  return (ne >= 16) ? vec_assignNf_sse_gte16(va, vb, ne)
                    : vec_assignNf_sse_lt16(va, vb, ne);
}

#endif
