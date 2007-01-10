#ifndef VEC_SUB_H
#define VEC_SUB_H

float *vec_subNf(float *, const float *, unsigned int);
float *vec_subNfx(const float *, const float *, float *, unsigned int);
double *vec_subNd(double *, const double *, unsigned int);
double *vec_subNdx(const double *, const double *, double *, unsigned int);

#define vec_sub2f(va,vb) vec_subNf((va),(vb),2)
#define vec_sub3f(va,vb) vec_subNf((va),(vb),3)
#define vec_sub4f(va,vb) vec_subNf((va),(vb),4)
#define vec_sub2fx(va,vb,vr) vec_subNfx((va),(vb),(vr),2)
#define vec_sub3fx(va,vb,vr) vec_subNfx((va),(vb),(vr),3)
#define vec_sub4fx(va,vb,vr) vec_subNfx((va),(vb),(vr),4)

#define vec_sub2d(va,vb) vec_subNd((va),(vb),2)
#define vec_sub3d(va,vb) vec_subNd((va),(vb),3)
#define vec_sub4d(va,vb) vec_subNd((va),(vb),4)
#define vec_sub2dx(va,vb,vr) vec_subNdx((va),(vb),(vr),2)
#define vec_sub3dx(va,vb,vr) vec_subNdx((va),(vb),(vr),3)
#define vec_sub4dx(va,vb,vr) vec_subNdx((va),(vb),(vr),4)

#endif
