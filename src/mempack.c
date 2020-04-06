meminvert (void * acc,size_t size) {
	unsigned char * q = acc;
	for (int n = 0;n < size;n++) {
		q[n] = ~(q[n]);
		}
	}

memand (void * acc,void * lval,void * rval,size_t size) {
	unsigned char * q = acc;
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		q[n] = x[n] & y[n];
		}
	}

memor (void * acc,void * lval,void * rval,size_t size) {
	unsigned char * q = acc;
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		q[n] = x[n] | y[n];
		}
	}

memnand (void * acc,void * lval,void * rval,size_t size) {
	unsigned char * q = acc;
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		q[n] = ~(x[n] & y[n]);
		}
	}

memnor (void * acc,void * lval,void * rval,size_t size) {
	unsigned char * q = acc;
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		q[n] = ~(x[n] | y[n]);
		}
	}

memxor (void * acc,void * lval,void * rval,size_t size) {
	unsigned char * q = acc;
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		q[n] = x[n] ^ y[n];
		}
	}

memxnor (void * acc,void * lval,void * rval,size_t size) {
	unsigned char * q = acc;
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		q[n] = ~(x[n] ^ y[n]);
		}
	}

memandset (void * lval,void * rval,size_t size) {
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] &= y[n];
		}
	}

memorset (void * lval,void * rval,size_t size) {
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] |= y[n];
		}
	}

memnandset (void * lval,void * rval,size_t size) {
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] = ~(x[n] & y[n]);
		}
	}

memnorset (void * lval,void * rval,size_t size) {
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] = ~(x[n] | y[n]);
		}
	}

memxorset (void * lval,void * rval,size_t size) {
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] ^= y[n];
		}
	}

memxnorset (void * lval,void * rval,size_t size) {
	unsigned char * x = lval;
	unsigned char * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] = ~(x[n] ^ y[n]);
		}
	}

#define memeq(X,Y,Z) !memcmp(X,Y,Z)
#define memlt(X,Y,Z) (memcmp(X,Y,Z) < 0)
#define memle(X,Y,Z) (memcmp(X,Y,Z) <= 0)
#define memgt(X,Y,Z) (memcmp(X,Y,Z) > 0)
#define memge(X,Y,Z) (memcmp(X,Y,Z) >= 0)

mempack (void * opaque,uint8_t * input,uint8_t bitoffset,int length,size_t boundry) {
/**HERE BE DRAGONS**/
	uint8_t * output = opaque;
	div_t offset = div(bitoffset,8);
	uint16_t buffer1;
	uint16_t buffer2;
	uint16_t mask;
	while (length > 0) {
		if (!boundry) {
			errno = EFAULT;
			return -1;
			}

		buffer1 = 0;
		memcpy(&buffer1,input,1);
		buffer1 <<= offset.rem;

		if (length < 8) {
			buffer2 = 0;
			memcpy(&buffer2,output + offset.quot,min(boundry,sizeof(uint16_t)));
			mask = -1;
			mask <<= length;
			meminvert(&mask,sizeof(uint16_t));
			memandset(&buffer2,&mask,sizeof(uint16_t));
			memorset(&buffer1,&buffer2,sizeof(uint16_t));
			}

		if (offset.rem) {
			buffer2 = 0;
			memcpy(&buffer2,output + offset.quot,min(boundry,sizeof(uint16_t)));
			mask = -1;
			mask <<= offset.rem;
			meminvert(&mask,sizeof(uint16_t));
			memandset(&buffer2,&mask,min(boundry,sizeof(uint16_t)));
			memorset(&buffer1,&buffer2,min(boundry,sizeof(uint16_t)));
			}

		length -= 8;
		boundry--;
		}
	return 0;
	}

memunpack (void * opaque,uint8_t * output,uint8_t bitoffset,int length,size_t boundry) {
	uint8_t * input = opaque;
	div_t offset = div(bitoffset,8);
	uint16_t buffer;
	uint8_t mask;
	for (int n;length > 0;n++) {
		if (!boundry) {
			errno = EFAULT;
			return -1;
			}

		buffer1 = 0;
		memcpy(&buffer1,input,min(boundry,sizeof(uint16_t)));
		buffer >>= offset.rem;

		if (length < 8) {
			mask = -1;
			mask >>= length;
			memandset(&buffer,&mask,sizeof(uint8_t));
			}

		memcpy(output + offset.quot,buffer,1);
		length -= 8;
		boundry--;
		}
	return 0;
	}

memswap(void * x,void * y,size_t size) {
	uint8_t * xx = x;
	uint8_t * yy = y;
	uint8_t tmp;
	for (int n,n < size_t,n++) {
		tmp = 0;
		tmp = xx[n];
		xx[n] = yy[n];
		yy[n] = tmp;
		}
	return 0;
	}

void ptrswap(intptr_t * x,intptr_t * y) {
	intptr_t tmp = *x;
	*x = *y;
	*y = tmp;
	}
