template <typename T>

class doublelinkedlist::node;

struct doublelinkedlist {
	doublelinkedlist::node<T> * head;
	doublelinkedlist::node<T> * tail;

	doublelinkedlist::node<T> * push_back (T input) {
		doublelinkedlist::node<T> * nova = new doublelinkedlist::node<T>;
		if (this->tail == NULL) {
			this->head = nova;
			this->tail = nova;
		} else {
			this->tail.next = nova;
			nova->prev = this->tail;
			this->tail = nova;
			}
		nova->data = T;
		return nova;
		};

	doublelinkedlist::node<T> * push_front (T input) {
		doublelinkedlist::node<T> * nova = new doublelinkedlist::node<T>;
		if (this->head == NULL) {
			this->head = nova;
			this->tail = nova;
		} else {
			this->head.prev = nova;
			nova->next = this->head;
			this->head = nova;
			}
		nova->data = T;
		return nova;
		};

	doublelinkedlist::node<T> * iter_front (unsigned n) {
		doublelinkedlist::node<T> * output = this->head;
		for (int i = 0;i <= n;i++) {
			if (this->next == NULL) {
				throw std::out_of_range;
				}
			this = this->next;
			}
		return output;

	doublelinkedlist::node<T> * iter_back (unsigned n) {
		doublelinkedlist::node<T> * output = this->tail;
		for (int i = 0;i <= n;i++) {
			if (this->prev == NULL) {
				throw std::out_of_range;
				}
			this = this->prev;
			}
		return output;
		};
	};

class doublelinkedlist::node {
	private:
	const doublelinkedlist<T> * ends;
	public:
	doublelinkedlist::node<T> * prev;
	doublelinkedlist::node<T> * next;
	T data;

	void drop () {
		if ((this.next == NULL) && (this.prev == NULL)) {
			this.ends->head = NULL;
			this.ends->tail = NULL;
		} else if (this.prev == NULL) {
			this.ends->head = this.next;
			this.next.prev = NULL;
		} else if (this.next == NULL) {
			this.ends->tail = this.prev;
			this.prev.next = NULL;
		} else {
			this.prev.next = this.next;
			this.next.prev = this.prev;
			}
		delete this;
		};
	};

extern "C" {
