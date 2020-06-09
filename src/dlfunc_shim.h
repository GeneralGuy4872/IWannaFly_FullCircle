#ifndef __GG4872_DLFUNC_SHIM_H__
#define __GG4872_DLFUNC_SHIM_H__
typedef void * dlfunc_t;
#define dlfunc(H,S) dlsym(H,S)
#endif
