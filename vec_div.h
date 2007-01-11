#ifndef VEC_DIV_H
#define VEC_DIV_H

float *vec_divNf(float *, const float *, unsigned int);
float *vec_divNfx(const float *, const float *, float *, unsigned int);
double *vec_divNd(double *, const double *, unsigned int);
double *vec_divNdx(const double *, const double *, double *, unsigned int);

#define vec_div2f(va,vb) vec_divNf((va),(vb),2)
#define vec_div3f(va,vb) vec_divNf((va),(vb),3)
#define vec_div4f(va,vb) vec_divNf((va),(vb),4)
#define vec_div2fx(va,vb,vr) vec_divNfx((va),(vb),(vr),2)
#define vec_div3fx(va,vb,vr) vec_divNfx((va),(vb),(vr),3)
#define vec_div4fx(va,vb,vr) vec_divNfx((va),(vb),(vr),4)

#define vec_div2d(va,vb) vec_divNd((va),(vb),2)
#define vec_div3d(va,vb) vec_divNd((va),(vb),3)
#define vec_div4d(va,vb) vec_divNd((va),(vb),4)
#define vec_div2dx(va,vb,vr) vec_divNdx((va),(vb),(vr),2)
#define vec_div3dx(va,vb,vr) vec_divNdx((va),(vb),(vr),3)
#define vec_div4dx(va,vb,vr) vec_divNdx((va),(vb),(vr),4)

#endif
