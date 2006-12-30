#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  printf("%s *vec_multsc%u%s(%s [%u], %s);\n",
          type, dim, abbr, type, dim, type);
  printf("%s *vec_multsc%u%sx(const %s [%u], %s [%u], %s);\n",
          type, dim, abbr, type, dim, type, dim, type);
  return 0;
}
