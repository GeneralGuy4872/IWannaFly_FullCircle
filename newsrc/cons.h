struct tree {
void * l;
void * r;
}

struct tree * cons (void * l,void * r);

#define car(X) ((struct tree *)X)->l;
#define cdr(X) ((struct tree *)X)->r;