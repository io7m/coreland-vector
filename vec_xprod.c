#include "vector.h"
#include "vec_xprod.h"

void vec_crossprod3fx(const float va[3], const float vb[3], float vr[3])
{
  vec_CROSSPROD3x(va, vb, vr);
}

void vec_crossprod3dx(const double va[3], const double vb[3], double vr[3])
{
  vec_CROSSPROD3x(va, vb, vr);
}

