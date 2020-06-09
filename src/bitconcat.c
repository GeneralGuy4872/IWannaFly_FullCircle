#ifdef __cplusplus
#error this is not a C++ file
#endif

#include "bitconcat.h"

uint16_t bitconcat8(uint8_t h,uint8_t l) {
	return ((uint16_t)h << 8) | l;
	}

uint32_t bitconcat16(uint16_t h,uint16_t l) {
	return ((uint32_t)h << 16) | l;
	}

uint64_t bitconcat32(uint32_t h,uint32_t l) {
	return ((uint64_t)h << 32) | l;
	}
