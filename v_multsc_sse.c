#include "v_multsc.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_types.h"
#include "v_inline.h"

#ifdef HAVE_CPU_EXT_SSE

static inline float *
vec_multscNf_sse_lt16(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 vsc;
  float *pva;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  n4 = ne >> 2;
  nr = ne - (n4 << 2);

  vsc = _mm_set1_ps(sc);
  pva = va;

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva1 = _mm_mul_ps(mva1, vsc);
    _mm_store_ps(pva + 0, mva1);
    pva += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pva[ind] *= sc;

  return va;
}

static inline float *
vec_multscNf_sse_gte16(float *va, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 vsc;
  float *pva;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  vsc = _mm_set1_ps(sc);
  pva = va;

  for (ind = 0; ind < n16; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mva1 = _mm_mul_ps(mva1, vsc);
    mva2 = _mm_mul_ps(mva2, vsc);
    mva3 = _mm_mul_ps(mva3, vsc);
    mva4 = _mm_mul_ps(mva4, vsc);
    _mm_store_ps(pva + 0, mva1);
    _mm_store_ps(pva + 4, mva2);
    _mm_store_ps(pva + 8, mva3);
    _mm_store_ps(pva + 12, mva4);
    pva += 16;
  }

  if (nr) vec_multscNf_sse_lt16(pva, sc, nr);
  return va;
}

static inline float *
vec_multscNf_sse(float *va, float sc, unsigned int ne)
{
  return (ne >= 16) ? vec_multscNf_sse_gte16(va, sc, ne)
                    : vec_multscNf_sse_lt16(va, sc, ne);
}

static inline float *
vec_multscNfx_sse_lt16(const float *va, float *vr, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 vsc;
  const float *pva;
  float *pvr;
  unsigned int ind;
  unsigned int n4;
  unsigned int nr;

  n4 = ne >> 2;
  nr = ne - (n4 << 2);
  vsc = _mm_set1_ps(sc);
  pva = va;
  pvr = vr;

  for (ind = 0; ind < n4; ++ind) {
    mva1 = _mm_load_ps(pva); pva += 4;
    mva1 = _mm_mul_ps(mva1, vsc);
    _mm_store_ps(pvr, mva1);
    pvr += 4;
  }
  for (ind = 0; ind < nr; ++ind)
    pvr[ind] = pva[ind] * sc;

  return vr;
}

static inline float *
vec_multscNfx_sse_gte16(const float *va, float *vr, float sc, unsigned int ne)
{
  __m128 mva1;
  __m128 mva2;
  __m128 mva3;
  __m128 mva4;
  __m128 vsc;
  const float *pva;
  float *pvr;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  vsc = _mm_set1_ps(sc);
  pva = va;
  pvr = vr;

  for (ind = 0; ind < n16; ++ind) {
    mva1 = _mm_load_ps(pva + 0);
    mva2 = _mm_load_ps(pva + 4);
    mva3 = _mm_load_ps(pva + 8);
    mva4 = _mm_load_ps(pva + 12);
    mva1 = _mm_mul_ps(mva1, vsc);
    mva2 = _mm_mul_ps(mva2, vsc);
    mva3 = _mm_mul_ps(mva3, vsc);
    mva4 = _mm_mul_ps(mva4, vsc);
    _mm_store_ps(pvr + 0, mva1);
    _mm_store_ps(pvr + 4, mva2);
    _mm_store_ps(pvr + 8, mva3);
    _mm_store_ps(pvr + 12, mva4);
    _mm_pause();
    pva += 16;
    pvr += 16; 
  }

  if (nr) vec_multscNfx_sse_lt16(pva, pvr, sc, nr);
  return vr;
}

static inline float *
vec_multscNfx_sse(const float *va, float *vr, float sc, unsigned int ne)
{
  return (ne >= 16) ? vec_multscNfx_sse_gte16(va, vr, sc, ne)
                    : vec_multscNfx_sse_lt16(va, vr, sc, ne);
}

#endif
