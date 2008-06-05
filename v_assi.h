#ifndef VEC_ASSI_H
#define VEC_ASSI_H

float *vec_assignNf (float *, const float *, unsigned int);
double *vec_assignNd (double *, const double *, unsigned int);

float *vec_assignNf_aligned (float *, const float *, unsigned int);
double *vec_assignNd_aligned (double *, const double *, unsigned int);

#define vec_assign2f(va,vb) vec_assignNf ((va),(vb),2)
#define vec_assign3f(va,vb) vec_assignNf ((va),(vb),3)
#define vec_assign4f(va,vb) vec_assignNf ((va),(vb),4)

#define vec_assign2d(va,vb) vec_assignNd ((va),(vb),2)
#define vec_assign3d(va,vb) vec_assignNd ((va),(vb),3)
#define vec_assign4d(va,vb) vec_assignNd ((va),(vb),4)

#define vec_ASSIGN(va,vb,ne,type)      \
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
    pva[0] = pvb[0];                   \
    pva[1] = pvb[1];                   \
    pva[2] = pvb[2];                   \
    pva[3] = pvb[3];                   \
    pva += 4;                          \
    pvb += 4;                          \
  }                                    \
  for (ind = 0; ind < seg[0]; ++ind)   \
    pva[ind] = pvb[ind];               \
}

#endif
