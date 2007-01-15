#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "frand.h"

float fa[4];
float fb[4];
unsigned int ind;
unsigned int sz;

void f_print(unsigned int sz, unsigned int ind)
{
  printf("  {\n");
  printf("    {%f, %f, %f, %f},\n", fa[0], fa[1], fa[2], fa[3]);
  printf("    {%f, %f, %f, %f},\n", fb[0], fb[1], fb[2], fb[3]);
  printf("    {%f, %f, %f, %f},\n",
          fa[0] + fb[0], fa[1] + fb[1], fa[2] + fb[2], fa[3] + fb[3]);
  printf("    %u,\n", sz);
  printf("  },\n");
}
void f_gen(unsigned int sz)
{
  unsigned int ind;

  fa[0] = fa[1] = fa[2] = fa[3] = 0;
  fb[0] = fb[1] = fb[2] = fb[3] = 0;
  for (ind = 0; ind < sz; ++ind) {
    fa[ind] = frand();
    fb[ind] = frand();
  }
}

int main()
{
  srandom(time(0));

  sz = 2;
  printf("struct add_testf tests_f[] = {\n");
  f_print(4, 0);
  for (ind = 1; ind < 30; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    f_gen(sz);
    f_print(sz, ind);
  }
  printf("};\n");

  fa[0] = fa[1] = fa[2] = fa[3] = 0;
  fb[0] = fb[1] = fb[2] = fb[3] = 0;
  sz = 2;
  printf("struct add_testd tests_d[] = {\n");
  f_print(4, 0);
  for (ind = 1; ind < 30; ++ind) {
    if (ind && !(ind % 10)) ++sz;
    f_gen(sz);
    f_print(sz, ind);
  }
  printf("};\n");
  return 0;
}
