#ifndef VEC_ALIGN_H
#define VEC_ALIGN_H

#include "_sd-ptr_uint.h"

#define VEC_IS_ALIGNED(p) ((((ptr_uint)(p)) & 15) == 0)
#define VEC_IS_UNALIGNED(p) !VEC_IS_ALIGNED((p))

#if defined(VECTOR_VERBOSE_UNALIGNED)

#define vec_unaligned(p) vec_unaligned_core(__func__, __LINE__, (p))
#define vec_aligned(p) vec_aligned_core(__func__, __LINE__, (p))
int vec_unaligned_core(const char *, unsigned long, const void *);
int vec_aligned_core(const char *, unsigned long, const void *);

#else

#define vec_aligned(p) VEC_IS_ALIGNED((p))
#define vec_unaligned(p) VEC_IS_UNALIGNED((p))

#endif /* VECTOR_VERBOSE_UNALIGNED */

#endif /* VEC_ALIGN_H */
