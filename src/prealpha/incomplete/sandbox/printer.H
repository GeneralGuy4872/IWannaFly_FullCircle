#ifndef __IWF_PRINTER__
#define __IWF_PRINTER__

#ifdef __cplusplus
extern "C" {
#endif

extern SYSINT iwf$$printer$$gets (const char * filename);
extern SYSINT iwf$$printer$$printline (unsigned index);

#ifdef __cplusplus
}
#endif
#endif
