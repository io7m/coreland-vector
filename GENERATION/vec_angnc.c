#include <stdio.h>
#include "vecgen.h"

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;
  const char *type = vg->type;
  const char *abbr = vg->abbrev;
  const char *acos;

  if (!type) { fprintf(stderr, "gen: type not specified\n"); return 112; }

  if (strcmp(type, "float") == 0)
    acos = "acosf";
  else
    acos = "acos";

  printf("%s vec_anglenorm%u%s(const %s va[%u], const %s vb[%u])\n",
          type, dim, abbr, type, dim, type, dim);
  printf("{\n");
  printf("  return %s(vec_dotprod%u%s(va, vb));\n", acos, dim, abbr);
  printf("}\n");

  return 0;
}
