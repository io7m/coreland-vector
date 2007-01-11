#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_add_data.c"

int main()
{
  float tmp[4] = {0, 0, 0, 0};
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct add_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        vec_add4fx(tests[ind].va, tests[ind].vb, tmp);
        break;
      case 3:
        vec_add3fx(tests[ind].va, tests[ind].vb, tmp);
        break;
      case 2:
        vec_add2fx(tests[ind].va, tests[ind].vb, tmp);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests[ind].sz; ++jnd) {
      if (!approx_equalf(tests[ind].vr[jnd], tmp[jnd], APPROX_MAX_ERROR)) {
        printf("fail: [%u] vr[%u] %f != tmp[%u] %f\n",
                ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
        return 1;
      }
      printf("[%u] vr[%u] %f ~ tmp[%u] %f\n",
              ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
    }
    printf("--\n");
  }

  return 0;
} 
