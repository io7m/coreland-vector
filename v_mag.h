#ifndef VEC_MAG_H
#define VEC_MAG_H

float vec_magNf (const float *, unsigned int);
double vec_magNd (const double *, unsigned int);

#define vec_mag2f(va) vec_magNf ((va),2)
#define vec_mag3f(va) vec_magNf ((va),3)
#define vec_mag4f(va) vec_magNf ((va),4)
#define vec_mag2fx(va) vec_magNfx ((va),2)
#define vec_mag3fx(va) vec_magNfx ((va),3)
#define vec_mag4fx(va) vec_magNfx ((va),4)

#endif
