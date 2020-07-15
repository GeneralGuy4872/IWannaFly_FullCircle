extern "C" {

void wrapper___std___shared_mutex___lock (void * opaque) {
	std::shared_mutex padlock = &opaque;
	padlock.lock();
	}

IMPLICIT wrapper___std___shared_mutex___try_lock (void * opaque) {
	std::shared_mutex padlock = &opaque;
	if (padlock.try_lock()) {
		return 0;
	} else {
		errno = EBUSY;
		return -1;
		}
	}

void wrapper___std___shared_mutex___unlock (void * opaque) {
	std::shared_mutex padlock = &opaque;
	padlock.unlock();
	}

void wrapper___std___shared_mutex___lock_shared (void * opaque) {
	std::shared_mutex padlock = &opaque;
	padlock.lock();
	}

IMPLICIT wrapper___std___shared_mutex___try_lock_shared (void * opaque) {
	std::shared_mutex padlock = &opaque;
	if (padlock.try_lock_shared()) {
		return 0;
	} else {
		errno = EBUSY;
		return -1;
		}
	}

void wrapper___std___shared_mutex___unlock_shared (void * opaque) {
	std::shared_mutex padlock = &opaque;
	padlock.unlock();
	}
