#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_addsc_data.c"

int main()
{
  float tmp[4] = {0.0, 0.0, 0.0, 0.0};
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct addsc_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        vec_addsc4fx(tests[ind].va, tmp, tests[ind].sc);
        break;
      case 3:
        vec_addsc3fx(tests[ind].va, tmp, tests[ind].sc);
        break;
      case 2:
        vec_addsc2fx(tests[ind].va, tmp, tests[ind].sc);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests[ind].sz; ++jnd) {
      if (!approx_equalf(tests[ind].vr[jnd], tmp[jnd], APPROX_MAX_ERROR)) {
        printf("fail: [%u] vr[%u] %f != va[%u] %f\n",
                ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
        return 1;
      }
      printf("[%u] vr[%u] %f ~ va[%u] %f\n",
              ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
    }
    printf("--\n");
  }

  return 0;
} 
