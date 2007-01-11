#include <stdio.h>
#include <time.h>
#include "vector.h"

#define VEC_SIZE 128
#define TEST_ITER 20000000

union align16 {
  char x[16];
  float f[VEC_SIZE];
};

struct test {
  union align16 xva;
  union align16 xvr;
  float *va;
  float *vr;
  float sc;
};

struct test test;

float frand()
{
  float f;
  float div;
  div = (random() % 1000);
  f = (random() % 10000) - 5000; 
  return f / div;
}

void fill()
{
  unsigned int ind;

  test.va = (float *) &test.xva;
  test.vr = (float *) &test.xvr;
  for (ind = 0; ind < VEC_SIZE; ++ind) {
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
  float t;

  fill(); 

  if (((unsigned long) test.va) & 15)
    printf("test.va unaligned %p\n", &test.va);
  if (((unsigned long) test.vr) & 15)
    printf("test.vr unaligned %p\n", &test.vr);
 
  t1 = clock();
  for (ind = 0; ind < TEST_ITER; ++ind)
    vec_subscNfx(test.va, test.vr, test.sc, VEC_SIZE);
  t2 = clock();

  t = (float) t2 - t1;
  printf("%f\n", t / CLOCKS_PER_SEC);
  return 0;
}
