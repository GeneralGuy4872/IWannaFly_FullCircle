/**************
 * IWANNAFLY  *
 *            *
 *  prealpha  *
 **************/

#define SNAPSHOT "MORNING/16/07/2020"

/* part of this program has been created using the toutorials at
 * http://irrlicht.sourceforge.net/docu/pages.html
 */

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

#include <cstdio>
#include <cstdint>
#include <cmath>
#include <cerrno>

#include <map>
#include <string>
#include <atomic>

#include <irrlicht/irrlicht.h>
//#include <lua5.3/lua.hpp>

#include <unistd.h>
#include <pthread.h>

extern "C" {
	#include <curses.h>
	}	//not C++ safe

std::atomic_bool SCRAM;
std::atomic<int16_t> PING;
std::atomic<uint16_t> JITTER;

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

//lua_State * LSTATE;
iwf::datatypes::camcoord CAMCOORD;
irr::scene::ICameraSceneNode * CAMERA;
pthread_mutex_t CAMLOCK = PTHREAD_MUTEX_INITIALIZER; 
volatile std::atomic_bool STEALCURSOR;

class MainEventReciever : public irr::IEventReceiver {
	public:
	virtual bool OnEvent (const irr::SEvent& event) {
puts("\033[1;36mif (PING >= 32) {\033[m");
		if (PING >= 32) {
puts("\033[1;36mSTEALCURSOR = false;\033[m");
			STEALCURSOR = false;
puts("\033[1;36mreturn false;\t//did nothing\033[m");
			return false;	//did nothing
			}
		switch (event.EventType) {
			case irr::EET_MOUSE_INPUT_EVENT : switch (event.MouseInput.Event) {
				case irr::EMIE_LMOUSE_PRESSED_DOWN : {
puts("\033[1;36mBEGIN LMOUSE\033[m");
					STEALCURSOR = true;
//					irrcontext::cursctrl->setVisible(0);
					irrcontext::cursctrl->setPosition(0.5f,0.5f);
					this->mouseCenter = irrcontext::cursctrl->getPosition();
puts("\033[1;36mEND LMOUSE\033[m");
					} break;
				case irr::EMIE_MOUSE_MOVED : if (STEALCURSOR) {
puts("\033[1;36mBEGIN MOUSE MOVE\033[m");
					pthread_mutex_lock(&CAMLOCK);
					CAMCOORD.el += (event.MouseInput.Y - this->mouseCenter.Y) * (180 / M_PI) * (1 / 1000.0) * irrcontext::deltatime;
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
puts("\033[1;36mEND MOUSE MOVE\033[m");
					} break;
				default : break;
				}
			case (irr::EET_KEY_INPUT_EVENT) : {
				if (event.KeyInput.PressedDown) {
					switch (event.KeyInput.Key) {

						case irr::KEY_KEY_W : {
puts("\033[1;36mBEGIN KEYPRESS W\033[m");
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.el += 5 * irrcontext::deltatime;
							if (CAMCOORD.el >= 0.0) {
								CAMCOORD.el = 0 - (M_PI / 1000);
								}
							pthread_mutex_unlock(&CAMLOCK);
puts("\033[1;36mEND KEYPRESS W\033[m");
							} break;

						case irr::KEY_KEY_S : {
puts("\033[1;36mBEGIN KEYPRESS S\033[m");
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.el -= 5 * irrcontext::deltatime;
							if (CAMCOORD.el <= -M_PI) {
								CAMCOORD.el = -(M_PI - (M_PI / 1000));
								}
							pthread_mutex_unlock(&CAMLOCK);
puts("\033[1;36mEND KEYPRESS S\033[m");
							} break;

						case irr::KEY_KEY_A : {
puts("\033[1;36mBEGIN KEYPRESS A\033[m");
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.az -= 5 * irrcontext::deltatime;
							while (CAMCOORD.az < -M_PI) {
								CAMCOORD.az += 2 * M_PI;
								}
							pthread_mutex_unlock(&CAMLOCK);
puts("\033[1;36mEND KEYPRESS A\033[m");
							} break;

						case irr::KEY_KEY_D : {
puts("\033[1;36mBEGIN KEYPRESS D\033[m");
							pthread_mutex_lock(&CAMLOCK);
							CAMCOORD.az += 5 * irrcontext::deltatime;
							while (CAMCOORD.az > M_PI) {
								CAMCOORD.az -= 2 * M_PI;
								}
							pthread_mutex_unlock(&CAMLOCK);
puts("\033[1;36mEND KEYPRESS D\033[m");
							} break;

						case irr::KEY_ESCAPE : {
puts("\033[1;36mBEGIN KEYPRESS ESC\033[m");
							STEALCURSOR = 0;
							irrcontext::cursctrl->setVisible(1);
puts("\033[1;36mEND KEYPRESS ESC\033[m");
							} break;

						default : break;
				}}} break;
			default : break;
			}
puts("\033[1;36mreturn false;\033[m");
		return false;
		}
	private:
	irr::core::vector2di mouseCenter;
	};

MainEventReciever RECIEVER;
SCREEN * CURSCREEN;

void * iwf$$threads$$jitterbug$$loop (void * dummy) {
	for (;;) {
puts("\033[95mPING++;\033[m");
	PING++;
puts("\033[95mif (PING == -1) {\033[m");
	if (PING == -1) {
		SCRAM = true;
		return -1;
		}
	JITTER = (JITTER + (PING * 2)) / 2;
puts("\033[95musleep(5000);\033[m");
	usleep(5000);
	}}

pthread_t iwf$$threads$$jitterbug;

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
		return 1;
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
	int placeholder2;

	for (;;) {
puts("\033[3;32mpthread_mutex_lock(&CAMLOCK);\033[m");
		pthread_mutex_lock(&CAMLOCK);
puts("\033[3;32mvprintw(… × 3\033[m");
		mvprintw(8,8,"camera azimuth   : %+3.10f°",CAMCOORD.az * (180 / M_PI));
		mvprintw(9,8,"camera elevation : %+3.10f°",CAMCOORD.el * (180 / M_PI));
		mvprintw(11,8,"camera basis vector: %+3.10f°",CAMCOORD.el * (180 / M_PI));
puts("\033[3;32mplaceholder = CAMCOORD.euclid();\033[0");
		placeholder = CAMCOORD.euclid();
puts("\033[3;32mpthread_mutex_unlock(&CAMLOCK);\033[0");
		pthread_mutex_unlock(&CAMLOCK);
puts("\033[3;32mvprintw(… × 4\033[0");
		mvprintw(12,10,"%+2.10fx",placeholder.X);
		mvprintw(13,10,"%+2.10fy",placeholder.Y);
		mvprintw(14,10,"%+2.10fz",placeholder.Z);
		mvprintw(16,8,"camera locked? >%s",STEALCURSOR ? "no " : "yes");
puts("\033[3;32placeholder2 = JITTER;\033[m");
		placeholder2 = JITTER;
puts("\033[3;32mvprintw(… × 1\033[0");
		mvprintw(17,8,"adverage jitter : %f",placeholder2 / 2.0);
puts("\033[3;32mrefresh();\033[m");
		refresh();
puts("\033[3;32msleep(1);\033[m");
		sleep(1);
	}};

pthread_t iwf$$threads$$curses;

SYSINT initialize (char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	SCRAM = 0;

	pthread_create(&iwf$$threads$$curses,NULL,iwf$$threads$$curses$$function,argv);
	pthread_create(&iwf$$threads$$jitterbug,NULL,iwf$$threads$$jitterbug$$loop,NULL);

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

	for (int x = 0;x < 2;x += 1) {
		for (int y = 0;y < 2;y += 1) {
			for (int z = 0;z < 2;z += 1) {
			irr::scene::IMeshSceneNode * tmp = irrcontext::smgr->addCubeSceneNode(
				10.0,
				NULL,
				((z << 2)|(y << 1)|x),
				irr::core::vector3df(
					(x ? 25 : -25),
					(y ? 25 : -25),
					(z ? 25 : -25)));
			irrcontext::meshmanipr->setVertexColors(tmp->getMesh(),RGBColor(
				((0xFF * x) | 0x55),
				((0xFF * y) | 0x55),
				((0xFF * z) | 0x55)));
	}}}
	irrcontext::smgr->addLightSceneNode();
	}

//void * repl (void * dummy) {
//	LSTATE = luaL_newstate();
//	lua_close(LSTATE);
//	return 0;
//	}

main (int argc, char *argv[]) {
	
	if (argc < 2) {
		printf("usage: %s <another tty> <$TERM of tty> ...\n",argv[0]);
		exit(1);
		}
	initialize(argv);
	while (irrcontext::device->run()) {
puts("PING = 0;");
		PING = 0;
puts("if (SCRAM) exit(0);");
		if (SCRAM) exit(0);
puts("pthread_mutex_lock(&CAMLOCK);");
		pthread_mutex_lock(&CAMLOCK);
puts("CAMERA->setTarget(CAMCOORD.euclid());");
		CAMERA->setTarget(CAMCOORD.euclid());
puts("pthread_mutex_unlock(&CAMLOCK);");
		pthread_mutex_unlock(&CAMLOCK);
puts("irrcontext::driver->beginScene(true, true, RGBAColor(0,0,0xAA,0xF0));");
		irrcontext::driver->beginScene(true, true, RGBAColor(0,0,0xAA,0xF0));
puts("irrcontext::smgr->drawAll();");
		irrcontext::smgr->drawAll();
puts("irrcontext::guienv->drawAll();");
		irrcontext::guienv->drawAll();
puts("irrcontext::driver->endScene();");
		irrcontext::driver->endScene();
puts("irrcontext::now = irrcontext::timer->getTime();");
		irrcontext::now = irrcontext::timer->getTime();
puts("irrcontext::deltatime = (irrcontext::now - irrcontext::then) / 1000.0;");
		irrcontext::deltatime = (irrcontext::now - irrcontext::then) / 1000.0;
puts("irrcontext::then = irrcontext::now;");
		irrcontext::then = irrcontext::now;
		}}
