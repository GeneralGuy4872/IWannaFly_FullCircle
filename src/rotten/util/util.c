#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "util.h"

/*---INTERGALS---*/

signed __attribute__((const)) max(signed a,signed b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

signed __attribute__((const)) min(signed a,signed b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

unsigned __attribute__((const)) umax(unsigned a,unsigned b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

unsigned __attribute__((const)) umin(unsigned a,unsigned b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

unsigned __attribute__((const)) squared(signed n) {
	return n * n
	}

unsigned __attribute__((const)) usquared(unsigned n) {
	return n * n
	}

__attribute__((const)) cmp(signed a,signed b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

__attribute__((const)) ucmp(unsigned a,unsigned b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

#define sgn(X) cmp(X,0)

__attribute__((const)) ceildiv(int numer,int denom) {
	div_t internal = div(numer,denom);
	if (internal.rem) {
		internal.quot++;
		}
	return internal.rem ? internal.quot + 1 : internal.quot;
	}

/*---LONG---*/

signed long __attribute__((const)) maxl(signed long a,signed long b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

signed long __attribute__((const)) minl(signed long a,signed long b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

unsigned long __attribute__((const)) umaxl(unsigned long a,unsigned long b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

unsigned long __attribute__((const)) uminl(unsigned long a,unsigned long b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

unsigned long __attribute__((const)) squaredl(signed long n) {
	return n * n
	}

unsigned long __attribute__((const)) usquaredl(unsigned long n) {
	return n * n
	}

__attribute__((const)) cmpl(signed long a,signed long b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

__attribute__((const)) ucmpl(unsigned long a,unsigned long b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

#define sgnl(X) cmpl(X,0)

/*---LONG LONG---*/

signed long long __attribute__((const)) maxll(signed long long a,signed long long b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

signed long long __attribute__((const)) minll(signed long long a,signed long long b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

unsigned long long __attribute__((const)) umaxll(unsigned long long a,unsigned long long b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

unsigned long long __attribute__((const)) uminll(unsigned long long a,unsigned long long b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

unsigned long long __attribute__((const)) squaredll(signed long long n) {
	return n * n
	}

unsigned long long __attribute__((const)) usquaredll(unsigned long long n) {
	return n * n
	}

__attribute__((const)) cmpll(signed long long a,signed long long b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

__attribute__((const)) ucmpll(unsigned long long a,unsigned long long b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

#define sgnll(X) cmpll(X,0)

/*---FLOATS---*/

float __attribute__((const)) maxf(float a,float b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

float __attribute__((const)) minf(float a,float b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

float __attribute__((const)) squaredf (float n) {
	return n * n
	}

__attribute__((const)) cmpf(float a,float b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

#define sgnf(X) cmpf(X,0)

/*---DOUBLES---*/

double __attribute__((const)) maxfd(double a,double b) {
	if (a >= b) {
		return a;
		}
	else {
		return b;
		}

double __attribute__((const)) minfd(double a,double b) {
	if (a <= b) {
		return a;
		}
	else {
		return b;
		}

double __attribute__((const)) squaredfd(double n) {
	return n * n
	}

__attribute__((const)) cmpf(float a,float b) {
	if (a == b) {
		return 0;
		}
	else if (a > b) {
		return 1;
		}
	else if (a < b) {
		return -1;
		}
	else {
		return INT_MIN;
		}
	}

#define sgnfd(X) cmpfd(X,0)

double __attribute__((const)) norm2xy(double x,double y) {
	return sqrt(fdsquared(x)+fdsquared(y));
	}

double __attribute__((const)) norm2xyz(double x,double y,double z) {
	return sqrt(fdsquared(x)+fdsquared(y)+fdsquared(z));
	}

double __attribute__((const)) norm2xyzw(double x,double y,double z,double w) {
	return sqrt(fdsquared(x)+fdsquared(y)+fdsquared(z)+fdsquared(z));
	}

/*---STDIN---*/

eatline() {
	return scanf("%*[^\n]%*c");
	}

eatall(FILE * input) {
	while (fgetc(input) != EOF);
	return 0;
	}
