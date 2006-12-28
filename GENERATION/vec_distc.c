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

  printf("%s vec_dist%u%s(const %s va[%u], const %s vb[%u])\n",
          type, dim, abbr, type, dim, type, dim);
  printf("{\n");
  printf("  %s d;\n", type);
  printf("  return d;\n");
  printf("}\n");

  return 0;
}
