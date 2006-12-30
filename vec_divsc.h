#ifndef VEC_DIVSC_H
#define VEC_DIVSC_H

#define vec_DIVSC2(va, sc) \
{ \
  (va)[0] /= (sc); \
  (va)[1] /= (sc); \
}
#define vec_DIVSC2x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] / (sc); \
  (vr)[1] = (va)[1] / (sc); \
}
#define vec_DIVSC3(va, sc) \
{ \
  (va)[0] /= (sc); \
  (va)[1] /= (sc); \
  (va)[2] /= (sc); \
}
#define vec_DIVSC3x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] / (sc); \
  (vr)[1] = (va)[1] / (sc); \
  (vr)[2] = (va)[2] / (sc); \
}
#define vec_DIVSC4(va, sc) \
{ \
  (va)[0] /= (sc); \
  (va)[1] /= (sc); \
  (va)[2] /= (sc); \
  (va)[3] /= (sc); \
}
#define vec_DIVSC4x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] / (sc); \
  (vr)[1] = (va)[1] / (sc); \
  (vr)[2] = (va)[2] / (sc); \
  (vr)[3] = (va)[3] / (sc); \
}

#endif
