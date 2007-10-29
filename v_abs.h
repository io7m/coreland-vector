#ifndef VEC_ABS_H
#define VEC_ABS_H

float *vec_absNf(float *, unsigned int);
float *vec_absNfx(const float *, float *, unsigned int);
double *vec_absNd(double *, unsigned int);
double *vec_absNdx(const double *, double *, unsigned int);

#define vec_abs2f(va) vec_absNf((va),2)
#define vec_abs3f(va) vec_absNf((va),3)
#define vec_abs4f(va) vec_absNf((va),4)
#define vec_abs2fx(va,vr) vec_absNfx((va),(vr),2)
#define vec_abs3fx(va,vr) vec_absNfx((va),(vr),3)
#define vec_abs4fx(va,vr) vec_absNfx((va),(vr),4)

#define vec_abs2d(va) vec_absNd((va),2)
#define vec_abs3d(va) vec_absNd((va),3)
#define vec_abs4d(va) vec_absNd((va),4)
#define vec_abs2dx(va,vr) vec_absNdx((va),(vr),2)
#define vec_abs3dx(va,vr) vec_absNdx((va),(vr),3)
#define vec_abs4dx(va,vr) vec_absNdx((va),(vr),4)

#define vec_ABS(va,ne,type,op) \
{ \
  type *pva; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = (va); \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pva[0] = op(pva[0]); \
    pva[1] = op(pva[1]); \
    pva[2] = op(pva[2]); \
    pva[3] = op(pva[3]); \
    pva += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pva[ind] = op(pva[ind]); \
}

#define vec_ABSX(va,vr,ne,type,op) \
{ \
  const type *pva; \
  type *pvr; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = (va); \
  pvr = (vr); \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pvr[0] = op(pva[0]); \
    pvr[1] = op(pva[1]); \
    pvr[2] = op(pva[2]); \
    pvr[3] = op(pva[3]); \
    pva += 4; \
    pvr += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pvr[ind] = op(pva[ind]); \
}

#endif
