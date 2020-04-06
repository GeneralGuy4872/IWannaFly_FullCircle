int ceildiv (int numer,int denom) {
	div_t internal = div(numer,denom);
	return internal.quot + !!(internal.rem);
	}

memread (void * dest,void * source,off_t offset,size_t span,unsigned char skew,unsigned char dropoff) {

	char * chdest = dest;
	char * chsource = source;

	if (skew) {
		if (span == 1) {
			uint8_t buffer;
			memcpy(&buffer,&(source[offset]),1);
			buffer >>= skew;
			buffer &= (-1 << (8 - dropoff));
			return memcpy(&dest,&buffer,1);
		} else {
			uint16_t buffer;
			for (int n;n < (span - 1);n++) {
				memcpy(&buffer,&(source[offset + n]),2);
				buffer >>= skew;
				if ((dropoff) && (n == (span - 2))) {
					buffer &= (-1 << (8 - dropoff));
					}
				memcpy(&(dest[n]),&buffer,1);
				}
			}
	} else {
		uint8_t buffer;
		for (int n = 0;n < span;n++) {
			memcpy(&buffer,&(source[offset + n]),1);
			if ((dropoff) && (n == (span - 1))) {
				buffer &= (-1 << (8 - dropoff));
				}
			memcpy(&(dest[n]),&buffer,1);
			}
		}
	}
	

void * memwritenew (size_t size,int argc,void * argv,int * argw) {
	unsigned char * output = malloc(size);
	uint16_t buffer;
	uint8_t buffer2;
	off_t pos;
	uint8_t srw;
	for (int i;i < argc;i++) {
		unsigned char * this = argv[i];
		if (srw) {
			memcpy(&buffer2,output[pos.quot],1);
			memcpy(&buffer,this,2);
			buffer = buffer2 | (buffer << srw);
			memcpy(&(output[pos]),&buffer,1);
			if (argw[i] + srw >= 8) {
				pos++;
				}
			}
		if (argw[i] >= 8) {
			int n = 0;
			for (;(8 * n) < argw[i]);n++) {
				if (n) {
					pos++;
					}
				memcpy(&buffer,&(this[n]),2);
				buffer <<= srw;
				memcpy(&(output[pos]),&buffer,1);
				}
			}
		srw = (argv[i] - srw) % 8;
		}
	}

void * memwriteat (void * input,off_t pos,uint8_t srw,int argc,void * data,size_t width) {
	unsigned char * chinput = input;
	uint16_t buffer;
	uint8_t buffer2;
	unsigned char * this = data;
		if (srw) {
			memcpy(&buffer2,output[pos.quot],1);
			memcpy(&buffer,&(this[n]),2);
			buffer = buffer2 | (buffer << srw);
			memcpy(&(output[pos]),&buffer,1);
			if (argw[i] + srw >= 8) {
				pos++;
				}
			}
		if (argw[i] >= 8) {
			int n = 0;
			for (;(8 * n) < argw[i]);n++) {
				if (n) {
					pos++;
					}
				memcpy(&buffer,&(this[n]),2);
				buffer <<= srw;
				memcpy(&(output[pos]),&buffer,1);
				}
			}
		srw = (argv[i] - srw) % 8;
		}
	}
