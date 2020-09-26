#ifdef __cplusplus
#error this is very much not a C++ file
#endif

#include "bitpack.h"
#include "base1.def"

void pack_8 (unsigned char * object,unsigned char value,unsigned width,int offset) {
	width &= 7;
	div_t pos = div(offset,CHAR_BITS);
	unsigned char mask = base1(unsigned char,width) << pos.rem;
	value <<= pos.rem;
	object[pos.quot] = (object[pos.quot] & ~mask) | (value & mask);
	}

unsigned char unpack_u8 (unsigned char * object,unsigned char width,int offset) {
	width &= 7;
	div_t pos = div(offset,CHAR_BITS);
	unsigned char output = object[pos.quot] >> pos.rem;
	return output & base1(width);
	}

char unpack_s8 (unsigned char * here,unsigned width,unsigned offset) {
	uint8_t output = *here >> offset;
	return output & base1(width);
	}

void pack_16 (unsigned char * object,uint16_t value,unsigned width,int offset) {
	width &= 0x0F;
	div_t pos = div(offset,16);
	uint16_t mask = base1(uint16_t,width) << pos.rem;
	value <<= pos.rem;
	uint16_t * here = object[pos.quot];
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

int64_t unpack_s64 (uint64_t * here,unsigned width,unsigned offset) {
	uint64_t output = *here >> offset;
	return output & base1(width);
	}
