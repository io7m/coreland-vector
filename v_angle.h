#ifndef VEC_ANGLE_H
#define VEC_ANGLE_H

float vec_angleNf (const float *, const float *, unsigned int);
double vec_angleNd (const double *, const double *, unsigned int);

float vec_angleNf_aligned (const float *, const float *, unsigned int);
double vec_angleNd_aligned (const double *, const double *, unsigned int);

#define vec_angle2f(va,vb) vec_angleNf ((va),(vb),2)
#define vec_angle3f(va,vb) vec_angleNf ((va),(vb),3)
#define vec_angle4f(va,vb) vec_angleNf ((va),(vb),4)
#define vec_angle2d(va,vb) vec_angleNd ((va),(vb),2)
#define vec_angle3d(va,vb) vec_angleNd ((va),(vb),3)
#define vec_angle4d(va,vb) vec_angleNd ((va),(vb),4)

#endif
