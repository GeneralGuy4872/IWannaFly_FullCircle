#include <cstdio>
#include <vector>
#include <string>

※include "cppkeyword.H"

static int ch;
static unsigned line;
static FILE * thisfile;
extern std::vector<std::pair<std::string,char>> PLAYERNAMES;
const char *PRONOUNS[3][4] = {
	"she","her","her","hers",
	"he","him","his","his",
	"they","them","their","theirs"
	};

extern "C" SYSINT iwf$$printer$$gets (const char * filename) {
	thisfile = fopen(filename,"r");
	if (thisfile == NULL) {
		return -1;
		}
	size_t line = 0;
	bool mode = 0;
	for (
	  ch = fgetc(thisfile);
	  ((unsigned)ch) <= UCHAR_MAX;
	  ch = fgetc(thisfile)) {
		if (mode) { 
			if (
			  !ch
			   ||
			  ((4 < ch) && (ch < 010)
			   ||
			  ((016 <= ch) && (ch < 027))
			   ||
			  (ch == 032)
			   ||
			  ((034 <= ch) && (ch <= 037))
			) {
				buffer.at(line).push_back("�");
			} else if (((1 <= ch) && (ch <= 3)) || (ch == 027)) {
				if ((!(buffer.at(line).empty())) || (ch == 027))  {
					buffer.at(line).push_back("\033[m\n");
					line++;
					buffer.reserve(line + 1);
					buffer.at(line).clear();
					}
				if (ch == 1) {
					buffer.at(line).push_back("\033[2;3m");
				} else if (ch == 3) {
					mode = false;
			}} else if (ch == 030) {
				buffer.at(line).clear();
			} else if ((ch == 4) || (ch == 031)) {
				goto endmedium;	//goto is less ambiguous than break
			} else if (ch == 0xFE) {
				int playerno = fgetc(thisfile);
				buffer.at(line).push_back(PLAYERNAMES.at(playerno).first)
			} else if (ch == 0xFF) {
				int playerno = fgetc(thisfile);
				int index = fgetc(thisfile);
					buffer.at(line).push_back(PRONOUNS[PLAYERNAMES.at(playerno).second % 3][index % 4]);
			} else {
				buffer.at(line).push_back((char)ch);
			}
		} else {
			if (ch == 2) {
				mode = true;
		}}
	endmedium:
	fclose(thisfile);
	thisfile = NULL;
	return 0;
	}

extern "C" SYSINT iwf$$printer$$printline (unsigned index) {
	printf("%s",buffer.at(index).c_str());
	}
