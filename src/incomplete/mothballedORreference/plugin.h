#ifndef __cplusplus
#include <stdlib.h>
#include <stddef.h>
#else
#include <cstddef>
#endif

#include "cppkeyword.def"

#ifndef __IWF_HAS_DLFUNC__
#include "dlfunc_shim.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void * iwf$$plugintable$$new ();
extern void iwf$$plugintable$$del (void * deadbeef);
extern IMPLICIT iwf$$plugintable$$load (void * self,char * name,void * handle);
extern IMPLICIT iwf$$plugintable$$loadfile (void * self,char * name);
extern dlfunc_t iwf$$plugintable$$getf (void * self,char * name,char * symbol);
extern void * iwf$$plugintable$$getsym (void * self,char * name,char * symbol);

struct iwf$$types$$dlfunc_fastref {
	char * module;
	char * symbol;
	dlfunc_t loaded_at;
	}

struct iwf$$types$$dlsym_fastref {
	char * module;
	char * symbol;
	void * loaded_at;
	}

#ifdef __cplusplus
}
#endif

#endif
