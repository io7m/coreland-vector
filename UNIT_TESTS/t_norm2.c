#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_norm_data.c"

int main()
{
  float mag;
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct norm_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        vec_norm4f(tests[ind].va);
        break;
      case 3:
        vec_norm3f(tests[ind].va);
        break;
      case 2:
        vec_norm2f(tests[ind].va);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    mag = 0.0;
    for (jnd = 0; jnd < tests[ind].sz; ++jnd) {
      if (!approx_equalf(tests[ind].vr[jnd],
                         tests[ind].va[jnd], APPROX_MAX_ERROR)) {
        printf("fail: [%u] vr[%u] %f != va[%u] %f\n",
                ind, jnd, tests[ind].vr[jnd], jnd, tests[ind].va[jnd]);
        return 1;
      }
      mag += (tests[ind].va[jnd] * tests[ind].va[jnd]);
      printf("[%u] vr[%u] %f ~ va[%u] %f\n",
              ind, jnd, tests[ind].vr[jnd], jnd, tests[ind].va[jnd]);
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
