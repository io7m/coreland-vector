#ifndef VEC_ALIGN_H
#define VEC_ALIGN_H

#define vec_unaligned(p) vec_unaligned_core(__func__, __LINE__, (p))
int vec_unaligned_core(const char *, unsigned long, const void *);

#endif
