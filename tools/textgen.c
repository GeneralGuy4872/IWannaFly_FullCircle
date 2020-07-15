#define newline puts("")

#include <stdlib.h>
#include <stdio.h>

	main (int argc,char *argv[]) {
		if ((argc < 2) || ((argc - 1) % 2)) {
			fprintf(stderr,"usage:\n%s (<attributes> \"string\")* > output.c",argv[0]);
			return 1;
			};

		size_t argpairs = (argc - 1) / 2;

puts("#include <stdlib.h>");
puts("#include <stdio.h>");
puts("#include <stddef.h>");
puts("#include <stdint.h>");
puts("#include <string.h>");
puts("#include <curses.h>");
newline;
printf("static const uint16_t blocks = %i;\n",argpairs);
newline;
puts("char *strings[] = {");
		for (int i = 0;;) {
			printf("\t\"%s\"",argv[(i * 2) + 2]);
			i++;
			if (i < argpairs) {
				puts(",");
			} else {
				puts("};");
				break;
				}}
newline;
puts("uint16_t attrs[] = {");
		for (int i = 0;;) {
			printf("\t%s",argv[(i * 2) + 1]);
			i++;
			if (i < argpairs) {
				puts(",");
			} else {
				puts("};");
				break;
				}}
newline;
puts("main () {");
puts("\tfwrite(&blocks,sizeof(uint16_t),1,stdout);");
puts("\tvolatile size_t L;");
puts("\tfor (int n;n < blocks;n++) {");
puts("\t\tL = strlen(strings[n]);");
puts("\t\tfwrite(&L,sizeof(uint16_t),1,stdout);");
puts("\t\tfwrite(&(attrs[n]),sizeof(uint16_t),1,stdout);");
puts("\t\tfwrite(strings[n],sizeof(char),L,stdout);");
puts("\t\t}");
puts("\treturn 0;");
puts("\t}");
		return 0;
		}
