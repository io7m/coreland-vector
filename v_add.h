#ifndef VEC_ADD_H
#define VEC_ADD_H

float *vec_addNf(float *, const float *, unsigned int);
float *vec_addNfx(const float *, const float *, float *, unsigned int);
double *vec_addNd(double *, const double *, unsigned int);
double *vec_addNdx(const double *, const double *, double *, unsigned int);

#define vec_add2f(va,vb) vec_addNf((va),(vb),2)
#define vec_add3f(va,vb) vec_addNf((va),(vb),3)
#define vec_add4f(va,vb) vec_addNf((va),(vb),4)
#define vec_add2fx(va,vb,vr) vec_addNfx((va),(vb),(vr),2)
#define vec_add3fx(va,vb,vr) vec_addNfx((va),(vb),(vr),3)
#define vec_add4fx(va,vb,vr) vec_addNfx((va),(vb),(vr),4)

#define vec_add2d(va,vb) vec_addNd((va),(vb),2)
#define vec_add3d(va,vb) vec_addNd((va),(vb),3)
#define vec_add4d(va,vb) vec_addNd((va),(vb),4)
#define vec_add2dx(va,vb,vr) vec_addNdx((va),(vb),(vr),2)
#define vec_add3dx(va,vb,vr) vec_addNdx((va),(vb),(vr),3)
#define vec_add4dx(va,vb,vr) vec_addNdx((va),(vb),(vr),4)

#define vec_ADD(va,vb,ne,type) \
{ \
  type *pva; \
  const type *pvb; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = (va); \
  pvb = (vb); \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pva[0] += pvb[0]; \
    pva[1] += pvb[1]; \
    pva[2] += pvb[2]; \
    pva[3] += pvb[3]; \
    pva += 4; \
    pvb += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pva[ind] += pvb[ind]; \
}

#define vec_ADDX(va,vb,vr,ne,type) \
{ \
  const type *pva; \
  const type *pvb; \
  type *pvr; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = (va); \
  pvb = (vb); \
  pvr = (vr); \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pvr[0] = pva[0] + pvb[0]; \
    pvr[1] = pva[1] + pvb[1]; \
    pvr[2] = pva[2] + pvb[2]; \
    pvr[3] = pva[3] + pvb[3]; \
    pva += 4; \
    pvb += 4; \
    pvr += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pvr[ind] = pva[ind] + pvb[ind]; \
}

#endif
