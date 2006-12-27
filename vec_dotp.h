#ifndef VEC_DOTP_H
#define VEC_DOTP_H

#define vec_DOTPROD2(va, vb) \
  ((va)[0] * (vb)[0]) + \
  ((va)[1] * (vb)[1])
#define vec_DOTPROD3(va, vb) \
  ((va)[0] * (vb)[0]) + \
  ((va)[1] * (vb)[1]) + \
  ((va)[2] * (vb)[2])
#define vec_DOTPROD4(va, vb) \
  ((va)[0] * (vb)[0]) + \
  ((va)[1] * (vb)[1]) + \
  ((va)[2] * (vb)[2]) + \
  ((va)[3] * (vb)[3])

#endif
