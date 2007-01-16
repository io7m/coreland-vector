#include "vec_zero.h"
#include "vec_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE
static float *vec_zeroNf_sse(float *va, unsigned int ne)
{
  __m128 mvz;
  float *pva;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  pva = va;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  mvz = _mm_setzero_ps();
  for (ind = 0; ind < d8; ++ind) {
    _mm_store_ps(pva, mvz);
    _mm_store_ps(pva + 4, mvz);
    pva += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    _mm_store_ps(pva, mvz);
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] = 0;

  return va;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
static double *vec_zeroNd_sse2(double *va, unsigned int n)
{
  return va;
}
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
static float *vec_zeroNf_altivec(float *va, unsigned int ne)
{
  vector float vz;
  float *pva;
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;
  unsigned int ind;

  vz = vec_ctf(vec_splat_u32(0), 0);
  pva = va;
  vec_simd_segments(&d16, &d8, &d4, &dr, ne);

  for (ind = 0; ind < d16; ++ind) {
    vec_st(vz, 0, pva);
    vec_st(vz, 0, pva + 4);
    vec_st(vz, 0, pva + 8);
    vec_st(vz, 0, pva + 12);
    pva += 16;
  }
  for (ind = 0; ind < d8; ++ind) {
    vec_st(vz, 0, pva);
    vec_st(vz, 0, pva + 4);
    pva += 8;
  }
  for (ind = 0; ind < d4; ++ind) {
    vec_st(vz, 0, pva);
    pva += 4;
  }
  for (ind = 0; ind < dr; ++ind)
    pva[ind] = 0;

  return va;
}
#endif

/* interface */

float *vec_zeroNf(float *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE
  if (!vec_unaligned(va))
    return vec_zeroNf_sse(va, n);
#endif
#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
  if (!vec_unaligned(va))
    return vec_zeroNf_altivec(va, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = 0;
    return va;
  }
}
double *vec_zeroNd(double *va, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE2
  if (!vec_unaligned(va))
    return vec_zeroNd_sse2(va, n);
#endif
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] = 0;
    return va;
  }
}
