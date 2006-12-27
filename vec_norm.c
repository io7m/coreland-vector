#include <math.h>
#include "vector.h"

void vec_norm2f(float v[2])
{
  float mag =
    (v[0] * v[0]) +
    (v[1] * v[1]);
  if (mag) {
    float mdiv = 1 / sqrtf(mag);
    v[0] *= mdiv;
    v[1] *= mdiv;
  }
}
void vec_norm2fx(const float v[2], float vr[2])
{
  float mag =
    (v[0] * v[0]) +
    (v[1] * v[1]);
  if (mag) {
    float mdiv = 1 / sqrtf(mag);
    vr[0] = v[0] * mdiv;
    vr[1] = v[1] * mdiv;
  }
}

void vec_norm3f(float v[3])
{
  float mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]);
  if (mag) {
    float mdiv = 1 / sqrtf(mag);
    v[0] *= mdiv;
    v[1] *= mdiv;
    v[2] *= mdiv;
  }
}
void vec_norm3fx(const float v[3], float vr[3])
{
  float mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]);
  if (mag) {
    float mdiv = 1 / sqrtf(mag);
    vr[0] = v[0] * mdiv;
    vr[1] = v[1] * mdiv;
    vr[2] = v[2] * mdiv;
  }
}

void vec_norm4f(float v[4])
{
  float mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]) +
    (v[3] * v[3]);
  if (mag) {
    float mdiv = 1 / sqrtf(mag);
    v[0] *= mdiv;
    v[1] *= mdiv;
    v[2] *= mdiv;
    v[3] *= mdiv;
  }
}
void vec_norm4fx(const float v[4], float vr[4])
{
  float mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]) +
    (v[3] * v[3]);
  if (mag) {
    float mdiv = 1 / sqrtf(mag);
    vr[0] = v[0] * mdiv;
    vr[1] = v[1] * mdiv;
    vr[2] = v[2] * mdiv;
    vr[3] = v[3] * mdiv;
  }
}

void vec_norm2d(double v[2])
{
  double mag =
    (v[0] * v[0]) +
    (v[1] * v[1]);
  if (mag) {
    double mdiv = 1 / sqrt(mag);
    v[0] *= mdiv;
    v[1] *= mdiv;
  }
}
void vec_norm2dx(const double v[2], double vr[2])
{
  double mag =
    (v[0] * v[0]) +
    (v[1] * v[1]);
  if (mag) {
    double mdiv = 1 / sqrt(mag);
    vr[0] = v[0] * mdiv;
    vr[1] = v[1] * mdiv;
  }
}

void vec_norm3d(double v[3])
{
  double mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]);
  if (mag) {
    double mdiv = 1 / sqrt(mag);
    v[0] *= mdiv;
    v[1] *= mdiv;
    v[2] *= mdiv;
  }
}
void vec_norm3dx(const double v[3], double vr[3])
{
  double mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]);
  if (mag) {
    double mdiv = 1 / sqrt(mag);
    vr[0] = v[0] * mdiv;
    vr[1] = v[1] * mdiv;
    vr[2] = v[2] * mdiv;
  }
}

void vec_norm4d(double v[4])
{
  double mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]) +
    (v[3] * v[3]);
  if (mag) {
    double mdiv = 1 / sqrt(mag);
    v[0] *= mdiv;
    v[1] *= mdiv;
    v[2] *= mdiv;
    v[3] *= mdiv;
  }
}
void vec_norm4dx(const double v[4], double vr[4])
{
  double mag =
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]) +
    (v[3] * v[3]);
  if (mag) {
    double mdiv = 1 / sqrt(mag);
    vr[0] = v[0] * mdiv;
    vr[1] = v[1] * mdiv;
    vr[2] = v[2] * mdiv;
    vr[3] = v[3] * mdiv;
  }
}

