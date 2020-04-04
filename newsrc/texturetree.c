struct texturetree {
	struct texturetree * parent;
	struct texturetree * left;
	struct texturetree * right;
	struct texturetree * prev;
	struct texturetree * next
	char * key;
	Texture2D data;
	int ref;
	}

int texturetree_splay(struct splaytree * old,struct texturetree * new,int direction) {
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
				zag = texturetree_splay(old,new->parent,-1);
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
				zag = texturetree_splay(old,new->parent,1)
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

struct texturetree * texturetree_splay_entry (struct texturetree * old,struct texturetree * new) {
	int zag = 0;
	do {	zag = texturetree_splay(old,new,zag);
		if (abs(zag) > 1) {
			return NULL;
			}
		}while (abs(zag) == 1);
	return new;
	}

struct splaytree * splaytree_new (char * key) {
	NEWALLOC(new,struct_splaytree);
	new->key = key;
	new->value = LoadTexture(key);
	new->ref = 1;
	return new;
	}

struct splaytree * splaytree_query (struct splaytree * root,char * key) {
	if (root == NULL) {
		return NULL;
		}
	recursion:
	switch (strcmp(root->key,key)) {
		case -1 : if (root->left != NULL) {
				root = root->left;
				goto recursion;
			} else {
				return NULL;
				}
		case 0 : return root;
		case 1 : if (root->right != NULL) {
				root = root->right;
				goto recursion;
			} else {
				return NULL;
				}
		}
	}

struct splaytree * texturetree_fetch (struct texturetree * root,char * key) {
	if (root == NULL) {
		return NULL;
		}
	struct texturetree * this = texturetree_query(root,key);
	if (this == NULL) {
		return NULL;
		}
	texturetree_splay_entry(root,this);
	return this;
	}

struct splaytree * texturetree_increment (struct texturetree * root,char * key) {
	if (root == NULL) {
		return NULL;
		}
	struct texturetree * this = texturetree_query(root,key);
	if (this == NULL) {
		return texturetree_insert(root,key);
		}
	this->ref += 1;
	texturetree_splay_entry(root,this);
	return this;
	}

struct texturetree * texturetree_insert_ninja (struct texturetree * root,char * key) {
	if (root == NULL) {
		return texturetree_new(key);
		}
	recursion:
	switch (strcmp(root->key,key)) {
		case -1 : if (root->left != NULL) {
				root = root->left;
				goto recursion;
			} else {
				root->left = texturetree_new(key);
				struct texturetree * this = root->left;
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
				root->right = texturetree_new(key);
				struct texturetree * this = root->right;
				this->parent = root;
				this->next = root->next;
				this->next->prev = this;
				this->prev = root;
				root->next = this;
				return this;
				}
		}
	}

struct texturetree * texturetree_decrement (struct texturetree * this) {
	if (this == NULL) {
		return NULL;
		}
	this->ref -= 1;
	if (this->refcount < 0) {
		texturetree_delete(this);
		}
	}


struct texturetree * texturetree_delete (struct texturetree * this) {
	if (this == NULL) {
		return NULL;
		}
	UnloadTexture(this->data);
	if (this->prev != NULL) {
		this->prev->next = this->next;
		}
	if (this->next != NULL) {
		this->next->prev = this->prev;
		}
	if (this->parent != NULL) {
		struct texturetree * root = this->parent;
		if (root->left == this) {
			root->left = texturetree_ripple(this->left,this->right);
			free(this);
			root->left->parent = root;
			return root->left;
		} else if (root->right == this) {
			root->right = texturetree_ripple(this->left,this->right);
			free(this);
			root->right->parent = root;
			return root->right;
		} else {
			errno = ENOTRECOVERABLE;
			perror();
			abort();
			}
	} else {
		free(this);
		struct texturetree * output = texturetree_ripple (this->left,this->right);
		output->parent = NULL;
		return output;
		}
	}

struct texturetree * texturetree_ripple (struct texturetree * lesser,struct texturetree * greater) {
	if ((lesser == NULL) && (greater == NULL)) {
		return NULL;
	} else if (lesser == NULL) {
		return greater;
	} else if (greater == NULL) {
		return lesser;
		}
	if (lesser->right == NULL) {
		lesser->right = greater;
		greater->parent = lesser;
		return lesser;
	} else if (greater->left == NULL) {
		greater->left = lesser;
		lesser->parent = greater;
		return greater;
	} else {
		struct texturetree * tmp = greater->left;
		greater->left = lesser;
		lesser->parent = lesser;
		tmp->parent = tmp->prev;
		tmp->prev->right = tmp;	//if this breaks the tree, it was already broken
		return greater;
		}
	}

struct texturetree * texturetree_insert (struct texturetree * root,char * key) {
	if (root == NULL) {
		return texturetree_new(key);
		}
	struct texturetree * tmp = texturetree_insert_ninja(root,key,value);
	texturetree_splay_entry(root,tmp);
	return tmp;
	}
