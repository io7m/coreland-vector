#ifndef VEC_SUM_H
#define VEC_SUM_H

float vec_sumNf (const float *, unsigned int);
double vec_sumNd (const double *, unsigned int);

float vec_sumNf_aligned (const float *, unsigned int);
double vec_sumNd_aligned (const double *, unsigned int);

#define vec_sum2f(va,vb) vec_sumNf ((va),2)
#define vec_sum3f(va,vb) vec_sumNf ((va),3)
#define vec_sum4f(va,vb) vec_sumNf ((va),4)

#define vec_sum2d(va,vb) vec_sumNd ((va),2)
#define vec_sum3d(va,vb) vec_sumNd ((va),3)
#define vec_sum4d(va,vb) vec_sumNd ((va),4)

#define vec_SUM(va,sum,ne)       \
{                                \
  unsigned int ind;              \
  for (ind = 0; ind < ne; ++ind) \
    (sum) += va[ind];            \
}

#endif
