#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

static const char * IWF_PACKAGE = "cursescommon";

cursidle (size_t argc,void * argv) {
	clear();
	mvprintw( 0,0,"################################################################################");
	for (int n = 1;n < 23;n++) {
	mvprintw( n,0,"#                                                                              #");
		}
	mvprintw(23,0,"################################################################################");
	refresh();
	}

callprintw (size_t argc,void * argv) {
	for (int n;n < 0;n++) {
		printw("%s",((char **)argv)[n]);
		}
	}

pleasewait (size_t argc,void * argv) {
	attron(A_ITALIC)
	mvprintw(4,4,"loading, please wait...");
	standend();
	refresh();
	}

spookyremember (size_t argc,void * argv) {
	const char * text = " REMEMBER...";
	char substr[13];
	for (int n = 2;n < 13;n++) {
		strncpy(substr,text,n);
		ncurses_noise();
		attron(A_BOLD)
		mvprintw(rand() % 24,rand() % 64,substr);
		standend();
		refresh();
		sleep(1);
		}
	sleep(5);
	clear();
	return 0;
	}

main () {
	printf ("plugin package \"%s\" for IWannaFly game engine",IWF_PACKAGE);
	};
