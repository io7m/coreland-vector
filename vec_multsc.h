#ifndef VEC_MULTSC_H
#define VEC_MULTSC_H

float *vec_multscNf(float *, float, unsigned int);
float *vec_multscNfx(const float *, float *, float, unsigned int);
double *vec_multscNd(double *, double, unsigned int);
double *vec_multscNdx(const double *, double *, double, unsigned int);

#define vec_multsc2f(v,sc) vec_multscNf((v),(sc),2)
#define vec_multsc3f(v,sc) vec_multscNf((v),(sc),3)
#define vec_multsc4f(v,sc) vec_multscNf((v),(sc),4)
#define vec_multsc2fx(v,vr,sc) vec_multscNfx((v),(vr),(sc),2)
#define vec_multsc3fx(v,vr,sc) vec_multscNfx((v),(vr),(sc),3)
#define vec_multsc4fx(v,vr,sc) vec_multscNfx((v),(vr),(sc),4)

#define vec_multsc2d(v,sc) vec_multscNd((v),(sc),2)
#define vec_multsc3d(v,sc) vec_multscNd((v),(sc),3)
#define vec_multsc4d(v,sc) vec_multscNd((v),(sc),4)
#define vec_multsc2dx(v,vr,sc) vec_multscNdx((v),(vr),(sc),2)
#define vec_multsc3dx(v,vr,sc) vec_multscNdx((v),(vr),(sc),3)
#define vec_multsc4dx(v,vr,sc) vec_multscNdx((v),(vr),(sc),4)

#define vec_MULTSC(va,sc,ne,type) \
{ \
  type *pva; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = va; \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pva[0] *= (sc); \
    pva[1] *= (sc); \
    pva[2] *= (sc); \
    pva[3] *= (sc); \
    pva += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pva[ind] *= (sc); \
}

#define vec_MULTSCX(va,vr,sc,ne,type) \
{ \
  const type *pva; \
  type *pvr; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = va; \
  pvr = vr; \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pvr[0] = pva[0] * (sc); \
    pvr[1] = pva[1] * (sc); \
    pvr[2] = pva[2] * (sc); \
    pvr[3] = pva[3] * (sc); \
    pva += 4; \
    pvr += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pvr[ind] = pva[ind] * (sc); \
}

#endif
