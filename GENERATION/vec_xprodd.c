#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  printf("%s *vec_crossprod%u%sx(const %s [%u], const %s [%u], %s [%u]);\n",
          type, dim, abbr, type, dim, type, dim, type, dim);
  return 0;
}
