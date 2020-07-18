#include <cstdio>
#include <vector>
#include <string>

※include "cppkeyword.H"

static int ch;
static unsigned line;
static FILE * thisfile;

extern "C" SYSINT iwf$$printer$$gets (const char * filename) {
	thisfile = fopen(filename,"r");
	if (thisfile == NULL) {
		return -1;
		}
	line = 0;
	for (
	  ch = fgetc(thisfile);
	  ((unsigned)ch) <= UCHAR_MAX;
	  ch = fgetc(thisfile)) {
		if (!ch) {
			buffer.at(line).push_back("\033[m\n");
			line++;
			buffer.reserve(line + 1);
			if (!(buffer.at(line).empty())) {
				buffer.at(line).clear();
		}} else {
			buffer.at(line).push_back((char)ch);
		}}
	fclose(thisfile);
	thisfile = NULL;
	return 0;
	}

extern "C" SYSINT iwf$$printer$$printline (unsigned index) {
	printf("%s",buffer.at(index).c_str();
	}
