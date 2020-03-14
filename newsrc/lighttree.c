struct lighttree {
	struct lighttree * prev;
	struct lighttree * left;
	struct lighttree * right;
	int tier;
	Vector3 pos;
	Vector3 target;
	Color color;
	}

lighttree__insert (lighttree * root,Vector3 pos,Vector3 target,Color color) {
	lighttree * new = calloc(1,sizeof(struct lighttree));
	new->pos = pos;
	new->target = target;
	new->color = color;

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