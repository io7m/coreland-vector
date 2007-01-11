#ifndef VEC_DIVSC_H
#define VEC_DIVSC_H

float *vec_divscNf(float *, float, unsigned int);
float *vec_divscNfx(const float *, float *, float, unsigned int);
double *vec_divscNd(double *, double, unsigned int);
double *vec_divscNdx(const double *, double *, double, unsigned int);

#define vec_divsc2f(v,sc) vec_divscNf((v),(sc),2)
#define vec_divsc3f(v,sc) vec_divscNf((v),(sc),3)
#define vec_divsc4f(v,sc) vec_divscNf((v),(sc),4)
#define vec_divsc2fx(v,vr,sc) vec_divscNfx((v),(vr),(sc),2)
#define vec_divsc3fx(v,vr,sc) vec_divscNfx((v),(vr),(sc),3)
#define vec_divsc4fx(v,vr,sc) vec_divscNfx((v),(vr),(sc),4)

#define vec_divsc2d(v,sc) vec_divscNd((v),(sc),2)
#define vec_divsc3d(v,sc) vec_divscNd((v),(sc),3)
#define vec_divsc4d(v,sc) vec_divscNd((v),(sc),4)
#define vec_divsc2dx(v,vr,sc) vec_divscNdx((v),(vr),(sc),2)
#define vec_divsc3dx(v,vr,sc) vec_divscNdx((v),(vr),(sc),3)
#define vec_divsc4dx(v,vr,sc) vec_divscNdx((v),(vr),(sc),4)

#endif
