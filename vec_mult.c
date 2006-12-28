#include "vector.h"
#include "vec_mult.h"

float *vec_mult2f(float va[2], const float vb[2])
{
  vec_MULT2(va, vb);
  return va;
}
float *vec_mult2fx(const float va[2], const float vb[2], float vr[2])
{
  vec_MULT2x(va, vb, vr);
  return vr;
}

float *vec_mult3f(float va[3], const float vb[3])
{
  vec_MULT3(va, vb);
  return va;
}
float *vec_mult3fx(const float va[3], const float vb[3], float vr[3])
{
  vec_MULT3x(va, vb, vr);
  return vr;
}

float *vec_mult4f(float va[4], const float vb[4])
{
  vec_MULT4(va, vb);
  return va;
}
float *vec_mult4fx(const float va[4], const float vb[4], float vr[4])
{
  vec_MULT4x(va, vb, vr);
  return vr;
}

double *vec_mult2d(double va[2], const double vb[2])
{
  vec_MULT2(va, vb);
  return va;
}
double *vec_mult2dx(const double va[2], const double vb[2], double vr[2])
{
  vec_MULT2x(va, vb, vr);
  return vr;
}

double *vec_mult3d(double va[3], const double vb[3])
{
  vec_MULT3(va, vb);
  return va;
}
double *vec_mult3dx(const double va[3], const double vb[3], double vr[3])
{
  vec_MULT3x(va, vb, vr);
  return vr;
}

double *vec_mult4d(double va[4], const double vb[4])
{
  vec_MULT4(va, vb);
  return va;
}
double *vec_mult4dx(const double va[4], const double vb[4], double vr[4])
{
  vec_MULT4x(va, vb, vr);
  return vr;
}

