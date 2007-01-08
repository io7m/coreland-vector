#include "simd.h"
#include "vector.h"
#include "vec_add.h"

float *vec_addNf(float *va, const float *vb, unsigned int n)
{
#ifdef HAVE_SIMD
#ifdef HAVE_SIMD_SSE

#endif
#ifdef HAVE_SIMD_ALTIVEC

#endif
#else
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] += vb[ind];
    return va;
  }
#endif
}
float *vec_addNfx(const float *va, const float *vb, float *vr, unsigned int n)
{
#ifdef HAVE_SIMD
#ifdef HAVE_SIMD_SSE

#endif
#ifdef HAVE_SIMD_ALTIVEC

#endif
#else
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] + vb[ind];
    return vr;
  }
#endif
}

double *vec_addNd(double *va, const double *vb, unsigned int n)
{
#ifdef HAVE_SIMD
#ifdef HAVE_SIMD_SSE2

#endif
#ifdef HAVE_SIMD_ALTIVEC

#endif
#else
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      va[ind] += vb[ind];
    return va;
  }
#endif
}
double *vec_addNdx(const double *va, const double *vb, double *vr, unsigned int n)
{
#ifdef HAVE_SIMD
#ifdef HAVE_SIMD_SSE2

#endif
#ifdef HAVE_SIMD_ALTIVEC

#endif
#else
  {
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      vr[ind] = va[ind] + vb[ind];
    return vr;
  }
#endif
}
