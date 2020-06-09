#ifdef __ROL8__

static inline void rol8 (uint8_t * adhoc,unsigned n) {
	n &= 7;
	*adhoc = (*adhoc << n) | (*adhoc >> (8 - n));
	}

#endif
#ifdef __ROL16__

static inline void rol16 (uint16_t * adhoc,unsigned n) {
	n &= 0x0f;
	*adhoc = (*adhoc << n) | (*adhoc >> (16 - n));
	}

#enddef
#ifdef __ROL32__

static inline void rol32 (uint32_t * adhoc,unsigned n) {
	n &= 0x1f;
	*adhoc = (*adhoc << n) | (*adhoc >> (32 - n));
	}

#endif
#ifdef __ROL64__

static inline void rol64 (uint64_t * adhoc,unsigned n) {
	n &= 0077;
	*adhoc = (*adhoc << n) | (*adhoc >> (64 - n));
	}

#endif
#ifdef __ROR8__

static inline void ror8 (uint8_t * adhoc,unsigned n) {
	n &= 7;
	*adhoc = (*adhoc >> n) | (*adhoc << (8 - n));
	}

#endif
#ifdef __ROR16__

static inline void ror16 (uint16_t * adhoc,unsigned n) {
	n &= 0x0f;
	*adhoc = (*adhoc >> n) | (*adhoc << (16 - n));
	}

#endif
#ifdef __ROR32__

static inline void ror32 (uint32_t * adhoc,unsigned n) {
	n &= 0x1f;
	*adhoc = (*adhoc >> n) | (*adhoc << (32 - n));
	}

#endif
#ifdef __ROR64__

static inline void ror64 (uint64_t * adhoc,unsigned n) {
	n &= 0077;
	*adhoc = (*adhoc >> n) | (*adhoc << (64 - n));
	}

#endif
