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

  printf("%s *vec_norm%u%s(%s v[%u])\n",
          type, dim, abbr, type, dim);
  printf("{\n");
  printf("  %s mag =\n", type);
  for (ind = 0; ind < dim; ++ind) {
    printf("    (v[%u] * v[%u])", ind, ind);
    if (ind != dim - 1)
      printf(" +\n");
    else
      printf(";\n");
  }
  printf("  if (mag) {\n");
  printf("    %s mdiv = 1 / %s(mag);\n", type, sqr);
  for (ind = 0; ind < dim; ++ind) {
    printf("    v[%u] *= mdiv;\n", ind);
  }
  printf("  }\n");
  printf("  return v;\n");
  printf("}\n");

  printf("%s *vec_norm%u%sx(const %s v[%u], %s vr[%u])\n",
          type, dim, abbr, type, dim, type, dim);
  printf("{\n");
  printf("  %s mag =\n", type);
  for (ind = 0; ind < dim; ++ind) {
    printf("    (v[%u] * v[%u])", ind, ind);
    if (ind != dim - 1)
      printf(" +\n");
    else
      printf(";\n");
  }
  printf("  if (mag) {\n");
  printf("    %s mdiv = 1 / %s(mag);\n", type, sqr);
  for (ind = 0; ind < dim; ++ind) {
    printf("    vr[%u] = v[%u] * mdiv;\n", ind, ind);
  }
  printf("  }\n");
  printf("  return vr;\n");
  printf("}\n");
  return 0;
}
