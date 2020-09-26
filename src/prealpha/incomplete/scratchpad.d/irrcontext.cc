namespace irrcontext {
	irr::IrrlichtDevice * device;
	irr::gui::ICursorControl * cursor;
	irr::IEventReciever * events;
	irr::io::FileSystem * filesystem;
	irr::gui::IGUIEnviroment * gui;
	irr:ILogger * logger;
	irr::scene::ISceneManager * sm;
	irr::ITimer * timer;
	irr::video::IVideoDriver * driver;
	irr::scene::ISceneNode;
	std::map<int32_t;IMeshSceneNode*> voxels;
	ISceneNode *chunks[7][7][7];
	}

namespace irrcontext::chunk_voxel {
	uint16_t counter;
	uint16_t voxelid[7][7][7];

	pan_up () ...
	pan_down () ...
	pan_north () ...
	pan_south () ...
	pan_west () ...
	pan_east () ...

	assign (char x,char y,char z) ...
	tie (char x,char y,char z,char xx,char yy,char zz) ...
	}

namespace irrcontext::textures {
	std::map<irr::io::path;irr::video::ITexture> cache;

	irr::video::ITexture * get (irr::io::path filename) {
		if (!(cache.contains(filename))) {
			irr::video::ITexture nova = irrcontext::driver->getTexture(filename);
			cache[filename] = nova;
			}
		return &(cache.at(filename));
		}
	}
