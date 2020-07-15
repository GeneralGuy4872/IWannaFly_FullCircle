#include "cppkeyword.def"

extern "C" {
	STRUCTTYPE_BEGIN(minifixed_t)
		bool whole : 1;
		unsigned part : 7;
	STRUCTTYPE_END;

	double minifixed$$get (minifixed_t * object) {
		return (object->whole + ((double) object->part / 0x80));
		};

	float minifixed$$getf (minifixed_t * object) {
		return (object->whole + ((float) object->part / 0x80));
		};

	minifixed_t minifixed$$set (minifixed_t * object,double input) {
		object->whole = istrue(((int)input));
		object->part = (int)(fmod(input,1) * 0x80);
		return get(object);
		};

	minifixed_t minifixed$$setf (minifixed_t * object,float input) {
		object->whole = istrue(((int)input));
		object->part = (int)(fmod(input,1) * 0x80);
		return getf(object);
		};
	}
namespace minifixed {
	double get (minifixed_t * object) {
		return (object->whole + ((double) object->part / 0x80));
		};

	float getf (minifixed_t * object) {
		return (object->whole + ((float) object->part / 0x80));
		};

	minifixed_t set (minifixed_t * object,double input) {
		object->whole = istrue(((int)input));
		object->part = (int)(fmod(input,1) * 0x80);
		return get(object);
		};

	minifixed_t setf (minifixed_t * object,float input) {
		object->whole = istrue(((int)input));
		object->part = (int)(fmod(input,1) * 0x80);
		return getf(object);
		};
	};
}
