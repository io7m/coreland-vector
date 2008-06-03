#ifndef VEC_SIMD_H
#define VEC_SIMD_H

#ifdef VECTOR_NO_SIMD
  #undef HAVE_CPU_EXT_SSE
  #undef HAVE_CPU_EXT_SSE2
  #undef HAVE_CPU_EXT_SSE3
  #undef HAVE_CPU_EXT_ALTIVEC
#endif

inline void vec_segments(unsigned int *, unsigned int, unsigned int);

#endif
