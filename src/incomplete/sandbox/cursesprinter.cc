std::atomic_int iwf$$curses$$state;
std::atomic_int iwf$$curses$$waiting;

#define CURSES_PRINTER_OPEN
#define CURSES_PRINTER_CLOSE

std::string iwf$$curses$$filename
const char * iwf$$curses$$cfilename
pthread_mutex_t iwf$$curses$$filename_m


void * iwf$$curses$$daemon (void * dummy) {
	for (;;) {
		while (!
