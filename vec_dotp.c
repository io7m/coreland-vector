#include "vector.h"
#include "vec_dotp.h"

float vec_dotprod2f(const float va[2], const float vb[2])
{
  return vec_DOTPROD2(va, vb);
}

float vec_dotprod3f(const float va[3], const float vb[3])
{
  return vec_DOTPROD3(va, vb);
}

float vec_dotprod4f(const float va[4], const float vb[4])
{
  return vec_DOTPROD4(va, vb);
}

double vec_dotprod2d(const double va[2], const double vb[2])
{
  return vec_DOTPROD2(va, vb);
}

double vec_dotprod3d(const double va[3], const double vb[3])
{
  return vec_DOTPROD3(va, vb);
}

double vec_dotprod4d(const double va[4], const double vb[4])
{
  return vec_DOTPROD4(va, vb);
}

