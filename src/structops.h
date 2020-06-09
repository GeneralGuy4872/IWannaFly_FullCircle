#ifndef __IWF_STRUCTOPS_H__
#define __IWF_STRUCTOPS_H__

#ifndef __cplusplus
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#else
#include <cstdint>
#include <cstddef>
#endif

#include "util.def"

#ifdef __cplusplus
extern "C" {
#endif

extern void meminvert(void * acc,size_t size);
extern void memandset(void * lval,void * rval,size_t size);
extern void memorset(void * lval,void * rval,size_t size);
extern void memnandset(void * lval,void * rval,size_t size);
extern void memnorset(void * lval,void * rval,size_t size);
extern void memxorset(void * lval,void * rval,size_t size);
extern void memxnorset(void * lval,void * rval,size_t size);
#define memeq(X,Y,Z) !memcmp(X,Y,Z)
#define memlt(X,Y,Z) (memcmp(X,Y,Z) < 0)
#define memle(X,Y,Z) (memcmp(X,Y,Z) <= 0)
#define memgt(X,Y,Z) (memcmp(X,Y,Z) > 0)
#define memge(X,Y,Z) (memcmp(X,Y,Z) >= 0)
extern void memswap (void * x,void * y,size_t size);
extern void ptrswap (intptr_t * x,intptr_t * y);

#ifdef __cplusplus
}
#endif
#endif
