std::string iwf::commandline::stringbuffer;

extern "C" {
	void iwf$$commandline$$stringbuffer$clear() {
		iwf::commandline::stringbuffer.clear();
		}
	char * iwf$$commandline$$stringbuffer$c_str () {
		return iwf::commandline::stringbuffer.c_str();
		}
	size_t iwf$$commandline$$stringbuffer$length () {
		return iwf::commandline::stringbuffer.length();
		}
	void iwf$$commandline$$stringbuffer$push_back (char input) {
		iwf::commandline::stringbuffer.push_back(input);
		}
	}

static std::set<char*> iwf$$commandline$$garbage;

extern "C" {
	void iwf$$commandline$$garbage$insert (char * input) {
		iwf::commandline::garbage.insert(input);
		}
	}

iwf::commandline::collectgarbage () {
	iwf::commandline::stringbuffer.clear()
	for (std::set<char*>::iterator i iwf::commandline::garbage.begin();i != iwf::commandline::garbage.end();) {
		free(*i);
		i = iwf::commandline::garbage.erase(i);
		}

iwf::commandline::repl () {
	for (;;) {
		
		yyparse();
		
