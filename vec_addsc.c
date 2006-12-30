#include "vector.h"
#include "vec_addsc.h"

float *vec_addsc2f(float va[2], float sc)
{
  vec_ADDSC2(va, sc);
  return va;
}
float *vec_addsc2fx(const float va[2], float vr[2], float sc)
{
  vec_ADDSC2x(va, vr, sc);
  return vr;
}

float *vec_addsc3f(float va[3], float sc)
{
  vec_ADDSC3(va, sc);
  return va;
}
float *vec_addsc3fx(const float va[3], float vr[3], float sc)
{
  vec_ADDSC3x(va, vr, sc);
  return vr;
}

float *vec_addsc4f(float va[4], float sc)
{
  vec_ADDSC4(va, sc);
  return va;
}
float *vec_addsc4fx(const float va[4], float vr[4], float sc)
{
  vec_ADDSC4x(va, vr, sc);
  return vr;
}

double *vec_addsc2d(double va[2], double sc)
{
  vec_ADDSC2(va, sc);
  return va;
}
double *vec_addsc2dx(const double va[2], double vr[2], double sc)
{
  vec_ADDSC2x(va, vr, sc);
  return vr;
}

double *vec_addsc3d(double va[3], double sc)
{
  vec_ADDSC3(va, sc);
  return va;
}
double *vec_addsc3dx(const double va[3], double vr[3], double sc)
{
  vec_ADDSC3x(va, vr, sc);
  return vr;
}

double *vec_addsc4d(double va[4], double sc)
{
  vec_ADDSC4(va, sc);
  return va;
}
double *vec_addsc4dx(const double va[4], double vr[4], double sc)
{
  vec_ADDSC4x(va, vr, sc);
  return vr;
}

