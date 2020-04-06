#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void not_a_typewriter() __attribute__((noreturn)) {
	errno = 0;
	fprintf(stderr,"Not a typewriter");
	abort();
	}
