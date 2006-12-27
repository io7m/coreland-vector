#ifndef VEC_SUB_H
#define VEC_SUB_H

#define vec_SUB2(va, vb) \
{ \
  (va)[0] -= (vb)[0]; \
  (va)[1] -= (vb)[1]; \
}
#define vec_SUB2x(va, vb, vr) \
{ \
  (vr)[0] = (va)[0] - (vb)[0]; \
  (vr)[1] = (va)[1] - (vb)[1]; \
}
#define vec_SUB3(va, vb) \
{ \
  (va)[0] -= (vb)[0]; \
  (va)[1] -= (vb)[1]; \
  (va)[2] -= (vb)[2]; \
}
#define vec_SUB3x(va, vb, vr) \
{ \
  (vr)[0] = (va)[0] - (vb)[0]; \
  (vr)[1] = (va)[1] - (vb)[1]; \
  (vr)[2] = (va)[2] - (vb)[2]; \
}
#define vec_SUB4(va, vb) \
{ \
  (va)[0] -= (vb)[0]; \
  (va)[1] -= (vb)[1]; \
  (va)[2] -= (vb)[2]; \
  (va)[3] -= (vb)[3]; \
}
#define vec_SUB4x(va, vb, vr) \
{ \
  (vr)[0] = (va)[0] - (vb)[0]; \
  (vr)[1] = (va)[1] - (vb)[1]; \
  (vr)[2] = (va)[2] - (vb)[2]; \
  (vr)[3] = (va)[3] - (vb)[3]; \
}

#endif
