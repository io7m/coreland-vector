#ifndef VEC_ANGLEN_H
#define VEC_ANGLEN_H

float vec_anglenormNf(const float *, const float *, unsigned int);
double vec_anglenormNd(const double *, const double *, unsigned int);

#define vec_anglenorm2f(va,vb) vec_anglenormNf((va),(vb),2)
#define vec_anglenorm3f(va,vb) vec_anglenormNf((va),(vb),3)
#define vec_anglenorm4f(va,vb) vec_anglenormNf((va),(vb),4)
#define vec_anglenorm2d(va,vb) vec_anglenormNd((va),(vb),2)
#define vec_anglenorm3d(va,vb) vec_anglenormNd((va),(vb),3)
#define vec_anglenorm4d(va,vb) vec_anglenormNd((va),(vb),4)

#endif
