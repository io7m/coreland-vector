#include "v_align.h"
#include "v_subsc.h"
#include "v_simd.h"
#include "v_types.h"

static inline float *
vec_subscNf_sse(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 vsc;
  unsigned int seg[3];
  float *pva;
  unsigned int ind;

  vec_segments(seg, 3, ne);
  pva = va;
  vsc = _mm_set1_ps(sc);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_sub_ps(mva1, vsc);
    mva2 = _mm_sub_ps(mva2, vsc);
    _mm_store_ps(pva, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_sub_ps(mva1, vsc);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] -= sc;

  return va;
}

static inline float *
vec_subscNfx_sse(const float *va, float *vr, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mvr1;
  __m128 vsc;
  unsigned int seg[3];
  const float *pva;
  float *pvr;
  unsigned int ind;

  vec_segments(seg, 3, ne);
  pva = va;
  pvr = vr;
  vsc = _mm_set1_ps(sc);

  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva2 = _mm_load_ps(pva + 4);
    mvr1 = _mm_sub_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    mvr1 = _mm_sub_ps(mva2, vsc);
    _mm_store_ps(pvr + 4, mvr1);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva);
    mvr1 = _mm_sub_ps(mva1, vsc);
    _mm_store_ps(pvr, mvr1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] - sc;

  return vr;
}
