#ifndef VEC_NORM_H
#define VEC_NORM_H

float *vec_normNf(float *, unsigned int);
float *vec_normNfx(const float *, float *, unsigned int);
double *vec_normNd(double *, unsigned int);
double *vec_normNdx(const double *, double *, unsigned int);

#define vec_norm2f(va) vec_normNf((va),2)
#define vec_norm3f(va) vec_normNf((va),3)
#define vec_norm4f(va) vec_normNf((va),4)
#define vec_norm2fx(va,vr) vec_normNfx((va),(vr),2)
#define vec_norm3fx(va,vr) vec_normNfx((va),(vr),3)
#define vec_norm4fx(va,vr) vec_normNfx((va),(vr),4)

#define vec_norm2d(va) vec_normNd((va),2)
#define vec_norm3d(va) vec_normNd((va),3)
#define vec_norm4d(va) vec_normNd((va),4)
#define vec_norm2dx(va,vr) vec_normNdx((va),(vr),2)
#define vec_norm3dx(va,vr) vec_normNdx((va),(vr),3)
#define vec_norm4dx(va,vr) vec_normNdx((va),(vr),4)

#endif
