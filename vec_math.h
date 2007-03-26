#ifndef VEC_MATH_H
#define VEC_MATH_H

#include "_sd_math.h"
#include <math.h>

#if !defined(HAVE_MATH_ACOSF)
float acosf(float);
#endif

#if !defined(HAVE_MATH_SQRTF)
float sqrtf(float);
#endif

#endif
