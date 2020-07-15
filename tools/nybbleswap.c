/* a trivial 4-bit rotate cipher program, for hiding spoilers.
 * inspired by the rot13 cipher commonly used for the same pourpose.
 *
 * WTFPL
 */

#include <stdlib.h>
#include <stdio.h>

main () {
	unsigned char ch;
	for (int err = fgetc(stdin);err != EOF;err = fgetc(stdin)) {
		ch = err;
		ch = ch >> 4 | ch << 4;
		fputc(ch,stdout);
		}
	return 0;
	}
