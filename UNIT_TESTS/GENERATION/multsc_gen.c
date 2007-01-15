#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "frand.h"

float fa[16];
double da[16];
double sc;

void out(unsigned int sz, void *a, unsigned int es, double sc)
{
  unsigned int ind;
  float *pfa;
  float *pfb;
  double *pda;
  double *pdb;

  if (es == sizeof(float))
    pfa = (float *) a;
  else
    pda = (double *) a;

  printf("{\n");
  printf("  {{");
  for (ind = 0; ind < 16; ++ind)
    if (es == sizeof(float))
      printf("%lf, ", pfa[ind]);
    else
      printf("%lf, ", pda[ind]);
  printf("}},\n");

  printf("  {{");
  for (ind = 0; ind < 16; ++ind)
    if (es == sizeof(float))
      printf("%lf, ", pfa[ind] * sc);
    else
      printf("%lf, ", pda[ind] * sc);
  printf("}},\n");

  printf("  %lf,\n", sc);
  printf("  %u,\n", sz);
  printf("},\n");
}

void gen(unsigned int sz, void *a, unsigned int es, double *sc)
{
  unsigned int ind;
  float *pfa;
  float *pfb;
  double *pda;
  double *pdb;

  if (es == sizeof(float)) {
    pfa = (float *) a;
    memset(pfa, 0, sizeof(float) * 16);
  } else {
    pda = (double *) a;
    memset(pda, 0, sizeof(double) * 16);
  }

  for (ind = 0; ind < sz; ++ind) {
    if (es == sizeof(float))
      fa[ind] = (float) frand();
    else
      da[ind] = frand();
  }
  *sc = frand();
}

int main()
{
  unsigned int ind;
  unsigned int jnd;
  unsigned int sz;

  srandom(time(0));

  memset(fa, 0, sizeof(float) * 16);
  sz = 2;
  printf("struct multsc_testf tests_f[] = {\n");
  out(16, fa, sizeof(float), sc);
  for (ind = 1; ind < 150; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(sz, fa, sizeof(float), &sc);
    out(sz, fa, sizeof(float), sc);
  }
  printf("};\n");

  memset(da, 0, sizeof(double) * 16);
  sz = 2;
  printf("struct multsc_testd tests_d[] = {\n");
  out(16, da, sizeof(double), sc);
  for (ind = 1; ind < 150; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(sz, da, sizeof(double), &sc);
    out(sz, da, sizeof(double), sc);
  }
  printf("};\n");
  return 0;
}
