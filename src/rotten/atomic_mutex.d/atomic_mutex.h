#ifndef __cplusplus
#include <stdlib.h>
#include <stdbool.h>
#include <stdatomic.h>
#else
#include <atomic>
#endif
#include <unistd.h>
#include <errno.h>
#include "cppkeywords.def"

struct atomic_mutex {
	volatile atomic_bool writelock;
	volatile atomic_uint readlock;
	}

IMPLICIT atomic_mutex$$lock (STRUCT atomic_mutex * adhoc);
IMPLICIT atomic_mutex$$unlock (STRUCT atomic_mutex * adhoc);
IMPLICIT atomic_mutex$$increment (STRUCT atomic_mutex * adhoc);
IMPLICIT atomic_mutex$$decrement (STRUCT atomic_mutex * adhoc);
