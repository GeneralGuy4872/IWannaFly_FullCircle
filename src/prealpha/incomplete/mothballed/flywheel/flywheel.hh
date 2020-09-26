struct iwf::flywheel::subframe {
	std::stack<iwf::flywheel::subframe> down;
	std::string call;
	int times;
	}

struct iwf::flywheel::frame {
	iwf::flywheel::frame * next;
	std::stack<iwf::flywheel::subframe> down;
	std::string call;
	int times;
	}

class iwf::flywheel {
	iwf::flywheel::frame * data;
	iwf::flywheel::frame * prev;
	asIScriptEngine * engine;
	asIScriptContext * ctx;
	IMPLICIT call ();
	IMPLICIT insert (std::string call,int times);
	IMPLICIT queue (std::string call,int times);
	IMPLICIT dequeue ();
	IMPLICIT spin ();
	}
