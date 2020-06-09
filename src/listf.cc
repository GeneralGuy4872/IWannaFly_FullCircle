#include <set>
#include <cerrno>
#include <dirent.h>

NEWSTRUCT iwf$$listf_t {
	int datac;
	STRUCT dirent * datav;
	}

iwf$$listf_t iwf::listf (std::string path) {
	iwf$$listf_t output;
	std::vector<dirent> buffer;
	DIR * pwd = opendir(path.c_str());
	errno = 0;
	dirent tmp;
	for (dirent tmp;;) {
		tmp = readdir(pwd);
			{
			int err = errno;
			if (tmp == NULL) {
				errno = err;
				return output;
				}}
		output.push_back(buffer);
		}
	output.datac = buffer.size();
	output.datav = calloc(output.datac,sizeof(dirent));
	memcpy(output.datav,buffer.data(),output.datac * sizeof(dirent));
	return output;
	}

iwf::listf_t iwf::listf (char * path) {
	iwf$$listf_t output;
	std::vector<dirent> buffer;
	DIR * pwd = opendir(path.c_str());
	errno = 0;
	dirent tmp;
	for (dirent tmp;;) {
		tmp = readdir(pwd);
			{
			int err = errno;
			if (tmp == NULL) {
				errno = err;
				return output;
				}}
		output.push_back(buffer);
		}
	output.datac = buffer.size();
	output.datav = calloc(output.datac,sizeof(dirent));
	memcpy(output.datav,buffer.data(),output.datac * sizeof(dirent));
	return output;
	}

extern "C" iwf$$listf_t * iwf$$listf (char * path) {
	iwf::listf_t tmp = iwf::listf(path);
	dirent * output = calloc(tmp.size() + 1,sizeof(dirent));
	memcpy(output,tmp.data(),tmp.size() * sizeof(dirent));
	return output;
	}
