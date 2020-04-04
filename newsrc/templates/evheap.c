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
	if (new->parent != NULL) {
		error = EINVAL;
		return -1;
		}
	new->parent = stack;
	return new;
	}

struct splaytree {
	struct splaytree * parent;
	struct splaytree * left;
	struct splaytree * right;
	struct splaytree * prev;
	struct splaytree * next
	uuid_t key;
	voidstack * stack;
	}

struct cons {
	void * caar;
	struct cons * cadr;
	struct cons * cdr;
	}

splaytree_splay(struct splaytree * old,struct splaytree * new,int direction) {
	int zag;
	if ((old->parent != NULL) || (new->parent == NULL)) {
		errno = EINVAL;
		if (abs(EINVAL) <= 1) {
			return -127;
		} else {
			return EINVAL;
			}
		}
	} else if (new->parent->left == new) {
		if (direction <= 0) {
			oldroot->left = newroot->right;
			newroot->right = oldroot;
			if (new->parent != old) {
				zag = splaytree_zig(old,new->parent,-1);
				if (abs(zag) > 1) {
					errno = tmp;
					return tmp;
					}
				}
		} else {
			zag = -1;
			}
	} else if (new->parent->right == new) {
		if (direction >= 0) {
			oldroot->right = newroot->left;
			newroot->left = oldroot;
			if (new->parent != old) {
				zag = splaytree_zig(old,new->parent,1)
				if (abs(zag) > 1) {
					errno = zag;
					return zag;
					}
				}
		} else {
			zag = 1;
			}
	} else {
		fprintf(stderr,"bogons with cosmic rayguns have assulted your data and rendered it irrecoverable.\nsorry about that.\n");\
		raise(SIGSEGV);
		}
	newroot->parent = oldroot->parent;
	oldroot->parent = newroot;
	return zag;
	}

struct splaytree * splaytree_splay_entry (struct splaytree * old,struct splaytree * new) {
	int zag = 0;
	do {	zag = splaytree_splay(old,new,zag);
		if (abs(zag) > 1) {
			return NULL;
			}
		}while (abs(zag) == 1);
	return new;
	}

split:
	find the point where a key fits and split into 2 trees
	returns them in a cons; it actually cheats by using the linked lists.
	primarily used for debug pourposes, it keeps track of which nodes are out of place and queues them to be added
		to the appropriate tree

struct splaytree * splaytree_new (uuid_t * key,void * value) {
	NEWALLOC(new,struct_splaytree);
	new->key = key;
	new->value = voidstack_new(value);
	return new;

struct splaytree * splaytree_insert_ninja (struct splaytree * root,uuid_t key,void * value) {
	recursion:
	switch (uuid_compare(root->key,key)) {
		case -1 : if (root->left != NULL) {
				root = root->left;
				goto recursion;
			} else {
				root->left = splaytree_new(key,value);
				struct splaytree * this = root->left;
				this->parent = root;
				this->prev = root->prev;
				this->prev->next = this;
				this->next = root;
				root->prev = this;
				return this;
				}
			
		case 0 : voidstack_pushframe(root->stack,value); return root;
		case 1 : if (root->right != NULL) {
				root = root->right;
				goto recursion;
			} else {
				root->right = splaytree_new(key,value);
				struct splaytree * this = root->right;
				this->parent = root;
				this->next = root->next;
				this->next->prev = this;
				this->prev = root;
				root->next = this;
				return this;
				}
		}
	}
	
struct splaytree * splaytree_insert (struct splaytree * root,uuid_t key,void * value) {
	struct splaytree * tmp = splaytree_insert_ninja(root,key,value);
	splaytree_splay_entry(root,tmp);
	return tmp;

splitinsert:
	called when inserting cannot be verified by the linked list pointers; 
