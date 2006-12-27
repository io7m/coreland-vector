#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  printf("void vec_add%u%s(%s va[%u], const %s vb[%u])\n",
          dim, abbr, type, dim, type, dim);
  printf("{\n");
  printf("  vec_ADD%u(va, vb);\n", dim);
  printf("}\n");

  printf("void vec_add%u%sx(const %s va[%u], const %s vb[%u], %s vr[%u])\n",
          dim, abbr, type, dim, type, dim, type, dim);
  printf("{\n");
  printf("  vec_ADD%ux(va, vb, vr);\n", dim);
  printf("}\n");
  return 0;
}
