#ifndef VEC_SUB_H
#define VEC_SUB_H

float *vec_subNf (float *, const float *, unsigned int);
float *vec_subNfx (const float *, const float *, float *, unsigned int);
double *vec_subNd (double *, const double *, unsigned int);
double *vec_subNdx (const double *, const double *, double *, unsigned int);

float *vec_subNf_aligned (float *, const float *, unsigned int);
float *vec_subNfx_aligned (const float *, const float *, float *, unsigned int);
double *vec_subNd_aligned (double *, const double *, unsigned int);
double *vec_subNdx_aligned (const double *, const double *, double *, unsigned int);

#define vec_sub2f(va,vb) vec_subNf ((va),(vb),2)
#define vec_sub3f(va,vb) vec_subNf ((va),(vb),3)
#define vec_sub4f(va,vb) vec_subNf ((va),(vb),4)
#define vec_sub2fx(va,vb,vr) vec_subNfx ((va),(vb),(vr),2)
#define vec_sub3fx(va,vb,vr) vec_subNfx ((va),(vb),(vr),3)
#define vec_sub4fx(va,vb,vr) vec_subNfx ((va),(vb),(vr),4)

#define vec_sub2d(va,vb) vec_subNd ((va),(vb),2)
#define vec_sub3d(va,vb) vec_subNd ((va),(vb),3)
#define vec_sub4d(va,vb) vec_subNd ((va),(vb),4)
#define vec_sub2dx(va,vb,vr) vec_subNdx ((va),(vb),(vr),2)
#define vec_sub3dx(va,vb,vr) vec_subNdx ((va),(vb),(vr),3)
#define vec_sub4dx(va,vb,vr) vec_subNdx ((va),(vb),(vr),4)

#define vec_SUB(va,vb,ne,type)         \
{                                      \
  type *pva;                           \
  const type *pvb;                     \
  unsigned int seg[2];                 \
  unsigned int ind;                    \
                                       \
  pva = (va);                          \
  pvb = (vb);                          \
  vec_segments (seg, 2, (ne));         \
                                       \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pva[0] -= pvb[0];                  \
    pva[1] -= pvb[1];                  \
    pva[2] -= pvb[2];                  \
    pva[3] -= pvb[3];                  \
    pva += 4;                          \
    pvb += 4;                          \
  }                                    \
  for (ind = 0; ind < seg[0]; ++ind)   \
    pva[ind] -= pvb[ind];              \
}

#define vec_SUBX(va,vb,vr,ne,type)     \
{                                      \
  const type *pva;                     \
  const type *pvb;                     \
  type *pvr;                           \
  unsigned int seg[2];                 \
  unsigned int ind;                    \
                                       \
  pva = (va);                          \
  pvb = (vb);                          \
  pvr = (vr);                          \
  vec_segments (seg, 2, (ne));         \
                                       \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pvr[0] = pva[0] - pvb[0];          \
    pvr[1] = pva[1] - pvb[1];          \
    pvr[2] = pva[2] - pvb[2];          \
    pvr[3] = pva[3] - pvb[3];          \
    pva += 4;                          \
    pvb += 4;                          \
    pvr += 4;                          \
  }                                    \
  for (ind = 0; ind < seg[0]; ++ind)   \
    pvr[ind] = pva[ind] - pvb[ind];    \
}

#endif
