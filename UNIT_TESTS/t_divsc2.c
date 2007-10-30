#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_divsc_data.c"

vector_16f vftmp;
vector_16d vdtmp;
float *ftmp = (float *) &vftmp;
double *dtmp = (double *) &vdtmp;

int main()
{
  double *dpa;
  double *dpr;
  double dsc;
  float *fpa;
  float *fpr;
  float fsc;
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < 16; ++ind) {
    ftmp[ind] = 1.0f;
    dtmp[ind] = 1.0f;
  }

  /* single precision */
  for (ind = 0; ind < sizeof(tests_f) / sizeof(struct divsc_testf); ++ind) {
    fpa = (float *) &tests_f[ind].vva;
    fpr = (float *) &tests_f[ind].vvr;
    fsc = tests_f[ind].sc;

    vec_divscNfx(fpa, ftmp, fsc, tests_f[ind].sz);

    for (jnd = 0; jnd < tests_f[ind].sz; ++jnd) {
      if (!approx_equalf(fpr[jnd], ftmp[jnd], 2.5f)) {
        printf("fail: tests_f[%u] vr[%u] %f != va[%u] %f\n",
                ind, jnd, fpr[jnd], jnd, ftmp[jnd]);
        return 1;
      }
      printf("[%u] vr[%u] %f ~ ftmp[%u] %f\n",
              ind, jnd, fpr[jnd], jnd, ftmp[jnd]);
    }
    printf("--\n");
  }

  /* double precision */
  for (ind = 0; ind < sizeof(tests_d) / sizeof(struct divsc_testd); ++ind) {
    dpa = (double *) &tests_d[ind].vva;
    dpr = (double *) &tests_d[ind].vvr;
    dsc = tests_d[ind].sc;

    vec_divscNdx(dpa, dtmp, dsc, tests_d[ind].sz);

    for (jnd = 0; jnd < tests_d[ind].sz; ++jnd) {
      if (!approx_equald(dpr[jnd], dtmp[jnd], 0.005f)) {
        printf("fail: tests_d[%u] vr[%u] %f != dtmp[%u] %f\n",
                ind, jnd, dpr[jnd], jnd, dtmp[jnd]);
        return 1;
      }
      printf("[%u] vr[%u] %f ~ dtmp[%u] %f\n",
              ind, jnd, dpr[jnd], jnd, dtmp[jnd]);
    }
    printf("--\n");
  }

  return 0;
} 
