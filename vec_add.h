#ifndef VEC_ADD_H
#define VEC_ADD_H

float *vec_addNf(float *, const float *, unsigned int);
float *vec_addNfx(const float *, const float *, float *, unsigned int);
double *vec_addNd(double *, const double *, unsigned int);
double *vec_addNdx(const double *, const double *, double *, unsigned int);

#define vec_ADD2(va, vb) \
{ \
  (va)[0] += (vb)[0]; \
  (va)[1] += (vb)[1]; \
}
#define vec_ADD2x(va, vb, vr) \
{ \
  (vr)[0] = (va)[0] + (vb)[0]; \
  (vr)[1] = (va)[1] + (vb)[1]; \
}
#define vec_ADD3(va, vb) \
{ \
  (va)[0] += (vb)[0]; \
  (va)[1] += (vb)[1]; \
  (va)[2] += (vb)[2]; \
}
#define vec_ADD3x(va, vb, vr) \
{ \
  (vr)[0] = (va)[0] + (vb)[0]; \
  (vr)[1] = (va)[1] + (vb)[1]; \
  (vr)[2] = (va)[2] + (vb)[2]; \
}
#define vec_ADD4(va, vb) \
{ \
  (va)[0] += (vb)[0]; \
  (va)[1] += (vb)[1]; \
  (va)[2] += (vb)[2]; \
  (va)[3] += (vb)[3]; \
}
#define vec_ADD4x(va, vb, vr) \
{ \
  (vr)[0] = (va)[0] + (vb)[0]; \
  (vr)[1] = (va)[1] + (vb)[1]; \
  (vr)[2] = (va)[2] + (vb)[2]; \
  (vr)[3] = (va)[3] + (vb)[3]; \
}

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

#endif
