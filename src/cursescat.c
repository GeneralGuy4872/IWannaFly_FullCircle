#include "cursecat.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>

curscat (const char * filename) {
	FILENO fh = openat(DATADIR,filename,O_RDONLY);
	ptrdiff_t blocks;
	read(fh,&blocks,sizeof(ptrdiff_t));
	ptrdiff_t count;
	attr_t attrs;
	char * buffer;
	for (int n = 0;n < blocks;n++) {
		read(fh,&count,sizeof(ptrdiff_t));
		buffer = calloc(count + 1,sizeof(char));
		read(fh,&attrs,sizeof(attr_t));
		attrset(attrs);
		read(fh,buffer,sizeof(char) * count);
		printw("%s",buffer);
		free(buffer);
		}
	close(fh);
	}
