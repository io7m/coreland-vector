#include "frand.h"

#define RANDOM_MAX 100000

double frand()
{
  double num;
  double div;

  for (;;) {
    div = (random() % (RANDOM_MAX / 10));
    num = (random() % RANDOM_MAX) - (RANDOM_MAX >> 1); 
    num /= div;
    if (!isinf(num) && !isnan(num)) break;
  }

  return num;
}
