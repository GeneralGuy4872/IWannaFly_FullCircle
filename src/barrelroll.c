#ifdef __cplusplus
#error this is not a C++ file
#endif

#include "barrelroll.h"

void rol8 (uint8_t * self,unsigned n) {
	n &= 7;
	*self = (*self << n) | (*self >> (8 - n));
	}

void rol16 (uint16_t * self,unsigned n) {
	n &= 0xf;
	*self = (*self << n) | (*self >> (16 - n));
	}

void rol32 (uint32_t * self,unsigned n) {
	n &= 0x1f;
	*self = (*self << n) | (*self >> (32 - n));
	}

void rol64 (uint64_t * self,unsigned n) {
	n &= 077;
	*self = (*self << n) | (*self >> (64 - n));
	}

void ror8 (uint8_t * self,unsigned n) {
	n &= 7;
	*self = (*self >> n) | (*self << (8 - n));
	}

void ror16 (uint16_t * self,unsigned n) {
	n &= 0xf;
	*self = (*self >> n) | (*self << (16 - n));
	}

void ror32 (uint32_t * self,unsigned n) {
	n &= 0x1f;
	*self = (*self >> n) | (*self << (32 - n));
	}

void ror64 (uint64_t * self,unsigned n) {
	n &= 077;
	*self = (*self >> n) | (*self << (64 - n));
	}
