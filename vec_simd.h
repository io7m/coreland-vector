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

#ifdef VECTOR_VERBOSE_UNALIGNED
int vec_unaligned(const void *);
#else
  #define vec_unaligned(p) (((unsigned long)(p)) & 0xF)
#endif

/* next multiple of 16 */
#define vec_pad(n) ((16 + (n) - ((n) & 15)) - (n))

/* macros for vec_align() */
#if SYS_CCTYPE == SYS_CCTYPE_GCC
  #define vec_align(n) __attribute__((aligned ((n))))
#endif
#if SYS_CCTYPE == SYS_CCTYPE_INTEL
  #define vec_align(n) _declspec(align((n)))
#endif

#ifndef vec_align
  #define vec_align(n) 
#endif

void vec_segments(unsigned int *, unsigned int, unsigned int);

#endif
