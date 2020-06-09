#ifdef __cplusplus
#error this is very much not a C++ file
#endif

#include "bitpack.h"
#include "base1.def"

void pack_8 (uint8_t * here,uint8_t value,unsigned width,unsigned offset) {
	offset &= 7;
	uint8_t mask = invbase1(width) << offset;
	value <<= offset;
	*here = (here & mask) | (value & ~mask);
	}

uint8_t unpack_u8 (uint8_t * here,unsigned width,unsigned offset) {
	uint8_t output = *here >> offset;
	return output & base1(width);
	}

int8_t unpack_s8 (uint8_t * here,unsigned width,unsigned offset) {
	uint8_t output = *here >> offset;
	return output & base1(width);
	}

void pack_8 (uint16_t * here,uint16_t value,unsigned width,unsigned offset) {
	offset &= 0x0F;
	uint16_t mask = invbase1(width) << offset;
	value <<= offset;
	*here = (here & mask) | (value & ~mask);
	}

uint16_t unpack_u16 (uint16_t * here,unsigned width,unsigned offset) {
	uint16_t output = *here >> offset;
	return output & base1(width);
	}

int16_t unpack_s16 (uint16_t * here,unsigned width,unsigned offset) {
	uint16_t output = *here >> offset;
	return output & base1(width);
	}

void pack_32 (uint32_t * here,uint32_t value,unsigned width,unsigned offset) {
	offset &= 0x1F;
	uint32_t mask = invbase1(width) << offset;
	value <<= offset;
	*here = (here & mask) | (value & ~mask);
	}

uint32_t unpack_u32 (uint32_t * here,unsigned width,unsigned offset) {
	uint32_t output = *here >> offset;
	return output & base1(width);
	}

int32_t unpack_s32 (uint8_t * here,unsigned width,unsigned offset) {
	uint32_t output = *here >> offset;
	return output & base1(width);
	}

void pack_64 (uint64_t * here,uint64_t value,unsigned width,unsigned offset) {
	offset &= 077;
	uint64_t mask = invbase1(width) << offset;
	value <<= offset;
	*here = (here & mask) | (value & ~mask);
	}

uint64_t unpack_u64 (uint64_t * here,unsigned width,unsigned offset) {
	uint64_t output = *here >> offset;
	return output & base1(width);
	}

int64_t unpack_s64 (uint8_t * here,unsigned width,unsigned offset) {
	uint64_t output = *here >> offset;
	return output & base1(width);
	}
