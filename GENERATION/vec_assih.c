#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;

  printf("#define vec_ASSIGN%u(va, vb) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (va)[%u] = (vb)[%u]; \\\n", ind, ind);
  printf("}\n");
  return 0;
}
