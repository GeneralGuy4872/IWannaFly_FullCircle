struct shared_mutex {
	pthread_mutex_t readmutexmutex;
	volatile unsigned counter;
	}

pthread_mutex_wait (pthread_mutex_t * lock) {
	for (int code;;) {
	if (pthread_mutex_trylock(lock)) {
		code = errno;
		if (code != EBUSY) {
			errno = code;
			return -1;
			}
	} else {
		return 0;
		}
	}}

shared_mutex_wait (struct shared_mutex * this) {
	for (;;) {
		pthread_mutex_wait(this->readmutexmutex);
		if (!this->counter) break;
		}
	return 0;
	}

shared_mutex_inc (struct shared_mutex * this,pthread_mutex_t * writeblock) {
	if (writeblock != NULL) {
		pthread_mutex_wait(writeblock);
		}
	pthread_mutex_lock(this->readmutexmutex);
	(this->counter)++;
	pthread_mutex_unlock(this->readmutexmutex);
	return 0;
	}
	
shared_mutex_dec (struct shared_mutex * this) {
	pthread_mutex_lock(this->readmutexmutex);
	(this->counter)--;
	pthread_mutex_unlock(this->readmutexmutex);
	return 0;
	}
