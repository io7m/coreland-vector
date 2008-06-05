#ifndef VEC_DEGREE_H
#define VEC_DEGREE_H

float vec_degreeNf (const float *, const float *, unsigned int);
double vec_degreeNd (const double *, const double *, unsigned int);

float vec_degreeNf_aligned (const float *, const float *, unsigned int);
double vec_degreeNd_aligned (const double *, const double *, unsigned int);

#define vec_degree2f(va,vb) vec_degreeNf ((va),(vb),2)
#define vec_degree3f(va,vb) vec_degreeNf ((va),(vb),3)
#define vec_degree4f(va,vb) vec_degreeNf ((va),(vb),4)
#define vec_degree2d(va,vb) vec_degreeNd ((va),(vb),2)
#define vec_degree3d(va,vb) vec_degreeNd ((va),(vb),3)
#define vec_degree4d(va,vb) vec_degreeNd ((va),(vb),4)

#endif
