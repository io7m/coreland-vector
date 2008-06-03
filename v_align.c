#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#if defined (VECTOR_VERBOSE_UNALIGNED)
#include <stdio.h>

inline int
vec_aligned_core (const char *func, unsigned long line, const void *vp)
{
  if (VEC_IS_ALIGNED (vp))
    return 1;
  else {
    fprintf (stderr, "%s %lu: warn: %p unaligned vector access\n", func, line, vp);
    return 0;
  }
}

inline int
vec_unaligned_core (const char *func, unsigned long line, const void *vp)
{
  if (VEC_IS_UNALIGNED (vp)) {
    fprintf (stderr, "%s %lu: warn: %p unaligned vector access\n", func, line, vp);
    return 1;
  } else
    return 0;
}
#endif
