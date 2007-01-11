#ifndef VEC_SIMD_H
#define VEC_SIMD_H

#include "sysinfo.h"

#ifdef VECTOR_NO_SIMD
#undef SYSINFO_HAVE_CPU_EXT_SSE
#undef SYSINFO_HAVE_CPU_EXT_SSE2
#undef SYSINFO_HAVE_CPU_EXT_ALTIVEC
#endif

#ifdef SYSINFO_HAVE_CPU_EXT_SSE
#include <xmmintrin.h>
#endif

void vec_simd_segments(unsigned int *, unsigned int *,
                       unsigned int *, unsigned int *, unsigned int); 

#ifdef VECTOR_VERBOSE_UNALIGNED
int vec_unaligned(const void *);
#else
#define vec_unaligned(p) (((unsigned long)(p)) & 0xF)
#endif

#define vec_align(n) ((16 + (n) - ((n) & 15)) - (n))

#endif
