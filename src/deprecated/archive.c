#define fhtell(X) lseek(X,0,SEEK_CUR)

typedef void (*writefptr)(struct writestackcontainer * tape,void * data,off_t offprev);
//note: arrays of structs should be stored as if they were arrays of pointers to structs

struct writestackcontainer {
struct writestack * head;
struct writestack * tail;
int n;
_FH_ file;
}

struct writestack {
struct writestack * prev;
struct writestack * next;
writefptr action;
void * data;
off_t offprev;
}

struct writestack * writestack_push(struct writestackcontainer * tape,writefptr action,void * data,off_t offprev) {
	struct writestack * new = malloc(sizeof(struct writestack));
	new->action = action;
	new->data = data;
	new->offprev = offprev;
	if (tape->n) {	
		tape->tail->next = new;
		new->prev = tail;
		tape->tail = new
	} else {
		tape->head = new;
		tape->tail = new;
		}	
	tape->n++;
	return new;
	}

writestack_exec(struct writestackcontainer * this) {
	if (this->head == NULL) {
		return -1
		}
	struct writestack * exec = this->head;
	this->head = this->head->next;
	exec->action(this,exec->data,exec->offprev);
	free(exec);
	if (this->n > 1) {
		this->head->prev = NULL;
	} else {
		this->head = NULL;
		this->tail = NULL;
		}
	this->n--;
	return 0;
	}

void stringlistyp_write(struct writestackcontainer * tape,struct stringlistyp * this,off_t offprev) {
assert(sizeof(off_t) == sizeof(void*));
for (;this != NULL;this = this->next) {
	off_t here = ltell(file);
	struct stringlistyp * tmp = calloc(1,sizeof(struct stringlistyp));
	write(file,tmp,sizeof(struct stringlistyp));
	free(tmp);
	off_t here2 = fhtell(file);
	dprintf(file,"%s\0",this->text);
	if (offprev != NULL) {
		pwrite(file,&here,sizeof(off_t),offprev + offsetof(struct stringlistyp,next));
		}
	pwrite(file,&here2,sizeof(off_t),here + offsetof(struct stringlistyp,text));
	return lseek(file,0,SEEK_END);
	}}

saveroom(roomtyp * this) {
	struct writestackcontainer * tape;
	char filename[15];
	sprintf(filename,"%02X%02X-%02X%02X.room",this->globpos[0],this->globpos[1],this->globpos[2],this->globpos[3]);
	tape->file = openat(TMPDIRFH,filename,O_WRONLY | O_CREAT | O_TRUNC,0700);
	off_t index = lseek(tape->file,sizeof(int),SEEK_SET);
	if (index == -1) {perror();abort();}
	struct roomtyp * tmp = calloc(1,sizeof(struct roomtyp));
	memcpy(tmp,this,sizeof(struct roomtyp));
	tmp->chunks = NULL;
	tmp->encon_ptr = NULL;
	tmp->ent_ptr = NULL;
	tmp->ev_ptr = NULL;
	tmp->obj_ptr = NULL;
	tmp->ray_ptr = NULL;
	tmp->light_ptr = NULL;
	tmp->path_ptr = NULL;
	
	write(tape->file,&tmp,sizeof(struct roomtyp));
	free(tmp);

	{
		int m = (this->size.w + this->size.x + 1) * (this->size.w + this->size.y + 1) * (this->size.w + this->size.z + 1);
		off_t tmpindex = fdtell(tape->file);
		lseek(tape->file,sizeof(off_t) * m,SEEK_CUR);
		for (int n = 0;n < m;n++) {
			writestack_push(tape,&chunktyp_write,this->chunks[n],tmpindex + (n * sizeof(off_t))
			}
		}
	writestack_push(tape,&encontyp_write,this->encon_ptr,index + offsetof(struct roomtyp,encon_ptr));
	writestack_push(tape,&enttyp_write,this->ent_ptr,index + offsetof(struct roomtyp,ent_ptr));
	writestack_push(tape,&eventtyp_write,this->ev_ptr,index + offsetof(struct roomtyp,ev_ptr));
	writestack_push(tape,&mapobjtyp_write,this->obj_ptr,index + offsetof(struct roomtyp,obj_ptr));
	writestack_push(tape,&ray_vfx_typ_write,this->ray_ptr,index + offsetof(struct roomtyp,ray_ptr));
	writestack_push(tape,&lightyp_write,this->light_ptr,index + offsetof(struct roomtyp,light_ptr));
	writestack_push(tape,&setcoord3_write,this->path_ptr,index + offsetof(struct roomtyp,path_ptr));

	while (head != NULL) {
		head = writestack_exec(head);	//boingboing
		}
	return close(file);
	}
