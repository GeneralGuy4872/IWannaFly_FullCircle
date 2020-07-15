#define macro_pthread_create(X,Y,Z) pthread_t X; pthread_create(&X,NULL,Y,Z)

//init curses

//init angelscript

int main (int argc,char *argv[]) {
	macro_pthread_create(iwf$$threadhandles$$joystick,iwf$$joystickio,NULL);
	//asynchronous button minithreads
	macro_pthread_create(iwf$$threadhandles$$commandline,iwf$$threads$$commandline,/*???*/);
	//movement
	//irrlicht thread
	//load game file
	//load room
	//load chunk
	//becomes event loop
