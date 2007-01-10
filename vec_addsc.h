#ifndef VEC_ADDSC_H
#define VEC_ADDSC_H

float *vec_addscNf(float *, float, unsigned int);
float *vec_addscNfx(const float *, float *, float, unsigned int);
double *vec_addscNd(double *, double, unsigned int);
double *vec_addscNdx(const double *, double *, double, unsigned int);

#define vec_addsc2f(v,sc) vec_addscNf((v),(sc),2)
#define vec_addsc3f(v,sc) vec_addscNf((v),(sc),3)
#define vec_addsc4f(v,sc) vec_addscNf((v),(sc),4)
#define vec_addsc2fx(v,vr,sc) vec_addscNfx((v),(vr),(sc),2)
#define vec_addsc3fx(v,vr,sc) vec_addscNfx((v),(vr),(sc),3)
#define vec_addsc4fx(v,vr,sc) vec_addscNfx((v),(vr),(sc),4)

#define vec_addsc2d(v,sc) vec_addscNd((v),(sc),2)
#define vec_addsc3d(v,sc) vec_addscNd((v),(sc),3)
#define vec_addsc4d(v,sc) vec_addscNd((v),(sc),4)
#define vec_addsc2dx(v,vr,sc) vec_addscNdx((v),(vr),(sc),2)
#define vec_addsc3dx(v,vr,sc) vec_addscNdx((v),(vr),(sc),3)
#define vec_addsc4dx(v,vr,sc) vec_addscNdx((v),(vr),(sc),4)

#endif
