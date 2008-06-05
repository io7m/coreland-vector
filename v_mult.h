#ifndef VEC_MULT_H
#define VEC_MULT_H

float *vec_multNf (float *, const float *, unsigned int);
float *vec_multNfx (const float *, const float *, float *, unsigned int);
double *vec_multNd (double *, const double *, unsigned int);
double *vec_multNdx (const double *, const double *, double *, unsigned int);

#define vec_mult2f(va,vb) vec_multNf ((va),(vb),2)
#define vec_mult3f(va,vb) vec_multNf ((va),(vb),3)
#define vec_mult4f(va,vb) vec_multNf ((va),(vb),4)
#define vec_mult2fx(va,vb,vr) vec_multNfx ((va),(vb),(vr),2)
#define vec_mult3fx(va,vb,vr) vec_multNfx ((va),(vb),(vr),3)
#define vec_mult4fx(va,vb,vr) vec_multNfx ((va),(vb),(vr),4)

#define vec_mult2d(va,vb) vec_multNd ((va),(vb),2)
#define vec_mult3d(va,vb) vec_multNd ((va),(vb),3)
#define vec_mult4d(va,vb) vec_multNd ((va),(vb),4)
#define vec_mult2dx(va,vb,vr) vec_multNdx ((va),(vb),(vr),2)
#define vec_mult3dx(va,vb,vr) vec_multNdx ((va),(vb),(vr),3)
#define vec_mult4dx(va,vb,vr) vec_multNdx ((va),(vb),(vr),4)

#define vec_MULT(va,vb,ne,type)        \
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
    pva[0] *= pvb[0];                  \
    pva[1] *= pvb[1];                  \
    pva[2] *= pvb[2];                  \
    pva[3] *= pvb[3];                  \
    pva += 4;                          \
    pvb += 4;                          \
  }                                    \
  for (ind = 0; ind < seg[0]; ++ind)   \
    pva[ind] *= pvb[ind];              \
}

#define vec_MULTX(va,vb,vr,ne,type)    \
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
    pvr[0] = pva[0] * pvb[0];          \
    pvr[1] = pva[1] * pvb[1];          \
    pvr[2] = pva[2] * pvb[2];          \
    pvr[3] = pva[3] * pvb[3];          \
    pva += 4;                          \
    pvb += 4;                          \
    pvr += 4;                          \
  }                                    \
  for (ind = 0; ind < seg[0]; ++ind)   \
    pvr[ind] = pva[ind] * pvb[ind];    \
}

#endif
