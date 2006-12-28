#ifndef VEC_NEGA_H
#define VEC_NEGA_H

#define vec_NEGA2(v) \
{ \
  (v)[0] = -(v)[0]; \
  (v)[1] = -(v)[1]; \
}
#define vec_NEGA2x(v, vr) \
{ \
  (vr)[0] = -(v)[0]; \
  (vr)[1] = -(v)[1]; \
}
#define vec_NEGA3(v) \
{ \
  (v)[0] = -(v)[0]; \
  (v)[1] = -(v)[1]; \
  (v)[2] = -(v)[2]; \
}
#define vec_NEGA3x(v, vr) \
{ \
  (vr)[0] = -(v)[0]; \
  (vr)[1] = -(v)[1]; \
  (vr)[2] = -(v)[2]; \
}
#define vec_NEGA4(v) \
{ \
  (v)[0] = -(v)[0]; \
  (v)[1] = -(v)[1]; \
  (v)[2] = -(v)[2]; \
  (v)[3] = -(v)[3]; \
}
#define vec_NEGA4x(v, vr) \
{ \
  (vr)[0] = -(v)[0]; \
  (vr)[1] = -(v)[1]; \
  (vr)[2] = -(v)[2]; \
  (vr)[3] = -(v)[3]; \
}

#endif
