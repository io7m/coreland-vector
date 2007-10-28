#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

int main(void)
{
  void *vp;

  vp = (void *) 0x3;
  if (vec_aligned(vp) == 1) { printf("fail: 0x3 is NOT aligned\n"); return 1; }
  if (vec_unaligned(vp) == 0) { printf("fail: 0x3 IS unaligned\n"); return 1; }
  return 0;
} 
