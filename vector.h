#ifndef VECTOR_H
#define VECTOR_H

#include "vec_add.h"
#include "vec_addsc.h"
#include "vec_assi.h"
#include "vec_div.h"
#include "vec_divsc.h"
#include "vec_dotp.h"
#include "vec_mult.h"
#include "vec_multsc.h"
#include "vec_nega.h"
#include "vec_norm.h"
#include "vec_sub.h"
#include "vec_subsc.h"
#include "vec_xprod.h"
#include "vec_zero.h"
#include "vec_simd.h"
#include "vec_types.h"

float vec_mag2f(const float [2]);
float vec_mag3f(const float [3]);
float vec_mag4f(const float [4]);
double vec_mag2d(const double [2]);
double vec_mag3d(const double [3]);
double vec_mag4d(const double [4]);

float *vec_crossprod3fx(const float [3], const float [3], float [3]);
double *vec_crossprod3dx(const double [3], const double [3], double [3]);

float vec_dist2f(const float [2], const float [2]);
float vec_dist3f(const float [3], const float [3]);
float vec_dist4f(const float [4], const float [4]);
double vec_dist2d(const double [2], const double [2]);
double vec_dist3d(const double [3], const double [3]);
double vec_dist4d(const double [4], const double [4]);

float vec_angle2f(const float [2], const float [2]);
float vec_angle3f(const float [3], const float [3]);
float vec_angle4f(const float [4], const float [4]);
double vec_angle2d(const double [2], const double [2]);
double vec_angle3d(const double [3], const double [3]);
double vec_angle4d(const double [4], const double [4]);

float vec_anglenorm2f(const float [2], const float [2]);
float vec_anglenorm3f(const float [3], const float [3]);
float vec_anglenorm4f(const float [4], const float [4]);
double vec_anglenorm2d(const double [2], const double [2]);
double vec_anglenorm3d(const double [3], const double [3]);
double vec_anglenorm4d(const double [4], const double [4]);

#endif
