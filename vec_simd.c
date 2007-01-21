#include "vec_simd.h"

/*
 * split ne into buffer sizes and pack into array of hm integers.
 * largest multiplicand is hm - 1. array size must be
 * at least hm. remainder is placed in seg[0].
 *
 * example:
 *   vec_segments(seg, 4, 55);
 *     seg[3] = 3;
 *     seg[2] = 0;
 *     seg[1] = 1;
 *     seg[0] = 3;
 *    
 *       3
 *    + (1 * (2 << 1))
 *    + (0 * (2 << 2))
 *    + (3 * (2 << 3))
 *    = 55
 */

void vec_segments(unsigned int *seg, unsigned int hm, unsigned int ne)
{
  for (;;) {
    if (hm - 1) {
      seg[hm - 1] = ne >> hm;
      ne -= seg[hm - 1] << hm;
      --hm;
    } else {
      *seg = ne; return;
    }
  }
}

#ifdef VECTOR_VERBOSE_UNALIGNED
#include <stdio.h>

int vec_unaligned(const void *vp)
{
  if (((unsigned long) vp) & 15) {
    fprintf(stderr, "warn: %p unaligned vector access\n", vp);
    return 1;
  } else
    return 0;
}
#endif
