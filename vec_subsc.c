#include "vector.h"
#include "vec_subsc.h"

float *vec_subsc2f(float va[2], float sc)
{
  vec_SUBSC2(va, sc);
  return va;
}
float *vec_subsc2fx(const float va[2], float vr[2], float sc)
{
  vec_SUBSC2x(va, vr, sc);
  return vr;
}

float *vec_subsc3f(float va[3], float sc)
{
  vec_SUBSC3(va, sc);
  return va;
}
float *vec_subsc3fx(const float va[3], float vr[3], float sc)
{
  vec_SUBSC3x(va, vr, sc);
  return vr;
}

float *vec_subsc4f(float va[4], float sc)
{
  vec_SUBSC4(va, sc);
  return va;
}
float *vec_subsc4fx(const float va[4], float vr[4], float sc)
{
  vec_SUBSC4x(va, vr, sc);
  return vr;
}

double *vec_subsc2d(double va[2], double sc)
{
  vec_SUBSC2(va, sc);
  return va;
}
double *vec_subsc2dx(const double va[2], double vr[2], double sc)
{
  vec_SUBSC2x(va, vr, sc);
  return vr;
}

double *vec_subsc3d(double va[3], double sc)
{
  vec_SUBSC3(va, sc);
  return va;
}
double *vec_subsc3dx(const double va[3], double vr[3], double sc)
{
  vec_SUBSC3x(va, vr, sc);
  return vr;
}

double *vec_subsc4d(double va[4], double sc)
{
  vec_SUBSC4(va, sc);
  return va;
}
double *vec_subsc4dx(const double va[4], double vr[4], double sc)
{
  vec_SUBSC4x(va, vr, sc);
  return vr;
}

