#ifndef VEC_DOTP_H
#define VEC_DOTP_H

float vec_dotprodNf(const float *, const float *, unsigned int);
double vec_dotprodNd(const double *, const double *, unsigned int);

#define vec_dotprod2f(va,vb) vec_dotprodNf((va),(vb),2)
#define vec_dotprod3f(va,vb) vec_dotprodNf((va),(vb),3)
#define vec_dotprod4f(va,vb) vec_dotprodNf((va),(vb),4)
#define vec_dotprod2fx(va,vb) vec_dotprodNfx((va),(vb),2)
#define vec_dotprod3fx(va,vb) vec_dotprodNfx((va),(vb),3)
#define vec_dotprod4fx(va,vb) vec_dotprodNfx((va),(vb),4)

#endif
