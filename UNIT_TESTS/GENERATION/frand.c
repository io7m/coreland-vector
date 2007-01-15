#include "frand.h"

double frand()
{
  double f;
  double div;
  div = (random() % 1000);
  f = (random() % 10000) - 5000; 
  return f / div;
}
