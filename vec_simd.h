#ifndef VEC_SIMD_H
#define VEC_SIMD_H

#include "sysinfo.h"

#ifdef VECTOR_NO_SIMD
#undef SYS_HAVE_CPU_EXT_SSE
#undef SYS_HAVE_CPU_EXT_SSE2
#undef SYS_HAVE_CPU_EXT_ALTIVEC
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE
#include <xmmintrin.h>
#endif

#ifdef SYS_HAVE_CPU_EXT_ALTIVEC
union align16v {
  float f[4];
  vector float v;
};
#endif

void vec_simd_segments(unsigned int *, unsigned int *,
                       unsigned int *, unsigned int *, unsigned int); 

#ifdef VECTOR_VERBOSE_UNALIGNED
int vec_unaligned(const void *);
#else
#define vec_unaligned(p) (((unsigned long)(p)) & 0xF)
#endif

/* next multiple of 16 */
#define vec_align(n) ((16 + (n) - ((n) & 15)) - (n))

#endif
