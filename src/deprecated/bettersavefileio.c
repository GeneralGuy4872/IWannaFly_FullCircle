#define PAGE_NUMBER_MASK ~((void*) (sysconf(_SC_PAGESIZE) - 1))
#define PAGE_OFFSET_MASK ((void*) (sysconf(_SC_PAGESIZE) - 1))

typedef int (*subroutine)(size_t,void*);

typedef std::map<std::string;void*> iwf::plugins::handletable;
iwf::plugins::handletable PLUGIN_TABLE;
iwf::sharedmutex PLUGIN_TABLE_MUTEX;

extern "C" int loadpluginfile(const char * fully_quantifyed_path) {
	void * handle = dlopen(path,RTLD_NOW|RTLD_GLOBAL);
	return loadpluginthis(handle);
	}

extern "C" int loadpluginthis(void * handle) {
	PLUGIN_TABLE_MUTEX.lockw();
	const char * packagename = dlsym(handle,"IWF_PACKAGE");
	if (packagename == NULL) {
		dlclose(handle);
		errno = ELIBBAD;
		return -1;
		}
	std::string key(packagename);
	if (exists<std::string;void*>(&PLUGIN_TABLE,key) {
		dlclose(PLUGIN_TABLE[key]);
		}
	PLUGIN_TABLE[key] = handle;
	PLUGIN_TABLE_MUTEX.unlockw();
	}

extern "C" subroutine callbyname(const char * package,const char * symbol) {
	while (
	return dlsym(
	
extern "C" void * fetchbyname(const char * package,const char * symbol) {


NEWSTRUCT symname {
	const char * package;
	const char * symbol;
	}



#define touchthis(X) (X)

NEWSTRUCT iwf::savestate::pagemapdata {
	std::map<intptr_t;size_t> datums;
	std::set<off_t> ptrs;
	std::set<off_t> calls;
	}
typedef std::map<intptr_t;iwf::pagemapdata> iwf::savestate::pagemap;
typedef std::map<intptr_t;std::pair<std::string;std::string>> iwf::savestate::callmap;

NEWSTRUCT iwf::savestate::filemapdata {
	int newpageaddr;
	FILENO data;
	FILENO ptrs;
	FILENO mask;

extern "C" IMPLICIT savethis (FILENO dirfs,) {
	

	IMPLICIT iwf::savestate::pushdata (iwf::savestate::pagemap * self,void* address,size_t length) {
		this->pages[address & PAGE_NUMBER_MASK].datums[address] = length;
		return 0;
		}

	IMPLICIT iwf::savestate::pushptrs (iwf::savestate::pagemap * self,size_t argc,void * argv) {
		for (int n;n < argc;n++) {
			this->pages[address & PAGE_NUMBER_MASK].ptrs.insert(\
			(off_t) (argv[n] & PAGE_OFFSET_MASK));
			}
		return 0;
		}

	IMPLICIT pushcall (void ** location,void * link) {
		this->pages[address & PAGE_NUMBER_MASK].datums[((off_t)\
		(location & PAGE_OFFSET_MASK))] = length;
		}

	IMPLICIT savepages(FILENO dirfd;) {
		std::map<intptr_t;std::pair<FILENO;FILENO>> files
		for (iwf::savestate::pagemap::iterator i = this->pages.begin();
		  i != this->pages.end();i++) {

			if (!exists<intptr_t;std::pair<FILENO;FILENO>>(&files,i->first) {
				std::string datafilename = std::to_string(i->first);
				datafilename.append(".dat");

				std::string ptrfilename = std::to_string(i->first);
				datafilename.append("ptr.dat");

				touchthis(files[i->first]);

				files[i->first].first = openat(dirfd,\
				datafilename.c_str(),O_RDWR | O_CREAT , 0766);

				files[i->first].second = openat(dirfd,\
				datafilename.c_str(),O_RDWR | O_CREAT , 0766);
				}

			for (std::map<void*;size_t>::iterator j = i->second.first.begin();\
				  j != i->second.first.end();j++) {
				lseek(files[i->first].first,j->first,SEEK_SET);
				write(files[i->first].first,j->first,j->second);
				}

			for (std::set<off_t>::iterator j = i->second.second.begin();\
				  j != i->second.second.end();j++) {
				lseek(files[i->first].first,j->first,SEEK_SET);
				write(files[i->first].first,j->first,j->second);
				}
