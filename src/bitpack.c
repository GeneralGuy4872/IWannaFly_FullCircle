#ifdef __cplusplus
#error this is very much not a C++ file
#endif

#include "bitpack.h"
#include "base1.def"

void pack_8 (uint8_t * here,uint8_t value,unsigned width,unsigned offset) {
	uint8_t mask = base1(width);
	value &= mask;
	value <<= offset;
	mask <<=offset;
	mask = ~mask;
	*here &= mask;
	*here |= value;
	}

uint8_t unpack_u8 (uint8_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	uint8_t output = *here & mask;
	return output >> offset;
	}

int8_t unpack_s8 (uint8_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	int8_t output = *here & mask;
	return output >> offset;
	}

void pack_16 (uint16_t * here,uint16_t value,unsigned width,unsigned offset) {
	uint8_t mask = base1(width);
	value &= mask;
	value <<= offset;
	mask <<=offset;
	mask = ~mask;
	*here &= mask;
	*here |= value;
	}

uint16_t unpack_u16 (uint16_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	uint8_t output = *here & mask;
	return output >> offset;
	}

int16_t unpack_s16 (uint16_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	int8_t output = *here & mask;
	return output >> offset;
	}

void pack_32 (uint32_t * here,uint32_t value,unsigned width,unsigned offset) {
	uint8_t mask = base1(width);
	value &= mask;
	value <<= offset;
	mask <<=offset;
	mask = ~mask;
	*here &= mask;
	*here |= value;
	}

uint32_t unpack_u32 (uint32_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	uint8_t output = *here & mask;
	return output >> offset;
	}

int32_t unpack_s32 (uint32_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	int8_t output = *here & mask;
	return output >> offset;
	}

void pack_64 (uint64_t * here,uint64_t value,unsigned width,unsigned offset) {
	uint8_t mask = base1(width);
	value &= mask;
	value <<= offset;
	mask <<=offset;
	mask = ~mask;
	*here &= mask;
	*here |= value;
	}

uint64_t unpack_u64 (uint64_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	uint8_t output = *here & mask;
	return output >> offset;
	}

int64_t unpack_s64 (uint64_t * here,unsigned width,unsigned offset) {
	uint8_t mask = base1(width) << offset;
	int8_t output = *here & mask;
	return output >> offset;
	}
