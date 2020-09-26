unsigned char iwf$$raw8$$tileref$$pack (unsigned char bank,unsigned char tile) {
	if ((bank < 4)&&(tile < 0100)) {
		return ((bank << 6)|(tile));
	} else {
		errno = EINVAL;
		return -1;
	}}

unsigned char iwf$$raw8$$tileref$$gettile (unsigned char input) {
	return (input & 077);
	};

unsigned char iwf$$raw8$$tileref$$getbank (unsigned char input) {
	return ((input >> 6) & 3);
	};

iwf$$raw8$$tileref$$settile (unsigned char * object,unsigned char input) {
	if (input < 0100) {
		*object &= ~(0300);
		*object |= input;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}
	};

iwf$$raw8$$tileref$$setbank (unsigned char * object,unsigned char input) {
	if (input < 4) {
		*object &= ~(077);
		*object |= (input << 6);
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}
	};
