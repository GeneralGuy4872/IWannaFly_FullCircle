bitvector64$$set (uint64_t * object,size_t size,unsigned pos) {
	if ((pos < 64) && (object != NULL) {
		*object |= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}
	
bitvector64$$clear (uint64_t * object,size_t size,unsigned pos) {
	if ((pos < 64) && (object != NULL) {
		*object |= ~(1 << pos);
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bitvector64$$toggle (uint64_t * object,size_t size,unsigned pos) {
	if ((pos < 64) && (object != NULL) {
		*object ^= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bool bitvector64$$get (uint64_t * object,size_t size,unsigned pos) {
	if ((pos < 64) && (object != NULL) {
		errno = 0;
		return *object & (1 << pos);
	} else {
		errno = EINVAL;
		return 0;
		}}
