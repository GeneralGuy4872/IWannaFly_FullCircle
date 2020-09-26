//OLD; REDO
struct lighttree {
	struct lighttree * prev;
	struct lighttree * left;
	struct lighttree * right;
	int tier;
	Vector3 pos;
	Vector3 target;
	Color color;
	}

lighttree__new (lighttree * root,Vector3 pos,Vector3 target,Color color) {
	lighttree * new = calloc(1,sizeof(struct lighttree));
	new->pos = pos;
	new->target = target;
	new->color = color;
	lighttree__insert(root,new);
	}

lighttree__insert (lighttree * root,lighttree * new) {
	new->left = NULL;
	new->right = NULL;
	for (;;) {
		switch (root->tier) {
			case 0 : if (root->pos.x > pos.x) {
					if (root->left == NULL) {
						new->prev = root;
						root->left = new;
						new->tier = (root->tier + 1) % 3;
						return new;
					} else {
						root = root->left
						}
				} else {
					if (root->right == NULL) {
						new->prev = root;
						root->right = new;
						new->tier = (root->tier + 1) % 3;
						return new;
					} else {
						root = root->right
						}
				}; break;
			case 1 : if (root->pos.y > pos.y) {
					if (root->left == NULL) {
						new->prev = root;
						root->left = new;
						new->tier = (root->tier + 1) % 3;
						return new;
					} else {
						root = root->left
						}
				} else {
					if (root->right == NULL) {
						new->prev = root;
						root->right = new;
						new->tier = (root->tier + 1) % 3;
						return new;
					} else {
						root = root->right
						}
				}; break;
			case 2 : if (root->pos.z > pos.z) {
					if (root->left == NULL) {
						new->prev = root;
						root->left = new;
						new->tier = (root->tier + 1) % 3;
						return new;
					} else {
						root = root->left
						}
				} else {
					if (root->right == NULL) {
						new->prev = root;
						root->right = new;
						new->tier = (root->tier + 1) % 3;
						return new;
					} else {
						root = root->right
						}
				}; break;
			default : diehard();
			}
		}
	}

lighttree * lighttree__iterate (lighttree * this) {
	if (this->left != NULL) {
		return this->left;
		}
	else if (this->right != NULL) {
		return this->right;
		}
	else while (this->prev != NULL) {
		this = this->prev;
		if (this->right != NULL) {
			return this->right;
			}
		}
	return NULL;
	}

lighttree * lighttree__delete (lighttree * root,lighttree * deadbeef) {
	if (root == deadbeef) {
		root = lighttree__makeroot(deadbeef->left);
	} else {
		lighttree__rebuild(root,deadbeef->left);
		}
	lighttree__rebuild(root,deadbeef->right);
	free(deadbeef);
	}

lighttree * lighttree__makeroot (lighttree * this) {
	lighttree * left = this->left;
	lighttree * right = this->right;
	this->prev = NULL;
	this->tier = 0;
	if (left != NULL) {
		lighttree__rebuild(this,left);
		}
	if (right != NULL) {
		lighttree__rebuild(this,right);
		}
	return this;
	}

lighttree__rebuild (lighttree * root,lighttree * this) {
	lighttree * left = this->left;
	lighttree * right = this->right;
	lighttree__insert(root,this);
	if (left != NULL) {
		lighttree__rebuild(root,left);
		}
	if (right != NULL) {
		lighttree__rebuild(root,right);
		}
	}

lighttree * lighttree__query(lighttree * root,Vector3 q) {
	lighttree * output;
	double best = INFINITY;
	for (;;) {
		for (lighttree * next = root;;next = lighttree__iterate(next)) {
			
			
			}
		}
			
	
