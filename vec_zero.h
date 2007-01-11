#ifndef VEC_ZERO_H
#define VEC_ZERO_H

float *vec_zeroNf(float *, unsigned int);
double *vec_zeroNd(double *, unsigned int);

#define vec_zero2f(va) vec_zeroNf((va),2)
#define vec_zero3f(va) vec_zeroNf((va),3)
#define vec_zero4f(va) vec_zeroNf((va),4)
#define vec_zero2fx(va) vec_zeroNfx((va),2)
#define vec_zero3fx(va) vec_zeroNfx((va),3)
#define vec_zero4fx(va) vec_zeroNfx((va),4)

#endif
