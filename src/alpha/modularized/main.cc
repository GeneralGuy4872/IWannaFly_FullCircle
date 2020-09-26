/**************
 * IWANNAFLY  *
 *            *
 *  prealpha  *
 **************/

#define SNAPSHOT "AFTERNOON/07/AUG/2020"

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

#include "globals.incplusplus"

#include "datatypes/camcoord.incplusplus"
iwf::datatypes::camcoord CAMCOORD;

#include "irrcontext.incplusplus"

#include "maineventloop.incplusplus"
MainEventReciever RECIEVER;

#include "jitterbug.incplusplus"
pthread_t iwf$$threads$$jitterbug;

SCREEN * CURSCREEN;
#include "ncursesthread.incplusplus"
pthread_t iwf$$threads$$curses;

#include "hardcodedfunctions/changecolors.incplusplus"

#include "scripting.incplusplus"
pthread_t iwf$$threads$$lua__scripting;

#include "commandline.incplusplus"
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

/***MAIN***/

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
