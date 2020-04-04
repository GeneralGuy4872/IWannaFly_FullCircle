#ifndef UTIL_H_REENTERANT
#define UTIL_H_REENTERANT

#include <stdint.h>

#define ≥ >=
#define ≤ <=

#define skip() {}
#define tosignbit(X) (X < 0 ? 1 : 0)
#define signbit(X) (X ? -1 : 1)

extern signed max(signed a,signed b);
extern signed min(signed a,signed b);
extern unsigned umax(unsigned a,unsigned b);
extern unsigned umin(unsigned a,unsigned b);
extern unsigned int squared(signed n);
extern unsigned int usquared(unsigned n);
extern int cmp(signed a,signed b);
extern int ucmp(unsigned a,unsigned b);
#define sgn(X) cmp(X,0)
extern int ceildiv(int numer,int denom);

extern signed long maxl(signed long a,signed long b);
extern signed long minl(signed long a,signed long b);
extern unsigned long umaxl(unsigned long a,unsigned long b);
extern unsigned long uminl(unsigned long a,unsigned long b);
extern unsigned long squaredl(signed long n);
extern unsigned long usquaredl(unsigned long n);
extern int cmpl(signed long a,signed long b);
extern int ucmpl(unsigned long a,unsigned long b);
#define sgnl(X) cmpl(X,0)

extern signed long long maxll(signed long long a,signed long long b);
extern signed long minll(signed long long a,signed long long b);
extern unsigned long long umaxll(unsigned long long a,unsigned long long b);
extern unsigned long long uminll(unsigned long long a,unsigned long long b);
extern unsigned long long squaredll(signed long long n);
extern unsigned long long usquaredll(unsigned long long n);
extern int cmpll(signed long long a,signed long long b);
extern int ucmpll(unsigned long long a,unsigned long long b);
#define sgnll(X) cmpll(X,0)

extern float maxf(float a,float b);
extern float minf(float a,float b);
extern float squaredf(float n);
extern int cmpf(float a,float b);
#define sgnf(X) cmpf(X,0)

extern double maxfd(double a,double b);
extern double minfd(double a,double b);
extern double squaredfd(double n);
extern int cmpfd(double a,double b);
#define sgnfd(X) cmpfd(X,0)

extern double norm2xy(double x,double y);
extern double norm2xyz(double x,double y,double z);
extern double norm2xyzw(double x,double y,double z,double w);

extern void swap(intptr_t * x,intptr_t * y);

extern int meminvert(void * acc,size_t size);
extern int memand(void * acc,void * lval,void * rval,size_t size);
extern int memor(void * acc,void * lval,void * rval,size_t size);
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
#define memeq(X,Y,Z) !memcmp(X,Y,Z)
#define memlt(X,Y,Z) (memcmp(X,Y,Z) < 0)
#define memle(X,Y,Z) (memcmp(X,Y,Z) <= 0)
#define memgt(X,Y,Z) (memcmp(X,Y,Z) > 0)
#define memge(X,Y,Z) (memcmp(X,Y,Z) >= 0)

extern int coin_flip();
extern unsigned roll(unsigned number,unsigned sides,bool off);
extern int roll_bonus(unsigned number)
#endif
