#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

float f[4];
 
float frand()
{
  float f;
  float div;
  div = (random() % 1000);
  f = (random() % 10000) - 5000; 
  return f / div;
}

void print(float f[4], unsigned int sz)
{
  float mag;

  mag = sqrtf((f[0] * f[0]) + (f[1] * f[1]) + (f[2] * f[2]) + (f[3] * f[3]));

  printf("  {\n");
  printf("    {%f, %f, %f, %f},\n", f[0], f[1], f[2], f[3]);
  printf("    %f,\n", mag);
  printf("    %u,\n", sz);
  printf("    {0},\n");
  printf("  },\n");
}

void gen(float f[4], unsigned int sz)
{
  unsigned int ind;

  f[0] = f[1] = f[2] = f[3] = 0;
  for (ind = 0; ind < sz; ++ind)
    f[ind] = frand();
}

int main()
{
  unsigned int ind = 30;
  unsigned int sz = 2;

  srandom(time(0));

  printf("  /* GENERATION/mag_gen.c */\n");
  print(f, 4);

  while (--ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(f, sz);
    print(f, sz);
  }
  return 0;
}
