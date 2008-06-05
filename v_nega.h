#ifndef VEC_NEGA_H
#define VEC_NEGA_H

float *vec_negaNf (float *, unsigned int);
float *vec_negaNfx (const float *, float *, unsigned int);
double *vec_negaNd (double *, unsigned int);
double *vec_negaNdx (const double *, double *, unsigned int);

float *vec_negaNf_aligned (float *, unsigned int);
float *vec_negaNfx_aligned (const float *, float *, unsigned int);
double *vec_negaNd_aligned (double *, unsigned int);
double *vec_negaNdx_aligned (const double *, double *, unsigned int);

#define vec_nega2f(va) vec_negaNf ((va),2)
#define vec_nega3f(va) vec_negaNf ((va),3)
#define vec_nega4f(va) vec_negaNf ((va),4)
#define vec_nega2fx(va,vr) vec_negaNfx ((va),(vr),2)
#define vec_nega3fx(va,vr) vec_negaNfx ((va),(vr),3)
#define vec_nega4fx(va,vr) vec_negaNfx ((va),(vr),4)

#define vec_nega2d(va) vec_negaNd ((va),2)
#define vec_nega3d(va) vec_negaNd ((va),3)
#define vec_nega4d(va) vec_negaNd ((va),4)
#define vec_nega2dx(va,vr) vec_negaNdx ((va),(vr),2)
#define vec_nega3dx(va,vr) vec_negaNdx ((va),(vr),3)
#define vec_nega4dx(va,vr) vec_negaNdx ((va),(vr),4)

#endif
