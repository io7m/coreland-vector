#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

#include "t_mag_data.dat"

int main()
{
  float mag;
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct mag_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        mag = vec_mag4f(tests[ind].va);
        break;
      case 3:
        mag = vec_mag3f(tests[ind].va);
        break;
      case 2:
        mag = vec_mag2f(tests[ind].va);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests[ind].sz; ++jnd) {
      if (!approx_equalf(tests[ind].vr, mag, APPROX_MAX_ERRORF)) {
        printf("fail: [%u] vr %f != mag %f\n",
                ind, tests[ind].vr, mag);
        return 1;
      }
    }
    printf("[%u] mag %f\n", ind, mag);
  }

  return 0;
} 
