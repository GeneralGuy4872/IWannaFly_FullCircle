int16_t iwf$$raw16$$octanttriple$$pack (char x,char y,char z) {
	if (
	  ((-13 <= x) && (x <= 13))
	   &&
	  ((-13 <= y) && (y <= 13))
	   &&
	  ((-13 <= z) && (z <= 13))) {
		return (((0x1F & z) << 10)|((0x1F & y) << 5)|(0x1F & x));
	} else {
		errno = EINVAL;
		return -1;
	}}

char iwf$$raw16$$octanttriple$$get$x (int16_t input) {
	char output = (input & 0x1F);
	if (output & 0x10) {
		return output | 0xF0;
	} else {
		return output;
	}};

char iwf$$raw16$$octanttriple$$get$y (int16_t input) {
	char output = ((input >> 5) & 0x1F);
	if (output & 0x10) {
		return output | 0xF0;
	} else {
		return output;
	}};

char iwf$$raw16$$octanttriple$$get$z (int16_t input) {
	char output = ((input >> 10) & 0x1F);
	if (output & 0x10) {
		return output | 0xF0;
	} else {
		return output;
	}};

iwf$$raw16$$octanttriple$$set$x (int16_t * object,char input) {
	if ((-13 <= input) && (input <= 13)) {
		*object &= ~(0x1F);
		*object |= (input & 0x1F);
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}
	};

iwf$$raw16$$octanttriple$$set$y (int16_t * object,unsigned char input) {
	if ((-13 <= input) && (input <= 13)) {
		*object &= ~(0x1F << 5);
		*object |= (input & 0x1F) << 5;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}
	};

iwf$$raw16$$octanttriple$$set$z (int16_t * output,unsigned char input) {
	if ((-13 <= input) && (input <= 13)) {
		*object &= ~(0x1F << 10);
		*object |= (input & 0x1F) << 10;
		return 0;
	} else {
		errno = EINVAL;
		return -1;
		}
	};
