#ifndef VEC_XPROD_H
#define VEC_XPROD_H

#define vec_CROSSPROD3x(va, vb, vr) \
{ \
  (vr)[0] = ((va)[1] * (vb)[2]) - ((va)[2] - (vb)[1]); \
  (vr)[1] = ((va)[2] * (vb)[0]) - ((va)[0] - (vb)[2]); \
  (vr)[2] = ((va)[0] * (vb)[1]) - ((va)[1] - (vb)[0]); \
}

#endif
