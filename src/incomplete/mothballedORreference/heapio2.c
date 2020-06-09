memread (void * dest,void * src,size_t length,size_t bounds,off_t offset,uint8_t srw,uint8_t endmask) {
	unsigned char * chdest;
	unsigned char * chsrc;
	uint16_t buffer;
	for (int n;n < length;n++) {
		buffer = 0;
		if ((n + offset) == (bounds - 1)) {
			memcpy(&buffer,chsrc + n + offset,1);
		} else {
			memcpy(&buffer,chsrc + n + offset,2);
			}
		buffer >>= srw;
		if (n == (length - 1)) {
			buffer &= endmask;
			}
		memcpy(chdest + n,buffer,1);
		}
	}

memwrite (void * src,void * dest,size_t length,size_t bounds,off_t offset,uint8_t slw,uint8_t endmask) {
	unsigned char * chdest;
	unsigned char * chsrc;
	uint8_t buffer2;
	uint16_t buffer1;
	if (slw && ((length + offset) >= bounds)) {
		errno = EIO;
		return -1;
		}
	{
	int n;
	if (slw) {
		memcpy(&buffer1,chdest + offset,1);
		buffer2 ^= -1 << slw;
		memcpy(&buffer2,chsrc,2);
		buffer2 &= buffer1 << slw;
		memcpy(chdest[offset],&buffer2,1);
		n++;
	for (int n;n < length;n++) {
		memcpy(&buffer1,chsrc + n,(((offset + n) < bounds) ? 1 : 2));
		buffer1 <<= slw;
		if (n == (length - 1)) {
			buffer &= endmask;
			}
		memcpy(chdest + n + offset,buffer,1);
		}
	}
