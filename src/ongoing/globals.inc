asIScriptEngine ASENGINE;

std::map<std::string;unsigned> LOADED_MODULES;

std::map<intptr_t;std::set<std::string>> DEPENDANCIES;

volatile ATOMIC(bool) HALT;
//everywhere

volatile ATOMIC(bool) ERROR;
//everywhere

volatile ATOMIC(bool) CHANGE_JSDEV;
//iwf$$joystickio

std::string iwf::iosettings::jsdevpath;
//iwf$$joystickio

uint8_t
