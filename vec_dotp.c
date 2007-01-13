#include "vec_dotp.h"
#include "vec_simd.h"

#ifdef SYS_HAVE_CPU_EXT_SSE3
static double vec_dotprodNd_sse3(const double *va, const double *vb,
                                 unsigned int n)
{
  float res;
  return res;
}
#endif

/* interface */

float vec_dotprodNf(const float *va, const float *vb, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE3
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_dotprodNf_sse3(va, vb, n);
#endif
  {
    float f = 0;
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      f += va[ind] * vb[ind]; 
    return f;
  }
}
double vec_dotprodNd(const double *va, const double *vb, unsigned int n)
{
#ifdef SYS_HAVE_CPU_EXT_SSE3
  if (!vec_unaligned(va) && !vec_unaligned(vb))
    return vec_dotprodNd_sse3(va, vb, n);
#endif
  {
    double d = 0;
    unsigned int ind;
    for (ind = 0; ind < n; ++ind)
      d += va[ind] * vb[ind];
    return d;
  }
}
