#include extmodules.h
#include extmodules.hh

class pluginholder {
	public:
		std::map<std::string;void*> objects;

		void * load (std::string filename) {
			void * tmp = objects[filename];
			if (tmp == NULL) {
				objects[filename] = dlopen(filename.c_str(),RTLD_NOW);
				if (objects[filename] == NULL) {
					fprintf(stderr,"cannot dynamically link to %s:\n%s\n",filename.c_str(),dlerror());
					exit(1);
					}
				}
			return objects[filename];
			}

		void * load (char * filename) {
			std::string stdfilename( ((filename == NULL) ? "" : filename) );
			void * tmp = objects[stdfilename];
			if (tmp == NULL) {
				objects[stdfilename] = dlopen(filename,RTLD_NOW);
				if (objects[stdfilename] == NULL) {
					fprintf(stderr,"cannot dynamically link to %s:\n%s\n",filename,dlerror());
					exit(1);
					}
				}
			return objects[stdfilename];
			}

		subroutine getsub (std::string filename,const char * symbol) {
			this->load(filename);
			subroutine output;
			output = dlsym(objects[filename],symbol);
			if (output == NULL) {
				fprintf(stderr,"cannot get executable symbol %s in module %s:\n%s\n",symbol,filename.c_str(),dlerror());
				exit(1);
				}
			}

		subroutine getsub (char * filename,const char * symbol) {
			std::string stdfilename( ((filename == NULL) ? "" : filename) );
			this->load(stdfilename);
			output = dlsym(objects[stdfilename],symbol);
			if (output == NULL) {
				fprintf(stderr,"cannot get executable symbol %s in module %s:\n%s\n",symbol,filename.c_str(),dlerror());
				exit(1);
				}
			}

		void * getvar (std::string filename,const char * symbol) {
			this->load(filename);
			subroutine output = dlsym(objects[filename],symbol);
			if (output == NULL) {
				fprintf(stderr,"cannot get data symbol %s in module %s:\n%s\n",symbol,filename.c_str(),dlerror());
				/*continue*/
				}
			}

		void * getvar (char * filename,const char * symbol) {
			std::string stdfilename( ((filename == NULL) ? "" : filename) );
			this->load(stdfilename);
			subroutine output = dlsym(objects[stdfilename],symbol);
			if (output == NULL) {
				fprintf(stderr,"cannot get data symbol %s in module %s:\n%s\n",symbol,filename.c_str(),dlerror());
				/*continue*/
				}
			}


	}

pluginholder PLUGINS;

extern "C" void * PLUGIN_LOAD (char * filename) {
	std::string tmp(filename);
	PLUGINS.load_char(filename);
	retu
	}

extern "C" IMPLICIT PLUGIN_LOADTHIS (char * filename,void * handle) {
	std::string tmp(filename);
	PLUGINS[tmp] = handle;
	return -!(PLUGINS[filename] == handle);
	}/* must be used from initialize() with ("",NULL)
	  * before PLUGINS__INIT to load the main symbol table.
	  */

extern "C" subroutine PLUGIN_GETSUB (char * filename,const char * symbol) {
	return PLUGINS.getsub_char(filename,symbol);
	}

extern "C" void * PLUGIN_GETVAR (char * filename,const char * symbol) {
	return PLUGINS.getvar_char(filename,symbol);
	}

extern "C" void PLUGIN__INIT (const char * pluginfilename) {
	std::fstream pluginfile;
	std::string buffer;
	pluginfile.open(pluginfilename,std::fstream::in);
	while(!(pluginfile.eof())) {
		getline(&pluginfile,&buffer);
		PLUGINS.load(buffer);
		}
	pluginfile.close();
	}

