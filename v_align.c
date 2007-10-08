#include "v_align.h"
#include "v_inline.h"
#include "_sd-ptr_uint.h"

#define IS_UNALIGNED(p) (((ptr_uint) (p)) & 15)

#if defined(VECTOR_VERBOSE_UNALIGNED)
#include <stdio.h>

inline int
vec_unaligned_core(const char *func, unsigned long line, const void *vp)
{
  if (IS_UNALIGNED(vp)) {
    fprintf(stderr, "%s %lu: warn: %p unaligned vector access\n", func, line, vp);
    return 1;
  } else
    return 0;
}
#else
inline int
vec_unaligned_core(const char *func, unsigned long line, const void *vp)
{
  return IS_UNALIGNED(vp);
}
#endif
