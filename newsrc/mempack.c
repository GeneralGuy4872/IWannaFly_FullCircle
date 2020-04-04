mempack (void * opaque,uint8_t * input,int bitoffset,int length,size_t boundry) {
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
	}

memunpack (void * opaque,uint8_t * output,int bitoffset,int length,int boundry) {
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