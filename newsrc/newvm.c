struct fwheelnode {
	struct fwheelnode * prev;
	int caar;
	struct fwheelnode * cadr;
	struct fwheelnode * cdr;
	int n;
	}

struct fwheelptrstack {
	struct fstacknode * prev;
	struct fwheelnode * sp;
	}

struct fwheelptrstack * TOPSTACK = calloc(1,sizeof(struct fstacknode));
#define SP TOPSTACK->sp

fwheel_left_append (int opcode,int persist) {
	struct fwheelnode * this;
	if (SP == NULL) {
		SP = calloc(1,sizeof(struct fwheelnode));
		this = SP;
	} else {
		this = SP;
		while (this->cadr != NULL) {
			this = this->cadr;
			}
		this->cadr = calloc(1,sizeof(struct fwheelnode));
		this = this->cadr;
		}
	this->caar = opcode;
	this->n = persist;
	}

fwheel_left_insertafter (int opcode,int persist) {
	struct fwheelnode * this;
	if (SP == NULL) {
		SP = calloc(1,sizeof(struct fwheelnode));
		this = SP;
	} else {
		this = SP;
		while (this->cadr != NULL) {
			this = this->cadr;
			}
		this->cadr = calloc(1,sizeof(struct fwheelnode));
		this = this->cadr;
		}
	this->caar = opcode;
	this->n = persist;
	}

fwheel_insertafter (int opcode,int persist) {
	struct fwheelnode * this;
	if (SP == NULL) {
		SP = calloc(1,sizeof(struct fwheelnode));
		if (TOPSTACK->prev == NULL) {
			SP->prev = SP;
			SP->cdr = SP;
			}
		this = SP;
	} else {
		this = calloc(1,sizeof(struct fwheelnode));
		this->cdr = SP->cdr;
		SP->cdr->prev = this;
		SP->cdr = this;
		this->prev = SP;
		}
	this->cadr->caar = opcode;
	this->cadr->n = persist;
	}	

struct fwheelptrstack * pushfstack (struct fwheelnode * newval) {
	struct fwheelptrstack * new = calloc(1,sizeof(struct fwheelptrstack));
	new->sp = newval;
	new->prev = TOPSTACK;
	TOPSTACK = new;
	return new;
	}

popfstack () {
	struct fwheelptrstack * tmp = TOPSTACK->prev;
	free(TOPSTACK);
	TOPSTACK = tmp;
	return tmp
	}

topleveldispatch (int key) {
	switch (key) {
// TODO
//#include topleveldispatch.swichcase
	}}

mainloop () {
	while (SP != NULL) {
		if (SP->n) {
			topleveldispatch(SP->caar);
			if (SP->persist > 0) {
				(SP->n)--;
				}
			if (SP->cadr != NULL) {
				this = pushfstack(SP->cadr);
			} else if (SP->cdr != NULL) {
				this = SP->cdr;
			} else {
				popfstack();
				}
		} else {
			if (SP->cadr != NULL) {
				struct fwheelnode * this = SP->cadr;
				while (this->cdr != NULL) {
					this = this->cdr;
					}
				if (SP->cdr != NULL) {
					this->cdr = SP->cdr
					SP->cdr->prev = this;
					}
				if (SP->prev != NULL) {
					SP->prev->cdr = SP->cadr;
					SP->cadr->prev = SP->prev;
					}
				this = SP->cadr;
				free(SP);
				SP = this;
			} else if ((SP->cdr == NULL) && (SP->prev == NULL)) {
				popfstack();
			} else {
				if (this->cdr != NULL) {
					SP->cdr->prev = SP->prev;
					}
				if (this->prev != NULL) {
					SP->prev->cdr = SP->cdr;
					}
				struct fwheelnode * tmp = SP->cdr;
				free(SP);
				SP = SP->cdr;
				}}}
	perror();
	fprintf(stderr,"IngirumimusnocteetconsumimurignI\n");
	quit(42);
	}
