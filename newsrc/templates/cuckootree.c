struct cuckootree {
	struct cuckootree * prev;
	struct cuckootree * less;
	struct cuckootree * more;
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
		new->prev = root->prev
		root->prev = NULL;
		if (root->less != NULL) {
			root->less->prev = new;
			new->less = root->less;
			root->less = NULL;
			}
		if (root->more != NULL) {
			root->more->prev = new;
			new->more = root->more;
			root->more = NULL;
			}
		if (new->key[root->optimal[3]] < root->key[root->optimal[3]]) {
			root->optimal[root->optimal[3]] = root->optimal[root->optimal[3]] - (root->optimal[root->optimal[3]] / 2);
			root->optimal[3] = (root->optimal[3] + 1) % 3;
			if (new->less == NULL) {
				new->less = root;
				root->prev = new;
				return new;
			} else {
				new->less = cuckootree_insert(new->less,root);
				}
		} else {
			root->optimal[root->optimal[3]] = root->optimal[root->optimal[3]] - (root->optimal[root->optimal[3]] / 2);
			root->optimal[3] = (root->optimal[3] + 1) % 3;
			if (new->more == NULL) {
				new->more = root;
				root->prev = new;
			} else {
				new->more = cuckootree_insert(new->more,root);
				}
			}
		return new;
	} else if (new->key[root->optimal[3]] < root->key[root->optimal[3]]) {
		if (root->less == NULL) {
			root->less = new;
			new->prev = root;
		} else {
			root->less = cuckootree_insert(root->less,new);
			}
	} else {
		if (root->more == NULL) {
			root->more = new;
			new->prev = root;
		} else {
			root->more = cuckootree_insert(root->more,new);
			}
		}
	return root;
	}

struct cuckootree * cuckootree_find (struct cuckootree * root,ucoord3 query) {
	struct cuckootree * output = root;
	double best = norm2xyz(root->key[0] - query[0],root->key[1] - query[1],root->key[2] - query[2]);
	if (query[root->optimal[3]] < root->optimal[root->optimal[3]]) {
		if (root->less != NULL) {
			return cuckootree_findrecurse(root->less,query,output,best);
		} else {
			return output;
			}
	} else {
		if (root->more != NULL) {
			return cuckootree_findrecurse(root->more,query,output,best);
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
		if (root->less != NULL) {
			return cuckootree_findrecurse(root->less,query,output,best);
		} else {
			return output;
			}
	} else {	
		if (root->more != NULL) {
			return cuckootree_findrecurse(root->more,query,output,best);
		} else {
			return output;
			}
		}
	}

cuckootree_delete (struct cuckootree * deadbeef) {
	struct cuckootree * prev = deadbeef->prev;
	struct cuckootree * less = deadbeef->less;
	struct cuckootree * more = deadbeef->more;
	ucoord4 optimal;
	memcpy(optimal,deadbeef->optimal,sizeof(ucoord4));
	free(deadbeef);
	return cuckootree_ripple(prev,less,more,optimal);
	}

struct cuckootree * cuckootree_ripple (struct cuckootree * prev,struct cuckootree * less,struct cuckootree * more,ucoord4 optimal) {
	if (norm2xyz(less[0] - optimal[0],less[1] - optimal[1],less[2] - optimal[2]) < (norm2xyz(more[0] - optimal[0],more[1] - optimal[1],more[2] - optimal[2]))) {
		less->prev = prev;
		optimal[optimal[3]] = optimal[optimal[3]] - (optimal[optimal[3]] / 2);
		optimal[3] = (optimal[3] + 1) % 3;
		less->more = cuckootree_ripple(less,less->more,more,optimal);
		return less;
	} else {
		more->prev = prev;
		optimal[optimal[3]] = optimal[optimal[3]] + (optimal[optimal[3]] / 2);
		optimal[3] = (optimal[3] + 1) % 3;
		more->less = cuckootree_ripple(more,less,more->less,optimal);
		return more;
		}
	}
