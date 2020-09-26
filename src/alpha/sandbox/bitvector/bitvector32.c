bitvector32$$set (uint32_t * object,size_t size,unsigned char pos) {
	if ((pos < 32) && (object != NULL) {
		*object |= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}
	
bitvector32$$clear (uint32_t * object,size_t size,unsigned char pos) {
	if ((pos < 32) && (object != NULL) {
		*object |= ~(1 << pos);
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bitvector32$$toggle (uint32_t * object,size_t size,unsigned char pos) {
	if ((pos < 32) && (object != NULL) {
		*object ^= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bool bitvector32$$get (uint32_t * object,size_t size,unsigned char pos) {
	if ((pos < 32) && (object != NULL) {
		errno = 0;
		return *object & (1 << pos);
	} else {
		errno = EINVAL;
		return 0;
		}}
