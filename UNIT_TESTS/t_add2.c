#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_add_data.c"

int main()
{
  float ftmp[4] = {0, 0, 0, 0};
  double dtmp[4] = {0, 0, 0, 0};
  double *dpa;
  double *dpb;
  double *dpr;
  float *fpa;
  float *fpb;
  float *fpr;
  unsigned int ind;
  unsigned int jnd;

  /* single precision */
  for (ind = 0; ind < sizeof(tests_f) / sizeof(struct add_testf); ++ind) {
    fpa = (float *) &tests_f[ind].vva;
    fpb = (float *) &tests_f[ind].vvb;
    fpr = (float *) &tests_f[ind].vvr;
    switch (tests_f[ind].sz) {
      case 4:
        vec_add4f(fpa, fpb);
        break;
      case 3:
        vec_add3f(fpa, fpb);
        break;
      case 2:
        vec_add2f(fpa, fpb);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests_f[ind].sz; ++jnd) {
      if (!approx_equalf(fpr[jnd], fpa[jnd], APPROX_MAX_ERRORF)) {
        printf("fail: tests_f[%u] vr[%u] %f != va[%u] %f\n",
                ind, jnd, fpr[jnd], jnd, fpa[jnd]);
        return 1;
      }
      printf("[%u] vr[%u] %f ~ va[%u] %f\n",
              ind, jnd, fpr[jnd], jnd, fpa[jnd]);
    }
    printf("--\n");
  }

  /* double precision */
  for (ind = 0; ind < sizeof(tests_d) / sizeof(struct add_testd); ++ind) {
    dpa = (double *) &tests_d[ind].vva;
    dpb = (double *) &tests_d[ind].vvb;
    dpr = (double *) &tests_d[ind].vvr;
    switch (tests_d[ind].sz) {
      case 4:
        vec_add4d(dpa, dpb);
        break;
      case 3:
        vec_add3d(dpa, dpb);
        break;
      case 2:
        vec_add2d(dpa, dpb);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests_d[ind].sz; ++jnd) {
      if (!approx_equald(dpr[jnd], dpa[jnd], APPROX_MAX_ERRORD)) {
        printf("fail: tests_d[%u] vr[%u] %f != va[%u] %f\n",
                ind, jnd, dpr[jnd], jnd, dpa[jnd]);
        return 1;
      }
      printf("[%u] vr[%u] %f ~ va[%u] %f\n",
              ind, jnd, dpr[jnd], jnd, dpa[jnd]);
    }
    printf("--\n");
  }

  return 0;
} 
