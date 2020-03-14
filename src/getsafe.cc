//WTFPL

#include <iostream>
#include <cstring>

extern "C" {
	char * getsafe() {
		std::string str;
		std::getline(std::cin,str);
		static char * output = new char [str.length() + 1];
		strcpy(output,str.c_str());
		return output;
		}

	char * concat(int argc, char *argv[]) {
		std::string str;
		for (int n = 0;n < argc;n++) {
			str += argv[n];
			}
		static char * output = new char [str.length() + 1];
		strcpy(output,str.c_str());
		return output;
		}
	}
