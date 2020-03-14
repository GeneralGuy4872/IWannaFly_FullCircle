struct ev_data_bst {
struct ev_data_bst * left;
struct ev_data_bst * right;
uuid_t key;
void * data;
}

struct ev_data_bst * ev_data_bst__leftmost(struct ev_data_bst * this) {
	while (this->left != NULL) {
		this = this->left;
		}
	return this;
	}

struct ev_data_bst * ev_data_bst__rightmost(struct ev_data_bst * this) {
	while (this->right != NULL) {
		this = this->right;
		}
	return this;
	}

void * ev_data_bst__fetch(struct ev_data_bst * root,uuid_t q) {
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
			return root->data;
			}
		}
	}

uuid_t ev_data_bst__insert(struct ev_data_bst * uroot,void * data) {
	struct ev_data_bst * new = malloc(sizeof(struct ev_data_bst));
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	/***/
	oops:
	struct ev_data_bst * root = uroot;
	uuid_generate(new->key);
	for (int cmp = uuid_compare(new->key,root->key);;) {
		if (cmp < 0) {
			if (root->left == NULL) {
				root->left = new;
				return new->key;
			} else {
				root = root->left;
				}
		} else if (cmp > 0) {
			if (root->right == NULL) {
				root->right = new;
				return new->key;
			} else {
				root = root->right;
				}
		} else {
			goto oops;
			}
		}
	}

/*implicit*/ ev_data_bst__delete(struct ev_data_bst * this,uuid_t q) {
	struct ev_data_bst * prev = NULL;
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
			ev_data_bst__rightmost(this->left)->right = this->right;
			break;
		case -1 :
			prev->left = this->right;
			ev_data_bst__leftmost(this->right)->left = this->left;
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
