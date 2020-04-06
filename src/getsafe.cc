#error I see no headers here...

char * getsafe() {
	std::string buffer;
	getline(std::cin,buffer);
	size_t len = buffer.length();
	char * output = calloc(len + 1,sizeof(char));
	for (int n;n < len;n++) {
		output[n] = buffer.at(n);
		}
	return output;
	}
