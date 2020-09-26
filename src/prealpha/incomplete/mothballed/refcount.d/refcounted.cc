#include "variablewidthdatablock.hh"

class iwf::refcounted {
	private:
	static iwf::refcounted * head;
	static iwf::refcounted * tail;
	iwf::refcounted * prev;
	iwf::refcounted * next;

	public:
	int refs;
	variablewidthdatablock data;

	int inc () {
		this->refs += 1;
		if (this->refs <= 0) {
			throw std::overflow_error;
			}
		return this->refs;
		};

	int del () {
		this->refs -= 1;
		if (this->refs < 0) {
			this.drop();
			return -1;
			}
		return this->refs;
		};

	void drop () {
		if ((this.next == NULL) && (this.prev == NULL)) {
			this.head = NULL;
			this.tail = NULL;
		} else if (this.prev == NULL) {
			this.head = this.next;
			this.head.prev = NULL;
		} else if (this.next == NULL) {
			this.tail = this.prev;
			this.tail.next = NULL;
		} else {
			this.prev.next = this.next;
			this.next.prev = this.prev;
			}
		delete this;
		};

	iwf::refcounted * alloc () {
		iwf::refcounted * nova = new iwf::refcounted;
		if (this.tail == NULL) {
			this.head = nova;
			this.tail = nova;
		} else {
			this.tail.next = nova;
			nova.prev = this.tail;
			this.tail = nova;
			}
		return nova;
		};
	};

extern "C" {
	int iwf$$refcounted$$inc (void * opaque) {
		iwf::refcounted * object = opaque;
		try {
			return object->inc();
		} catch (std::overflow_error) {
			errno = EOVERFLOW;
			return -1;
			}
		};

	int iwf$$refcounted$$del (void * opaque) {
		iwf::refcounted * object = opaque;
		return object->del();
		}
	
	void iwf$$refcounted$$drop (void * opaque) {
		iwf::refcounted object = opaque;
		object->drop();
		};

	void * iwf$$refcounted$$alloc () {
		return iwf::refcounted::alloc();
		}
	}
