#ifndef __cplusplus
#error this IS a C++ file
#endif

#include <sys/types.h>
#include <string>
#include <iostream>
#include <fstream>
#include "cppkeyword.def"

extern "C" char * getsafe() {
	std::string buffer;
	getline(std::cin,buffer);
	size_t len = buffer.length();
	char * output = calloc(len + 1,sizeof(char));
	for (int n;n < len;n++) {
		output[n] = buffer.at(n);
		}
	return output;
	}

extern "C" IMPLICIT cat (const char * filename) {
	std::fstream fs;
	fs.open(filename,std::fstream::in);
	std::stream buffer;
	while (!fs.eof()) {
		getline(fs,buffer);
		std::cout << buffer;
		}
	fs.close();
	}
