#include <time.h>
#include <stdlib.h>
#include <stdio.h>

float f[4];
float sc;
 
float frand()
{
  float f;
  float div;
  div = (random() % 1000);
  f = (random() % 10000) - 5000; 
  return f / div;
}

void print(float f[4], float sc, unsigned int sz)
{
  printf("  {\n");
  printf("    {%f, %f, %f, %f},\n", f[0], f[1], f[2], f[3]);
  printf("    %f,\n", sc);
  printf("    {%f, %f, %f, %f},\n",
          f[0] * sc, f[1] * sc, f[2] * sc, f[3] * sc);
  printf("    %u,\n", sz);
  printf("  },\n");
}

void gen(float f[4], float *sc, unsigned int sz)
{
  unsigned int ind;

  f[0] = f[1] = f[2] = f[3] = 0;
  for (ind = 0; ind < sz; ++ind)
    f[ind] = frand();
  *sc = frand();
}

int main()
{
  unsigned int ind = 30;
  unsigned int sz = 2;

  srandom(time(0));

  printf("  /* tools/multsc_gen.c */\n");
  print(f, sc, 4);

  while (--ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(f, &sc, sz);
    print(f, sc, sz);
  }
  return 0;
}
