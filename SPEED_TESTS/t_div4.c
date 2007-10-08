#include "frand.h"
#include <stdio.h>
#include <time.h>
#include "vector.h"


union align16 {
  vector_4d v;
  double f[TEST_VEC_SIZE];
};

struct test {
  union align16 xva;
  union align16 xvb;
  double *va;
  double *vb;
};

struct test test;

void fill()
{
  unsigned int ind;

  test.va = (double *) &test.xva;
  test.vb = (double *) &test.xvb;
  for (ind = 0; ind < TEST_VEC_SIZE; ++ind) {
    test.va[ind] = frand();
    test.vb[ind] = frand();
  }
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
  if (vec_unaligned(test.vb))
    fprintf(stderr, "test.vb unaligned %p\n", &test.vb);
 
  t1 = clock();
  for (ind = 0; ind < TEST_ITER; ++ind)
    vec_divNd(test.va, test.vb, TEST_VEC_SIZE);
  t2 = clock();

  t = (double) t2 - t1;
  printf("%.15f\n", t / CLOCKS_PER_SEC);
  return 0;
}
