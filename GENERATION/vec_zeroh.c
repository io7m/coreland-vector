#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;

  printf("#define vec_ZERO%u(v) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (v)[%u] = 0; \\\n", ind);
  printf("} \n");
  return 0;
}
