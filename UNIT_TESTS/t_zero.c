#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

int main()
{
  float va[4];

  va[0] = 123.0f;
  va[1] = 456.0f;
  va[2] = 789.0f;
  va[3] = 9.123f;

  vec_zero4f(va);

  printf("zero4f\n");
  if (va[0] != 0.0f) { printf("fail: va[0] == %f\n", va[0]); return 1; }
  if (va[1] != 0.0f) { printf("fail: va[1] == %f\n", va[1]); return 1; }
  if (va[2] != 0.0f) { printf("fail: va[2] == %f\n", va[2]); return 1; }
  if (va[3] != 0.0f) { printf("fail: va[3] == %f\n", va[3]); return 1; }

  va[0] = 123.0f;
  va[1] = 456.0f;
  va[2] = 789.0f;

  vec_zero3f(va);

  printf("zero3f\n");
  if (va[0] != 0.0f) { printf("fail: va[0] == %f\n", va[0]); return 1; }
  if (va[1] != 0.0f) { printf("fail: va[1] == %f\n", va[1]); return 1; }
  if (va[2] != 0.0f) { printf("fail: va[2] == %f\n", va[2]); return 1; }

  va[0] = 123.0f;
  va[1] = 456.0f;

  vec_zero2f(va);

  printf("zero2f\n");
  if (va[0] != 0.0f) { printf("fail: va[0] == %f\n", va[0]); return 1; }
  if (va[1] != 0.0f) { printf("fail: va[1] == %f\n", va[1]); return 1; }
  return 0;
} 
