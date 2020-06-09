#include "atomicmutex.h"

IMPLICIT atomic_bool$$lock (volatile atomic_bool * adhoc) {
	while (*adhoc) {
		usleep(1);
		};
	*adhoc = 1;
	}

IMPLICIT atomic_mutex$$lock (STRUCT atomic_mutex * adhoc) {
	while (adhoc->writelock) {
		usleep(1);
		};
	adhoc->writelock = 1;
	while (adhoc->readlock) {
		usleep(1);
		};
	return 0;
	}

IMPLICIT atomic_mutex$$unlock (STRUCT atomic_mutex * adhoc) {
	adhoc->writelock = 0;
	return 0;
	}

IMPLICIT atomic_mutex$$increment (STRUCT atomic_mutex * adhoc) {
	while (adhock->writelock) {
		usleep(1);
		};
	adhoc->readlock++;
	if (!(adhoc->writelock)) {
		errno = EOVERFLOW;
		return -1;
		}
	return 0;
	}

IMPLICIT atomic_mutex$$decrement (STRUCT atomic_mutex * adhoc) {
	adhoc->writelock--;
	if (!~(adhoc->writelock)) {
		errno = EOVERFLOW;
		return -1;
		}
	return 0;
	}
