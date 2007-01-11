#include <time.h>
#include <stdlib.h>
#include <stdio.h>

float f[4];
float g[4];
 
float frand()
{
  float f;
  float div;
  div = (random() % 1000);
  f = (random() % 10000) - 5000; 
  return f / div;
}

void print(float f[4], float g[4], unsigned int sz)
{
  printf("  {\n");
  printf("    {%f, %f, %f, %f},\n", f[0], f[1], f[2], f[3]);
  printf("    {%f, %f, %f, %f},\n", g[0], g[1], g[2], g[3]);
  printf("    {%f, %f, %f, %f},\n",
          f[0] + g[0], f[1] + g[1], f[2] + g[2], f[3] + g[3]);
  printf("    %u,\n", sz);
  printf("    {0},\n");
  printf("  },\n");
}

void gen(float f[4], float g[4], unsigned int sz)
{
  unsigned int ind;

  f[0] = f[1] = f[2] = f[3] = 0;
  g[0] = g[1] = g[2] = g[3] = 0;
  for (ind = 0; ind < sz; ++ind) {
    f[ind] = frand();
    g[ind] = frand();
  }
}

int main()
{
  unsigned int ind = 30;
  unsigned int sz = 2;

  srandom(time(0));

  printf("  /* GENERATION/add_gen.c */\n");
  print(f, g, 4);

  while (--ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(f, g, sz);
    print(f, g, sz);
  }
  return 0;
}
