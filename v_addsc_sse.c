#include "v_addsc.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_types.h"
#include "v_inline.h"

static inline float *
vec_addscNf_sse(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 vsc;
  unsigned int seg[4];
  float *pva;
  unsigned int ind;

  vsc = _mm_set1_ps(sc);
  vec_segments(seg, 4, ne);
  pva = va;

  for (ind = 0; ind < seg[3]; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mva1 = _mm_add_ps(mva1, vsc);
    mva2 = _mm_add_ps(mva2, vsc);
    mva3 = _mm_add_ps(mva3, vsc);
    mva4 = _mm_add_ps(mva4, vsc);
    _mm_store_ps(pva + 0, mva1);
    _mm_store_ps(pva + 4, mva2);
    _mm_store_ps(pva + 8, mva3);
    _mm_store_ps(pva + 12, mva4);
    pva += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mva1 = _mm_add_ps(mva1, vsc);
    mva2 = _mm_add_ps(mva2, vsc);
    _mm_store_ps(pva + 0, mva1);
    _mm_store_ps(pva + 4, mva2);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva1 = _mm_add_ps(mva1, vsc);
    _mm_store_ps(pva + 0, mva1);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] += sc;

  return va;
}

static inline float *
vec_addscNfx_sse(const float *va, float *vr, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 mvr1;
  __m128 mvr2;
  __m128 mvr3;
  __m128 mvr4;
  __m128 vsc;
  unsigned int seg[4];
  const float *pva;
  float *pvr;
  unsigned int ind;

  vsc = _mm_set1_ps(sc);
  vec_segments(seg, 4, ne);
  pva = va;
  pvr = vr;

  for (ind = 0; ind < seg[3]; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mvr1 = _mm_add_ps(mva1, vsc);
    mvr2 = _mm_add_ps(mva2, vsc);
    mvr3 = _mm_add_ps(mva3, vsc);
    mvr4 = _mm_add_ps(mva4, vsc);
    _mm_store_ps(pvr + 0, mvr1);
    _mm_store_ps(pvr + 4, mvr2);
    _mm_store_ps(pvr + 8, mvr3);
    _mm_store_ps(pvr + 12, mvr4);
    pva += 16;
    pvr += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mvr1 = _mm_add_ps(mva1, vsc);
    mvr2 = _mm_add_ps(mva2, vsc);
    _mm_store_ps(pvr + 0, mvr1);
    _mm_store_ps(pvr + 4, mvr2);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mvr1 = _mm_add_ps(mva1, vsc);
    _mm_store_ps(pvr + 0, mvr1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] + sc;

  return vr;
}
