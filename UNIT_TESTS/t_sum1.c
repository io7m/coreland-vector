#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_sum_data.dat"

int main()
{
  double dsum;
  double *dpa;
  float fsum;
  float *fpa;
  unsigned int ind;

  /* single precision */
  for (ind = 0; ind < sizeof(tests_f) / sizeof(struct sum_testf); ++ind) {
    fpa = (float *) &tests_f[ind].v;
    fsum = vec_sumNf(fpa, tests_f[ind].sz);

    if (!approx_equalf(tests_f[ind].sum, fsum, APPROX_MAX_ERRORF)) {
      printf("fail: tests_f[%u] r %f != %f\n", ind, tests_f[ind].sum, fsum);
      return 1;
    }
    printf("[%u] r %f ~ %f\n", ind, tests_f[ind].sum, fsum);
  }

  /* double precision */
  for (ind = 0; ind < sizeof(tests_d) / sizeof(struct sum_testd); ++ind) {
    dpa = (double *) &tests_d[ind].v;
    dsum = vec_sumNd(dpa, tests_d[ind].sz);

    if (!approx_equald(tests_d[ind].sum, dsum, APPROX_MAX_ERRORD)) {
      printf("fail: tests_d[%u] r %f != %f\n", ind, tests_d[ind].sum, dsum);
      return 1;
    }
    printf("[%u] r %f ~ %f\n", ind, tests_d[ind].sum, dsum);
  }

  return 0;
} 
