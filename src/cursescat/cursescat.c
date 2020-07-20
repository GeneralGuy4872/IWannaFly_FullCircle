#include "cursecat.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fnctrl.h>

iwf$$cursescat (const char * filename) {
	FILENO fh = openat(DATADIR,filename,O_RDONLY);
	ptrdiff_t blocks;
	read(fh,&blocks,sizeof(ptrdiff_t));
	uint16_t count;
	uint16_t attrs;
	char * buffer;
	for (int n = 0;n < blocks;n++) {
		read(fh,&count,sizeof(uint16_t));
		buffer = calloc(count + 1,sizeof(char));
		read(fh,&attrs,sizeof(uint16_t));
		attrset((attr_t)attrs);
		read(fh,buffer,sizeof(char) * count);
		printw("%s",buffer);
		free(buffer);
		}
	close(fh);
	}
