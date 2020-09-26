#ifndef __GG4872_UTIL_H__
#define __GG4872_UTIL_H__

#ifndef __cplusplus
#include <stdlib.h>
#include <stdio.h>
#else
#include <cstdio>
#endif
#include "util.def"
#ifdef __cplusplus
extern "C" {
#endif

extern signed max(signed a,signed b);
extern signed min(signed a,signed b);
extern unsigned umax(unsigned a,unsigned b);
extern unsigned umin(unsigned a,unsigned b);
extern unsigned int squared(signed n);
extern unsigned int usquared(unsigned n);
extern int cmp(signed a,signed b);
extern int ucmp(unsigned a,unsigned b);
extern int ceildiv(int numer,int denom);

extern signed long maxl(signed long a,signed long b);
extern signed long minl(signed long a,signed long b);
extern unsigned long umaxl(unsigned long a,unsigned long b);
extern unsigned long uminl(unsigned long a,unsigned long b);
extern unsigned long squaredl(signed long n);
extern unsigned long usquaredl(unsigned long n);
extern int cmpl(signed long a,signed long b);
extern int ucmpl(unsigned long a,unsigned long b);

extern signed long long maxll(signed long long a,signed long long b);
extern signed long minll(signed long long a,signed long long b);
extern unsigned long long umaxll(unsigned long long a,unsigned long long b);
extern unsigned long long uminll(unsigned long long a,unsigned long long b);
extern unsigned long long squaredll(signed long long n);
extern unsigned long long usquaredll(unsigned long long n);
extern int cmpll(signed long long a,signed long long b);
extern int ucmpll(unsigned long long a,unsigned long long b);

extern float fmaxf(float a,float b);
extern float fminf(float a,float b);
extern float fsquaredf(float n);
extern int fcmpf(float a,float b);

extern double fmax(double a,double b);
extern double fmin(double a,double b);
extern double fsquared(double n);
extern int fcmp(double a,double b);

extern double norm2xy(double x,double y);
extern double norm2xyz(double x,double y,double z);
extern double norm2xyzw(double x,double y,double z,double w);

extern int eatline ();
extern int eatall ();

#ifdef __cplusplus
}
#endif
#endif
