#include "frand.h"
#include <stdio.h>
#include <time.h>
#include "vector.h"
#include "v_align.h"


union align16 {
  vector_4f v;
  float f[TEST_VEC_SIZE];
};

struct test {
  union align16 xva;
  union align16 xvr;
  float *va;
  float *vr;
  float sc;
};

struct test test;

void fill()
{
  unsigned int ind;

  test.va = (float *) &test.xva;
  test.vr = (float *) &test.xvr;
  for (ind = 0; ind < TEST_VEC_SIZE; ++ind) {
    test.va[ind] = frand();
    test.vr[ind] = frand();
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
  if (vec_unaligned(test.vr))
    fprintf(stderr, "test.vr unaligned %p\n", &test.vr);
 
  t1 = clock();
  for (ind = 0; ind < TEST_ITER; ++ind)
    vec_addscNfx(test.va, test.vr, test.sc, TEST_VEC_SIZE);
  t2 = clock();

  t = (double) t2 - t1;
  printf("%.15f\n", t / CLOCKS_PER_SEC);
  return 0;
}
