#include "vector.h"
#include "vec_div.h"

float *vec_div2f(float va[2], const float vb[2])
{
  vec_DIV2(va, vb);
  return va;
}
float *vec_div2fx(const float va[2], const float vb[2], float vr[2])
{
  vec_DIV2x(va, vb, vr);
  return vr;
}

float *vec_div3f(float va[3], const float vb[3])
{
  vec_DIV3(va, vb);
  return va;
}
float *vec_div3fx(const float va[3], const float vb[3], float vr[3])
{
  vec_DIV3x(va, vb, vr);
  return vr;
}

float *vec_div4f(float va[4], const float vb[4])
{
  vec_DIV4(va, vb);
  return va;
}
float *vec_div4fx(const float va[4], const float vb[4], float vr[4])
{
  vec_DIV4x(va, vb, vr);
  return vr;
}

double *vec_div2d(double va[2], const double vb[2])
{
  vec_DIV2(va, vb);
  return va;
}
double *vec_div2dx(const double va[2], const double vb[2], double vr[2])
{
  vec_DIV2x(va, vb, vr);
  return vr;
}

double *vec_div3d(double va[3], const double vb[3])
{
  vec_DIV3(va, vb);
  return va;
}
double *vec_div3dx(const double va[3], const double vb[3], double vr[3])
{
  vec_DIV3x(va, vb, vr);
  return vr;
}

double *vec_div4d(double va[4], const double vb[4])
{
  vec_DIV4(va, vb);
  return va;
}
double *vec_div4dx(const double va[4], const double vb[4], double vr[4])
{
  vec_DIV4x(va, vb, vr);
  return vr;
}

