#ifndef __GG4872_BITCONCAT_H__
#define __GG4872_BITCONCAT_H__

#ifndef __cplusplus
#include <stdlib.h>
#include <stdint.h>
#else
#include <cstdint>
extern "C" {
#endif

extern uint16_t bitconcat8 (uint8_t h,uint8_t l);
extern uint32_t bitconcat16 (uint16_t h,uint16_t l);
extern uint64_t bitconcat32 (uint32_t h,uint32_t l);

#ifdef __cplusplus
}
#endif
#endif
