#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  printf("%s *vec_multsc%u%s(%s va[%u], %s sc)\n",
          type, dim, abbr, type, dim, type);
  printf("{\n");
  printf("  vec_MULTSC%u(va, sc);\n", dim);
  printf("  return va;\n");
  printf("}\n");

  printf("%s *vec_multsc%u%sx(const %s va[%u], %s vr[%u], %s sc)\n",
          type, dim, abbr, type, dim, type, dim, type);
  printf("{\n");
  printf("  vec_MULTSC%ux(va, vr, sc);\n", dim);
  printf("  return vr;\n");
  printf("}\n");
  return 0;
}
