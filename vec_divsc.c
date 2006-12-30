#include "vector.h"
#include "vec_divsc.h"

float *vec_divsc2f(float va[2], float sc)
{
  vec_DIVSC2(va, sc);
  return va;
}
float *vec_divsc2fx(const float va[2], float vr[2], float sc)
{
  vec_DIVSC2x(va, vr, sc);
  return vr;
}

float *vec_divsc3f(float va[3], float sc)
{
  vec_DIVSC3(va, sc);
  return va;
}
float *vec_divsc3fx(const float va[3], float vr[3], float sc)
{
  vec_DIVSC3x(va, vr, sc);
  return vr;
}

float *vec_divsc4f(float va[4], float sc)
{
  vec_DIVSC4(va, sc);
  return va;
}
float *vec_divsc4fx(const float va[4], float vr[4], float sc)
{
  vec_DIVSC4x(va, vr, sc);
  return vr;
}

double *vec_divsc2d(double va[2], double sc)
{
  vec_DIVSC2(va, sc);
  return va;
}
double *vec_divsc2dx(const double va[2], double vr[2], double sc)
{
  vec_DIVSC2x(va, vr, sc);
  return vr;
}

double *vec_divsc3d(double va[3], double sc)
{
  vec_DIVSC3(va, sc);
  return va;
}
double *vec_divsc3dx(const double va[3], double vr[3], double sc)
{
  vec_DIVSC3x(va, vr, sc);
  return vr;
}

double *vec_divsc4d(double va[4], double sc)
{
  vec_DIVSC4(va, sc);
  return va;
}
double *vec_divsc4dx(const double va[4], double vr[4], double sc)
{
  vec_DIVSC4x(va, vr, sc);
  return vr;
}

