#ifndef VEC_SIMD_H
#define VEC_SIMD_H

#include "sysinfo.h"

#ifdef NO_VECTOR_SIMD
#undef SYSINFO_HAVE_CPU_EXT_SSE
#undef SYSINFO_HAVE_CPU_EXT_SSE2
#undef SYSINFO_HAVE_CPU_EXT_ALTIVEC
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_SSE
#include <xmmintrin.h>
#endif

void vec_simd_segments(unsigned int *, unsigned int *,
                       unsigned int *, unsigned int *, unsigned int); 

#endif
