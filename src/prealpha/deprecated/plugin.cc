#include "plugin.h"
#include <libgen.h>

#include "CONFIG.DEF"
#include "atomic_mutex.h"

#ifndef __IWF_HAS_DLFUNC__
#include "dlfunc_shim.inl"
#endif

class iwf::plugintable {
	std::map<std::string;void*> data;
	atomic_mutex mutex;
	public:
	bool loadplugin (std::string key,void * handle) {
		atomic_mutex$$lock(this->mutex);
		if (exists<std::string;void*>(&PLUGIN_TABLE,key) {
			dlclose(PLUGIN_TABLE[key]);
			}
		this->data[key] = handle;
		atomic_mutex$$unlock(this->mutex);
		return 1;
		}
	bool cloadplugin (char * name,void * handle) {
		std::string key = name;
		atomic_mutex$$lock(this->mutex);
		if (exists<std::string;void*>(&PLUGIN_TABLE,key) {
			dlclose(PLUGIN_TABLE[key]);
			}
		this->data[key] = handle;
		atomic_mutex$$unlock(this->mutex);
		return 1;
		}
	bool loadpluginfile (char * path) {
		void * handle;
		if (path == NULL) {
			fprintf(stderr,"...you want me to take NULL and do what with it?\n");
			return false;
		} else if (path[0] == '/') {
			handle = dlopen(path,RTLD_NOW | RTLD_PRIVATE);
		} else if (path[0] < 034) {
			fprintf(stderr,"refusing to load plugin: %s is not a valid filename",path);
			return false;
		} else {
			std::string newpath = CONFIG_DEFAULT_LIB_PATH;
			newpath.append(path);
			newpath.append(CONFIG_PLUGIN_SUFFIX);
			handle = dlopen(newpath.c_str(),RTLD_NOW | RTLD_PRIVATE);
			}
		if (handle == NULL) {
			fprintf(stderr,"%s\n",dlerror());
			return false;
			}
		std::string key = basename(path);
		return this->loadplugin(key,handle);
		}
	dlfunc_t getf (std::string key,char * symbol) {
		atomic_mutex$$increment(this->mutex);
		void * handle;
		try {
			handle = PLUGIN_TABLE.at(key);
		} catch (std::out_of_range) {
			atomic_mutex$$decrement(this->mutex);
			fprintf(stderr,"cannot find :%s;%s",module,symbol);
			return NULL;
			}
		atomic_mutex$$decrement(this->mutex);
		dlfunc_t symptr = dlfunc(handle,symbol);
		if (symptr == NULL) {
			fprintf(stderr,"%s\n",dlerror());
			return NULL;
			}
		return symptr;
		}
	void * getsym (std::string key,char * symbol) {
		atomic_mutex$$increment(this->mutex);
		void * handle;
		try {
			handle = PLUGIN_TABLE.at(key);
		} catch (std::out_of_range) {
			atomic_mutex$$decrement(this->mutex);
			fprintf(stderr,"cannot find :%s;%s",module,symbol);
			return NULL;
			}
		atomic_mutex$$decrement(this->mutex);
		void * symptr = dlsym(handle,symbol);
		if (symptr == NULL) {
			fprintf(stderr,"%s\n",dlerror());
			return NULL;
			}
		return symptr;
		}
	}

extern "C" {

void * iwf$$plugintable$$new () {
	return new iwf::plugintable;
	}

void iwf$$plugintable$$del (void * deadbeef) {
	delete deadbeef;
	}

IMPLICIT iwf$$plugintable$$load (void * self,char * name,void * handle) {
	return -!( ((iwf::plugintable*)self)->cloadplugin(name,handle) );
	}

IMPLICIT iwf$$plugintable$$loadfile (void * self,char * name) {
	return -!( ((iwf::plugintable*)self)->loadplugin(name) );
	}

dlfunc_t iwf$$plugintable$$getf (void * self,char * name,char * symbol) {
	std::string key = name;
	return ((iwf::plugintable*)self)->getf(key,symbol);
	}

void * iwf$$plugintable$$getsym (void * self,char * name,char * symbol) {
	std::string key = name;
	return ((iwf::plugintable*)self)->getsub(key,symbol);
	}
}
