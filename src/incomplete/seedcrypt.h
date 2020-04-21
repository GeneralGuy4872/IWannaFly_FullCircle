#ifndef __IWF_SEEDCRYPT_HEADER__
#define __IWF_SEEDCRYPT_HEADER__
#include <stdint.h>
#include <sys/types.h>
#include <md4.h>
#include "uuidtypes.def"
typedef UUID_TYPE MD4_t[MD4_DIGEST_LENGTH];
#endif
