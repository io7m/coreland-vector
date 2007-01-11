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
  float *va;
  float *vb;
  float *vr;
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
  for (ind = 0; ind < VEC_SIZE; ++ind) {
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
    vec_zeroNf(test.va, VEC_SIZE);
  t2 = clock();

  t = (float) t2 - t1;
  printf("%f\n", t / CLOCKS_PER_SEC);
  return 0;
}
