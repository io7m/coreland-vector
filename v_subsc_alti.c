#include "v_align.h"
#include "v_subsc.h"
#include "v_simd.h"
#include "v_types.h"

#ifdef HAVE_CPU_EXT_ALTIVEC

static inline float *
vec_subscNf_altivec(float *va, float sc, unsigned int ne)
{
  vector_4f vs;
  vector float vva1;
  vector float vva2;
  vector float vva3;
  vector float vva4;
  unsigned int seg[4];
  float *pva;
  unsigned int ind;

  pva = va;
  vec_segments(seg, 4, ne);

  vs.f[0] = sc;
  vs.v = vec_splat(vs.v, 0);

  for (ind = 0; ind < seg[3]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva3 = vec_ld(0, pva + 8);
    vva4 = vec_ld(0, pva + 12);
    vva1 = vec_sub(vva1, vs.v);
    vva2 = vec_sub(vva2, vs.v);
    vva3 = vec_sub(vva3, vs.v);
    vva4 = vec_sub(vva4, vs.v); 
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    vec_st(vva3, 0, pva + 8);
    vec_st(vva4, 0, pva + 12);
    pva += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva2 = vec_ld(0, pva + 4);
    vva1 = vec_sub(vva1, vs.v);
    vva2 = vec_sub(vva2, vs.v);
    vec_st(vva1, 0, pva);
    vec_st(vva2, 0, pva + 4);
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vva1 = vec_ld(0, pva);
    vva1 = vec_sub(vva1, vs.v);
    vec_st(vva1, 0, pva);
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pva[ind] -= sc;

  return va;
}

static inline float *
vec_subscNfx_altivec(const float *va, float *vr, float sc, unsigned int ne)
{
  vector_4f vs;
  vector float vvr1;
  vector float vvr2;
  vector float vvr3;
  vector float vvr4;
  unsigned int seg[4];
  const float *pva;
  float *pvr;
  unsigned int ind;

  pva = va;
  pvr = vr;
  vec_segments(seg, 4, ne);

  vs.f[0] = sc;
  vs.v = vec_splat(vs.v, 0);

  for (ind = 0; ind < seg[3]; ++ind) {
    vvr1 = vec_ld(0, pva); 
    vvr2 = vec_ld(0, pva + 4);
    vvr3 = vec_ld(0, pva + 8);
    vvr4 = vec_ld(0, pva + 12);
    vvr1 = vec_sub(vvr1, vs.v);
    vvr2 = vec_sub(vvr2, vs.v);
    vvr3 = vec_sub(vvr3, vs.v);
    vvr4 = vec_sub(vvr4, vs.v);
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    vec_st(vvr3, 0, pvr + 8);
    vec_st(vvr4, 0, pvr + 12);
    pvr += 16;
    pva += 16;
  }
  for (ind = 0; ind < seg[2]; ++ind) {
    vvr1 = vec_ld(0, pva);
    vvr2 = vec_ld(0, pva + 4);
    vvr1 = vec_sub(vvr1, vs.v);
    vvr2 = vec_sub(vvr2, vs.v);
    vec_st(vvr1, 0, pvr);
    vec_st(vvr2, 0, pvr + 4);
    pvr += 8;
    pva += 8;
  }
  for (ind = 0; ind < seg[1]; ++ind) {
    vvr1 = vec_ld(0, pva);
    vvr1 = vec_sub(vvr1, vs.v);
    vec_st(vvr1, 0, pvr);
    pvr += 4;
    pva += 4;
  }
  for (ind = 0; ind < seg[0]; ++ind)
    pvr[ind] = pva[ind] - sc;

  return vr;
}

#endif
