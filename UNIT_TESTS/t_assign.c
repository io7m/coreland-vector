#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

int main()
{
  float va[4];
  float vb[4];

  va[0] = 123.0f;
  va[1] = 456.0f;
  va[2] = 789.0f;
  va[3] = 9.123f;

  vec_assign4f(vb, va);

  printf("assign4f\n");
  if (vb[0] != va[0]) { printf("fail: vb[0] != va[0] (%f)\n", vb[0]); return 1; }
  if (vb[1] != va[1]) { printf("fail: vb[1] != va[1] (%f)\n", vb[1]); return 1; }
  if (vb[2] != va[2]) { printf("fail: vb[2] != va[2] (%f)\n", vb[2]); return 1; }
  if (vb[3] != va[3]) { printf("fail: vb[3] != va[3] (%f)\n", vb[3]); return 1; }

  va[0] = 123.0f;
  va[1] = 456.0f;
  va[2] = 789.0f;

  vec_assign3f(vb, va);

  printf("assign3f\n");
  if (vb[0] != va[0]) { printf("fail: vb[0] != va[0] (%f)\n", vb[0]); return 1; }
  if (vb[1] != va[1]) { printf("fail: vb[1] != va[1] (%f)\n", vb[1]); return 1; }
  if (vb[2] != va[2]) { printf("fail: vb[2] != va[2] (%f)\n", vb[2]); return 1; }

  va[0] = 123.0f;
  va[1] = 456.0f;

  vec_assign2f(vb, va);

  printf("assign2f\n");
  if (vb[0] != va[0]) { printf("fail: vb[0] != va[0] (%f)\n", vb[0]); return 1; }
  if (vb[1] != va[1]) { printf("fail: vb[1] != va[1] (%f)\n", vb[1]); return 1; }

  return 0;
} 
