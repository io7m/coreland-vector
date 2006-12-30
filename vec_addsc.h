#ifndef VEC_ADDSC_H
#define VEC_ADDSC_H

#define vec_ADDSC2(va, sc) \
{ \
  (va)[0] += (sc); \
  (va)[1] += (sc); \
}
#define vec_ADDSC2x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] + (sc); \
  (vr)[1] = (va)[1] + (sc); \
}
#define vec_ADDSC3(va, sc) \
{ \
  (va)[0] += (sc); \
  (va)[1] += (sc); \
  (va)[2] += (sc); \
}
#define vec_ADDSC3x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] + (sc); \
  (vr)[1] = (va)[1] + (sc); \
  (vr)[2] = (va)[2] + (sc); \
}
#define vec_ADDSC4(va, sc) \
{ \
  (va)[0] += (sc); \
  (va)[1] += (sc); \
  (va)[2] += (sc); \
  (va)[3] += (sc); \
}
#define vec_ADDSC4x(va, vr, sc) \
{ \
  (vr)[0] = (va)[0] + (sc); \
  (vr)[1] = (va)[1] + (sc); \
  (vr)[2] = (va)[2] + (sc); \
  (vr)[3] = (va)[3] + (sc); \
}

#endif
