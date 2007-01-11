#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_multsc_data.c"

int main()
{
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct multsc_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        vec_multsc4f(tests[ind].va, tests[ind].sc);
        break;
      case 3:
        vec_multsc3f(tests[ind].va, tests[ind].sc);
        break;
      case 2:
        vec_multsc2f(tests[ind].va, tests[ind].sc);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests[ind].sz; ++jnd) {
      if (!approx_equalf(tests[ind].vr[jnd],
                         tests[ind].va[jnd], APPROX_MAX_ERROR * 10)) {
        printf("fail: [%u] vr[%u] %f != va[%u] %f\n",
                ind, jnd, tests[ind].vr[jnd], jnd, tests[ind].va[jnd]);
        return 1;
      }
      printf("[%u] vr[%u] %f ~ va[%u] %f\n",
              ind, jnd, tests[ind].vr[jnd], jnd, tests[ind].va[jnd]);
    }
    printf("--\n");
  }

  return 0;
} 
