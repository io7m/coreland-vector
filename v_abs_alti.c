#include "v_abs.h"
#include "v_align.h"
#include "v_simd.h"
#include "v_inline.h"

#ifdef HAVE_CPU_EXT_ALTIVEC

static inline float *
vec_absNf_altivec(float *va, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  unsigned int seg[4];
  float *pva;
  unsigned int ind;

  pva = va;
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vva1 = vec_abs(vva1);
    vva2 = vec_abs(vva2);
    vva3 = vec_abs(vva3);
    vva4 = vec_abs(vva4); 
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    vec_st(vva3, 0, pva + 8);
    vec_st(vva4, 0, pva + 12);
    pva += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva1 = vec_abs(vva1);
    vva2 = vec_abs(vva2);
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva1 = vec_abs(vva1);
    vec_st(vva1, 0, pva);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] = fabs(pva[ind]);

  return va;
}

static inline float *
vec_absNfx_altivec(const float *va, float *vr, unsigned int ne)
{
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  vector float vvr1;
  vector float vvr2;
  vector float vvr3;
  vector float vvr4;
  unsigned int seg[4];
  const float *pva;
  float *pvr;
  unsigned int ind;

  pvr = vr;
  pva = va;
  vec_segments(seg, 4, ne);

  for (ind = 0; ind < seg[3]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vvr1 = vec_abs(vva1);
    vvr2 = vec_abs(vva2);
    vvr3 = vec_abs(vva3);
    vvr4 = vec_abs(vva4); 
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    vec_st(vvr3, 0, pvr + 8);
    vec_st(vvr4, 0, pvr + 12);
    pva += 16;
    pvr += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vvr1 = vec_abs(vva1);
    vvr2 = vec_abs(vva2);
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    pva += 8;
    pvr += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1 = vec_ld(0, pva);
    vvr1 = vec_abs(vva1);
    vec_st(vvr1, 0, pvr);
    pva += 4;
    pvr += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = fabs(pva[ind]);

  return vr;
}

#endif
