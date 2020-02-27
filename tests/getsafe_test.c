#include <stdlib.h>
#include <stdio.h>
#include "../src/getsafe.h"

main () {
	char * this;
	this = getsafe();
	printf("%s",this);
	}
