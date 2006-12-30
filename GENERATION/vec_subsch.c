#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;

  printf("#define vec_SUBSC%u(va, sc) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (va)[%u] -= (sc); \\\n", ind);
  printf("}\n");
  printf("#define vec_SUBSC%ux(va, vr, sc) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (vr)[%u] = (va)[%u] - (sc); \\\n", ind, ind);
  printf("}\n");
  return 0;
}
