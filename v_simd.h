#ifndef VEC_SIMD_H
#define VEC_SIMD_H

#include "sysinfo.h"

#ifdef VECTOR_NO_SIMD
  #undef SYS_HAVE_CPU_EXT_SSE
  #undef SYS_HAVE_CPU_EXT_SSE2
  #undef SYS_HAVE_CPU_EXT_ALTIVEC
#endif

/* this can be replaced with a compiler version check when Sun C
   supports SSE correctly */

#if SYS_CCTYPE == SYS_CCTYPE_SUN_C
  #undef SYS_HAVE_CPU_EXT_SSE
  #undef SYS_HAVE_CPU_EXT_SSE2
  #undef SYS_HAVE_CPU_EXT_ALTIVEC
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE
#include <xmmintrin.h>
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
#include <emmintrin.h>
#endif

inline void vec_segments(unsigned int *, unsigned int, unsigned int);

#endif
