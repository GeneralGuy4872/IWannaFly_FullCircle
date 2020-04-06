#error I see no headers here...

#include "seedcrypt.h"

MD4_seed initseed () {
	MD4_CTX context;
	std::string input;
	static MD4_seed output;
	getline(std::cin,input);
	MD4Init(&context);
	MD4Update(&context,input.c_str(),strlen(input.c_str()));
	MD4Final(&output,&context);
	return output;
	}
