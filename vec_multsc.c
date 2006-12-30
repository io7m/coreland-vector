#include "vector.h"
#include "vec_multsc.h"

float *vec_multsc2f(float va[2], float sc)
{
  vec_MULTSC2(va, sc);
  return va;
}
float *vec_multsc2fx(const float va[2], float vr[2], float sc)
{
  vec_MULTSC2x(va, vr, sc);
  return vr;
}

float *vec_multsc3f(float va[3], float sc)
{
  vec_MULTSC3(va, sc);
  return va;
}
float *vec_multsc3fx(const float va[3], float vr[3], float sc)
{
  vec_MULTSC3x(va, vr, sc);
  return vr;
}

float *vec_multsc4f(float va[4], float sc)
{
  vec_MULTSC4(va, sc);
  return va;
}
float *vec_multsc4fx(const float va[4], float vr[4], float sc)
{
  vec_MULTSC4x(va, vr, sc);
  return vr;
}

double *vec_multsc2d(double va[2], double sc)
{
  vec_MULTSC2(va, sc);
  return va;
}
double *vec_multsc2dx(const double va[2], double vr[2], double sc)
{
  vec_MULTSC2x(va, vr, sc);
  return vr;
}

double *vec_multsc3d(double va[3], double sc)
{
  vec_MULTSC3(va, sc);
  return va;
}
double *vec_multsc3dx(const double va[3], double vr[3], double sc)
{
  vec_MULTSC3x(va, vr, sc);
  return vr;
}

double *vec_multsc4d(double va[4], double sc)
{
  vec_MULTSC4(va, sc);
  return va;
}
double *vec_multsc4dx(const double va[4], double vr[4], double sc)
{
  vec_MULTSC4x(va, vr, sc);
  return vr;
}

