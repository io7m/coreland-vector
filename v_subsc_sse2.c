#include "v_align.h"
#include "v_subsc.h"
#include "v_simd.h"
#include "v_types.h"

#ifdef HAVE_CPU_EXT_SSE2

static inline double *
vec_subscNd_sse2(double *va, double sc, unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d vsc;
  unsigned int seg[2];
  double *pva;
  unsigned int ind;

  vsc = _mm_set1_pd(sc);
  pva = va;
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mva1 = _mm_sub_pd(mva1, vsc);
    mva2 = _mm_sub_pd(mva2, vsc);
    _mm_store_pd(pva, mva1);
    _mm_store_pd(pva + 2, mva2);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] -= sc;

  return va;
}

static double *
vec_subscNdx_sse2(const double *va, double *vr, double sc, unsigned int ne)
{
  __m128d mva1;
  __m128d mva2;
  __m128d mvr;
  __m128d vsc;
  unsigned int seg[2];
  const double *pva;
  double *pvr;
  unsigned int ind;

  pva = va;
  pvr = vr;
  vsc = _mm_set1_pd(sc);
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    mva1 = _mm_load_pd(pva);
    mva2 = _mm_load_pd(pva + 2);
    mvr = _mm_sub_pd(mva1, vsc);
    _mm_store_pd(pvr, mvr);
    mvr = _mm_sub_pd(mva2, vsc);
    _mm_store_pd(pvr + 2, mvr);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] - sc;

  return vr;
}

#endif
