/*************************************************************************!
 * this is an example file of how to generate a bytecode representation
 * for colored text. it should adverage out around the same size as an
 * NFO file containing the same data, but uses ncurses to implement a
 * portable generation script.
 *
 * despite this technically being a script, it is unlikely to be rewritten
 * in a scripting language, as the width of fields are defined by sizeof()
 * calls against types defined in the ncurses implementation and the
 * standard library.
 *
 * although the generation script as shown here should be portable,
 * the file it produces is very much not.
 *
 * compile with "-lcurses", and run the resulting file to generate the file
 *************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <curses.h>

const ptrdiff_t blocks = 7;

char *strings[] = {
	"The ",
	"quick",
	" ",
	"brown",
	" fox jumps over the ",
	"lazy dog",
	"."};

attr_t attrs[] = {
	0,
	A_ITALIC,
	0,
	COLOR_PAIR(COLOR_WHITE | (8 * COLOR_YELLOW)) | A_DIM,
	0,
	A_BOLD,
	0};

main () {
	FILE * fp = fopen("examplecursestext.hex","a+");
	fwrite(&blocks,sizeof(ptrdiff_t),1,fp);
	{ptrdiff_t L;
	for (int n;n < 7;n++) {
		L = strlen(strings[n]);
		fwrite(&L,sizeof(ptrdiff_t),1,fp);
		fwrite(&(attrs[n]),sizeof(attr_t),1,fp);
		fwrite(strings[n],sizeof(char),L,fp);
		}};
	fclose(fp);
	}
