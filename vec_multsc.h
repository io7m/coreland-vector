#ifndef VEC_MULTSC_H
#define VEC_MULTSC_H

float *vec_multscNf(float *, float, unsigned int);
float *vec_multscNfx(const float *, float *, float, unsigned int);
double *vec_multscNd(double *, double, unsigned int);
double *vec_multscNdx(const double *, double *, double, unsigned int);

#define vec_multsc2f(v,sc) vec_multscNf((v),(sc),2)
#define vec_multsc3f(v,sc) vec_multscNf((v),(sc),3)
#define vec_multsc4f(v,sc) vec_multscNf((v),(sc),4)
#define vec_multsc2fx(v,vr,sc) vec_multscNfx((v),(vr),(sc),2)
#define vec_multsc3fx(v,vr,sc) vec_multscNfx((v),(vr),(sc),3)
#define vec_multsc4fx(v,vr,sc) vec_multscNfx((v),(vr),(sc),4)

#define vec_multsc2d(v,sc) vec_multscNd((v),(sc),2)
#define vec_multsc3d(v,sc) vec_multscNd((v),(sc),3)
#define vec_multsc4d(v,sc) vec_multscNd((v),(sc),4)
#define vec_multsc2dx(v,vr,sc) vec_multscNdx((v),(vr),(sc),2)
#define vec_multsc3dx(v,vr,sc) vec_multscNdx((v),(vr),(sc),3)
#define vec_multsc4dx(v,vr,sc) vec_multscNdx((v),(vr),(sc),4)

#endif
