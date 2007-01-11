#include "vec_simd.h"

void vec_simd_segments(unsigned int *pd16, unsigned int *pd8,
                       unsigned int *pd4,  unsigned int *pdr, unsigned int ne)
{
  unsigned int d16;
  unsigned int d8;
  unsigned int d4;
  unsigned int dr;

  d16 = ne >> 4; ne -= d16 << 4;
  d8 = ne >> 3; ne -= d8 << 3;
  d4 = ne >> 2; ne -= d4 << 2;
  dr = ne;

  *pd16 = d16;
  *pd8 = d8;
  *pd4 = d4;
  *pdr = dr;
}

#ifdef VECTOR_VERBOSE_UNALIGNED
#include <stdio.h>

int vec_unaligned(void *vp)
{
  if (((unsigned long) vp) & 15) {
    fprintf(stderr, "warn: %p unaligned vector access\n", vp);
    return 1;
  } else
    return 0;
}
#endif
