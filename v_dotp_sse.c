#include "v_align.h"
#include "v_dotp.h"
#include "v_types.h"
#include "v_simd.h"

static inline float
vec_dotprodNf_sse(const float *va, const float *vb, unsigned int ne)
{
  vector_4f vva1;
  vector_4f vva2;
  vector_4f vva3;
  vector_4f vva4;
  vector_4f vvb1;
  vector_4f vvb2;
  vector_4f vvb3;
  vector_4f vvb4;
  const float *pvb;
  const float *pva;
  float res;
  unsigned int ind;
  unsigned int n16;
  unsigned int nr;

  n16 = ne >> 4;
  nr = ne - (n16 << 4);

  res = 0;
  pva = va;
  pvb = vb;

  for (ind = 0; ind < n16; ++ind) {
    vva1.v = _mm_load_ps(pva); pva += 4;
    vva2.v = _mm_load_ps(pva); pva += 4;
    vva3.v = _mm_load_ps(pva); pva += 4;
    vva4.v = _mm_load_ps(pva); pva += 4;
    vvb1.v = _mm_load_ps(pvb); pvb += 4;
    vva1.v = _mm_mul_ps(vva1.v, vvb1.v);
    vvb2.v = _mm_load_ps(pvb); pvb += 4;
    vva2.v = _mm_mul_ps(vva2.v, vvb2.v);
    vvb3.v = _mm_load_ps(pvb); pvb += 4;
    vva3.v = _mm_mul_ps(vva3.v, vvb3.v);
    vvb4.v = _mm_load_ps(pvb); pvb += 4;
    vva4.v = _mm_mul_ps(vva4.v, vvb4.v);
    vva1.v = _mm_add_ps(vva1.v, vva2.v);
    vva1.v = _mm_add_ps(vva1.v, vva3.v);
    vva1.v = _mm_add_ps(vva1.v, vva4.v);
    res += vva1.f[0] + vva1.f[1] + vva1.f[2] + vva1.f[3];
  }
  for (ind = 0; ind < nr; ++ind)
    res += pva[ind] * pvb[ind];

  return res;
}
