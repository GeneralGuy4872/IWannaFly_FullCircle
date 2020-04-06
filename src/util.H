#ifndef __GG4872_UTIL_H_SUPERHEADER__
#define __GG4872_UTIL_H_SUPERHEADER__

#define ≥ >=
#define ≤ <=

#define skip() {}
#define tosignbit(X) (X < 0 ? 1 : 0)
#define signbit(X) (X ? -1 : 1)

#define sgn(X) cmp(X,0)
#define sgnl(X) cmpl(X,0)
#define sgnll(X) cmpll(X,0)
#define sgnf(X) cmpf(X,0)
#define sgnfd(X) cmpfd(X,0)
#endif
