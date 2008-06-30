#include <time.h>
#include <stdlib.h>
#include <stdio.h>

float f[3];
float g[3];
 
float frand()
{
  float f;
  float div;
  div = (random() % 1000);
  f = (random() % 10000) - 5000; 
  return f / div;
}

void print(float f[3], float g[3])
{
  float tmp[3];

  printf("  {\n");
  printf("    {%f, %f, %f},\n", f[0], f[1], f[2]);
  printf("    {%f, %f, %f},\n", g[0], g[1], g[2]);

  tmp[0] = (f[1] * g[2]) - (f[2] * g[1]); 
  tmp[1] = (f[2] * g[0]) - (f[0] * g[2]); 
  tmp[2] = (f[0] * g[1]) - (f[1] * g[0]); 

  printf("    {%f, %f, %f},\n", tmp[0], tmp[1], tmp[2]);
  printf("  },\n");
}

void gen(float f[3], float g[3])
{
  unsigned int ind;

  f[0] = f[1] = f[2] = 0;
  g[0] = g[1] = g[2] = 0;
  for (ind = 0; ind < 3; ++ind) {
    f[ind] = frand();
    g[ind] = frand();
  }
}

int main()
{
  unsigned int ind = 30;

  srandom(time(0));

  printf("  /* GENERATION/xprod_gen.c */\n");
  print(f, g);

  while (--ind) {
    gen(f, g);
    print(f, g);
  }
  return 0;
}
