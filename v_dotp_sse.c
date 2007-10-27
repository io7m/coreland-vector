#include "v_align.h"
#include "v_dotp.h"
#include "v_types.h"
#include "v_simd.h"

static inline float
vec_dotprodNf_sse(const float *va, const float *vb, unsigned int ne)
{
  vector_4f vva1;
  vector_4f vva2;
  vector_4f vvb1;
  vector_4f vvb2;
  unsigned int seg[3];
  const float *pvb;
  const float *pva;
  register float res;
  unsigned int ind;

  res = 0;
  pva = va;
  pvb = vb;
  vec_segments(seg, 3, ne);

  for (ind = 0; ind < seg[2]; ++ind) {
    vva1.v = _mm_load_ps(pva);
    vva2.v = _mm_load_ps(pva + 4);
    vvb1.v = _mm_load_ps(pvb);
    vvb2.v = _mm_load_ps(pvb + 4);
    vva1.v = _mm_mul_ps(vva1.v, vvb1.v);
    vva2.v = _mm_mul_ps(vva2.v, vvb2.v);
    res += vva1.f[0] + vva1.f[1] + vva1.f[2] + vva1.f[3];
    res += vva2.f[0] + vva2.f[1] + vva2.f[2] + vva2.f[3];
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1.v = _mm_load_ps(pva);
    vvb1.v = _mm_load_ps(pvb);
    vva1.v = _mm_mul_ps(vva1.v, vvb1.v);
    res += vva1.f[0] + vva1.f[1] + vva1.f[2] + vva1.f[3];
    pva += 4;
    pvb += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    res += pva[ind] * pvb[ind];

  return res;
}
