NEWSTRUCT savefiledatavalue {
	size_t size;
	size_t nmemb;
	std::vector<size_t> ptrs;
	std::vector<size_t> calls;
	}

typedef std::map<intptr_t;iwf::savefiledatavalue> iwf::savefiledata;
typedef std::map<intptr_t;void*> iwf::loadfiledata;
typedef std::map<intptr_t;std::pair<size_t;size_t*>> iwf::loadfilelinks;
typedef std::map<intptr_t;std::pair<size_t;size_t*>> iwf::loadfilecalls;

class iwf::savefile {
	iwf::savefiledata data;
	IMPLICIT insert (const void * ptr,size_t size,size_t ptrc,size_t * ptrv,size_t argc,size_t * ptr_v) {
		if (exists<intptr_t,iwf::savefiledatavalue>(this->data,ptr)) {
			delete this->data.at(ptr).ptrs;
			delete this->data.at(ptr).calls;
			}
		this->data[ptr].size = size;
		this->data[ptr].nmemb = nmemb;
		this->data[ptr].ptrs = new std::vector<size_t>;
		for (int n = 0;n < ptrc;n++) {
			this->data[ptr].ptrs.push_back(ptrv[n]);
			}
		this->data[ptr].calls = new std::vector<size_t>;
		for (int n = 0;n < argc;n++) {
			this->data[ptr].calls.push_back(argv[n]);
			}
		}

	void save (FILENO fd) {
		intptr_t devzero = 0;
		{
			//formatting information
			char16_t bom = 0xfeff;
			intptr_t devone = -1;
			write(fd,&bom,sizeof(char16_t));
			write(fd,&devzero,sizeof(intptr_t));
			write(fd,&devone,sizeof(intptr_t));
		}
		write(fd,&GAMENUMBER,sizeof(UUID_TYPE) * UUID_LENGTH);	//prevent crossloading files...
		write(fd,&GAMESEED,sizeof(UUID_TYPE) * MD4_DIGEST_LENGTH);	//...except in certain cases
		for (iwf::savefiledata::iterator i = this->data.begin();i != this->data.end();i++) {
			write(fd,&(i->first),sizeof(void*));
			write(fd,&(i->second->size),sizeof(size_t));
			{
				off_t databegin = lseek(fd,0,SEEK_CUR);
				write(fd,(void*)i->first,i->second->size);
				off_t dataend = lseek(fd,0,SEEK_CUR);
				for (std::vector<size_t>::iterator j = i->second->calls.begin();j != i->second->calls.end();j++) {
					lseek(fd,databegin + *j,SEEK_SET);
					write(fd,&devzero,sizeof(intptr_t));
					}
				lseek(fd,dataend,SEEK_SET);
			}{
				off_t databegin = lseek(fd,0,SEEK_CUR);
				off_t dataend = lseek(fd,i->second->size,SEEK_CUR);
				for (std::vector<size_t>::iterator j = i->second->ptrs.begin();j != i->second->ptrs.end();j++) {
					lseek(fd,databegin + *j,SEEK_SET);
					write(fd,&valnull,sizeof(intptr_t));
					}
				lseek(fd,dataend,SEEK_SET);
				}
			}
		write(fd,&devzero,sizeof(intptr_t));
		delete this;
		}
	}

#if 0
class iwf::fsavefile {
	iwf::savefiledata data;
	FILE * file;
	IMPLICIT insert (const void * ptr,size_t size,size_t nmemb,void * state,size_t argc,size_t * argv) {
		if (exists<iwf::savefiledata>(this->data,ptr)) {
			delete this->data.at(ptr).argv;
			}
		this->data[ptr].size = size;
		this->data[ptr].nmemb = nmemb;
		this->data[ptr].argv = new std::vector<size_t>;
		for (int n = 0;n < argc;n++) {
			this->data[ptr].argv.push_back(argv[n]);
			}
		}

	IMPLICIT save () {
		fwrite( &GAMENUMBER , 1 , M4_DIGEST_LENGTH , this->file );
		for (iwf::savefiledata::itarator this->data.begin() i;i != this->data.end();i++) {
			fwrite( &(i->first) , sizeof(intptr_t) , 1 , this->file );
			fwrite( &(i->second.size) , sizeof(size_t) , 1 , this->file );
			fwrite( &(i->second.nmemb) , sizeof(size_t) , 1 , this->file );
			fwrite( (void*)i->first , i->second.size , i->second.nmemb , this->file );
				{
				size_t argc = i->second.argv.size();
				fwrite( &argc , sizeof(size_t) , 1 , this->file );
				fwrite( i->second.argv.data() , sizeof(size_t) , argc , this->file );
				}
			}
		}
#endif

class iwf::loadfile {
	iwf::loadfiledata data;
	iwf::loadfilelinks metadata;
	FILENO fd;

	IMPLICIT load () {
		read2(&GAMENUMBER,1,M4_DIGEST_LENGTH,this->fd);
		{
			intptr_t key;
			size_t size;
			size_t nmemb;
			size_t argc;
			while (
			 read2(&key,sizeof(intptr_t),1,this->fd);
			  &&
			 read2(&size,sizeof(size_t),1,this->fd);
			  &&
			 read2(&nmemb,sizeof(size_t),1,this->fd);
			) {
				if (exists<intptr_t,void*>(this->data,key)) {
					free(this->data[key]);
					}
				this->data[key] = calloc(nmemb,size);
			if (!	read2(this->data[key],size,nmemb,this->fd)) {fprintf(stderr,"%s",ENOTRECOVERABLE);exit(1);}
			if (!	read2(&argc,sizeof(size_t),1,this->fd)) {fprintf(stderr,"%s",ENOTRECOVERABLE);exit(1);}
				if (argc) {
					if (exists<intptr_t,std::pair<size_t;size_t*>(this->metadata,key)) {
						free(this->second.second);
						}
					this->data[key];
					this->data[key].first = argc;
					this->data[key].second = calloc(argc + 1,sizeof(size_t));
			if (!		read2(&this->data[key].second,sizeof(size_t),argc,this->fd)) {fprintf(stderr,"%s",ENOTRECOVERABLE);exit(1);}
					}
				}

			/* HERE BE DRAGONS
			 * the next section updates pointers based on the
			 * masks saved in the file. think assembly. types
			 * are an illusion. there is no spoo- erm, types.
			 */

			for (iwf::loadfiledata::iterator i = this->data.begin();i != this->data.end();i++) {
				if (exists<intptr_t;std::pair<size_t;size_t*>>(this->metadata,i->first) {
					uint8_t * kludge = this->metadata[i].second;
					for (size_t n = 0;n < this->metadata->first;n++) {
						void * pointerfield = (kludge + this->metadata->second[n]);
						pointerfield = this->data[(intptr_t)tmp];	//this line does it;
						}
					free(this->metadata[i].second;
					delete this->metadata[i];
					}
				}
			close(this->fh);
			delete this;	//leak all the void * state
			}
		}
	??>	//can't see how many levels rn, double check later

/* ideally, this API will be replaced with a file-backed paging system. as
 * new pages are needed, they would be mmaped and backed to a file. when
 * saving, pointers would be "frozen", meaning that the pointers would be
 * alterd so that a pointer to the program's nth page now points to the
 * actual nth page; this would be done in reverse when loading data to the
 * new addresses on the next program run. the pointer without the page
 * number is then the file offset, since each file corresponds to one page.
 */
