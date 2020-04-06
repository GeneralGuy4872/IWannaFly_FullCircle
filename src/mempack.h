extern int meminvert(void * acc,size_t size);
extern int memand(void * acc,void * lval,void * rval,size_t size);
iextern int memor(void * acc,void * lval,void * rval,size_t size);
extern int memnand(void * acc,void * lval,void * rval,size_t size);
extern int memnor(void * acc,void * lval,void * rval,size_t size);
extern int memxor(void * acc,void * lval,void * rval,size_t size);
extern int memxnor(void * acc,void * lval,void * rval,size_t size);
extern int memandset(void * lval,void * rval,size_t size);
extern int memorset(void * lval,void * rval,size_t size);
extern int memnandset(void * lval,void * rval,size_t size);
extern int memnorset(void * lval,void * rval,size_t size);
extern int memxorset(void * lval,void * rval,size_t size);
extern int memxnorset(void * lval,void * rval,size_t size);
extern void memswap (void * x,void * y,size_t size);
#define memeq(X,Y,Z) !memcmp(X,Y,Z)
#define memlt(X,Y,Z) (memcmp(X,Y,Z) < 0)
#define memle(X,Y,Z) (memcmp(X,Y,Z) <= 0)
#define memgt(X,Y,Z) (memcmp(X,Y,Z) > 0)
#define memge(X,Y,Z) (memcmp(X,Y,Z) >= 0)
extern int mempack (void * opaque,uint8_t * input,int length,size_t bounds);
extern int memunpack (void * opaque,uint8_t * output,int length,size_t bounds);
extern void ptrswap (intptr_t * x,intptr_t * y);
