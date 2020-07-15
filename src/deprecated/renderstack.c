struct renderobjectconstructor {
	int opcode;
	char * texturename;
	}

struct renderobject {
	struct renderobject * prev;
	struct renderobject * next;
	int opcode;
	scalar_ref texture;
	Vector3 * location;
	}

struct renderstack {
	struct renderobject * front;
	struct renderobject * tail;
	}

struct renderstack * renderstack_push (struct renderstack * this,int opcode,struct texturetree * texture,Vector3 * location) {
	NEWALLOC(new,struct renderobject);
	if (this->front == NULL) {
		this->front = new;
		this->tail = new;
	} else {
		new->prev = this->tail;
		this->tail->next = new;
		this->tail = new;
		}
	new->opcode = opcode;
	new->texture = texture;
	new->location = location;
	return new;
	}

void renderobject_del (struct renderstack * here,struct renderobject * this) {
	if (this->prev == NULL) {
		here->front = this->next;
	} else {
		this->prev->next = this->next;
		}

	if (this->next == NULL) {
		here->tail = this->prev;
	} else {
		this->next->prev = this->prev;
		}

	texturetree_decrement(this->texture);
	free(this);
	}
	
