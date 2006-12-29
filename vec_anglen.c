#include <math.h>
#include "vector.h"

float vec_anglenorm2f(const float va[2], const float vb[2])
{
  return acosf(vec_dotprod2f(va, vb));
}

float vec_anglenorm3f(const float va[3], const float vb[3])
{
  return acosf(vec_dotprod3f(va, vb));
}

float vec_anglenorm4f(const float va[4], const float vb[4])
{
  return acosf(vec_dotprod4f(va, vb));
}

double vec_anglenorm2d(const double va[2], const double vb[2])
{
  return acos(vec_dotprod2d(va, vb));
}

double vec_anglenorm3d(const double va[3], const double vb[3])
{
  return acos(vec_dotprod3d(va, vb));
}

double vec_anglenorm4d(const double va[4], const double vb[4])
{
  return acos(vec_dotprod4d(va, vb));
}

