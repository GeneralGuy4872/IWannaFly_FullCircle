bitvector16$$set (uint16_t * object,size_t size,unsigned pos) {
	if ((pos < 16) && (object != NULL) {
		*object |= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}
	
bitvector16$$clear (uint16_t * object,size_t size,unsigned pos) {
	if ((pos < 16) && (object != NULL) {
		*object |= ~(1 << pos);
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bitvector16$$toggle (uint16_t * object,size_t size,unsigned pos) {
	if ((pos < 16) && (object != NULL) {
		*object ^= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bool bitvector16$$get (uint16_t * object,size_t size,unsigned pos) {
	if ((pos < 16) && (object != NULL) {
		errno = 0;
		return *object & (1 << pos);
	} else {
		errno = EINVAL;
		return 0;
		}}
