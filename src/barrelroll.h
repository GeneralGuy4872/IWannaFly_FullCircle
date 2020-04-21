#ifndef __GG4872_BARRELROLL_H__
#define __GG4872_BARRELROLL_H__

#ifndef __cplusplus
#include <stdlib.h>
#include <stdint.h>
#else
#include <cstdint>
extern "C" {
#endif

extern void rol8 (uint8_t * self,unsigned n);
extern void rol16 (uint16_t * self,unsigned n);
extern void rol32 (uint32_t * self,unsigned n);
extern void rol64 (uint64_t * self,unsigned n);
extern void ror8 (uint8_t * self,unsigned n);
extern void ror16 (uint16_t * self,unsigned n);
extern void ror32 (uint32_t * self,unsigned n);
extern void ror64 (uint64_t * self,unsigned n);

#ifdef __cplusplus
}
#endif
#endif
