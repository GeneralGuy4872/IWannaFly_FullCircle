struct cuckootree {
	struct cuckootree * up;
	struct cuckootree * left;
	struct cuckootree * right;
	struct cuckootree *prev[3];	//todo
	struct cuckootree *next[3];	//todo
	ucoord4 optimal;
	ucoord3 key;
	}

cuckootree_insertnew (struct cuckootree * root,ucoord3 key) {
	new = calloc(1,sizeof(struct cuckootree));
	new->key = key;
	new->optimal[0] = 32;
	new->optimal[1] = 32;
	new->optimal[2] = 32;
	return cuckootree_insert(root,new);
	}

cuckootree_insert (struct cuckootree * root,struct cuckootree * new) {
	if (root == NULL) {
		return new;
		}
	if (
	 memcmp(root->optimal,root->key,sizeof(ucoord3))
	  && (
	 !(memcmp(root->optimal,new->key,sizeof(ucoord3)))
	  ||
	 (norm2xyz(new->key[0] - root->optimal[0],new->key[1] - root->optimal[1],new->key[2] - root->optimal[2]) < (norm2xyz(root->key[0] - root->optimal[0],root->key[1] - root->optimal[1],root->key[2] - root->optimal[2])))
	)) {
		if (memcmp(new->optimal,root->optimal,sizeof(ucoord4))) {
			memcpy(new->optimal,root->optimal,sizeof(ucoord4));
			}
		new->up = root->up
		root->up = NULL;
		if (root->left != NULL) {
			root->left->up = new;
			new->left = root->left;
			root->left = NULL;
			}
		if (root->right != NULL) {
			root->right->up = new;
			new->right = root->right;
			root->right = NULL;
			}
		if (new->key[root->optimal[3]] < root->key[root->optimal[3]]) {
			root->optimal[root->optimal[3]] = root->optimal[root->optimal[3]] - (root->optimal[root->optimal[3]] / 2);
			root->optimal[3] = (root->optimal[3] + 1) % 3;
			if (new->left == NULL) {
				new->left = root;
				root->up = new;
				return new;
			} else {
				new->left = cuckootree_insert(new->left,root);
				}
		} else {
			root->optimal[root->optimal[3]] = root->optimal[root->optimal[3]] - (root->optimal[root->optimal[3]] / 2);
			root->optimal[3] = (root->optimal[3] + 1) % 3;
			if (new->right == NULL) {
				new->right = root;
				root->up = new;
			} else {
				new->right = cuckootree_insert(new->right,root);
				}
			}
		return new;
	} else if (new->key[root->optimal[3]] < root->key[root->optimal[3]]) {
		if (root->left == NULL) {
			root->left = new;
			new->up = root;
		} else {
			root->left = cuckootree_insert(root->left,new);
			}
	} else {
		if (root->right == NULL) {
			root->right = new;
			new->up = root;
		} else {
			root->right = cuckootree_insert(root->right,new);
			}
		}
	return root;
	}

struct cuckootree * cuckootree_find (struct cuckootree * root,ucoord3 query) {
	struct cuckootree * output = root;
	double best = norm2xyz(root->key[0] - query[0],root->key[1] - query[1],root->key[2] - query[2]);
	if (query[root->optimal[3]] < root->optimal[root->optimal[3]]) {
		if (root->left != NULL) {
			return cuckootree_findrecurse(root->left,query,output,best);
		} else {
			return output;
			}
	} else {
		if (root->right != NULL) {
			return cuckootree_findrecurse(root->right,query,output,best);
		} else {
			return output;
			}
		}
	}

struct cuckootree * cuckootree_findrecurse (struct cuckootree * root,struct cuckootree * output,ucoord3 output,double best) {
	double test = norm2xyz(root->key[0] - query[0],root->key[1] - query[1],root->key[2] - query[2]);
	if (test < best) {
		output = root;
		best = test;
		}
	if (query[root->optimal[3]] < root->optimal[root->optimal[3]]) {
		if (root->left != NULL) {
			return cuckootree_findrecurse(root->left,query,output,best);
		} else {
			return output;
			}
	} else {	
		if (root->right != NULL) {
			return cuckootree_findrecurse(root->right,query,output,best);
		} else {
			return output;
			}
		}
	}

cuckootree_delete (struct cuckootree * deadbeef) {
	struct cuckootree * up = deadbeef->up;
	struct cuckootree * left = deadbeef->left;
	struct cuckootree * right = deadbeef->right;
	ucoord4 optimal;
	memcpy(optimal,deadbeef->optimal,sizeof(ucoord4));
	free(deadbeef);
	return cuckootree_ripple(up,left,right,optimal);
	}

struct cuckootree * cuckootree_ripple (struct cuckootree * up,struct cuckootree * left,struct cuckootree * right,ucoord4 optimal) {
	if (norm2xyz(left[0] - optimal[0],left[1] - optimal[1],left[2] - optimal[2]) < (norm2xyz(right[0] - optimal[0],right[1] - optimal[1],right[2] - optimal[2]))) {
		left->up = up;
		optimal[optimal[3]] = optimal[optimal[3]] - (optimal[optimal[3]] / 2);
		optimal[3] = (optimal[3] + 1) % 3;
		left->right = cuckootree_ripple(left,left->right,right,optimal);
		return left;
	} else {
		right->up = up;
		optimal[optimal[3]] = optimal[optimal[3]] + (optimal[optimal[3]] / 2);
		optimal[3] = (optimal[3] + 1) % 3;
		right->left = cuckootree_ripple(right,left,right->left,optimal);
		return right;
		}
	}
