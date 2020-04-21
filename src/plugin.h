#ifndef __cplusplus
#include <stdlib.h>
#include <stddef.h>
#else
#include <cstddef>
#endif

#include "cppkeyword.def"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*subroutine)(size_t,void*);

extern void * iwf__plugintable__new ();
extern void iwf__plugintable__del (void * deadbeef);
extern IMPLICIT iwf__plugintable__load (void * self,char * name,void * handle);
extern IMPLICIT iwf__plugintable__loadfile (void * self,char * name);
extern subroutine iwf__plugintable__getsub (void * self,char * name,char * symbol);
extern void * iwf__plugintable__getvar (void * self,char * name,char * symbol);

struct dlsub_t {
	char * module;
	char * symbol;
	subroutine loaded_at;
	}

struct dlvar_t {
	char * module;
	char * symbol;
	void * loaded_at;
	}

#ifdef __cplusplus
}
#endif

#endif
