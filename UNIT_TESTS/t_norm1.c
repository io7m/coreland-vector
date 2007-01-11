#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_norm_data.c"

int main()
{
  float tmp[4] = {0, 0, 0, 0};
  float mag;
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct norm_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        vec_norm4fx(tests[ind].va, tmp);
        break;
      case 3:
        vec_norm3fx(tests[ind].va, tmp);
        break;
      case 2:
        vec_norm2fx(tests[ind].va, tmp);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    mag = 0.0f;
    for (jnd = 0; jnd < tests[ind].sz; ++jnd) {
      if (!approx_equalf(tests[ind].vr[jnd], tmp[jnd], APPROX_MAX_ERROR)) {
        printf("fail: [%u] vr[%u] %f != tmp[%u] %f\n",
                ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
        return 1;
      }
      mag += (tmp[jnd] * tmp[jnd]);
      printf("[%u] vr[%u] %f ~ tmp[%u] %f\n",
              ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
    }
    if (ind) {
      if (!approx_equalf(mag, 1.0f, APPROX_MAX_ERROR)) {
        printf("[%u] mag != 1.0f (%f)\n", ind, mag);
        return 1;
      }
    }
    printf("--\n");
  }

  return 0;
} 
