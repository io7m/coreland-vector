#ifndef VEC_DIST_H
#define VEC_DIST_H

float vec_distNf (float *, const float *, const float *, unsigned int);
double vec_distNd (double *, const double *, const double *, unsigned int);

#define vec_dist2f (va) vec_distNf ((va),2)
#define vec_dist3f (va) vec_distNf ((va),3)
#define vec_dist4f (va) vec_distNf ((va),4)
#define vec_dist2fx (va) vec_distNfx ((va),2)
#define vec_dist3fx (va) vec_distNfx ((va),3)
#define vec_dist4fx (va) vec_distNfx ((va),4)

#endif
