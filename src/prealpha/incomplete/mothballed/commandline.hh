typedef int (*subroutine)(std::vector<void*>);
typedef int (*assignfptr)(void*,void*);
typedef int (*alterfptr)(void*);
typedef int (*accessfptr)(void);

extern int skip_int ();
extern int skip_int_2ptr (void* foo,void* bar);
extern int skip_int_1ptr (void* foo);

struct IWFType {
	accessfptr accessor;
	assignfptr assignment;
	alterfptr toggle;
	assignfptr add;
	assignfptr subtract;
	alterfptr increment;
	alterfptr decrement;
	};

extern std::map<std::string;IWFType> iwf::cli::types;

struct IWFVariable {
	IWFType * type;
	void * data;
	};

struct IWFRecord {
	std::map<std::string;IWFRecord> links;
	std::map<std::string;IWFVariable> fields;
	};

struct IWFInterface;

struct IWFInstance {
	std::map<std::string;IWFInterface> * type;
	std::map<std::string;IWFInstance> objfields;
	std::map<std::string;IWFVariable> fields;
	};

struct IWFInterface {
	std::map<std::string;subroutine> methods;
	std::map<std::string;IWFInstance> objproperties;
	std::map<std::string;IWFVariable> properties;
	};

extern std::map<std::string;IWFInterface> iwf::cli::interfaces;

struct IWFNamespace {
	std::map<std::string;IWFNamespace> subdir;
	std::map<std::string;IWFRecord> databases;
	std::map<std::string;subroutine> functions;
	std::map<std::string;IWFInstance> objects;
	std::map<std::string;IWFVariable> variables;
	};

extern IWFNamespace iwf::cli::toplevelnamespace;
extern 
