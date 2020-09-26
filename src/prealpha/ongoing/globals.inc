asIScriptEngine ASENGINE;

std::map<std::string;unsigned> LOADED_MODULES;

std::map<intptr_t;std::set<std::string>> DEPENDANCIES;

volatile ATOMIC(bool) HALT;
//everywhere

volatile ATOMIC(bool) ERROR;
//everywhere

iwf::dictionary_t TOPLEVEL
std::map<short;boost::simple_segregated_storage<size_t> *> POOLS;
ATOMIC(short) NEXTPOOL;
ATOMIC(bool) POOLSMAXED;
//savefile stuff

ATOMIC(std::map<void*;int>) iwf::refcounter::table;
//anywhere that leaks

volatile ATOMIC(bool) CHANGE_JSDEV;
//iwf$$joystickio

std::string iwf::iosettings::jsdevpath;
//iwf$$joystickio


uint8_t
