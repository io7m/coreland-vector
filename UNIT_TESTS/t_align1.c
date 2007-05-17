#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

int main(void)
{
  void *vp;

  vp = (void *) 0x3;
  return (vec_unaligned(vp) == 1);
} 
