#ifdef __cplusplus
#error this is very much not a C++ file
#endif

#include "structops.h"

void meminvert (void * acc,size_t size) {
	uint8_t * q = acc;
	for (int n = 0;n < size;n++) {
		q[n] = ~(q[n]);
		}
	}

void memandset (void * lval,void * rval,size_t size) {
	uint8_t * x = lval;
	uint8_t * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] &= y[n];
		}
	}

void memorset (void * lval,void * rval,size_t size) {
	uint8_t * x = lval;
	uint8_t * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] |= y[n];
		}
	}

void memnandset (void * lval,void * rval,size_t size) {
	uint8_t * x = lval;
	uint8_t * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] = ~(x[n] & y[n]);
		}
	}

void memnorset (void * lval,void * rval,size_t size) {
	uint8_t * x = lval;
	uint8_t * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] = ~(x[n] | y[n]);
		}
	}

void memxorset (void * lval,void * rval,size_t size) {
	uint8_t * x = lval;
	uint8_t * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] ^= y[n];
		}
	}

void memxnorset (void * lval,void * rval,size_t size) {
	uint8_t * x = lval;
	uint8_t * y = rval;
	for (int n = 0;n < size;n++) {
		x[n] = ~(x[n] ^ y[n]);
		}
	}

#define memeq(X,Y,Z) !memcmp(X,Y,Z)
#define memlt(X,Y,Z) (memcmp(X,Y,Z) < 0)
#define memle(X,Y,Z) (memcmp(X,Y,Z) <= 0)
#define memgt(X,Y,Z) (memcmp(X,Y,Z) > 0)
#define memge(X,Y,Z) (memcmp(X,Y,Z) >= 0)

void memswap(void * x,void * y,size_t size) {
	uint8_t * xx = x;
	uint8_t * yy = y;
	uint8_t tmp;
	for (int n,n < size_t,n++) {
		tmp = 0;
		tmp = xx[n];
		xx[n] = yy[n];
		yy[n] = tmp;
		}
	return 0;
	}

void ptrswap(intptr_t * x,intptr_t * y) {
	intptr_t tmp = *x;
	*x = *y;
	*y = tmp;
	}
