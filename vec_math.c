#include <math.h>
#include "_sd_math.h"

#if !defined(HAVE_MATH_ACOSF)
static float acosf(float x) { return (float) acos(x); }
#endif
