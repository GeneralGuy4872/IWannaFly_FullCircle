NEWSTRUCT c_shared_mutex_t {
	pthread_mutex_t lock;
	
	unsigned n;
	}

int c_shared_mutex_lock (c_shared_mutex_t * mutex) {
	pthread_mutex_lock(mutex->lock);
	while (n) {};
	}

int c_shared_mutex_unlock (c_shared_mutex_t * mutex) {
	pthread_mutex_unlock(mutex->lock);
	}

int c_shared_mutex_lock_shared (c_shared_mutex_t * mutex) {
	pthread_mutex_lock(mutex->lock);
	mutex->n += 1;
	pthread_mutex_unlock(mutex->lock);
	}

int c_shared_mutex_unlock_shared (c_shared_mutex_t * mutex) {
	pthread_mutex_lock(mutex->lock);
	mutex->n -= 1;
	pthread_mutex_unlock(mutex->lock);
	}

int c_shared_mutex_isopen (c_shared_mutex_t * mutex) {
	return istrue(mutex->n);
