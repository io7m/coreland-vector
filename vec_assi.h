#ifndef VEC_ASSI_H
#define VEC_ASSI_H

float *vec_assignNf(float *, const float *, unsigned int);
double *vec_assignNd(double *, const double *, unsigned int);

#define vec_assign2f(va,vb) vec_assignNf((va),(vb),2)
#define vec_assign3f(va,vb) vec_assignNf((va),(vb),3)
#define vec_assign4f(va,vb) vec_assignNf((va),(vb),4)
#define vec_assign2fx(va,vb,vr) vec_assignNfx((va),(vb),(vr),2)
#define vec_assign3fx(va,vb,vr) vec_assignNfx((va),(vb),(vr),3)
#define vec_assign4fx(va,vb,vr) vec_assignNfx((va),(vb),(vr),4)

#define vec_assign2d(va,vb) vec_assignNd((va),(vb),2)
#define vec_assign3d(va,vb) vec_assignNd((va),(vb),3)
#define vec_assign4d(va,vb) vec_assignNd((va),(vb),4)
#define vec_assign2dx(va,vb,vr) vec_assignNdx((va),(vb),(vr),2)
#define vec_assign3dx(va,vb,vr) vec_assignNdx((va),(vb),(vr),3)
#define vec_assign4dx(va,vb,vr) vec_assignNdx((va),(vb),(vr),4)

#endif
