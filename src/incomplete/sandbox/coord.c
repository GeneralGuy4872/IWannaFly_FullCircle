int16_t iwf$$raw16$$coord3$$pack (unsigned char x,unsigned char y,unsigned char z) {
	if ((z < 0x20)&&(y < 0x20)&&(x < 0x20)) {
		return ((z << 10)|(y << 5)|(x));
	} else {
		errno = EINVAL;
		return -1;
	}}

unsigned char iwf$$raw16$$coord3$$get$x (int16_t input) {
	return (input & 0x1F);
	}

unsigned char iwf$$raw16$$coord3$$get$y (int16_t input) {
	return ((input >> 5) & 0x1F);
	}

unsigned char iwf$$raw16$$coord3$$get$z (int16_t input) {
	return ((input >> 10) & 0x1F);
	}

iwf$$raw16$$coord3$$set$x (int16_t * object,unsigned char input) {
	if (input < 0x20) {
		*object &= ~(0x1F);
		*object |= input;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
	}}

iwf$$raw16$$coord3$$set$y (int16_t * object,unsigned char input) {
	if (input < 0x20) {
		*object &= ~(0x1F << 5);
		*object |= input << 5;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
	}}

iwf$$raw16$$coord3$$set$z (int16_t * object,unsigned char input) {
	if (input < 0x20) {
		*object &= ~(0x1F << 10);
		*object |= input << 10;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
	}}
