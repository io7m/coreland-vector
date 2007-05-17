#include "vec_align.h"
#include "_sd_ptr_uint.h"

#define IS_ALIGNED(p) (((ptr_uint) (p)) & 15)

#if defined(VECTOR_VERBOSE_UNALIGNED)
#include <stdio.h>

int vec_unaligned_core(const char *func, unsigned long line, const void *vp)
{
  if (IS_ALIGNED(vp)) {
    fprintf(stderr, "%s %lu: warn: %p unaligned vector access\n", func, line, vp);
    return 1;
  } else
    return 0;
}
#else
int vec_unaligned_core(const char *func, unsigned long line, const void *vp)
{
  return !IS_ALIGNED(vp);
}
#endif
