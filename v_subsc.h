#ifndef VEC_SUBSC_H
#define VEC_SUBSC_H

float *vec_subscNf(float *, float, unsigned int);
float *vec_subscNfx(const float *, float *, float, unsigned int);
double *vec_subscNd(double *, double, unsigned int);
double *vec_subscNdx(const double *, double *, double, unsigned int);

#define vec_subsc2f(v,sc) vec_subscNf((v),(sc),2)
#define vec_subsc3f(v,sc) vec_subscNf((v),(sc),3)
#define vec_subsc4f(v,sc) vec_subscNf((v),(sc),4)
#define vec_subsc2fx(v,vr,sc) vec_subscNfx((v),(vr),(sc),2)
#define vec_subsc3fx(v,vr,sc) vec_subscNfx((v),(vr),(sc),3)
#define vec_subsc4fx(v,vr,sc) vec_subscNfx((v),(vr),(sc),4)

#define vec_subsc2d(v,sc) vec_subscNd((v),(sc),2)
#define vec_subsc3d(v,sc) vec_subscNd((v),(sc),3)
#define vec_subsc4d(v,sc) vec_subscNd((v),(sc),4)
#define vec_subsc2dx(v,vr,sc) vec_subscNdx((v),(vr),(sc),2)
#define vec_subsc3dx(v,vr,sc) vec_subscNdx((v),(vr),(sc),3)
#define vec_subsc4dx(v,vr,sc) vec_subscNdx((v),(vr),(sc),4)

#define vec_SUBSC(va,sc,ne,type) \
{ \
  type *pva; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = (va); \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pva[0] -= (sc); \
    pva[1] -= (sc); \
    pva[2] -= (sc); \
    pva[3] -= (sc); \
    pva += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pva[ind] -= (sc); \
}

#define vec_SUBSCX(va,vr,sc,ne,type) \
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
    pvr[0] = pva[0] - (sc); \
    pvr[1] = pva[1] - (sc); \
    pvr[2] = pva[2] - (sc); \
    pvr[3] = pva[3] - (sc); \
    pva += 4; \
    pvr += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pvr[ind] = pva[ind] - (sc); \
}

#endif
