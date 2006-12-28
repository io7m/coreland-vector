#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  printf("%s *vec_sub%u%s(%s va[%u], const %s vb[%u])\n",
          type, dim, abbr, type, dim, type, dim);
  printf("{\n");
  printf("  vec_SUB%u(va, vb);\n", dim);
  printf("  return va;\n");
  printf("}\n");

  printf("%s *vec_sub%u%sx(const %s va[%u], const %s vb[%u], %s vr[%u])\n",
          type, dim, abbr, type, dim, type, dim, type, dim);
  printf("{\n");
  printf("  vec_SUB%ux(va, vb, vr);\n", dim);
  printf("  return vr;\n");
  printf("}\n");
  return 0;
}
