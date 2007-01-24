#ifndef VEC_DOTP_H
#define VEC_DOTP_H

float vec_dotprodNf(const float *, const float *, unsigned int);
double vec_dotprodNd(const double *, const double *, unsigned int);

#define vec_dotprod2f(va,vb) vec_dotprodNf((va),(vb),2)
#define vec_dotprod3f(va,vb) vec_dotprodNf((va),(vb),3)
#define vec_dotprod4f(va,vb) vec_dotprodNf((va),(vb),4)

#define vec_DOTPROD(va,vb,sc,ne,type) \
{ \
  const type *pva; \
  const type *pvb; \
  unsigned int seg[2]; \
  unsigned int ind; \
  type res; \
  \
  pva = (va); \
  pvb = (vb); \
  vec_segments(seg, 2, (ne)); \
  \
  res = 0; \
  for (ind = 0; ind < seg[1]; ++ind) { \
    res += pva[0] * pvb[0]; \
    res += pva[1] * pvb[1]; \
    res += pva[2] * pvb[2]; \
    res += pva[3] * pvb[3]; \
    pva += 4; \
    pvb += 4; \
  } \
  for (ind = 0; ind < seg[0]; ++ind) \
    res += pva[ind] * pvb[ind]; \
  *(sc) = res; \
}

#endif
