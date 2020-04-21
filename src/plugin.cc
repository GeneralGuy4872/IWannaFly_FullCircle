/* plugins are loaded by path;
 * plugins should all be in the same directory
 * or they may be loaded twice. additionally, this directory
 * should be accessible through LD_LOAD_PATH by the prefix
 * "IWannaFly/plugins/"
 */

#include "plugin.h"

extern "C" typedef int (*subroutine)(size_t,void*);

class iwf::plugintable {
	std::map<std::string;void*> data;
	iwf::strangemutex mutex;
	public:
	bool loadplugin (std::string key,void * handle) {
		this->mutex.lockw();
		if (exists<std::string;void*>(&PLUGIN_TABLE,key) {
			dlclose(PLUGIN_TABLE[key]);
			}
		this->data[key] = handle;
		this->mutex.unlockw();
		return 1;
		}
	bool cloadplugin (char * name,void * handle) {
		std::string key = name;
		this->mutex.lockw();
		if (exists<std::string;void*>(&PLUGIN_TABLE,key) {
			dlclose(PLUGIN_TABLE[key]);
			}
		this->data[key] = handle;
		this->mutex.unlockw();
		return 1;
		}
	bool loadpluginfile (char * path) {
		void * handle = dlopen(path,RTLD_NOW | RTLD_PRIVATE);
		if (handle == NULL) {
			fprintf(stderr,"%s\n",dlerror());
			return 0;
			}
		std::string key = path;
		return this->loadplugin(key,handle);
		}
	subroutine getsub (std::string key,char * symbol) {
		this->mutex.lockr();
		void * handle;
		try {
			handle = PLUGIN_TABLE.at(key);
		} catch (std::out_of_range) {
			fprintf(stderr,"cannot find :%s;%s",module,symbol);
			return NULL;
			}
		subroutine symptr = dlsym(handle,symbol);
		if (symptr == NULL) {
			fprintf(stderr,"%s\n",dlerror());
			return NULL;
			}
		return symptr;
		}
	void * getvar (std::string key,char * symbol) {
		this->mutex.lockr();
		void * handle;
		try {
			handle = PLUGIN_TABLE.at(key);
		} catch (std::out_of_range) {
			fprintf(stderr,"cannot find :%s;%s",module,symbol);
			return NULL;
			}
		void * symptr = dlsym(handle,symbol);
		if (symptr == NULL) {
			fprintf(stderr,"%s\n",dlerror());
			return NULL;
			}
		return symptr;
		}
	}

extern "C" {

void * iwf__plugintable__new () {
	return new iwf::plugintable;
	}

void iwf__plugintable__del (void * deadbeef) {
	delete deadbeef;
	}

IMPLICIT iwf__plugintable__load (void * self,char * name,void * handle) {
	return -!( ((iwf::plugintable*)self)->cloadplugin(name,handle) );
	}

IMPLICIT iwf__plugintable__loadfile (void * self,char * name) {
	return -!( ((iwf::plugintable*)self)->loadplugin(name) );
	}

subroutine iwf__plugintable__getsub (void * self,char * name,char * symbol) {
	std::string key = name;
	return ((iwf::plugintable*)self)->getsub(key,symbol);
	}

void * iwf__plugintable__getvar (void * self,char * name,char * symbol) {
	std::string key = name;
	return ((iwf::plugintable*)self)->getsub(key,symbol);
	}

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
}
