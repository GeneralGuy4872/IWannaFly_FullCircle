#include "variablewidthdatablock.hh"

int variablewidthdatablock_write (FILENO file,variablewidthdatablock * datablock) {
	ssize_t x, y;
	size_t tmp = datablock->size();
	if (write(file,&tmp,sizeof(size_t)) < 0) {
		return -1;
		}
	return write(file,datablock->data(),tmp);
	}

int variablewidthdatablock_read (FILENO file,variablewidthdatablock * emptyblock) {
	errno = 0;
	if (!emptyblock.empty()) {
		errno = EINVAL;
		return -1;
		}
	size_t tmp;
	if (!(read(file,&tmp,sizeof(size_t)))) {
		if (errno) {
			return -1;
		}}
	emptyblock.reserve(tmp);
	return read(file,emptyblock.data(),tmp);
	}
