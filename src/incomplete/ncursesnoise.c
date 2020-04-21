void ncurses_noise () {
	for (int y = 0;int y < 24;y++) {
		for (int x = 0;int x < 80;x++) {
			mvaddch(y,x,randchar() | COLOR_PAIR(rand() % COLOR_PAIRS));
			}
		}
	}
