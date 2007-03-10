#ifndef VEC_DEGREENORM_H
#define VEC_DEGREENORM_H

float vec_degreenormNf(const float *, const float *, unsigned int);
double vec_degreenormNd(const double *, const double *, unsigned int);

#define vec_degreenorm2f(va,vb) vec_degreenormNf((va),(vb),2)
#define vec_degreenorm3f(va,vb) vec_degreenormNf((va),(vb),3)
#define vec_degreenorm4f(va,vb) vec_degreenormNf((va),(vb),4)
#define vec_degreenorm2d(va,vb) vec_degreenormNd((va),(vb),2)
#define vec_degreenorm3d(va,vb) vec_degreenormNd((va),(vb),3)
#define vec_degreenorm4d(va,vb) vec_degreenormNd((va),(vb),4)

#endif
