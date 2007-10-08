#include "v_assi.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

static inline double *
vec_assignNd_sse2(double *va, const double *vb, unsigned int ne)
{
  __m128d mvb1;
  unsigned int seg[4];
  const double *pvb;
  double *pva;
  unsigned int ind;

  pva = va;
  pvb = vb;
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    mvb1 = _mm_load_pd(pvb);
    _mm_store_pd(pva, mvb1);
    mvb1 = _mm_load_pd(pvb + 2);
    _mm_store_pd(pva + 2, mvb1);
    mvb1 = _mm_load_pd(pvb + 4);
    _mm_store_pd(pva + 4, mvb1);
    mvb1 = _mm_load_pd(pvb + 6);
    _mm_store_pd(pva + 6, mvb1);
    mvb1 = _mm_load_pd(pvb + 8);
    _mm_store_pd(pva + 8, mvb1);
    mvb1 = _mm_load_pd(pvb + 10);
    _mm_store_pd(pva + 10, mvb1);
    mvb1 = _mm_load_pd(pvb + 12);
    _mm_store_pd(pva + 12, mvb1);
    mvb1 = _mm_load_pd(pvb + 14);
    _mm_store_pd(pva + 14, mvb1);
    pva += 16;
    pvb += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    mvb1 = _mm_load_pd(pvb);
    _mm_store_pd(pva, mvb1);
    mvb1 = _mm_load_pd(pvb + 2);
    _mm_store_pd(pva + 2, mvb1);
    mvb1 = _mm_load_pd(pvb + 4);
    _mm_store_pd(pva + 4, mvb1);
    mvb1 = _mm_load_pd(pvb + 6);
    _mm_store_pd(pva + 6, mvb1);
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    mvb1 = _mm_load_pd(pvb);
    _mm_store_pd(pva, mvb1);
    mvb1 = _mm_load_pd(pvb + 2);
    _mm_store_pd(pva + 2, mvb1);
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = pvb[ind];

  return va;
}
