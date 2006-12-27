#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;
  const char *sqr;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  if (strcmp(type, "float") == 0)
    sqr = "sqrtf";
  else
    sqr = "sqrt";

  printf("%s vec_mag%u%s(const %s v[%u])\n",
          type, dim, abbr, type, dim);
  printf("{\n");
  printf("  return %s(\n", sqr);
  for (ind = 0; ind < dim; ++ind) {
    printf("    (v[%u] * v[%u])", ind, ind);
    if (ind != dim - 1)
      printf(" +\n");
    else printf("\n");
  }
  printf("  );\n");
  printf("}\n");
  return 0;
}
