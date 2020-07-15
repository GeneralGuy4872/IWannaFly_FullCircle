#ifndef __GG4872_BITPACK_H__
#define __GG4872_BITPACK_H__

#ifndef __cplusplus
#include <stdlib.h>
#include <stdint.h>
#else
#include <cstdint>
extern "C" {
#endif

void pack_8 (uint8_t * here,uint8_t value,unsigned width,unsigned offset);
uint8_t unpack_u8 (uint8_t * here,unsigned width,unsigned offset);
int8_t unpack_s8 (uint8_t * here,unsigned width,unsigned offset);

void pack_16 (uint16_t * here,uint16_t value,unsigned width,unsigned offset);
uint16_t unpack_u16 (uint16_t * here,unsigned width,unsigned offset);
int16_t unpack_s16 (uint16_t * here,unsigned width,unsigned offset);

void pack_32 (uint32_t * here,uint32_t value,unsigned width,unsigned offset);
uint32_t unpack_u32 (uint32_t * here,unsigned width,unsigned offset);
int32_t unpack_s32 (uint32_t * here,unsigned width,unsigned offset);

void pack_64 (uint64_t * here,uint64_t value,unsigned width,unsigned offset);
uint64_t unpack_u64 (uint64_t * here,unsigned width,unsigned offset);
int64_t unpack_s64 (uint64_t * here,unsigned width,unsigned offset);

#ifdef __cplusplus
}
#endif
#endif
