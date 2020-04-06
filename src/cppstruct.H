#ifndef __IWF_CPPSTRUCT__
#define __IWF_CPPSTRUCT__
#ifdef __cplusplus
#define STRUCT
#define NEWSTRUCT extern "C" struct
#define UNION
#define NEWUNION extern "C" union
typedef int IMPLICIT;
#else
#define STRUCT struct
#define NEWSTRUCT struct
#define UNION union
#define NEWUNION union
#define IMPLICIT
#endif
#endif
