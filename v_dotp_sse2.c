#include "v_align.h"
#include "v_dotp.h"
#include "v_types.h"
#include "v_simd.h"

#ifdef HAVE_CPU_EXT_SSE2

static inline double
vec_dotprodNd_sse2(const double *va, const double *vb, unsigned int ne)
{
  vector_2d vva1;
  vector_2d vva2;
  vector_2d vvb1;
  vector_2d vvb2;
  unsigned int seg[2];
  const double *pvb;
  const double *pva;
  double res;
  unsigned int ind;

  res = 0;
  pva = va;
  pvb = vb;
  vec_segments(seg, 2, ne);

  for (ind = 0; ind < seg[1]; ++ind) {
    vva1.v = _mm_load_pd(pva);
    vva2.v = _mm_load_pd(pva + 2);
    vvb1.v = _mm_load_pd(pvb);
    vvb2.v = _mm_load_pd(pvb + 2);
    vva1.v = _mm_mul_pd(vva1.v, vvb1.v);
    vva2.v = _mm_mul_pd(vva2.v, vvb2.v);
    res += vva1.d[0] + vva1.d[1];
    res += vva2.d[0] + vva2.d[1];
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    res += pva[ind] * pvb[ind];

  return res;
}

#endif
