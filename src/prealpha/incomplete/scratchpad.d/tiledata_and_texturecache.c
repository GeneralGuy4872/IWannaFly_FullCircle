struct tilemeta {
	bool ladder : 1;
	bool fence : 1;

	bool solid : 1;
	bool liquid : 1;
	bool nophase : 1;

	bool burn : 1;
	bool hypotherm : 1;
	bool electric : 1;
	bool conductive : 1;
	bool poison : 1;
	bool spikes : 1;
	bool void_ : 1;
	
	double friction;
	double speed;
	float dig;

	char *texture[3];
	};

struct texture_cache_entry {
	irr::io::IReadFile file;
	irr::video::IImage image;
	irr::video::ITexture texture;
	int refcount
	};

std::map<std::basic_string_view;texture_cache_entry> texture_cache;
