#ifndef VEC_DIV_H
#define VEC_DIV_H

float *vec_divNf(float *, const float *, unsigned int);
float *vec_divNfx(const float *, const float *, float *, unsigned int);
double *vec_divNd(double *, const double *, unsigned int);
double *vec_divNdx(const double *, const double *, double *, unsigned int);

#define vec_div2f(va,vb) vec_divNf((va),(vb),2)
#define vec_div3f(va,vb) vec_divNf((va),(vb),3)
#define vec_div4f(va,vb) vec_divNf((va),(vb),4)
#define vec_div2fx(va,vb,vr) vec_divNfx((va),(vb),(vr),2)
#define vec_div3fx(va,vb,vr) vec_divNfx((va),(vb),(vr),3)
#define vec_div4fx(va,vb,vr) vec_divNfx((va),(vb),(vr),4)

#define vec_div2d(va,vb) vec_divNd((va),(vb),2)
#define vec_div3d(va,vb) vec_divNd((va),(vb),3)
#define vec_div4d(va,vb) vec_divNd((va),(vb),4)
#define vec_div2dx(va,vb,vr) vec_divNdx((va),(vb),(vr),2)
#define vec_div3dx(va,vb,vr) vec_divNdx((va),(vb),(vr),3)
#define vec_div4dx(va,vb,vr) vec_divNdx((va),(vb),(vr),4)

#define vec_DIV(va,vb,ne,type) \
{ \
  type *pva; \
  const type *pvb; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = va; \
  pvb = vb; \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pva[0] /= pvb[0]; \
    pva[1] /= pvb[1]; \
    pva[2] /= pvb[2]; \
    pva[3] /= pvb[3]; \
    pva += 4; \
    pvb += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pva[ind] /= pvb[ind]; \
}

#define vec_DIVX(va,vb,vr,ne,type) \
{ \
  const type *pva; \
  const type *pvb; \
  type *pvr; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = va; \
  pvb = vb; \
  pvr = vr; \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pvr[0] = pva[0] / pvb[0]; \
    pvr[1] = pva[1] / pvb[1]; \
    pvr[2] = pva[2] / pvb[2]; \
    pvr[3] = pva[3] / pvb[3]; \
    pva += 4; \
    pvb += 4; \
    pvr += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pvr[ind] = pva[ind] / pvb[ind]; \
}

#endif
