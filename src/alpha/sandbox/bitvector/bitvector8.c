bitvector8$$set (unsigned char * object,size_t size,unsigned pos) {
	if ((pos < 8) && (object != NULL) {
		*object |= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}
	
bitvector8$$clear (unsigned char * object,size_t size,unsigned pos) {
	if ((pos < 8) && (object != NULL) {
		*object |= ~(1 << pos);
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bitvector8$$toggle (unsigned char * object,size_t size,unsigned pos) {
	if ((pos < 8) && (object != NULL) {
		*object ^= 1 << pos;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}}

bool bitvector8$$get (unsigned char * object,size_t size,unsigned pos) {
	if ((pos < 8) && (object != NULL) {
		errno = 0;
		return *object & (1 << pos);
	} else {
		errno = EINVAL;
		return 0;
		}}
