#ifndef __IWF_CURSESCAT_H__
#define __IWF_CURSESCAT_H__

#ifndef __cplusplus
#include <stdlib.h>
#endif
#include <sys/stat.h>
#include <fnctrl.h>
#include <curses.h>
#include "cppkeyword.def"
#ifdef __cplusplus
extern "C" {
#endif

extern IMPLICIT curscat (const char * filename);

#ifdef __cplusplus
}
#endif
#endif
