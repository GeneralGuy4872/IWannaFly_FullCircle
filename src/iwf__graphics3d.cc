struct iwf::graphics3d::viewportal {
	irr::IrrlichtDevice * device;
	video::IVideoDriver * driver;
	scene::ISceneManager * smgr;
	gui::IGUIEnviroment * guienv;
	std::shared_mutex lock;
	}

viewportal * iwf::graphics3d::initialize () {
	viewportal * VIEWPORT = new viewportal;
	VIEWPORT->device = ::irr::createdevice(::video::EDT_OPENGL,::core::dimension2d<u32>(850,640),16,false,false,false,0);

	VIEWPORT->driver = VIEWPORT->device->getVideoDriver();
	VIEWPORT->smgr = VIEWPORT->device->getSceneManager();
	VIEWPORT->guienv = VIEWPORT->device->getGUIEnvironment();

	VIEWPORT->device->setWindowCaption(L"Main Viewport - IWannaFly α8");

	return VIEWPORT;
	}

IMPLICIT iwf::graphics3d::mainloop (viewportal * VIEWPORT) {
	while (VIEWPORT->device->run()) {
		VIEWPORT->lock->lock();
		VIEWPORT->driver->beginScene(true,true,irr::video::SColor(250,0,0,0));
		VIEWPORT->smgr->drawAll();
		VIEWPORT->guienv->drawAll();
		VIEWPORT->driver->endScene();
		}
	VIEWPORT->device->drop();
	return 0;
	}
				}} extern "C" {
				}
