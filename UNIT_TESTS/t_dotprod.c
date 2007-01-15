#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_dotp_data.c"

int main()
{
  float res;
  unsigned int ind;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct dotprod_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        res = vec_dotprod4f(tests[ind].va, tests[ind].vb);
        break;
      case 3:
        res = vec_dotprod3f(tests[ind].va, tests[ind].vb);
        break;
      case 2:
        res = vec_dotprod2f(tests[ind].va, tests[ind].vb);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }

    /* APPROX_MAX_ERRORF multiplied because results are likely to be
       larger due to dot product */

    if (!approx_equalf(tests[ind].res, res, APPROX_MAX_ERRORF * 10.0)) {
      printf("fail: [%u] res %f != %f\n", ind, tests[ind].res, res);
      return 1;
    }
    printf("[%u] dotprod(va) %f ~ res %f\n", ind, tests[ind].res, res);
  }

  return 0;
} 
