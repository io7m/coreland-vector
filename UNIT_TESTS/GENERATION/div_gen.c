#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "frand.h"

float fa[16];
float fb[16];
double da[16];
double db[16];

void divset()
{
  unsigned int ind;
  for (ind = 0; ind < sizeof(fa) / sizeof(float); ++ind) fa[ind] = 1.0f;
  for (ind = 0; ind < sizeof(fb) / sizeof(float); ++ind) fb[ind] = 1.0f;
  for (ind = 0; ind < sizeof(da) / sizeof(double); ++ind) da[ind] = 1.0f;
  for (ind = 0; ind < sizeof(db) / sizeof(double); ++ind) db[ind] = 1.0f;
}

void out(unsigned int sz, void *a, void *b, unsigned int es)
{
  unsigned int ind;
  float *pfa;
  float *pfb;
  double *pda;
  double *pdb;

  if (es == sizeof(float)) {
    pfa = (float *) a;
    pfb = (float *) b;
  } else {
    pda = (double *) a;
    pdb = (double *) b;
  }

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
      printf("%lf, ", pfb[ind]);
    else
      printf("%lf, ", pdb[ind]);
  printf("}},\n");

  printf("  {{");
  for (ind = 0; ind < 16; ++ind)
    if (es == sizeof(float))
      printf("%lf, ", pfa[ind] / pfb[ind]);
    else
      printf("%lf, ", pda[ind] / pdb[ind]);
  printf("}},\n");

  printf("  %u,\n", sz);
  printf("},\n");
}

void gen(unsigned int sz, void *a, void *b, unsigned int es)
{
  unsigned int ind;
  float *pfa;
  float *pfb;
  double *pda;
  double *pdb;

  divset();
  if (es == sizeof(float)) {
    pfa = (float *) a;
    pfb = (float *) b;
  } else {
    pda = (double *) a;
    pdb = (double *) b;
  }

  for (ind = 0; ind < sz; ++ind) {
    if (es == sizeof(float)) {
      fa[ind] = (float) frand();
      fb[ind] = (float) frand();
    } else {
      da[ind] = frand();
      db[ind] = frand();
    }
  }
}

int main()
{
  unsigned int ind;
  unsigned int jnd;
  unsigned int sz;

  srandom(time(0));

  divset();
  sz = 2;
  printf("struct div_testf tests_f[] = {\n");
  out(16, fa, fb, sizeof(float));
  for (ind = 1; ind < 150; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(sz, fa, fb, sizeof(float));
    out(sz, fa, fb, sizeof(float));
  }
  printf("};\n");

  divset();
  sz = 2;
  printf("struct div_testd tests_d[] = {\n");
  out(16, da, db, sizeof(double));
  for (ind = 1; ind < 150; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    gen(sz, da, db, sizeof(double));
    out(sz, da, db, sizeof(double));
  }
  printf("};\n");
  return 0;
}
