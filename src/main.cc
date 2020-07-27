/**************
 * IWANNAFLY  *
 *            *
 *  prealpha  *
 **************/

#define SNAPSHOT "AFTERNOON/26/07/2020"

/* this program currently requires a second terminal to be used; this is
 * done by passing the terminal's device file (which can be obtained with
 * the command tty) as argv[1] and the device's $TERM value as argv[2]. you
 * must have permission to open the device file as "r+".
 *
 * an example of invocation is:
 *
 * Iwannafly /dev/pts/1 xterm
 *
 * this is primarily to speed prototyping, and will not be necissary in the
 * finished game; during development, all text input will be done using
 * stdio, and all GUI interaction will be done using nCurses.
 */

#define SYSINT int
#define RGBColor(R,G,B) irr::video::SColor(0xFF,R,G,B)
#define RGBAColor(R,G,B,A) irr::video::SColor(A,R,G,B)

#define POLLTIME 5000

#include <cstdio>
#include <cstdint>
#include <cmath>
#include <cerrno>

#include <map>
#include <string>
#include <atomic>
#include <iostream>

#include <irrlicht/irrlicht.h>
#include <lua5.3/lua.hpp>
#include <lua5.3/lauxlib.h>

#include <unistd.h>
#include <pthread.h>

extern "C" {
	#include <curses.h>
	}	//not C++ safe-- idk why this fixes it.

/***GLOBALS***/

std::atomic_bool SCRAM;
std::atomic<char> JITTER;
std::atomic<char> JITTERMAX;
pthread_mutex_t JITTER_ADV_LOCK = PTHREAD_MUTEX_INITIALIZER;
float JITTER_ADVERAGE;
typedef std::map<char,irr::scene::IMeshSceneNode *> NODES_t;
NODES_t NODES;

#define THREAD__MAIN 0
#define THREAD__EVENT 1
#define THREAD__JITTERBUG 2
#define THREAD__NCURSES 3
#define THREAD__LUA_SCRIPTING 4
#define THREAD__LUA_COMMANDLINE 5
#define THREADCOUNT 6
std::atomic_int EXELINE[THREADCOUNT];
#define CHECKPOINT(X,Y) EXELINE[X] = Y

/***CUSTOM CLASSES***/

namespace iwf { namespace datatypes {
class camcoord {
	public:
	double az;
	double el;

	irr::core::vector3df euclid () {
		irr::core::vector3df tmp;
		tmp.X = sin(this->el) * cos(this->az);
		tmp.Y = sin(this->el) * sin(this->az);
		tmp.Z = cos(this->el);
		return tmp;
	}};
}}
                  
namespace irrcontext {
	irr::IrrlichtDevice * device;
	irr::video::IVideoDriver * driver;
	irr::scene::ISceneManager * smgr;
	irr::gui::IGUIEnvironment * guienv;
	irr::scene::IMeshManipulator * meshmanipr;
	irr::gui::ICursorControl * cursctrl;
	irr::ITimer * timer;
	double deltatime;
	uint32_t then;
	uint32_t now;
	}

iwf::datatypes::camcoord CAMCOORD;
irr::scene::ICameraSceneNode * CAMERA;
pthread_mutex_t CAMLOCK = PTHREAD_MUTEX_INITIALIZER; 
std::atomic_bool STEALCURSOR;
std::atomic_bool YINVERT;

/***EVENT LOOP***/

class MainEventReciever : public irr::IEventReceiver {
/* part of this program has been created using the toutorials at
 * http://irrlicht.sourceforge.net/docu/pages.html
 *
 * (on a related note, have I mentioned the Ship of Theseus today?)
 */
	public:
	virtual bool OnEvent (const irr::SEvent& event) {
		CHECKPOINT(THREAD__EVENT,__LINE__);
		if (JITTER >= JITTERMAX) {
			CHECKPOINT(THREAD__EVENT,__LINE__);
			return false;	//did nothing
			}
		CHECKPOINT(THREAD__EVENT,__LINE__);
		switch (event.EventType) {
			CHECKPOINT(THREAD__EVENT,__LINE__);
			case irr::EET_MOUSE_INPUT_EVENT : switch (event.MouseInput.Event) {
				CHECKPOINT(THREAD__EVENT,__LINE__);
				case irr::EMIE_LMOUSE_PRESSED_DOWN : {
					CHECKPOINT(THREAD__EVENT,__LINE__);
					STEALCURSOR = true;
					irrcontext::cursctrl->setVisible(0);
					irrcontext::cursctrl->setPosition(0.5f,0.5f);
					this->mouseCenter = irrcontext::cursctrl->getPosition();
					CHECKPOINT(THREAD__EVENT,__LINE__);
					} break;
				case irr::EMIE_MOUSE_MOVED : if (!STEALCURSOR) {
					return false;
				} else {
					CHECKPOINT(THREAD__EVENT,__LINE__);
					pthread_mutex_lock(&CAMLOCK);
					CAMCOORD.el += (event.MouseInput.Y - this->mouseCenter.Y) * (YINVERT ? -1 : 1) * (180 / M_PI) * (1 / 1000.0) * irrcontext::deltatime;
						if (CAMCOORD.el >= 0.0) {
							CAMCOORD.el = 0 - (M_PI / 1000);
						} else if (CAMCOORD.el <= -M_PI) {
							CAMCOORD.el = -(M_PI - (M_PI / 1000));
							}
					CAMCOORD.az += (event.MouseInput.X - this->mouseCenter.X) * (180 / M_PI) * (1 / 1000.0) * irrcontext::deltatime;
						while (CAMCOORD.az < -M_PI) {
							CAMCOORD.az += 2 * M_PI;
						} while (CAMCOORD.az > M_PI) {
							CAMCOORD.az -= 2 * M_PI;
							}
					pthread_mutex_unlock(&CAMLOCK);
					irrcontext::cursctrl->setPosition(0.5f,0.5f);
					CHECKPOINT(THREAD__EVENT,__LINE__);
					} break;
				default : break;
				}
			case (irr::EET_KEY_INPUT_EVENT) : {
				CHECKPOINT(THREAD__EVENT,__LINE__);
				if (event.KeyInput.PressedDown) {
					CHECKPOINT(THREAD__EVENT,__LINE__);
					switch (event.KeyInput.Key) {

						case irr::KEY_KEY_W : {
							CHECKPOINT(THREAD__EVENT,__LINE__);
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.el += 5 * irrcontext::deltatime;
							if (CAMCOORD.el >= 0.0) {
								CAMCOORD.el = 0 - (M_PI / 1000);
								}
							pthread_mutex_unlock(&CAMLOCK);
							CHECKPOINT(THREAD__EVENT,__LINE__);
							} break;

						case irr::KEY_KEY_S : {
							CHECKPOINT(THREAD__EVENT,__LINE__);
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.el -= 5 * irrcontext::deltatime;
							if (CAMCOORD.el <= -M_PI) {
								CAMCOORD.el = -(M_PI - (M_PI / 1000));
								}
							pthread_mutex_unlock(&CAMLOCK);
							CHECKPOINT(THREAD__EVENT,__LINE__);
							} break;

						case irr::KEY_KEY_A : {
							CHECKPOINT(THREAD__EVENT,__LINE__);
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.az -= 5 * irrcontext::deltatime;
							while (CAMCOORD.az < -M_PI) {
								CAMCOORD.az += 2 * M_PI;
								}
							pthread_mutex_unlock(&CAMLOCK);
							CHECKPOINT(THREAD__EVENT,__LINE__);
							} break;

						case irr::KEY_KEY_D : {
							CHECKPOINT(THREAD__EVENT,__LINE__);
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.az += 5 * irrcontext::deltatime;
							while (CAMCOORD.az > M_PI) {
								CAMCOORD.az -= 2 * M_PI;
								}
							pthread_mutex_unlock(&CAMLOCK);
							CHECKPOINT(THREAD__EVENT,__LINE__);
							} break;

						case irr::KEY_ESCAPE : {
							CHECKPOINT(THREAD__EVENT,__LINE__);
							STEALCURSOR = 0;
							irrcontext::cursctrl->setVisible(1);
							CHECKPOINT(THREAD__EVENT,__LINE__);
							} break;

						case irr::KEY_KEY_Y : {
							CHECKPOINT(THREAD__EVENT,__LINE__);
							YINVERT = !YINVERT;
							} break;

						default : break;
				}}} break;
			default : break;
			}
		CHECKPOINT(THREAD__EVENT,__LINE__);
		return false;
		}
	private:
	irr::core::vector2di mouseCenter;
	};

MainEventReciever RECIEVER;

/***JITTERBUG THREAD GOVERNER***/

void * iwf$$threads$$jitterbug$$loop (void * dummy) {
	double localbuffer = 0.0;
	for (;;usleep(POLLTIME)) {
	CHECKPOINT(THREAD__JITTERBUG,__LINE__);
	JITTER++;
	if (JITTER == -1) {
		SCRAM = true;
		return NULL;
		}
	CHECKPOINT(THREAD__JITTERBUG,__LINE__);
	localbuffer = ((JITTER * 3) + localbuffer) / 4;
	if (!pthread_mutex_trylock(&JITTER_ADV_LOCK)) {
		CHECKPOINT(THREAD__JITTERBUG,__LINE__);
		JITTER_ADVERAGE = localbuffer;
		pthread_mutex_unlock(&JITTER_ADV_LOCK);
		}
	CHECKPOINT(THREAD__JITTERBUG,__LINE__);	
	}}

pthread_t iwf$$threads$$jitterbug;

/***NCURSES THREAD***/

SCREEN * CURSCREEN;

void * iwf$$threads$$curses$$function (void * input) {
	char *(*argv)[] = input;
	for (int fg = 0;fg < 8;fg++) {
		for (int bg = 0;bg < 8;bg++) {
			init_pair(fg | (bg << 3),fg,bg);
		}}
	FILE * devfile = fopen((*argv)[1],"r+");
	if (devfile == NULL) {
		fprintf(stderr,"%s\n(Not a typewriter?)\n",strerror(errno));
		printf("usage: %s <another tty> <$TERM of tty> ...\n",(*argv)[0]);
		SCRAM = true;
		return NULL;
		}

	CURSCREEN = newterm((*argv)[2],devfile,devfile);
	set_term(CURSCREEN);
	
	raw();
	noecho();
	keypad(NULL,1);

	mvprintw(3,3,"IWannaFly");
	mvprintw(4,4,"prealpha devtest");
	mvprintw(5,5,"revision snapshot:");
	mvprintw(6,5,SNAPSHOT);

	irr::core::vector3df placeholder;
	float placeholder2;
	char tmp;
	int tmp0;
	int tmp1;
	int tmp2;
	int tmp4;
	int tmp5;

	for (;;sleep(1)) {
		CHECKPOINT(THREAD__NCURSES,__LINE__);
		pthread_mutex_lock(&CAMLOCK);
		mvprintw(8,8,"camera azimuth   : % 15.10f°",CAMCOORD.az * (180 / M_PI));
		mvprintw(9,8,"camera elevation : % 15.10f°",CAMCOORD.el * (180 / M_PI));
		mvprintw(11,8,"camera basis vector:");
		placeholder = CAMCOORD.euclid();
		pthread_mutex_unlock(&CAMLOCK);
		CHECKPOINT(THREAD__NCURSES,__LINE__);
		mvprintw(12,10,"% 12.10fx",placeholder.X);
		mvprintw(13,10,"% 12.10fy",placeholder.Y);
		mvprintw(14,10,"% 12.10fz",placeholder.Z);
		mvprintw(16,8,"cursor grabbed? >%s",STEALCURSOR ? "yes" : "no ");
		CHECKPOINT(THREAD__NCURSES,__LINE__);
		pthread_mutex_lock(&JITTER_ADV_LOCK);
		mvprintw(17,8,"adverage jitter : %4.4f",JITTER_ADVERAGE);
		pthread_mutex_unlock(&JITTER_ADV_LOCK);

		CHECKPOINT(THREAD__NCURSES,__LINE__);
		tmp = JITTERMAX;
		mvprintw(18,8,"(max jitter : %3i)",tmp);
		CHECKPOINT(THREAD__NCURSES,__LINE__);

		tmp0 = EXELINE[0];
		tmp1 = EXELINE[1];
		tmp2 = EXELINE[2];
		tmp4 = EXELINE[4];
		tmp5 = EXELINE[5];
		CHECKPOINT(THREAD__NCURSES,__LINE__);
		mvprintw(20,8,"line of execution : % 4i  % 4i  % 4i  SELF  % 4i  % 4i",tmp0,tmp1,tmp2,tmp4,tmp5);

		CHECKPOINT(THREAD__NCURSES,__LINE__);
		refresh();
		CHECKPOINT(THREAD__NCURSES,__LINE__);
	}};

pthread_t iwf$$threads$$curses;

/***CHANGE THE COLORS***/

// lua code created using toutorials at lua.org

static int LFunc$$changecolor (lua_State * L) {
	int tmp[5];
	for (ptrdiff_t i = 0;i < 5;i++) {
		tmp[i] = lua_tointeger(L,i + 1);
	}{
	NODES_t::iterator i = NODES.find(tmp[0]);
	if (i != NODES.end()) {
		irrcontext::meshmanipr->setVertexColors(i->second->getMesh(),RGBAColor(tmp[1],tmp[2],tmp[3],tmp[4]));
		return 0;
	}}}

static const struct luaL_Reg LLib$$changecolor [] = {
	{"changecolor",LFunc$$changecolor},
	{NULL,NULL}
	};

/***INTERNAL SCRIPTING LUA THREAD***/

pthread_mutex_t SCRIPTPASS = PTHREAD_MUTEX_INITIALIZER;
bool SCRIPTGO;
std::string SCRIPTJOB;

void * iwf$$threads$$lua__scripting$$function (void * dummy) {
	lua_State * L = luaL_newstate();
	luaL_newlib(L,LLib$$changecolor);
	lua_setglobal(L,"lib");
	for (;;usleep(POLLTIME)) {
		pthread_mutex_lock(&SCRIPTPASS);
		CHECKPOINT(THREAD__LUA_SCRIPTING,__LINE__);
		if (SCRIPTGO) {
			luaL_dostring(L,SCRIPTJOB.c_str());
			SCRIPTJOB.clear();
			SCRIPTGO = false;
			}
		pthread_mutex_unlock(&SCRIPTPASS);
		CHECKPOINT(THREAD__LUA_SCRIPTING,__LINE__);
		}
	return NULL;
	}

pthread_t iwf$$threads$$lua__scripting;

/***LUA COMMAND LINE THREAD***/

void * iwf$$threads$$lua__commandline$$function (void * dummy) {
	lua_State * L = luaL_newstate();
	luaL_newlib(L,LLib$$changecolor);
	lua_setglobal(L,"lib");
	printf("IWannaFly lua commandline\n]> ");
	for (std::string buffer;;) {
		CHECKPOINT(THREAD__LUA_COMMANDLINE,__LINE__);
		getline(std::cin,buffer);
		CHECKPOINT(THREAD__LUA_COMMANDLINE,__LINE__);
		luaL_dostring(L,buffer.c_str());
		CHECKPOINT(THREAD__LUA_COMMANDLINE,__LINE__);
		buffer.clear();
		CHECKPOINT(THREAD__LUA_COMMANDLINE,__LINE__);
		printf("Done\n]> ");
		}
	return NULL;
	}

pthread_t iwf$$threads$$lua__commandline;

/***INITIALIZATION***/

SYSINT initialize (char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	SCRAM = 0;
	JITTERMAX = 0xF;

	pthread_create(&iwf$$threads$$curses,NULL,iwf$$threads$$curses$$function,argv);
	pthread_create(&iwf$$threads$$jitterbug,NULL,iwf$$threads$$jitterbug$$loop,NULL);
	pthread_create(&iwf$$threads$$lua__scripting,NULL,iwf$$threads$$lua__scripting$$function,NULL);
	pthread_create(&iwf$$threads$$lua__commandline,NULL,iwf$$threads$$lua__commandline$$function,NULL);

	irrcontext::device = irr::createDevice(irr::video::EDT_OPENGL,irr::core::dimension2d<irr::u32>(640, 480),16,false,false,false,&RECIEVER);
	irrcontext::driver = irrcontext::device->getVideoDriver();
	irrcontext::smgr = irrcontext::device->getSceneManager();
	irrcontext::guienv = irrcontext::device->getGUIEnvironment();
	irrcontext::meshmanipr = irrcontext::smgr->getMeshManipulator();
	irrcontext::cursctrl = irrcontext::device->getCursorControl();
	irrcontext::timer = irrcontext::device->getTimer();

	irrcontext::guienv->addStaticText(L"IWannaFly Devtest prealpha snapshot " SNAPSHOT,irr::core::rect<irr::s32>(10,10,260,22),1);
	CAMERA = irrcontext::smgr->addCameraSceneNode(NULL,irr::core::vector3df(0,0,0),irr::core::vector3df(1,1,1));
	CAMERA->setUpVector(irr::core::vector3df(0,0,1));

	for (int x = -1;x < 2;x += 1) {
		for (int y = -1;y < 2;y += 1) {
			for (int z = -1;z < 2;z += 1) {
				if (x || y || z) {
					irr::scene::IMeshSceneNode * tmp = irrcontext::smgr->addCubeSceneNode(
						10.0,
						NULL,
						((z * 9) + (y * 3) + x),
						irr::core::vector3df(
							(x * 25),
							(y * 25),
							(z * 25)));
					NODES[(z * 9) + (y * 3) + x] = tmp;
		}}}}
	irrcontext::smgr->addLightSceneNode();
	}

/***MAIN, FEAT. RENDER LOOP***/

main (int argc, char *argv[]) {
	
	if (argc < 2) {
		printf("usage: %s <another tty> <$TERM of tty> ...\n",argv[0]);
		exit(1);
		}
	initialize(argv);
	while (irrcontext::device->run()) {
		JITTER = 0;
		if (SCRAM) exit(0);
		CHECKPOINT(THREAD__MAIN,__LINE__);
		pthread_mutex_lock(&CAMLOCK);
		CAMERA->setTarget(CAMCOORD.euclid());
		pthread_mutex_unlock(&CAMLOCK);
		CHECKPOINT(THREAD__MAIN,__LINE__);
		irrcontext::driver->beginScene(true, true, RGBAColor(0,0,0xAA,0xF0));
		CHECKPOINT(THREAD__MAIN,__LINE__);
		irrcontext::smgr->drawAll();
		CHECKPOINT(THREAD__MAIN,__LINE__);
		irrcontext::guienv->drawAll();
		CHECKPOINT(THREAD__MAIN,__LINE__);
		irrcontext::driver->endScene();
		CHECKPOINT(THREAD__MAIN,__LINE__);
		irrcontext::now = irrcontext::timer->getTime();
		CHECKPOINT(THREAD__MAIN,__LINE__);
		irrcontext::deltatime = (irrcontext::now - irrcontext::then) / 1000.0;
		CHECKPOINT(THREAD__MAIN,__LINE__);
		irrcontext::then = irrcontext::now;
		CHECKPOINT(THREAD__MAIN,__LINE__);
		}}
