#include "vector.h"
#include "vec_add.h"

void vec_add2f(float va[2], const float vb[2])
{
  vec_ADD2(va, vb);
}
void vec_add2fx(const float va[2], const float vb[2], float vr[2])
{
  vec_ADD2x(va, vb, vr);
}

void vec_add3f(float va[3], const float vb[3])
{
  vec_ADD3(va, vb);
}
void vec_add3fx(const float va[3], const float vb[3], float vr[3])
{
  vec_ADD3x(va, vb, vr);
}

void vec_add4f(float va[4], const float vb[4])
{
  vec_ADD4(va, vb);
}
void vec_add4fx(const float va[4], const float vb[4], float vr[4])
{
  vec_ADD4x(va, vb, vr);
}

void vec_add2d(double va[2], const double vb[2])
{
  vec_ADD2(va, vb);
}
void vec_add2dx(const double va[2], const double vb[2], double vr[2])
{
  vec_ADD2x(va, vb, vr);
}

void vec_add3d(double va[3], const double vb[3])
{
  vec_ADD3(va, vb);
}
void vec_add3dx(const double va[3], const double vb[3], double vr[3])
{
  vec_ADD3x(va, vb, vr);
}

void vec_add4d(double va[4], const double vb[4])
{
  vec_ADD4(va, vb);
}
void vec_add4dx(const double va[4], const double vb[4], double vr[4])
{
  vec_ADD4x(va, vb, vr);
}

