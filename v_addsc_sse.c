#include "v_addsc.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_types.h"
#include "v_inline.h"

static inline float *
vec_addscNf_sse_lt16(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 vsc;
  float *pva;
  unsigned int ind;
  unsigned int nv = ne / 4;
  unsigned int nc = ne % 4;

  vsc = _mm_set1_ps(sc);
  pva = va;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva1 = _mm_add_ps(mva1, vsc);
    _mm_store_ps(pva + 0, mva1);
    pva += 4;
  }
  for (ind = 0; ind < nc; ++ind)
    pva[ind] += sc;

  return va;
}

static inline float *
vec_addscNf_sse_gte16(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 vsc;
  float *pva;
  unsigned int ind;
  unsigned int nv = ne / 16;
  unsigned int nc = ne % 16;

  vsc = _mm_set1_ps(sc);
  pva = va;

  for (ind = 0; ind < nv; ++ind) {
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

  vec_addscNf_sse_lt16(pva, sc, nc);
  return va;
}

static inline float *
vec_addscNf_sse(float *va, float sc, unsigned int ne)
{
  return (ne >= 16) ? vec_addscNf_sse_gte16(va, sc, ne)
                    : vec_addscNf_sse_lt16(va, sc, ne);
}

static inline float *
vec_addscNfx_sse_lt16(const float *va, float *vr, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 vsc;
  const float *pva;
  float *pvr;
  unsigned int ind;
  unsigned int nv = ne / 4;
  unsigned int nc = ne % 4;

  vsc = _mm_set1_ps(sc);
  pva = va;
  pvr = vr;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva1 = _mm_add_ps(mva1, vsc);
    _mm_store_ps(pvr + 0, mva1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < nc; ++ind)
    pvr[ind] = pva[ind] + sc;

  return vr;
}

static inline float *
vec_addscNfx_sse_gte16(const float *va, float *vr, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 vsc;
  const float *pva;
  float *pvr;
  unsigned int ind;
  unsigned int nv = ne / 16;
  unsigned int nc = ne % 16;

  vsc = _mm_set1_ps(sc);
  pva = va;
  pvr = vr;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mva1 = _mm_add_ps(mva1, vsc);
    mva2 = _mm_add_ps(mva2, vsc);
    mva3 = _mm_add_ps(mva3, vsc);
    mva4 = _mm_add_ps(mva4, vsc);
    _mm_store_ps(pvr + 0, mva1);
    _mm_store_ps(pvr + 4, mva2);
    _mm_store_ps(pvr + 8, mva3);
    _mm_store_ps(pvr + 12, mva4);
    pva += 16;
    pvr += 16; 
  }

  vec_addscNfx_sse_lt16(pva, pvr, sc, nc);
  return vr;
}

static inline float *
vec_addscNfx_sse(const float *va, float *vr, float sc, unsigned int ne)
{
  return (ne >= 16) ? vec_addscNfx_sse_gte16(va, vr, sc, ne)
                    : vec_addscNfx_sse_lt16(va, vr, sc, ne);
}
