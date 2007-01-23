#include "frand.h"
#include <stdio.h>
#include <time.h>
#include "vector.h"
#include "test_const.h"

union align16 {
  vector_4d v;
  double f[TEST_VEC_SIZE];
};

struct test {
  union align16 xva;
  double *va;
  double *vb;
  double *vr;
};

struct test test;

void fill()
{
  unsigned int ind;

  test.va = (double *) &test.xva;
  for (ind = 0; ind < TEST_VEC_SIZE; ++ind) {
    test.va[ind] = frand();
  }
}

int main()
{
  unsigned long t1;
  unsigned long t2;
  unsigned int ind;
  float t;

  fill(); 

  if (((unsigned long) test.va) & 15)
    printf("test.va unaligned %p\n", &test.va);
 
  t1 = clock();
  for (ind = 0; ind < TEST_ITER; ++ind)
    vec_zeroNd(test.va, TEST_VEC_SIZE);
  t2 = clock();

  t = (float) t2 - t1;
  printf("%f\n", t / CLOCKS_PER_SEC);
  return 0;
}
