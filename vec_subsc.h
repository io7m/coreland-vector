#ifndef VEC_SUBSC_H
#define VEC_SUBSC_H

float *vec_subscNf(float *, float, unsigned int);
float *vec_subscNfx(const float *, float *, float, unsigned int);
double *vec_subscNd(double *, double, unsigned int);
double *vec_subscNdx(const double *, double *, double, unsigned int);

#define vec_subsc2f(v,sc) vec_subscNf((v),(sc),2)
#define vec_subsc3f(v,sc) vec_subscNf((v),(sc),3)
#define vec_subsc4f(v,sc) vec_subscNf((v),(sc),4)
#define vec_subsc2fx(v,vr,sc) vec_subscNfx((v),(vr),(sc),2)
#define vec_subsc3fx(v,vr,sc) vec_subscNfx((v),(vr),(sc),3)
#define vec_subsc4fx(v,vr,sc) vec_subscNfx((v),(vr),(sc),4)

#define vec_subsc2d(v,sc) vec_subscNd((v),(sc),2)
#define vec_subsc3d(v,sc) vec_subscNd((v),(sc),3)
#define vec_subsc4d(v,sc) vec_subscNd((v),(sc),4)
#define vec_subsc2dx(v,vr,sc) vec_subscNdx((v),(vr),(sc),2)
#define vec_subsc3dx(v,vr,sc) vec_subscNdx((v),(vr),(sc),3)
#define vec_subsc4dx(v,vr,sc) vec_subscNdx((v),(vr),(sc),4)

#endif
