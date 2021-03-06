#ifndef VEC_TYPES_H
#define VEC_TYPES_H

/* types never use less than 4 elements */

#ifdef HAVE_CPU_EXT_SSE
#include <xmmintrin.h>

union vector_16f { float f[16]; __m128 v; };
union vector_8f { float f[8]; __m128 v; };
union vector_4f { float f[4]; __m128 v; };
union vector_3f { float f[4]; __m128 v; };
union vector_2f { float f[4]; __m128 v; };
#endif

#ifdef HAVE_CPU_EXT_ALTIVEC
union vector_16f { float f[16]; vector float v; };
union vector_8f { float f[8]; vector float v; };
union vector_4f { float f[4]; vector float v; };
union vector_3f { float f[4]; vector float v; };
union vector_2f { float f[4]; vector float v; };
#endif

#ifdef HAVE_CPU_EXT_SSE2
#include <emmintrin.h>

union vector_16d { double d[16]; __m128d v; };
union vector_8d { double d[8]; __m128d v; };
union vector_4d { double d[4]; __m128d v; };
union vector_3d { double d[4]; __m128d v; };
union vector_2d { double d[4]; __m128d v; };
#endif

#if !defined(HAVE_CPU_EXT_SSE2)
union vector_16d { double d[16]; };
union vector_8d { double d[8]; };
union vector_4d { double d[4]; };
union vector_3d { double d[4]; };
union vector_2d { double d[4]; };
#endif

#if !defined(HAVE_CPU_EXT_SSE) && !defined(HAVE_CPU_EXT_ALTIVEC)
union vector_16f { float f[16]; };
union vector_8f { float f[8]; };
union vector_4f { float f[4]; };
union vector_3f { float f[4]; };
union vector_2f { float f[4]; };
#endif

typedef union vector_2d vector_2d;
typedef union vector_3d vector_3d;
typedef union vector_4d vector_4d;
typedef union vector_8d vector_8d;
typedef union vector_16d vector_16d;

typedef union vector_2f vector_2f;
typedef union vector_3f vector_3f;
typedef union vector_4f vector_4f;
typedef union vector_8f vector_8f;
typedef union vector_16f vector_16f;

#endif
