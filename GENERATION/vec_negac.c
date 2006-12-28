#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  printf("%s *vec_nega%u%s(%s v[%u])\n",
          type, dim, abbr, type, dim);
  printf("{\n");
  printf("  vec_NEGA%u(v);\n", dim);
  printf("  return v;\n");
  printf("}\n");

  printf("%s *vec_nega%u%sx(const %s v[%u], %s vr[%u])\n",
          type, dim, abbr, type, dim, type, dim);
  printf("{\n");
  printf("  vec_NEGA%ux(v, vr);\n", dim);
  printf("  return vr;\n");
  printf("}\n");
  return 0;
}
