#include "vector.h"
#include "vec_assi.h"

float *vec_assign2f(float va[2], const float vb[2])
{
  vec_ASSIGN2(va, vb);
  return va;
}

float *vec_assign3f(float va[3], const float vb[3])
{
  vec_ASSIGN3(va, vb);
  return va;
}

float *vec_assign4f(float va[4], const float vb[4])
{
  vec_ASSIGN4(va, vb);
  return va;
}

double *vec_assign2d(double va[2], const double vb[2])
{
  vec_ASSIGN2(va, vb);
  return va;
}

double *vec_assign3d(double va[3], const double vb[3])
{
  vec_ASSIGN3(va, vb);
  return va;
}

double *vec_assign4d(double va[4], const double vb[4])
{
  vec_ASSIGN4(va, vb);
  return va;
}

