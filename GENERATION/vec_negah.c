#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;

  printf("#define vec_NEGA%u(v) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (va)[%u] = -(v)[%u]; \\\n", ind, ind);
  printf("}\n");
  printf("#define vec_NEGA%ux(v, vr) \\\n", dim);
  printf("{ \\\n");
  for (ind = 0; ind < dim; ++ind)
    printf("  (vr)[%u] = -(v)[%u]; \\\n", ind, ind);
  printf("}\n");
  return 0;
}
