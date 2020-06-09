int angelscript::r;

asIScriptEngine * iwf::bootengine::new (unsigned argc,*void[] argv,std::string[] names,*iwf::strangemutex[] locks) {
	asIScriptEngine * nova = asCreateScriptEngine(); assert (nova != NULL);
	RegisterScriptArray(nova,true);
	RegisterStdString(nova);
	RegisterScriptDictionary(nova);
	RegisterScriptFile(nova);
	RegisterScriptFileSystem(nova);
	RegisterScriptMath(nova);
	RegisterScriptDateTime(nova);
	RegisterExceptionRoutines(nova);
	#include "astypes.def"
	for (unsigned n;n < argc;n++) {
		angelscript::r = nova->RegisterGlobalProperty(names[n].c_str(), &g_number); assert(angelscript::r >= 0);
		}
	
	}

