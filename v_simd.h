#ifndef VEC_SIMD_H
#define VEC_SIMD_H

#include "sysinfo.h"

#ifdef VECTOR_NO_SIMD
  #undef SYS_HAVE_CPU_EXT_SSE
  #undef SYS_HAVE_CPU_EXT_SSE2
  #undef SYS_HAVE_CPU_EXT_SSE3
  #undef SYS_HAVE_CPU_EXT_ALTIVEC
#endif

/* this can be replaced with a compiler version check when Sun C
   supports SSE correctly */

#if SYS_CCTYPE == SYS_CCTYPE_SUN_C
  #undef SYS_HAVE_CPU_EXT_SSE
  #undef SYS_HAVE_CPU_EXT_SSE2
  #undef SYS_HAVE_CPU_EXT_SSE3
  #undef SYS_HAVE_CPU_EXT_ALTIVEC
#endif

/* if ANY cpu extensions are present, define a convenient constant */
#if defined(SYS_HAVE_CPU_EXT_SSE) || defined(SYS_HAVE_CPU_EXT_SSE2) || defined(SYS_HAVE_CPU_EXT_SSE3) || defined(SYS_HAVE_CPU_EXT_ALTIVEC)
  #define SYS_HAVE_VECTOR_HARDWARE
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE
#include <xmmintrin.h>
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE2
#include <emmintrin.h>
#endif

#ifdef SYS_HAVE_CPU_EXT_SSE3
#include <pmmintrin.h>
#endif

inline void vec_segments(unsigned int *, unsigned int, unsigned int);

#endif
