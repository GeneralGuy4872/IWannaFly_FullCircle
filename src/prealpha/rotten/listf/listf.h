#ifndef __GG4872_LISTF_H__
#define __GG4872_LISTF_H__

#ifndef __cplusplus
#include <stdlib.h>
#include <errno.h>
#else
#include <cerrno>
#endif

#include <dirent.h>
#include "cppkeyword.def"

NEWSTRUCT iwf$$listf_t {
	int datac;
	STRUCT dirent * datav;
	}

#ifdef __cplusplus
#include <set>
#include <string>

extern iwf$$listf_t iwf::listf (std::string path);
extern iwf$$listf_t iwf::listf (char * path);

extern "C" {
#endif

extern iwf$$listf_t iwf$$listf (char * path);

#ifdef __cplusplus
}
#endif
#endif
