#include "vector.h"
#include "vec_sub.h"

void vec_sub2f(float va[2], const float vb[2])
{
  vec_SUB2(va, vb);
}
void vec_sub2fx(const float va[2], const float vb[2], float vr[2])
{
  vec_SUB2x(va, vb, vr);
}

void vec_sub3f(float va[3], const float vb[3])
{
  vec_SUB3(va, vb);
}
void vec_sub3fx(const float va[3], const float vb[3], float vr[3])
{
  vec_SUB3x(va, vb, vr);
}

void vec_sub4f(float va[4], const float vb[4])
{
  vec_SUB4(va, vb);
}
void vec_sub4fx(const float va[4], const float vb[4], float vr[4])
{
  vec_SUB4x(va, vb, vr);
}

void vec_sub2d(double va[2], const double vb[2])
{
  vec_SUB2(va, vb);
}
void vec_sub2dx(const double va[2], const double vb[2], double vr[2])
{
  vec_SUB2x(va, vb, vr);
}

void vec_sub3d(double va[3], const double vb[3])
{
  vec_SUB3(va, vb);
}
void vec_sub3dx(const double va[3], const double vb[3], double vr[3])
{
  vec_SUB3x(va, vb, vr);
}

void vec_sub4d(double va[4], const double vb[4])
{
  vec_SUB4(va, vb);
}
void vec_sub4dx(const double va[4], const double vb[4], double vr[4])
{
  vec_SUB4x(va, vb, vr);
}

