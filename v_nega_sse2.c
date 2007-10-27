#include "v_align.h"
#include "v_nega.h"
#include "v_simd.h"
#include "v_types.h"

static inline double *
vec_negaNd_sse2(double *va, unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d mvz;
  unsigned int seg[2];
  double *pva;
  unsigned int ind;

  pva = va;
  mvz = _mm_setzero_pd();
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mva1 = _mm_sub_pd(mvz, mva1);
    mva2 = _mm_sub_pd(mvz, mva2);
    _mm_store_pd(pva, mva1);
    _mm_store_pd(pva + 2, mva2);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = -pva[ind];

  return va;
}

static inline double *
vec_negaNdx_sse2(const double *va, double *vr, unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d mvr;
  __m128d mvz;
  unsigned int seg[2];
  const double *pva;
  double *pvr;
  unsigned int ind;

  pva = va;
  pvr = vr;
  mvz = _mm_setzero_pd();
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mvr = _mm_sub_pd(mvz, mva1);
    _mm_store_pd(pvr, mvr);
    mvr = _mm_sub_pd(mvz, mva2);
    _mm_store_pd(pvr + 2, mvr);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = -pva[ind];

  return vr;
}

