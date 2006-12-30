#ifndef VEC_SUBSC_H
#define VEC_SUBSC_H

#define vec_SUBSC2(va, sc) \
{ \
  (va)[0] -= (sc); \
  (va)[1] -= (sc); \
}
#define vec_SUBSC2x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] - (sc); \
  (vr)[1] = (va)[1] - (sc); \
}
#define vec_SUBSC3(va, sc) \
{ \
  (va)[0] -= (sc); \
  (va)[1] -= (sc); \
  (va)[2] -= (sc); \
}
#define vec_SUBSC3x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] - (sc); \
  (vr)[1] = (va)[1] - (sc); \
  (vr)[2] = (va)[2] - (sc); \
}
#define vec_SUBSC4(va, sc) \
{ \
  (va)[0] -= (sc); \
  (va)[1] -= (sc); \
  (va)[2] -= (sc); \
  (va)[3] -= (sc); \
}
#define vec_SUBSC4x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] - (sc); \
  (vr)[1] = (va)[1] - (sc); \
  (vr)[2] = (va)[2] - (sc); \
  (vr)[3] = (va)[3] - (sc); \
}

#endif
