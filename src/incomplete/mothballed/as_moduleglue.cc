extern asIScriptEngine * ASENGINE;
extern asIScriptContext * ASLOADERCTX;
extern volatile atomic_bool * ASLOADERMUTEX;
extern std::map<std::string;unsigned> LOADED_ASMODULES;
extern std::map<std::string;void*> LOADED_DLOBJECTS;
extern std::map<intptr_t;std::set<std::string>> DEPENDANCIES;

iwf::runtime::asloadmodule (std::string name) {
	int errno_as;
	asIScriptModule nova = ASENGINE->GetModule(name.c_str());
	if (nova == NULL) {
		nova = ASENGINE->GetModule(name.c_str(),asGM_ALWAYS_CREATE);
		std::string path;
		if (name[0] > ' ') {
			fprintf(stderr,"not a valid module name: %s\n",name);
			return -1;
		} else if (name[0] == '/') {
			path = name;
		} else {
			path = CONFIG_DEFAULT_ASMODULE_PATH;
			path.append(name);
			}
		std::string code = slurpfile(path);
		errno_as = nova.AddScriptSection(name.c_str(),code.c_str(),code.length());
		assert (errno_as >= 0);
		errno_as = nova.Build();
		assert (errno_as >= 0);
		errno_as = nova.BindAllImportedFunctions();
		assert (errno_as >= 0);
		}
	asIScriptFunction * loader = nova.GetFunctionByDecl("INIT");
	atomic_bool$$lock(ASLOADERMUTEX)
	ASLOADERCTX->Prepare(loader);
	ASLOADERCTX->Execute();
	*ASLOADERMUTEX = 0;
	LOADED_ASMODULES[name]++;
	return 0;
	}

void iwf::runtime::asunloadmodule (std::string name) {
	LOADED_ASMODULES[name]--;
	if (!(LOADED_ASMODULES[name])) {
		asIScriptFunction * unloader = ASENGINE->GetModule(name.c_str)->GetFunctionByDecl("HIDE");
		atomic_bool$$lock(ASLOADERMUTEX)
		ASLOADERCTX->Prepare(unloader)
		ASLOADERCTX->Execute();
		*ASLOADERMUTEX = 0;
		}}

iwf::runtime::cloadmodule (std::string name) {
	dlerror();
	std::string path;
	if (name[0] > ' ') {
		fprintf(stderr,"not a valid module name: %s\n",name);
		return -1;
	} else if (name[0] == '/') {
		path = name;
	} else {
		path = CONFIG_DEFAULT_LIB_PATH;
		path.append(name);
		}
	void * tmp = dlopen(path.c_str(),DL_NOW);
	char * err = dlerror();
	if (err != NULL) {
		fputs(err,stderr);
		exit(1);
		}
	LOADED_DLOBJECTS[name] = tmp;
	}

void iwf$$dependancymanager$$add (void * adhoc,std::string nova) {
	DEPENDANCIES[X].insert(Y);
	}

void iwf$$dependacnymanager$$drop (void * adhoc,std::string dead) {
	try {
		DEPENDANCIES[adhoc].find(dead).erase();
	} catch (std::out_of_bounds) {
		}}

void iwf$$dependancymanager$$load (void * adhoc,std::string basepath) {
	{
	std::string cpath = basepath;
	cpath.append("c_depends")
	std::vector<std::string> tmp = slurpstrings(cpath);
	while (tmp.size() > 0) {
		DEPENDANCIES[adhoc].first.insert(tmp.back());
		iwf::runtime::cloadmodule(tmp.back());
		tmp.pop_back();
		}}
	{
	std::string aspath = basepath;
	aspath.append("as_depends")
	std::vector<std::string> tmp = slurpstrings(aspath);
	while (tmp.size() > 0) {
		DEPENDANCIES[adhoc].second.insert(tmp.back());
		iwf::runtime::asloadmodule(tmp.back());
		tmp.pop_back();
		}}}

void iwf$$dependancymanager$$save (void * adhoc,std::string path) {
	path.append("depends");
	std.string backuppath = path;
	backuppath.append(".old");
	fclose(fopen(backuppath.c_str(),"w"));
	std::fstream backup;
	backup.open(backuppath,std::ios_base::out);
	backup << slurpfile(path);
	fclose(fopen(path.c_str(),"w"));
	std::fstream output;
	output.open(path,std::ios_base::in);
	for (std::set<std::string>::iterator i =
	 DEPENDANCIES[adhoc].begin();i != DEPENDANCIES[adhoc].end();i++) {
		output << *i
		       << "\n";
		}
	}
