struct funwheel {
	int fun;
	int n;
	int argc;
	scalar *(*argv)[];
	struct funwheel * down;
	struct funwheel * next;
	}

struct funstack {
	struct funstack * prev;
	struct funwheel * index;
	}

struct funwheel * funwheel_new_args (int fun,int n,struct funwheel * down,int argc,struct scalar * argv,struct funwheel * next) {
	struct funwheel new = calloc(1,sizeof(struct funwheel));
	new->fun = fun;
	new->n = n;
	new->argc = argc;
	new->argv = calloc(argc,sizeof(struct scalar));
	for (int n;n < argc;n++) {
		memcpy(new->argv[n],argv[n],sizeof(struct scalar));
		}
	new->down = down;
	new->next = next;
	return new;
	}

struct funwheel * funwheel_new (int fun,int n,struct funwheel * down,struct funwheel * next) {
	struct funwheel * new = calloc(1,sizeof(struct funwheel));
	new->fun = fun;
	new->n = n;
	new->down = down;
	new->next = next;
	return new;
	}

struct funwheel * funwheel_queue (struct funwheel * this,struct funwheel * new) {
	new->next = this->down;
	this->down = new;
	return new;
	}
	
struct funwheel * funwheel_push (struct funwheel * this,struct funwheel * new) {
	new->next = this->next;
	this->next = new;
	return new;
	}

struct funwheel * funstack_shunt (struct funstack * this) {
	struct funwheel * left;
	struct funwheel * right;
	while (this->index->down != NULL) {
		left = this->index->down;
		right = this->index->next;
		this->index->down = left->next;
		left->next = right;
		this->index->next = left;
		}
	if (!(this->index->n)) {
		struct funwheel * tmp = this->index->next;
		if (this->index->argc) {
			for (int n = 0;n < argc;n++) {
				if ( ((*(this->index->argv))[n])->ref < 0) {
					decscalar((*argv)[n]);
					(*argv)[n] = NULL;
					}
				}
			free(argv);
			}
		free(this->index);
		this->prev->next = tmp;
		this->index = tmp;
	} else if (this->index->n > 0) {
		this->index->n -= 1;
		}
	if (this->index->next == NULL) {
		fprintf(stderr,"Flywheel on the loose! *boulder chase music* TOPLEVELSTACK->index->next\n");
		exit(127 + SIGSEGV);
		}
	this->index = this->index->next;
	return this->index;
	}
