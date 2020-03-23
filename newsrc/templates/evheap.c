struct voidstack {
	struct voidstack * prev;
	void * data;
	}

struct voidstack * voidstack_new (void * data) {
	struct voidstack * new = calloc(1,sizeof(struct voidstack));
	new->data = data;
	return new;
	}

struct voidstack * voidstack_pushframe (struct voidstack * stack,struct voidstack * new) {
	if (new->prev != NULL) {
		error = EINVAL;
		return -1;
		}
	new->prev = stack;
	return new;
	}

struct splaytree {
	struct splaytree * prev;
	struct splaytree * left;
	struct splaytree * right;
	struct splaytree * next[2];
	uuid_t key;
	voidstack * stack;
	}

struct cons {
	void * car;
	void * cdr;
	}

#define ZigOrZag int zag;\
if ((old->prev != NULL) || (new->prev == NULL)) {\
	errno = EINVAL;\
	return -1;\
} else if (new->prev->left == new) {\
	if (direction <= 0) {\
		if (new->prev != old) {\
			if (splaytree_zig(old,new->prev,-1)) {\
				errno = errno;\
				return -1;\
				}\
			}\
	} else {\
		zag = -1;\
		}\
} else if (new->prev->right == new) {\
	if (direction >= 0) {\
		if (new->prev != old) {\
			if (splaytree_zig(old,new->prev,1)) {\
				errno = errno;\
				return -1;\
				}\
			}\
	} else {\
		zag = 1;\
		}\
} else {\
	fprintf(stderr,"bogons with cosmic rayguns have assulted your data and rendered it irrecoverable.\nsorry about that.\n");\
	raise(SIGSEGV);\
	}\
			

splaytree_zig(struct splaytree * old,struct splaytree * new,int direction) {
	ZigOrZag
	if (prev->left = this) {
		prev->left = this->right
		this->right = prev;
		this->prev = prev->prev
		prev->prev = this

splay_zigzig :
	call zig recursively in head position until it's arguments are parent-child;
	then as each return they are also parent child;
	only do this if they are streight lines

splay_zag:
	call zig or zigzig in tail position going the other direction

split:
	find the point where a key fits and split into 2 trees
	returns them in a cons; it actually cheats by using the linked lists.
	primarily used for debug pourposes, it keeps track of which nodes are out of place and queues them to be added
		to the appropriate tree

insertnew:

insertninja: do not splay

splitinsert:
	called when inserting cannot be verified by the linked list pointers; 
