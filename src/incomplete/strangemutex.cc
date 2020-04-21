class iwf::strangemutex {
	std::shared_mutex mutex;
	std::mutex pending;
	std::mutex writing;
	void lockr () {
		for (bool success;!success;) {
			this->pending.lock();
			success = this->mutex.trylock_shared();
			this->pending.unlock();
			}
		}
	void unlockr () {
		this->mutex.unlock_shared();
		}
	void lockw () {
		for (bool success;!success;) {
			this->pending.lock();
			success = this->writing.trylock();
			if (success) {
				this->mutex.lock();
				}
			this->pending.unlock();
			}
		}
	void unlockw () {
		this->writing.unlock();
		this->mutex.unlock();
		}
	}

extern "C" {

void * iwf__strangemutex__new () {
	return new iwf::strangemutex;
	}

void iwf__strangemutex__delete (void * deadbeef) {
	delete ((iwf::strangemutex *) deadbeef);
	}

void iwf__strangemutex__lockr (void * self) {
	((iwf::strangemutex *) self)->lockr();
	}

void iwf__strangemutex__unlockr (void * self) {
	((iwf::strangemutex *) self)->unlockr();
	}

void iwf__strangemutex__lockw (void * self) {
	((iwf::strangemutex *) self)->lockw();
	}

void iwf__strangemutex__unlockw (void * self) {
	((iwf::strangemutex *) self)->unlockw();
	}
}
