/**************
 * IWANNAFLY  *
 *            *
 *  prealpha  *
 **************/

#define SNAPSHOT "NIGHT/10/JAN/2021"

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
	PLAYER_VELOCITY = calloc(3,sizeof(double));
	CAMERA_MANUAL_OVERRIDE = calloc(1,sizeof(bool));

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
	irrcontext::trisel = irrcontext::smgr->createMetaTriangleSelector();

	irrcontext::guienv->addStaticText(L"IWannaFly Devtest prealpha snapshot " SNAPSHOT,irr::core::rect<irr::s32>(10,10,260,22),1);
	CAMERA = irrcontext::smgr->addCameraSceneNode(NULL,irr::core::vector3df(0,0,0),irr::core::vector3df(1,1,1));
	CAMERA->setUpVector(irr::core::vector3df(0,0,1));
	PLAYER = IWF::FUNC::initidcube(.4,NULL,20);
	irrcontext::colresanim = irrcontext::smgr->createCollisionResponseAnimator(irrcontext::trisel,CAMERA,irr::core::vector3df(.2,.2,.2),irr::core::vector3df(0,0,-0.98),irr::core::vector3df(0,0,0.001));
	PLAYER->addAnimator(irrcontext::colresanim);
	irrcontext::meshmanipr->setVertexColors(PLAYER->getMesh(),RGBColor(0x55,0x55,0xFF));

	for (int x = -1;x < 2;x += 1) {
		for (int y = -1;y < 2;y += 1) {
			for (int z = -1;z < 2;z += 1) {
				if (x || y || z) {
					irr::scene::IMeshSceneNode * tmp = IWF::FUNC::initidcubef(10.0,NULL,((z * 9) + (y * 3) + x),(x * 25),(y * 25),(z * 25));
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
		pthread_mutex_lock(&CAMLOCK);
		if (*CAMERA_MANUAL_OVERRIDE) {
			CAMERA->setPosition(irr::core::vector3df(0,0,0));
			(*CAMERA_MANUAL_OVERRIDE) = false;
			}
		CAMERA->setTarget(CAMCOORD.euclid());
		CAMERA_POS_BUFFER = CAMERA->getPosition();
		PLAYER_POS_BUFFER = PLAYER->getPosition();
		{
			irr::core::vector3df tmp = PLAYER->getPosition();
			tmp.X = tmp.X + (*PLAYER_VELOCITY)[0];
			tmp.Y = tmp.Y + (*PLAYER_VELOCITY)[1];
			tmp.Z = tmp.Z + (*PLAYER_VELOCITY)[2];
			PLAYER->setPosition(tmp);
			CAMERA->setPosition(tmp);		
		}
		pthread_mutex_unlock(&CAMLOCK);
		irrcontext::driver->beginScene(true, true, RGBAColor(0,0,0x55,0xEE));
		irrcontext::smgr->drawAll();
		irrcontext::guienv->drawAll();
		irrcontext::driver->endScene();
		(*PLAYER_VELOCITY)[0] = ((int)(((*PLAYER_VELOCITY)[0] / 2) * 1000000)) / 1000000.0;	//if this underflows, then the optimizer is screwing you
		(*PLAYER_VELOCITY)[1] = ((int)(((*PLAYER_VELOCITY)[1] / 2) * 1000000)) / 1000000.0;
		(*PLAYER_VELOCITY)[2] = ((int)(((*PLAYER_VELOCITY)[2] / 2) * 1000000)) / 1000000.0;
		irrcontext::now = irrcontext::timer->getTime();
		irrcontext::deltatime = (irrcontext::now - irrcontext::then) / 1000.0;
		irrcontext::then = irrcontext::now;
		}}
