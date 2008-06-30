#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "frand.h"

float f_sum;
double d_sum;
float fa[16];
double da[16];

void
out(unsigned int sz, void *a, unsigned int es)
{
  unsigned int ind;
  float *pfa;
  double *pda;

  if (es == sizeof(float)) {
    pfa = (float *) a;
  } else {
    pda = (double *) a;
  }

  printf("{\n");

  if (es == sizeof (float))
    printf("  %f,\n", f_sum);
  else
    printf("  %f,\n", d_sum);

  printf("  {{");
  for (ind = 0; ind < 16; ++ind)
    if (es == sizeof(float))
      printf("%lf, ", pfa[ind]);
    else
      printf("%lf, ", pda[ind]);
  printf("}},\n");

  printf("  %u,\n", sz);
  printf("},\n");
}

void
gen(unsigned int sz, void *a, unsigned int es)
{
  unsigned int ind;
  float *pfa;
  double *pda;
  double *pds;

  if (es == sizeof(float)) {
    pfa = (float *) a;
    memset(pfa, 0, sizeof(float) * 16);
  } else {
    pda = (double *) a;
    memset(pda, 0, sizeof(double) * 16);
  }

  f_sum = 0;
  d_sum = 0;

  for (ind = 0; ind < sz; ++ind) {
    if (es == sizeof(float)) {
      pfa[ind] = (float) frand();
      f_sum += pfa[ind];
    } else {
      pda[ind] = frand();
      d_sum += pda[ind];
    }
  }
}

int main()
{
  unsigned int ind;
  unsigned int jnd;
  unsigned int sz;

  srandom(time(0));

  memset(fa, 0, sizeof(float) * 16);
  sz = 2;
  printf("struct sum_testf tests_f[] = {\n");
  out(16, fa, sizeof(float));

  for (ind = 0; ind < 16; ++ind) fa[ind] = 1.0;
  f_sum = 16.0;
  out(16, fa, sizeof(float));

  for (ind = 0; ind < 16; ++ind) da[ind] = 1.0;
  d_sum = 16.0;
  out(16, da, sizeof(double));

  for (ind = 1; ind < 150; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(sz, fa, sizeof(float));
    out(sz, fa, sizeof(float));
  }
  printf("};\n");

  memset(da, 0, sizeof(double) * 16);
  sz = 2;
  printf("struct sum_testd tests_d[] = {\n");
  out(16, da, sizeof(double));
  for (ind = 1; ind < 150; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(sz, da, sizeof(double));
    out(sz, da, sizeof(double));
  }
  printf("};\n");
  return 0;
}
