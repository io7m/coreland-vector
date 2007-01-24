#ifndef VEC_ADDSC_H
#define VEC_ADDSC_H

float *vec_addscNf(float *, float, unsigned int);
float *vec_addscNfx(const float *, float *, float, unsigned int);
double *vec_addscNd(double *, double, unsigned int);
double *vec_addscNdx(const double *, double *, double, unsigned int);

#define vec_addsc2f(v,sc) vec_addscNf((v),(sc),2)
#define vec_addsc3f(v,sc) vec_addscNf((v),(sc),3)
#define vec_addsc4f(v,sc) vec_addscNf((v),(sc),4)
#define vec_addsc2fx(v,vr,sc) vec_addscNfx((v),(vr),(sc),2)
#define vec_addsc3fx(v,vr,sc) vec_addscNfx((v),(vr),(sc),3)
#define vec_addsc4fx(v,vr,sc) vec_addscNfx((v),(vr),(sc),4)

#define vec_addsc2d(v,sc) vec_addscNd((v),(sc),2)
#define vec_addsc3d(v,sc) vec_addscNd((v),(sc),3)
#define vec_addsc4d(v,sc) vec_addscNd((v),(sc),4)
#define vec_addsc2dx(v,vr,sc) vec_addscNdx((v),(vr),(sc),2)
#define vec_addsc3dx(v,vr,sc) vec_addscNdx((v),(vr),(sc),3)
#define vec_addsc4dx(v,vr,sc) vec_addscNdx((v),(vr),(sc),4)

#define vec_ADDSC(va,sc,ne,type) \
{ \
  type *pva; \
  unsigned int seg[2]; \
  unsigned int ind; \
  \
  pva = (va); \
  vec_segments(seg, 2, (ne)); \
  \
  for (ind = 0; ind < seg[1]; ++ind) { \
    pva[0] += (sc); \
    pva[1] += (sc); \
    pva[2] += (sc); \
    pva[3] += (sc); \
    pva += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pva[ind] += (sc); \
}

#define vec_ADDSCX(va,vr,sc,ne,type) \
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
    pvr[0] = pva[0] + (sc); \
    pvr[1] = pva[1] + (sc); \
    pvr[2] = pva[2] + (sc); \
    pvr[3] = pva[3] + (sc); \
    pva += 4; \
    pvr += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pvr[ind] = pva[ind] + (sc); \
}

#endif
