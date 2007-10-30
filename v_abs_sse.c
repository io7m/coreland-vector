#include "v_abs.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline float *
vec_absNf_sse(float *va, unsigned int ne)
{
  __m128 mva1;
  __m128 mvx; 
  const union { unsigned int i; float f; } sb = { 0x7fffffff };
  float *pva;
  unsigned int ind;
  unsigned int nv = ne / 4;
  unsigned int nc = ne % 4;

  mvx = _mm_set1_ps(sb.f);
  pva = va;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_and_ps(mva1, mvx);
    _mm_store_ps(pva, mva1);
    pva += 4;
  }
  for (ind = 0; ind < nc; ++ind)
    pva[ind] = fabs(pva[ind]);

  return va;
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
  unsigned int nv = ne / 4;
  unsigned int nc = ne % 4;

  mvx = _mm_set1_ps(sb.f);
  pva = va;
  pvr = vr;

  for (ind = 0; ind < nv; ++ind) {
    mva1 = _mm_load_ps(pva);
    mva1 = _mm_and_ps(mva1, mvx);
    _mm_store_ps(pvr, mva1);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < nc; ++ind)
    pvr[ind] = fabs(pva[ind]);

  return vr;
}
