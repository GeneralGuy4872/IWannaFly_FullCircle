extern volatile atomic_bool HALT;
extern volatile atomic_bool ERROR;

iwf$$threads$$commandline (iwf::types::asrepl * state) {
	std::string buffer;
	for (int as_errno;!(HALT || ERROR);) {
		getline(std::cin,buffer);
		as_errno = ExecuteString(state->engine,buffer.c_str(),state->module,state->context);
		assert (as_errno >= 0) {
			HALT = 1;
			ERROR = 1;
			return -1;
			}
		}
	return ERROR ? -1 : 0;
	}
