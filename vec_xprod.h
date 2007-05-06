#ifndef VEC_XPROD_H
#define VEC_XPROD_H

float *vec_crossprod3fx(const float [3], const float [3], float [3]);
double *vec_crossprod3dx(const double [3], const double [3], double [3]);

#define vec_CROSSPROD3x(va, vb, vr) \
{ \
  (vr)[0] = ((va)[1] * (vb)[2]) - ((va)[2] - (vb)[1]); \
  (vr)[1] = ((va)[2] * (vb)[0]) - ((va)[0] - (vb)[2]); \
  (vr)[2] = ((va)[0] * (vb)[1]) - ((va)[1] - (vb)[0]); \
}

#endif
