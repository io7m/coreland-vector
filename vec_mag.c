#include <math.h>

float vec_mag2f(const float v[2])
{
  return sqrtf(
    (v[0] * v[0]) +
    (v[1] * v[1])
  );
}

float vec_mag3f(const float v[3])
{
  return sqrtf(
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2])
  );
}

float vec_mag4f(const float v[4])
{
  return sqrtf(
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]) +
    (v[3] * v[3])
  );
}

double vec_mag2d(const double v[2])
{
  return sqrt(
    (v[0] * v[0]) +
    (v[1] * v[1])
  );
}

double vec_mag3d(const double v[3])
{
  return sqrt(
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2])
  );
}

double vec_mag4d(const double v[4])
{
  return sqrt(
    (v[0] * v[0]) +
    (v[1] * v[1]) +
    (v[2] * v[2]) +
    (v[3] * v[3])
  );
}

