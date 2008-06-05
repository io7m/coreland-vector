#include "v_simd.h"
#include "v_types.h"
#include "v_align.h"
#include "v_inline.h"

#include "v_dotp.h"
#include "v_proj.h"
#include "v_mag.h"
#include "v_multsc.h"

/*
 * proj A = (A * B) / (||B|| ^ 2) * B
 */

float *
vec_projNf (const float *va, const float *vb, float *vr, unsigned int n)
{
  const float adp = vec_dotprodNf (va, vb, n);
  float bms = vec_magNf (vb, n);

  bms *= bms;
  return vec_multscNfx (vb, vr, adp / bms, n);
}

double *
vec_projN (const double *va, const double *vb, double *vr, unsigned int n)
{
  const double adp = vec_dotprodNd (va, vb, n);
  float bms = vec_magNd (vb, n);

  bms *= bms;
  return vec_multscNdx (vb, vr, adp / bms, n);
}

float *
vec_projNf_aligned (const float *va, const float *vb, float *vr, unsigned int n)
{
  const float adp = vec_dotprodNf_aligned (va, vb, n);
  float bms = vec_magNf_aligned (vb, n);

  bms *= bms;
  return vec_multscNfx_aligned (vb, vr, adp / bms, n);
}

double *
vec_projN_aligned (const double *va, const double *vb, double *vr, unsigned int n)
{
  const double adp = vec_dotprodNd_aligned (va, vb, n);
  float bms = vec_magNd_aligned (vb, n);

  bms *= bms;
  return vec_multscNdx_aligned (vb, vr, adp / bms, n);
}
