#include <stdio.h>
#include "vecgen.h"

/* cross product only applies to three dimensional vectors */

int gen(struct vecgen *vg)
{
  unsigned int ind;
  unsigned int dim = vg->dim;

  printf("#define vec_CROSSPROD%ux(va, vb, vr) \\\n", dim);
  printf("{ \\\n");
  printf("  (vr)[0] = ((va)[1] * (vb)[2]) - ((va)[2] - (vb)[1]); \\\n");
  printf("  (vr)[1] = ((va)[2] * (vb)[0]) - ((va)[0] - (vb)[2]); \\\n");
  printf("  (vr)[2] = ((va)[0] * (vb)[1]) - ((va)[1] - (vb)[0]); \\\n");
  printf("}\n");
  return 0;
}
