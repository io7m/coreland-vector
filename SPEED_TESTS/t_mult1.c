#include "frand.h"
#include <stdio.h>
#include <time.h>
#include "vector.h"
#include "test_const.h"

union align16 {
  vector_4f v;
  float f[TEST_VEC_SIZE];
};

struct test {
  union align16 xva;
  union align16 xvb;
  union align16 xvr;
  float *va;
  float *vb;
  float *vr;
};

struct test test;

void fill()
{
  unsigned int ind;

  test.va = (float *) &test.xva;
  test.vb = (float *) &test.xvb;
  test.vr = (float *) &test.xvr;
  for (ind = 0; ind < TEST_VEC_SIZE; ++ind) {
    test.va[ind] = frand();
    test.vb[ind] = frand();
    test.vr[ind] = frand();
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
  if (((unsigned long) test.vb) & 15)
    printf("test.vb unaligned %p\n", &test.vb);
  if (((unsigned long) test.vr) & 15)
    printf("test.vr unaligned %p\n", &test.vr);
 
  t1 = clock();
  for (ind = 0; ind < TEST_ITER; ++ind)
    vec_multNfx(test.va, test.vb, test.vr, TEST_VEC_SIZE);
  t2 = clock();

  t = (float) t2 - t1;
  printf("%f\n", t / CLOCKS_PER_SEC);
  return 0;
}
