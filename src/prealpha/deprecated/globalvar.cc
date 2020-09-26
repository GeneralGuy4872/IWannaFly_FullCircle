NEWSTRUCT globalvar {
	size_t num;
	size_t size;
	void * ptr;
	}

#ifdef __cplusplus

class iwf::globaltmp {
	std::map<std::string;std::stack<globalvar>> data;
	void * alloc (std::string name,size_t num,size_t size) {
		void * tmp = calloc(num,size);
		this->data[name].push({num,size,tmp});
		return tmp;
		}
	void * alloc (char * cname,size_t num,size_t size) {
		std::string name(cname);
		return this->alloc(name,width,length);
		}
	void dealloc (std::string name) {
		if (this->data.contains(name)) {
			if (!(this->data[name].empty())) {
				free(this->data[name].back().ptr);
				this->data[name].pop_back();
				}
			if (this->data[name].empty()) {
				this->data.erase(name));
				}
		}}
	void dealloc (char * cname) {
		std::string name;
		this->dealloc(name);
		}
	}

extern "C" {
#endif

	void * iwf$$globaltmp$$alloc (void * adhoc,char * name,size_t num,size_t size) {
		iwf::globaltmp * objcast = adhoc;
		return objcast->alloc(name,num,size);
		}

	void * iwf$$globaltmp$$alloc (void * adhoc,char * name) {
		iwf::globaltmp * objcast = adhoc;
		return objcast->dealloc(name);
		}

#ifdef __cplusplus
	}
#endif
