#include "v_math.h"

#if !defined(HAVE_MATH_ACOSF)
float acosf(float x) { return (float) acos(x); }
#endif

#if !defined(HAVE_MATH_SQRTF)
float sqrtf(float x) { return (float) sqrt(x); }
#endif
