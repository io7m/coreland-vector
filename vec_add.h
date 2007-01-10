#ifndef VEC_ADD_H
#define VEC_ADD_H

float *vec_addNf(float *, const float *, unsigned int);
float *vec_addNfx(const float *, const float *, float *, unsigned int);
double *vec_addNd(double *, const double *, unsigned int);
double *vec_addNdx(const double *, const double *, double *, unsigned int);

#define vec_add2f(va,vb) vec_addNf((va),(vb),2)
#define vec_add3f(va,vb) vec_addNf((va),(vb),3)
#define vec_add4f(va,vb) vec_addNf((va),(vb),4)
#define vec_add2fx(va,vb,vr) vec_addNfx((va),(vb),(vr),2)
#define vec_add3fx(va,vb,vr) vec_addNfx((va),(vb),(vr),3)
#define vec_add4fx(va,vb,vr) vec_addNfx((va),(vb),(vr),4)

#define vec_add2d(va,vb) vec_addNd((va),(vb),2)
#define vec_add3d(va,vb) vec_addNd((va),(vb),3)
#define vec_add4d(va,vb) vec_addNd((va),(vb),4)
#define vec_add2dx(va,vb,vr) vec_addNdx((va),(vb),(vr),2)
#define vec_add3dx(va,vb,vr) vec_addNdx((va),(vb),(vr),3)
#define vec_add4dx(va,vb,vr) vec_addNdx((va),(vb),(vr),4)

#endif
