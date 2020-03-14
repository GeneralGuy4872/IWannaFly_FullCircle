struct tree {
void * l;
void * r;
}

struct tree * cons (void * l,void * r) {
	static struct tree * output;
	output->l = l;
	output->r = r;
	return output;
	}