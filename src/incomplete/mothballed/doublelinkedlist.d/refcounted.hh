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
	int inc ();
	int del ();
	void drop ();
	iwf::refcounted * alloc ();
	};

extern "C" {
	int iwf$$refcounted$$inc (void * opaque);
	int iwf$$refcounted$$del (void * opaque);
	void iwf$$refcounted$$drop (void * opaque);
	void * iwf$$refcounted$$alloc ();
	};
