#include "frand.h"
#include <stdio.h>
#include <time.h>
#include "vector.h"


union align16 {
  vector_4f v;
  float f[TEST_VEC_SIZE];
};

struct test {
  union align16 xva;
  float *va;
  float sc;
};

struct test test;

void fill()
{
  unsigned int ind;

  test.va = (float *) &test.xva;
  for (ind = 0; ind < TEST_VEC_SIZE; ++ind) {
    test.va[ind] = frand();
  }
  test.sc = frand();
}

int main()
{
  unsigned long t1;
  unsigned long t2;
  unsigned int ind;
  double t;

  fill(); 

  if (vec_unaligned(test.va))
    fprintf(stderr, "test.va unaligned %p\n", &test.va);
 
  t1 = clock();
  for (ind = 0; ind < TEST_ITER; ++ind)
    vec_subscNf(test.va, test.sc, TEST_VEC_SIZE);
  t2 = clock();

  t = (double) t2 - t1;
  printf("%.15f\n", t / CLOCKS_PER_SEC);
  return 0;
}
