#include "vec_align.h"
#include "vec_dotp.h"
#include "vec_types.h"
#include "vec_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float vec_dotprodNf_sse(const float *va, const float *vb,
                               unsigned int ne)
{
  vector_4f vva1;
  vector_4f vva2;
  vector_4f vvb1;
  vector_4f vvb2;
  unsigned int seg[3];
  const float *pvb;
  const float *pva;
  float res;
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
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float vec_dotprodNf_altivec(const float *va, const float *vb,
                                   unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vvb1;
  vector float vvb2;
  vector float vvb3;
  vector float vvb4;
  vector float vlen;
  vector unsigned int tmp;
  unsigned int seg[4];
  const float *pva;
  const float *pvb;
  unsigned int ind;
  float res;

  res = 0;
  pva = va;
  pvb = vb;
  tmp = vec_splat_u32(-1);
  vlen = vec_ctf(vec_splat_u32(0), 0);
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vvb3 = vec_ld(0, pvb + 8);
    vvb4 = vec_ld(0, pvb + 12);
    vlen = vec_madd(vva1, vvb1, vlen);
    vlen = vec_madd(vva2, vvb2, vlen);
    vlen = vec_madd(vva3, vvb3, vlen);
    vlen = vec_madd(vva4, vvb4, vlen);
    vlen = vec_add(vlen, vec_sld(vlen, vlen, 4));
    vlen = vec_add(vlen, vec_sld(vlen, vlen, 8));
    pva += 16;
    pvb += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vvb1 = vec_ld(0, pvb);
    vvb2 = vec_ld(0, pvb + 4);
    vlen = vec_madd(vva1, vvb1, vlen);
    vlen = vec_madd(vva2, vvb2, vlen);
    vlen = vec_add(vlen, vec_sld(vlen, vlen, 4));
    vlen = vec_add(vlen, vec_sld(vlen, vlen, 8));
    pva += 8;
    pvb += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1 = vec_ld(0, pva);
    vvb1 = vec_ld(0, pvb);
    vlen = vec_madd(vva1, vvb1, vlen);
    vlen = vec_add(vlen, vec_sld(vlen, vlen, 4));
    vlen = vec_add(vlen, vec_sld(vlen, vlen, 8));
    pva += 4;
    pvb += 4;
  }
  vec_ste(vlen, 0, &res);

  for (ind = 0; ind < seg[0]; ++ind)
    res += pva[ind] * pvb[ind];

  return res;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double vec_dotprodNd_sse2(const double *va, const double *vb,
                                unsigned int ne)
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

#ifdef SYS_HAVE_CPU_EXT_SSE3
static double vec_dotprodNd_sse3(const double *va, const double *vb,
                                 unsigned int ne)
{
  float res;
  return res;
}
#endif

/* interface */

float vec_dotprodNf(const float *va, const float *vb, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_dotprodNf_sse(va, vb, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_dotprodNf_altivec(va, vb, n);
#endif
  float f;
  vec_DOTPROD(va, vb, &f, n, float);
  return f;
}
double vec_dotprodNd(const double *va, const double *vb, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE3
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_dotprodNd_sse3(va, vb, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_dotprodNd_sse2(va, vb, n);
#endif
  double d;
  vec_DOTPROD(va, vb, &d, n, double);
  return d;
}
