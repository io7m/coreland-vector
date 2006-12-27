#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;

  printf("#define vec_DOTPROD%u(va, vb) \\\n", dim);
  for (ind = 0; ind < dim; ++ind) {
    printf("  ((va)[%u] * (vb)[%u])", ind, ind);
    if (ind != dim - 1)
      printf(" + \\\n");
  }
  printf("\n");
  return 0;
}
