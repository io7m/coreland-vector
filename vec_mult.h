#ifndef VEC_MULT_H
#define VEC_MULT_H

float *vec_multNf(float *, const float *, unsigned int);
float *vec_multNfx(const float *, const float *, float *, unsigned int);
double *vec_multNd(double *, const double *, unsigned int);
double *vec_multNdx(const double *, const double *, double *, unsigned int);

#define vec_mult2f(va,vb) vec_multNf((va),(vb),2)
#define vec_mult3f(va,vb) vec_multNf((va),(vb),3)
#define vec_mult4f(va,vb) vec_multNf((va),(vb),4)
#define vec_mult2fx(va,vb,vr) vec_multNfx((va),(vb),(vr),2)
#define vec_mult3fx(va,vb,vr) vec_multNfx((va),(vb),(vr),3)
#define vec_mult4fx(va,vb,vr) vec_multNfx((va),(vb),(vr),4)

#define vec_mult2d(va,vb) vec_multNd((va),(vb),2)
#define vec_mult3d(va,vb) vec_multNd((va),(vb),3)
#define vec_mult4d(va,vb) vec_multNd((va),(vb),4)
#define vec_mult2dx(va,vb,vr) vec_multNdx((va),(vb),(vr),2)
#define vec_mult3dx(va,vb,vr) vec_multNdx((va),(vb),(vr),3)
#define vec_mult4dx(va,vb,vr) vec_multNdx((va),(vb),(vr),4)

#endif
