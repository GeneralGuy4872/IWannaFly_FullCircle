struct scalar {
	scalar * prev;
	scalar * next;
	uuid_t key;
	pthread_mutex_t lock;
	void * data;
	void (*delete)(void*);
	int refc;
	}/* note: should be replaced with a data structure with better
	  * than O(n) complexity. this is because adding a new node
	  * necissarily has a worst case of the square of the complexity
	  * of the access, in the event of a uuid collision: O(n^2). if
	  * the uuid generator is faulty, this becomes an expedeture of
	  * O(n^2 * UINT_MAX) before this is discovered
	  */

union scalar_ref {
	uuid_t eternal;
	scalar * ptr;
	}

bool scalar_ref_isloaded (scalar_ref * unknown) {
	scalar_ref tmp;
	tmp->ptr = ((signed intptr_t)-1);
	meminvert(&tmp,sizeof(scalar_ref));
	memandset(&tmp,unknown,sizeof(scalar_ref));
	return uuid_is_null(tmp->eternal);
	}
	
struct scalarcache {
	struct scalar * head;
	struct scalar * tail;
	}

initscalar (struct scalar_ref * slot,struct scalarcache * here) {
	if (!scalar_ref_isloaded(slot)) {
		uuid_t key = slot->key->eternal;
		slot->key->ptr = findscalar(key,here);
		if (slot->key->ptr == NULL) {
			slot->key->eternal = key;
			errno = ENOTRECOVERABLE;
			return -1;
		} else {
			return 0;
			}
	} else {
		errno = EINVAL;
		return 1;
		}
	}

struct scalar * tracescalar (struct scalar_ref * this,struct scalarcache * here) {
	if (!scalar_ref_isloaded(this)) {
		if (initscalar(this,here) < 0) {
			perror();
			char culprit[37];
			uuid_parse(this->eternal,culprit);
			fprintf(stderr,"data for UUID#%s not found.\nsave file data may be corrupted\n",culprit);
			exit(1);
			}
		}
	return this->ptr;
	}

struct scalar * findscalar (uuid_t key,struct scalarcache * here) {
	scalar * finger = here->head;
	while (finger != NULL) {
		int sw = uuid_compare(key,finger->key);
		if (sw < 0) {
			finger = finger->next;
		} else if (sw > 0) {
			return NULL;
		} else /*sw == 0*/ {
			return finger;
			}
		}
	return NULL
	}

struct scalar * makescalar (struct scalar_ref * slot,struct scalarcache * cache,void * data,void (*delete)(void*)) {
	struct scalar * new = malloc(sizeof(struct scalar));
	new->data = data;
	new->delete = delete;
	new->refc = 0;
	int trys = 1;
	
	if (cache->head = NULL) {
		oops:
		if (!trys) {
			fprintf(stderr,"%s,failed to generate a uuid to freeze %p in %u tries\nUUID or C Type Union implementation unsuitable for bitmask comparison introspections\nor you are just incredibly unlucky\n",strerror(EAGAIN),new,UINT_MAX);
			exit(1);
			}
		new->key = uuid_generate();
		if (scalar_ref_isloaded(new->key)) {
			char culprit[37];
			uuid_parse(new->key,culprit);
			fprintf(stderr,"%s\nUUID unsuitible\n%s reads as a pointer\n",strerror(EAGAIN),culprit);
			trys++;
			goto oops;
		new->prev = NULL;
		new->next = NULL;
		cache->head = new;
		cache->tail = new;
		}
	inconcievable:
	if (!trys) {
		fprintf(stderr,"%s,failed to generate a uuid to freeze %p in %u tries\nthis computer may be unsecure\n",strerror(EAGAIN),new,UINT_MAX);
		exit(1);
		}
	new->key = uuid_generate();
	if (scalar_ref_isloaded(new->key)) {
		char culprit[37];
		uuid_parse(new->key,culprit);
		fprintf(stderr,"%s\nUUID unsuitible\n%s reads as a pointer\n",strerror(EAGAIN),culprit);
		trys++;
		goto inconcievable;
	int sw = uuid_compare(cache->head->key,new->key);
	if (sw < 0) {
		new->next = cache->head;
		cache->head = new;
		return new;
	} else if (sw > 0) {
		struct * finger = cache->head->next;
		while (finger != NULL) {
			int sw = uuid_compare(finger->key,new->key);
			if (sw < 0) {
				finger = finger->next;
			} else if (sw > 0) {
				new->next = finger;
				new->prev = finger->prev;
				new->next->prev = new;
				new->prev->next = new;
				return new;
			} else /*sw == 0*/ {
				fprintf(stderr,"%s\nUUID collision...?\n",strerror(EAGAIN));
				trys++;
				goto inconcievable;
				}
			}
		cache->tail->next = new;
		new->prev = cache->tail;
		new->next = NULL;
		cache->tail = new;
		return new;
	} else /*sw == 0*/ {
		fprintf(stderr,"%s\nUUID collision...?",strerror(EAGAIN));
		trys++;
		goto inconcievable;
		}
	}

struct scalar * makeprimascalar (struct scalar_ref * slot,struct scalarcache * cache,void * data) {
	struct scalar * new = malloc(sizeof(struct scalar));
	new->data = data;
	new->delete = free;
	new->refc = 0;
	int trys = 1;
	if (cache->head = NULL) {
		new->key = uuid_generate();
		new->prev = NULL;
		new->next = NULL;
		cache->head = new;
		cache->tail = new;
		}
	inconcievable:
	if (!trys) {
		fprintf(stderr,"%s,failed to generate a uuid to freeze %p in %u tries\nthis computer may be unsecure\n",strerror(EAGAIN),new,UINT_MAX);
		exit(1);
		}
	new->key = uuid_generate();
	int sw = uuid_compare(cache->head->key,new->key);
	if (sw < 0) {
		new->next = cache->head;
		cache->head = new;
		return new;
	} else if (sw > 0) {
		struct * finger = cache->head->next;
		while (finger != NULL) {
			int sw = uuid_compare(finger->key,new->key);
			if (sw < 0) {
				finger = finger->next;
			} else if (sw > 0) {
				new->next = finger;
				new->prev = finger->prev;
				new->next->prev = new;
				new->prev->next = new;
				return new;
			} else /*sw == 0*/ {
				fprintf(stderr,"%s\nUUID collision...?",strerror(EAGAIN));
				trys++;
				goto inconcievable;
				}
			}
		cache->tail->next = new;
		new->prev = cache->tail;
		new->next = NULL;
		cache->tail = new;
		return new;
	} else /*sw == 0*/ {
		fprintf(stderr,"%s\nUUID collision...?",strerror(EAGAIN));
		trys++;
		goto inconcievable;
		}
	}

void decscalar (struct scalarcache * cache,struct scalar * this) {
	this->refc -= 1;
	if (this->refc < 0) {
		(*(this->delete))(this->data);
		if (this == cache->head) {
			cache->head = this->next;
		} else {
			this->prev->next = this->next;
			}
		if (this == cache->tail) {
			cache->tail = this->prev;
		} else {
			this->next->prev = this->prev;
			}
		free(this);
	}}
