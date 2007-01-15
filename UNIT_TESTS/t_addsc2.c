#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_addsc_data.c"

int main()
{
  float ftmp[4] = {0, 0, 0, 0};
  double dtmp[4] = {0, 0, 0, 0};
  double *dpa;
  double *dpr;
  double dsc;
  float *fpa;
  float *fpr;
  float fsc;
  unsigned int ind;
  unsigned int jnd;

  /* single precision */
  for (ind = 0; ind < sizeof(tests_f) / sizeof(struct addsc_testf); ++ind) {
    fpa = (float *) &tests_f[ind].vva;
    fpr = (float *) &tests_f[ind].vvr;
    fsc = tests_f[ind].sc;
    switch (tests_f[ind].sz) {
      case 4:
        vec_addsc4fx(fpa, ftmp, fsc);
        break;
      case 3:
        vec_addsc3fx(fpa, ftmp, fsc);
        break;
      case 2:
        vec_addsc2fx(fpa, ftmp, fsc);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests_f[ind].sz; ++jnd) {
      if (!approx_equalf(fpr[jnd], dtmp[jnd], APPROX_MAX_ERRORF)) {
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
  for (ind = 0; ind < sizeof(tests_d) / sizeof(struct addsc_testd); ++ind) {
    dpa = (double *) &tests_d[ind].vva;
    dpr = (double *) &tests_d[ind].vvr;
    dsc = tests_d[ind].sc;
    switch (tests_d[ind].sz) {
      case 4:
        vec_addsc4dx(dpa, dtmp, dsc);
        break;
      case 3:
        vec_addsc3dx(dpa, dtmp, dsc);
        break;
      case 2:
        vec_addsc2dx(dpa, dtmp, dsc);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests_d[ind].sz; ++jnd) {
      if (!approx_equald(dpr[jnd], dtmp[jnd], APPROX_MAX_ERRORD)) {
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
