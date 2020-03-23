struct evdatatree {
struct evdatatree * prev;
struct evdatatree * left;
struct evdatatree * right;
uuid_t key;
void * data;
}

struct evdatatree * evdatatree__leftmost(struct evdatatree * this) {
	while (this->left != NULL) {
		this = this->left;
		}
	return this;
	}

struct evdatatree * evdatatree__rightmost(struct evdatatree * this) {
	while (this->right != NULL) {
		this = this->right;
		}
	return this;
	}

evdatatree__splay(struct evdatatree ** slot,struct evdatatree * newroot) {
	evdatatree__splayraw((*slot),newroot);
	*slot = newroot;
	return 0;
	}	

evdatatree__splayraw(struct evdatatree * oldroot,struct evdatatree * newroot) {
	if (newroot->prev == NULL) {
		return 1;
		}

	for (int n;oldroot->prev != NULL;n++) {
		oldroot = oldroot->prev;
		if (newroot->prev != oldroot) {
			evdatatree__splayraw(oldroot,newroot->prev);
			oldroot = newroot->prev;
			}
		if (n == -1) {
			errno = ERANGE;
			perror();
			exit(9001);
			}
		}

	if (oldroot->left == newroot) {
		oldroot->left = newroot->right;
		newroot->right = oldroot;
	} else if (oldroot->right == newroot) {
		oldroot->right = newroot->left;
		newroot->left = oldroot;
	} else {
		return 1;
		}
	oldroot->prev = newroot;
	newroot->prev = NULL;
	}

void * evdatatree__fetch(struct evdatatree ** slot,uuid_t q) {
	struct evdatatree * root = *slot;
	for (int cmp = uuid_compare(q,root->key);;) {
		if (cmp < 0) {
			if (root->left == NULL) {
				return NULL;
			} else {
				root = root->left;
				}
		} else if (cmp > 0) {
			if (root->right == NULL) {
				return NULL;
			} else {
				root = root->right;
				}
		} else {
			void * output = root->data;
			evdatatree__splay(slot,root);
			return output;
			}
		}
	}

evdatatree__insert(struct evdatatree ** slot,void * data) {
	struct evdatatree * new = malloc(sizeof(struct evdatatree));
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	/***/
	oops:
	struct evdatatree * root = *slot;
	uuid_generate(new->key);
	for (int cmp = uuid_compare(new->key,root->key);;) {
		if (cmp < 0) {
			if (root->left == NULL) {
				root->left = new;
				return new;
			} else {
				root = root->left;
				}
		} else if (cmp > 0) {
			if (root->right == NULL) {
				root->right = new;
				return new;
			} else {
				root = root->right;
				}
		} else {
			goto oops;
			}
		}
	}

/*implicit*/ evdatatree__delete(struct evdatatree * this,uuid_t q) {
	struct evdatatree * prev = NULL;
	int dir;
	for (int cmp = uuid_compare(q,this->key);;) {
		if (cmp < 0) {
			if (this->left == NULL) {
				return -1;
			} else {
				prev = this;
				this = this->left;
				dir = -1;
				}
		} else if (cmp > 0) {
			if (this->right == NULL) {
				return -1;
			} else {
				prev = this;
				this = this->right;
				dir = 1;
				}
		} else {
			goto last;
			}
		}
	last: switch (dir) {
		case 1 :
			prev->right = this->left;
			evdatatree__rightmost(this->left)->right = this->right;
			break;
		case -1 :
			prev->left = this->right;
			evdatatree__leftmost(this->right)->left = this->left;
			uuid_clear(this->key);
			free(this->data);
			free(this);
			break;
		default : diehard(__FILE__,__LINE__);
		}
	uuid_clear(this->key);
	free(this->data);
	free(this);
	return 0;
	}
