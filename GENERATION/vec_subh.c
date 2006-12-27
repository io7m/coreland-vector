#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;

  printf("#define vec_SUB%u(va, vb) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (va)[%u] -= (vb)[%u]; \\\n", ind, ind);
  printf("}\n");
  printf("#define vec_SUB%ux(va, vb, vr) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (vr)[%u] = (va)[%u] - (vb)[%u]; \\\n", ind, ind, ind);
  printf("}\n");
  return 0;
}
