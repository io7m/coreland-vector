#ifndef VEC_ZERO_H
#define VEC_ZERO_H

float *vec_zeroNf(float *, unsigned int);
double *vec_zeroNd(double *, unsigned int);

#define vec_zero2f(va) vec_zeroNf((va),2)
#define vec_zero3f(va) vec_zeroNf((va),3)
#define vec_zero4f(va) vec_zeroNf((va),4)

#define vec_zero2d(va) vec_zeroNd((va),2)
#define vec_zero3d(va) vec_zeroNd((va),3)
#define vec_zero4d(va) vec_zeroNd((va),4)

#define vec_ZERO(va,vb,ne,type) \
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
    pva[0] = 0; \
    pva[1] = 0; \
    pva[2] = 0; \
    pva[3] = 0; \
    pva += 4; \
    pvb += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    pva[ind] = 0; \
}

#endif
