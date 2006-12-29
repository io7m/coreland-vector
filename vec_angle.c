#include <math.h>
#include "vector.h"

float vec_angle2f(const float va[2], const float vb[2])
{
  return acosf(vec_dotprod2f(va, vb) /
           (vec_mag2f(va) * vec_mag2f(vb)));
}

float vec_angle3f(const float va[3], const float vb[3])
{
  return acosf(vec_dotprod3f(va, vb) /
           (vec_mag3f(va) * vec_mag3f(vb)));
}

float vec_angle4f(const float va[4], const float vb[4])
{
  return acosf(vec_dotprod4f(va, vb) /
           (vec_mag4f(va) * vec_mag4f(vb)));
}

double vec_angle2d(const double va[2], const double vb[2])
{
  return acos(vec_dotprod2d(va, vb) /
           (vec_mag2d(va) * vec_mag2d(vb)));
}

double vec_angle3d(const double va[3], const double vb[3])
{
  return acos(vec_dotprod3d(va, vb) /
           (vec_mag3d(va) * vec_mag3d(vb)));
}

double vec_angle4d(const double va[4], const double vb[4])
{
  return acos(vec_dotprod4d(va, vb) /
           (vec_mag4d(va) * vec_mag4d(vb)));
}

