#include "v_align.h"
#include "v_dotp.h"
#include "v_types.h"
#include "v_simd.h"

#ifdef HAVE_CPU_EXT_SSE3

static inline double
vec_dotprodNd_sse3(const double *va, const double *vb, unsigned int ne)
{
  float res;
  return res;
}

#endif
